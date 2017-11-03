//Author: Abel Teklu Hilemichael
//athailem@aggies.ncat.edu
//NCAT ACESS LAB
//This code performs defuzzification for type-1 and tpe-2 FLSs for TSK and Mamdani FLSs

#include <exception>
#include <vector>

using namespace std;

#include "defuzz.h"
defuzz::defuzz() {
}

vector<double> defuzz::t1_tsk(vector<double> aInput, vector<double> aFiring_level) {
	//for all outputs, get the crisp output using weighted average defuzzification
				for (int _out = 0; _out < _numOutputs; _out++) {
					//construct yl and yr from rule
					vector<double> _y;
					double _y_ = 0, _Y_t1 = 0;
					double f_y = 0, sum_firing_level =0;
					
					for (int i = 0; i < _maxNumRules; i++) {//for all rules, find yl and yr
						//for each rule, y = Co + C1*Input1 + C2l*Input2 + ... Cp*Inputp
						_y_ = _ruleMatrix[i][_numInputs + _numOutputs + 1]; //Co
						for (int _inpts = 0, _rIndex = 0; _inpts < _numInputs; _inpts++, _rIndex + 2) {
							_y_ += (_ruleMatrix[i][_numInputs + _numOutputs + 1 + _rIndex] * aInput[_inpts]);//1 has to be index from input vector _inVector[_inputs]
						}
						_y.push_back(_y_);
					}
	
					for (int i = 0; i < _maxNumRules; i++) {
						f_y = f_y + aFiring_level[i] * _y[i];
						sum_firing_level = sum_firing_level + aFiring_level[i];
					}
					//Defuzzification Weighted Average for TSK
					_Y_t1 = f_y / sum_firing_level;
					_y_crisp.push_back(_Y_t1);//prepare output vector
				}//end of for all outputs
				 //Defuzzification
	return _y_crisp;
}

vector<double> defuzz::ub(vector<double> aInput, vector<double> aUfiring_level, vector<double> aLfiring_level) {
	//for all outputs, get the crisp output using UB output processing technique
				for (int _out = 0; _out < _numOutputs; _out++) {
					//construct yl and yr from rule
					vector<double> _y_l;
					vector<double> _y_r;
					double _y_l_ = 0, _y_r_ = 0;
					double fl_yl = 0, fh_yl = 0, fl_yr = 0, fh_yr = 0.0;
					double A = 0, B = 0, C = 0, D = 0, E = 0, F = 0;
					double yl_hi = 0, yr_lo = 0, yl_lo = 0, yr_hi = 0, sum_lfiring_level = 0, sum_ufiring_level = 0;
	
					for (int i = 0; i < _maxNumRules; i++) {//for all rules, find yl and yr
						//for each rule, yl = Col + C1l*Input1 + C2l*Input2 + ... Cpl*Inputp, yr = Cor + C1r*Input1 + C2r*Input2 + ... Cpr*Inputp
						_y_l_ = _ruleMatrix[i][_numInputs + _numOutputs + 1]; //Col
						_y_r_ = _ruleMatrix[i][_numInputs + _numOutputs + 2]; //Cor
						for (int _inpts = 0, _rIndex = 0; _inpts < _numInputs; _inpts++, _rIndex + 2) {
							_y_l_ += (_ruleMatrix[i][_numInputs + _numOutputs + 1 + _rIndex]* aInput[_inpts]);//1 has to be index from input vector _inVector[_inputs]
							_y_r_ += (_ruleMatrix[i][_numInputs + _numOutputs + 2 + _rIndex]* aInput[_inpts]);//1 has to be index from input vector _inVector[_inputs]
						}
							_y_l.push_back(_y_l_);
							_y_r.push_back(_y_r_);					
					}
	
					//Inner Bounds Calculation
					for (int i = 0; i < _maxNumRules; i++) {
						fl_yl = fl_yl + aLfiring_level[i] * _y_l[i];
						fh_yl = fh_yl + aUfiring_level[i] * _y_l[i];
						fl_yr = fl_yr + aLfiring_level[i] * _y_r[i];
						fh_yr = fh_yr + aUfiring_level[i] * _y_r[i];
						sum_lfiring_level = sum_lfiring_level + aLfiring_level[i];
						sum_ufiring_level = sum_ufiring_level + aUfiring_level[i];
					}
					if (sum_lfiring_level != 0 && sum_ufiring_level != 0) {//if these values are 0, it will generate _nan this is a drawback of UB
						fl_yl = fl_yl / sum_lfiring_level;
						fh_yl = fh_yl / sum_ufiring_level;
						fl_yr = fl_yr / sum_lfiring_level;
						fh_yr = fh_yr / sum_ufiring_level;
	
						yl_hi = min(fl_yl, fh_yl);
						yr_lo = max(fh_yr, fl_yr);
	
						//Outer Bounds Calculation
						for (int i = 0; i < _maxNumRules; i++) {
							A = A + aUfiring_level[i] - aLfiring_level[i];
							C = C + aLfiring_level[i] * (_y_l[i] - _y_l[0]);
							D = D + aUfiring_level[i] * (_y_l[_maxNumRules - 1] - _y_l[i]);
							E = E + aUfiring_level[i] * (_y_r[i] - _y_r[0]);
							F = F + aLfiring_level[i] * (_y_r[_maxNumRules - 1] - _y_r[i]);
						}	B = sum_lfiring_level * sum_ufiring_level;
						if (B != 0 && (C + D) != 0 && (E + F) != 0) {
							yl_lo = yl_hi - ((A / B) * (C*D) / (C + D));
							yr_hi = yr_lo + ((A / B) * (E*F) / (E + F));
						}
						else {//if _nan, output is set to 0
							yl_lo = 0;
							yr_hi = 0;
						}
					}
					else {//if _nan, output is set to 0
						yl_lo = 0;
						yr_hi = 0;
					}
					//Final Uncertainty Bounds
					_y_left = (yl_hi + yl_lo) / 2;
					_y_right = (yr_hi + yr_lo) / 2;
					//Defuzzification
					_y_crisp.push_back((_y_left + _y_right) / 2);//prepare output vector
				}//end of for all outputs		
	return _y_crisp;
}

