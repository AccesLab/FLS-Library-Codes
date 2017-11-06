//Authors: Abel Teklu Hilemichael, Ali Karimoddini, Abdollah Homaifar
//athailem@aggies.ncat.edu
//NCAT ACESS LAB
//This code performs defuzzification for type-1 and tpe-2 FLSs for TSK and Mamdani FLSs

#include "defuzz.h"
defuzzify::defuzzify() {
}
defuzzify::~defuzzify() {
}


vector<double> defuzzify::t1_tsk(vector<double> *aFiring_level, vector<vector<vector<double>>> *aOutFSet, MainWindow_t *stData) {
	//for all outputs, get the crisp output using weighted average defuzzification
				for (int _out = 0; _out < stData->vstOutputs[_out].vstMF.size(); _out++) {
					//construct yl and yr from rule
					vector<double> _y;
					double _y_ = 0, _Y_t1 = 0;
					double f_y = 0, sum_firing_level =0;
						
					for (int i = 0; i < stData->vstRules.size(); i++) {
						f_y = f_y + *((double *)(&aFiring_level[i])) * *((double *)(&aOutFSet[i][_out]));
						sum_firing_level = sum_firing_level + *((double *)(&aFiring_level[i]));
					}
					//Defuzzification Weighted Average for TSK
					_Y_t1 = f_y / sum_firing_level;
					_y_crisp.push_back(_Y_t1);//prepare output vector
				}//end of for all outputs
				 //Defuzzification
	return _y_crisp;
}

vector<double> defuzzify::ub(vector<vector<double>> *_tskOutputSet, MainWindow_t *stData) {
	//for all outputs, get the crisp output using UB output processing technique
				for (int _out = 0; _out < stData->vstOutputs[_out].vstMF.size(); _out++) {
				//Defuzzification
					_y_crisp.push_back((*((double *)(&_tskOutputSet[_out][0])) + *((double *)(&_tskOutputSet[_out][1]))) / 2);//prepare output vector
				}//end of for all outputs		
	return _y_crisp;
}

vector<double> defuzzify::centroid(vector<vector<vector<double>>> *_outputSet, MainWindow_t *stData) {
	//throw "not";
	//for all outputs, get the crisp output using centroid defuzzification technique
	for (int _out = 0; _out < stData->vstOutputs[_out].vstMF.size(); _out++) {
		
		double _temp =  0, _temp2 = 0;
		
		for (int i = 0; i < _outputSet[_out][0].size(); i++) {
			_temp = _temp + *((double *)(&_outputSet[_out][0][i])) * *((double *)(&_outputSet[_out][1][i]));
			_temp2 = _temp2 + *((double *)(&_outputSet[_out][0][i]));
		}

		//Store the output
		_y_crisp.push_back(_temp / _temp2);
	}//end of for all outputs

	return _y_crisp;
}

vector<double> defuzzify::nt(vector<vector<vector<double>>> *_it2_outputFset, MainWindow_t *stData) {
	//for all outputs, get the crisp output using NT type reduction and defuzzification technique
	for (int _out = 0; _out < stData->vstOutputs[_out].vstMF.size(); _out++) {

		_uStar.clear();
		double _temp = 0, _temp2 = 0;

		for (int i = 0; i < _it2_outputFset[_out][0].size(); i++) {
			_uStar.push_back((*((double *)(&_it2_outputFset[0][i])) + *((double *)(&_it2_outputFset[1][i]))) / 2);
		}
		//Do Defuzzification
		for (int i = 0; i < _it2_outputFset[_out][0].size(); i++) {
			_temp = _temp + *((double *)(&_it2_outputFset[_out][2][i])) * ((double)(_uStar[i]));
			_temp2 = _temp2 + *((double *)(&_uStar[i]));
		}

		//Store the output
		if (_temp != 0){
			_y_crisp.push_back(_temp / _temp2);
		}
		else {
			_y_crisp.push_back(0);
		}

	}//end of for all outputs

	return _y_crisp;
}

vector<double> defuzzify::km() {
	throw "Not yet implemented";
}

vector<double> defuzzify::weightedAvg() {
	throw "Not yet implemented";
}

vector<double> defuzzify::height() {
	throw "Not yet implemented";
}

vector<double> defuzzify::gaussianMF() {
	throw "Not yet implemented";
}

vector<double> defuzzify::triangularMF() {
	throw "Not yet implemented";
}

vector<double> defuzzify::trapezoidalMF() {
	throw "Not yet implemented";
}

vector<double> defuzzify::it2Gaussian() {
	throw "Not yet implemented";
}