vector<double> defuzz::centroid(vector<double> aInput, vector<double> aFiring_level) {
	throw "not";
	//for all outputs, get the crisp output using centroid defuzzification technique
/*	for (int _out = 0; _out < _numOutputs; _out++) {
		
		int _local_index = 4;
		int _numofMFs = _OutputMatrix[_out][2];
		double _temp =  0, _temp2 = 0, _temp3 = 0;
		double _aggSet[_precision] = { 0 };
		double _quantization = (_OutputMatrix[_out][1] - _OutputMatrix[_out][0]) / _precision;//descritize the output range
		double _outputSet[_numRules][_precision] = { 0 }; //fill the array with 0
		
		//fill the output matrix
		for (int _r = 0; _r < _numRules; _r++) {
			if (aFiring_level[_r] != 0) {
				for (double _decreteVal = _OutputMatrix[_out][0], _row = 0; _decreteVal <= _OutputMatrix[_out][1]; _decreteVal + _quantization, _row++)
				{
					//find the membership value
					if (_OutputMatrix[_out][3] == 0) {
						_temp = t1mfs.trimf(_decreteVal, _OutputMatrix[_out][_local_index], _OutputMatrix[_out][_local_index + 1], _OutputMatrix[_out][_local_index + 2], _OutputMatrix[_out][_local_index + 4]);
						_local_index += 7;
					}
					if (_OutputMatrix[_out][3] == 1) {
						_temp = t1mfs.trapmf(_decreteVal, _OutputMatrix[_out][_local_index], _OutputMatrix[_out][_local_index + 1], _OutputMatrix[_out][_local_index + 2], _OutputMatrix[_out][_local_index + 3], _OutputMatrix[_out][_local_index + 4]);
						_local_index += 7;
					}
					if (_OutputMatrix[_out][3] == 2) {
						_temp = t1mfs.gaussmf(_decreteVal, _OutputMatrix[_out][_local_index], _OutputMatrix[_out][_local_index + 1]);
						_local_index += 7;
					}
					
					//do clipping
					if (_temp >= aFiring_level[_r]) {
						_outputSet[_r][int(_row)] = aFiring_level[_r];
					}
					else { _outputSet[_r][int(_row)] = _temp; }
				}
			}
		}
		//Find the Aggregate Set
		for (int i = 0; i < _precision; i ++) {
			for (int _r = 0; _r < _numRules - 1; _r++) {
				_aggSet[i] = max(_outputSet[_r][i], _outputSet[_r + 1][i]);
			}
		}

		//Do Centroid Defuzzification
		for (double _decreteVal = _OutputMatrix[_out][0], _row = 0; _decreteVal < _OutputMatrix[_out][1]; _decreteVal + _quantization, _row++)
		{
			_temp2 = _temp2 + (_decreteVal*_aggSet[int(_row)]);
			_temp3 = _temp3 + _aggSet[int(_row)];
		}

		//Store the output
		_y_crisp.push_back(_temp2 / _temp3);
	}//end of for all outputs

	return _y_crisp;*/
}

vector<double> defuzz::nt(vector<double> aInput, vector<double> _umf_firingLevel, vector<double> _lmf_firingLevel) {
	//for all outputs, get the crisp output using NT type reduction and defuzzification technique
	for (int _out = 0; _out < _numOutputs; _out++) {

		int _local_index = 4;
		int _numofMFs = _uOutputMatrix[_out][2];
		double _utemp = 0, _ltemp = 0, _temp2 = 0, _temp3 = 0;
		double _uStar[_precision] = { 0 };
		double _uaggSet[_precision] = { 0 };
		double _laggSet[_precision] = { 0 };
		double _quantization = (_uOutputMatrix[_out][1] - _uOutputMatrix[_out][0]) / _precision;//descritize the output range
		double _uoutputSet[_numRules][_precision] = { 0 }; //fill the array with 0
		double _loutputSet[_numRules][_precision] = { 0 }; //fill the array with 0

		//fill the output matrix
		for (int _r = 0; _r < _numRules; _r++) {
			if (_umf_firingLevel[_r] != 0) {
				for (double _decreteVal = _uOutputMatrix[_out][0], _row = 0; _decreteVal <= _uOutputMatrix[_out][1]; _decreteVal + _quantization, _row++)
				{
					//find the membership value
					if (_uOutputMatrix[_out][3] == 0) {
						_utemp = t1mfs.trimf(&_decreteVal, _uOutputMatrix[_out][_local_index], _uOutputMatrix[_out][_local_index + 1], _uOutputMatrix[_out][_local_index + 2], _uOutputMatrix[_out][_local_index + 4]);
						//_ltemp = t1mfs.trimf(_decreteVal, _lOutputMatrix[_out][_local_index], _lOutputMatrix[_out][_local_index + 1], _lOutputMatrix[_out][_local_index + 2], _lOutputMatrix[_out][_local_index + 4]);
						_local_index += 7;
					}
					if (_uOutputMatrix[_out][3] == 1) {
						_utemp = t1mfs.trapmf(&_decreteVal, _uOutputMatrix[_out][_local_index], _uOutputMatrix[_out][_local_index + 1], _uOutputMatrix[_out][_local_index + 2], _uOutputMatrix[_out][_local_index + 3], _uOutputMatrix[_out][_local_index + 4]);
						//_ltemp = t1mfs.trapmf(_decreteVal, _lOutputMatrix[_out][_local_index], _lOutputMatrix[_out][_local_index + 1], _lOutputMatrix[_out][_local_index + 2], _lOutputMatrix[_out][_local_index + 3], _lOutputMatrix[_out][_local_index + 4]);
						_local_index += 7;
					}
					if (_uOutputMatrix[_out][3] == 2) {
						_utemp = t1mfs.gaussmf(&_decreteVal, _uOutputMatrix[_out][_local_index], _uOutputMatrix[_out][_local_index + 1]);
						//_ltemp = t1mfs.gaussmf(_decreteVal, _lOutputMatrix[_out][_local_index], _lOutputMatrix[_out][_local_index + 1]);
						_local_index += 7;
					}

					//do clipping
					if (_utemp >= _umf_firingLevel[_r]) {
						_uoutputSet[_r][int(_row)] = _umf_firingLevel[_r];
					}
					else {
						_uoutputSet[_r][int(_row)] = _utemp;
					}
				}
			}

			if (_lmf_firingLevel[_r] != 0) {
				for (double _decreteVal = _lOutputMatrix[_out][0], _row = 0; _decreteVal <= _lOutputMatrix[_out][1]; _decreteVal + _quantization, _row++)
				{
					//find the membership value
					if (_uOutputMatrix[_out][3] == 0) {
						//_utemp = t1mfs.trimf(_decreteVal, _uOutputMatrix[_out][_local_index], _uOutputMatrix[_out][_local_index + 1], _uOutputMatrix[_out][_local_index + 2], _uOutputMatrix[_out][_local_index + 4]);
						_ltemp = t1mfs.trimf(&_decreteVal, _lOutputMatrix[_out][_local_index], _lOutputMatrix[_out][_local_index + 1], _lOutputMatrix[_out][_local_index + 2], _lOutputMatrix[_out][_local_index + 4]);
						_local_index += 7;
					}
					if (_uOutputMatrix[_out][3] == 1) {
						//_utemp = t1mfs.trapmf(_decreteVal, _uOutputMatrix[_out][_local_index], _uOutputMatrix[_out][_local_index + 1], _uOutputMatrix[_out][_local_index + 2], _uOutputMatrix[_out][_local_index + 3], _uOutputMatrix[_out][_local_index + 4]);
						_ltemp = t1mfs.trapmf(&_decreteVal, _lOutputMatrix[_out][_local_index], _lOutputMatrix[_out][_local_index + 1], _lOutputMatrix[_out][_local_index + 2], _lOutputMatrix[_out][_local_index + 3], _lOutputMatrix[_out][_local_index + 4]);
						_local_index += 7;
					}
					if (_uOutputMatrix[_out][3] == 2) {
						//_utemp = t1mfs.gaussmf(_decreteVal, _uOutputMatrix[_out][_local_index], _uOutputMatrix[_out][_local_index + 1]);
						_ltemp = t1mfs.gaussmf(&_decreteVal, _lOutputMatrix[_out][_local_index], _lOutputMatrix[_out][_local_index + 1]);
						_local_index += 7;
					}

					//do clipping
					if (_ltemp >= _lmf_firingLevel[_r]) {
						_loutputSet[_r][int(_row)] = _lmf_firingLevel[_r];
					}
					else {
						_loutputSet[_r][int(_row)] = _ltemp;
					}
				}
			}
		}
		//Find the Aggregate Set
		for (int i = 0; i < _precision; i++) {
			for (int _r = 0; _r < _numRules - 1; _r++) {
				_uaggSet[i] = max(_uoutputSet[_r][i], _uoutputSet[_r + 1][i]);
			}
		}

		for (int i = 0; i < _precision; i++) {
			for (int _r = 0; _r < _numRules - 1; _r++) {
				_laggSet[i] = max(_loutputSet[_r][i], _loutputSet[_r + 1][i]);
			}
		}

		for (int i = 0; i < _precision; i++) {
			_uStar[i] = (_uaggSet[i] + _laggSet[i]) / 2;
		}
		//Do Defuzzification
		for (double _decreteVal = _OutputMatrix[_out][0], _row = 0; _decreteVal < _OutputMatrix[_out][1]; _decreteVal + _quantization, _row++)
		{
			_temp2 = _temp2 + (_decreteVal*_uStar[int(_row)]);
			_temp3 = _temp3 + _uStar[int(_row)];
		}

		//Store the output
		if (_temp3 != 0){
			_y_crisp.push_back(_temp2 / _temp3);
		}
		else {
			_y_crisp.push_back(0);
		}

	}//end of for all outputs

	return _y_crisp;
}

vector<double> defuzz::km() {
	throw "Not yet implemented";
}

vector<double> defuzz::weightedAvg() {
	throw "Not yet implemented";
}

vector<double> defuzz::height() {
	throw "Not yet implemented";
}

vector<double> defuzz::defuzzify(vector<double> aFiring_level, vector<double> aUfiring_level, vector<double> aLfiring_level) {
	if (_type == "T2") {
			throw "Not Yet Implemented";
		}//end of type T2
	
		if (_type == "IT2") {
			if (_defuzzMethod == "UB") {
				throw "Not Yet Implemented";		
			}//end of UB
		}//end of _type IT2
	
		if (_type == "T1") {
			if (_defuzzMethod == "wavg") {
				throw "Not Yet Implemented";
			}//end of wavg
		}//end of type T1
	
	cout << "FLS Output "<< _y_crisp[0]<< endl;
	return _y_crisp;
}