//Authors: Abel Teklu Hilemichael, Ali Karimoddini, Abdollah Homaifar
//athailem@aggies.ncat.edu
//NCAT ACESS LAB
//The operations in this code performs fuzzy inference processes. They return firing level and output fuzzy set for a type-1 anf inteval type-2 FLSs 
//which are based on both Mamdani and TSK inference techniques

using namespace std;

#include "infer.h"
inference::inference() {
	_outputFset = { { { 0 } } };
}
inference::~inference() {
}

vector<double> inference::_t1_firing_level(vector<vector<double>> *aFuzzified_val, MainWindow_t *stData) {

	_firing_level.clear();

	//for all rules, calculate the firing level
		for (int i = 0; i < stData->vstRules.size(); i++)
		{
			//get antecedents from each rule and extract them
			QString sString = stData->vstRules[i].sAntecedent;
			QStringList slTockens = sString.split(",");
			vAntecedents.clear();
			vValues.clear();

			for (int j = 0; j < slTockens.size(); j++)
			{
				vAntecedents.push_back((double &)(aFuzzified_val[j][slTockens[j].toInt()]));
			}

			//Calculate the firing level according to configuration
			if (stData->vstRules[i].sInference == "And" && stData->sAndMethod == "Min") {
				foreach(int var, vAntecedents)
				{
					dVal = *std::min_element(vAntecedents.constBegin(), vAntecedents.constEnd());//find the minimum tnotm 
					//cout << "\n" << var;
				}
				_firing_level.push_back(dVal);
			}
			if (stData->vstRules[i].sInference == "And" && stData->sAndMethod == "Prod") {
				dVal = vAntecedents[0];
				for (int k = 1; k < vAntecedents.size(); k++)
				{
					dVal = dVal*vAntecedents[k];//find the product tnotm 
					//cout << "\n" << var;
				}
				_firing_level.push_back(dVal);
			}
			if (stData->vstRules[i].sInference == "Or") {
				foreach(int var, vAntecedents)
				{
					dVal = *std::max_element(vAntecedents.constBegin(), vAntecedents.constEnd());//find the maximum tnotm 
					//cout << "\n" << var;
				}
				_firing_level.push_back(dVal);
			}
		}//end of calculating type-1 firing levels
	
	return _firing_level;
}

vector<vector<vector<double>>> inference::_type1_mamdani_processing(vector<double> *aFiring_level, MainWindow_t *stData) {
	double maxVal;
		for (int i = 0; i < stData->vstOutputs.size(); i++) {//for all outputs
			//OutputData_t stOutput = stData->vstOutputs[i];
			vMFRanges.clear();
			vOPRanges.clear();
			_outputFset.clear();
			_outputSet.clear();
			QString sOString = stData->vstOutputs[i].sRange;
			QStringList slTockens = sOString.split(",");

			//vOPRanges.push_back(abs(slTockens[1].toInt()) - abs(slTockens[0].toInt()));//Store the range to find the maximum for knowing the size of the agg set vector

			for (int j = 0; j < stData->vstOutputs[i].vstMF.size(); j++) {//find the smallest MF
				//OutputMF_t stOMF = stData->vstOutputs[i].vstMF[j];
				if (stData->vstOutputs[i].vstMF[j].sType == "tri") {
					vMFRanges.push_back(abs(stData->vstOutputs[i].vstMF[j].dP3) - abs(stData->vstOutputs[i].vstMF[j].dP1));
				}
				if (stData->vstOutputs[i].vstMF[j].sType == "trap") {
					vMFRanges.push_back(abs(stData->vstOutputs[i].vstMF[j].dP4) - abs(stData->vstOutputs[i].vstMF[j].dP1));
				}
				if (stData->vstOutputs[i].vstMF[j].sType == "gauss") {
					vMFRanges.push_back(abs(stData->vstOutputs[i].vstMF[j].dP2));
				}
			}
		//}
		
		dQuantization = (*std::min_element(vMFRanges.constBegin(), vMFRanges.constEnd()) / 100); //get quantization = smallest MF/100
		dPrecssision = (abs(slTockens[1].toDouble()) - abs(slTockens[0].toDouble())) / dQuantization; //Get precession = Largest O/P range / quantization
		vector<double> zeros(dPrecssision, 0);
		vector<double> zeros1 = zeros;
	
			for (int _r = 0; _r < stData->vstRules.size(); _r++) {//for all rules
				if ((double *)(&aFiring_level[_r]) != 0) {//save computation time if firing level is zero. If so, all output membership values will be zero.

					QString sConsString = stData->vstRules[_r].sConsequent;//get the rule consequent from the configuration file
					QStringList slConsTockens = sConsString.split(",");//parse and extract the consequents
					double oFval = slTockens[0].toDouble();//the minimum range is the start point
					double oFuzVal = 0.0;
					for (int rOutput = 0; rOutput < int(dPrecssision); rOutput++)//for all discrete levels, find membership value and perform implication for the given rule
					{
						//find the membership value
						//if (stOMF.sType == "tri") {
						//int cons = slConsTockens[i].toInt();
						if (stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].sType ==  "tri") {
							oFuzVal=(t1mfs.trimf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dMaximum));
							
						}
						else if (stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].sType == "trap") {
							oFuzVal=(t1mfs.trapmf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dMaximum));
							
						}
						else if (stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].sType == "gauss") {
							oFuzVal=(t1mfs.gaussmf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2));
							
						}

						//do min clipping/implication
						if (oFuzVal >= *((double *)(&aFiring_level[rOutput]))) {
							_outputFset[0][rOutput].push_back(*((double *)(&aFiring_level[rOutput])));
							_outputFset[1][rOutput].push_back(oFval);
						}
						else { 
							_outputFset[0][rOutput].push_back(oFuzVal);
							_outputFset[1][rOutput].push_back(oFval);
						}
						oFval += dQuantization;
					}
				}
				else{ 
					double oFval = slTockens[0].toDouble();//the minimum range is the start point
					double oFuzVal = 0.0;
					for (int rOutput = 0; rOutput < int(dPrecssision); rOutput++)//for all discrete levels, find membership value and perform implication for the given rule
					{
						_outputFset[0][rOutput].push_back(0.0);
						_outputFset[1][rOutput].push_back(oFval);
						oFval += dQuantization;
					}
				}
			}
			//Find the Aggregate Set
			for (int l = 0; l < dPrecssision; l++) {
				maxVal = 0;
				for (int _r = 0; _r < stData->vstRules.size(); _r++) {
					maxVal = max(_outputFset[0][_r][l], maxVal);
				}
				_outputSet[i][0].push_back(maxVal);
				_outputSet[i][1].push_back(_outputFset[0][1][l]);
			}			
		}
		return _outputSet;		
}
//Interval Type-2 System Inference

vector<vector<vector<double>>> inference::_type1_tsk_processing(vector<double> *aInputs, MainWindow_t *stData) {
	double tskOutput;
	_outputSet.clear();
		
		for (int _r = 0; _r < stData->vstRules.size(); _r++) {//for all rules
			QString sConsString = stData->vstRules[_r].sConsequent;//get the rule consequent from the configuration file
			QStringList slConsTockens = sConsString.split(":");//parse and extract the consequents for all rule outputs
			for (int i = 0; i < stData->vstOutputs.size(); i++) {//for all outputs
				QStringList slConsTockens2 = slConsTockens[i].split(",");//parse and extract the consequents
				tskOutput = 0;
				for (int j = 0; j < stData->vstInputs.size(); j++) {//for all inputs
					tskOutput += (slConsTockens[j].toDouble() * *((double *)(&aInputs[j])));//add the configured tsk coefficients multiplied by the respective inputs
				}
				_toutputSet[_r][i].push_back(tskOutput);//push the tsk output for all outputs of a single rule
			}
		}
	return _toutputSet;
}

vector<vector<double>> inference::_it2_firing_level(vector<vector<vector<double>>> *aFuzzified_val, MainWindow_t *stData) {

	_firing_level_t2.clear();

	//for all rules, calculate the firing level
	for (int i = 0; i < stData->vstRules.size(); i++)
	{
		//get antecedents from each rule and extract them
		QString sString = stData->vstRules[i].sAntecedent;
		QStringList slTockens = sString.split(",");
		vAntecedentsUMF.clear();
		vAntecedentsLMF.clear();
		vValues.clear();

		for (int j = 0; j < slTockens.size(); j++)
		{
			vAntecedentsUMF.push_back((double &)(aFuzzified_val[0][j][slTockens[j].toInt()]));//push the UMF fuzzified values
			vAntecedentsLMF.push_back((double &)(aFuzzified_val[1][j][slTockens[j].toInt()]));//push the LMF fuzzified values
		}

		//Calculate the firing level according to configuration
		if (stData->vstRules[i].sInference == "And" && stData->sAndMethod == "Min") {
			foreach(int var, vAntecedentsUMF)//note that UMF and LMF have the same numbers
			{
				dValUMF = *std::min_element(vAntecedentsUMF.constBegin(), vAntecedentsUMF.constEnd());//find the minimum tnotm for UMF
				dValLMF = *std::min_element(vAntecedentsUMF.constBegin(), vAntecedentsUMF.constEnd());//find the minimum tnotm for LMF																			 
			}
			_firing_level_t2[0].push_back(dValUMF);
			_firing_level_t2[1].push_back(dValLMF);
		}
		if (stData->vstRules[i].sInference == "And" && stData->sAndMethod == "Prod") {
			dValUMF = vAntecedentsUMF[0];
			dValLMF = vAntecedentsLMF[0];
			for (int k = 1; k < vAntecedentsUMF.size(); k++)
			{
				dValUMF = dValUMF*vAntecedentsUMF[k];//find the product tnotm 
				dValLMF = dValLMF*vAntecedentsLMF[k];//find the product tnotm 
			}
			_firing_level_t2[0].push_back(dValUMF);
			_firing_level_t2[1].push_back(dValLMF);
		}
		if (stData->vstRules[i].sInference == "Or") {
			foreach(int var, vAntecedentsUMF)
			{
				dValUMF = *std::max_element(vAntecedentsUMF.constBegin(), vAntecedentsUMF.constEnd());//find the maximum tnotm 
				dValLMF = *std::max_element(vAntecedentsLMF.constBegin(), vAntecedentsLMF.constEnd());//find the maximum tnotm
			}
			_firing_level_t2[0].push_back(dValUMF);
			_firing_level_t2[1].push_back(dValLMF);
		}
	}//end of calculating interval type-2 firing level
	return _firing_level_t2;
}

vector<vector<vector<double>>> inference::_it2_mamdani_processing(vector<vector<double>> *aFiring_level, MainWindow_t *stData) {
	double maxValUMF, maxValLMF;

	for (int i = 0; i < stData->vstOutputs.size(); i++) {//for all outputs
		vMFRanges.clear();
		vOPRanges.clear();
		_outputFset.clear();
		QString sOString = stData->vstOutputs[i].sRange;
		QStringList slTockens = sOString.split(",");

		//vOPRanges.push_back(abs(slTockens[1].toInt()) - abs(slTockens[0].toInt()));//Store the range to find the maximum for knowing the size of the agg set vector

		for (int j = 0; j < stData->vstOutputs[i].vstMF.size(); j++) {//find the smallest MF
																	  //OutputMF_t stOMF = stData->vstOutputs[i].vstMF[j];
			if (stData->vstOutputs[i].vstMF[j].sType == "utri" || stData->vstOutputs[i].vstMF[j].sType == "ltri") {
				vMFRanges.push_back(abs(stData->vstOutputs[i].vstMF[j].dP3) - abs(stData->vstOutputs[i].vstMF[j].dP1));
			}
			else if (stData->vstOutputs[i].vstMF[j].sType == "utrap" || stData->vstOutputs[i].vstMF[j].sType == "ltrap") {
				vMFRanges.push_back(abs(stData->vstOutputs[i].vstMF[j].dP4) - abs(stData->vstOutputs[i].vstMF[j].dP1));
			}
			else if (stData->vstOutputs[i].vstMF[j].sType == "ugauss" || stData->vstOutputs[i].vstMF[j].sType == "lgauss") {
				vMFRanges.push_back(abs(stData->vstOutputs[i].vstMF[j].dP2));
			}
		}
		//}

		dQuantization = (*std::min_element(vMFRanges.constBegin(), vMFRanges.constEnd()) / 100); //get quantization = smallest MF/100
		dPrecssision = (abs(slTockens[1].toDouble()) - abs(slTockens[0].toDouble())) / dQuantization; //Get precession = Largest O/P range / quantization
		vector<double> zeros(dPrecssision, 0);
		vector<double> zeros1 = zeros;
		double oFval = slTockens[0].toDouble();//[0] is the starting point of the output range

		for (int _r = 0; _r < stData->vstRules.size(); _r++) {//for all rules
			if ((double *)(&aFiring_level[0][_r]) != 0) {//save computation time if firing level is zero. If so, all output membership values will be zero.

				QString sConsString = stData->vstRules[_r].sConsequent;//get the rule consequent from the configuration file
				QStringList slConsTockens = sConsString.split(",");//parse and extract the consequents
				double oFuzValUMF, oFuzValLMF;

				for (int rOutput = 0; rOutput < int(dPrecssision); rOutput++)//for all discrete levels, find membership value and perform implication for the given rule
				{
					//find the membership value
					//if (stOMF.sType == "tri") {
					//int cons = slConsTockens[i].toInt();
					if (stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].sType == "utri" || stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].sType == "ltri") {
						oFuzValUMF = (t1mfs.trimf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dMaximum));
						oFuzValLMF = (t1mfs.trimf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dMaximum));
					}
					else if (stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].sType == "utrap" || stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].sType == "ltrap") {
						oFuzValUMF = (t1mfs.trapmf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dMaximum));
						oFuzValLMF = (t1mfs.trapmf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dMaximum));

					}
					else if (stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].sType == "ugauss" || stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].sType == "ugauss") {
						oFuzValUMF = (t1mfs.gaussmf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2));
						oFuzValLMF = (t1mfs.gaussmf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2));

					}

					//do clipping/implication for UMF
					if (oFuzValUMF >= *((double *)(&aFiring_level[0][rOutput]))) {
						_outputFsetUMF[0][rOutput].push_back(*((double *)(&aFiring_level[0][rOutput])));
					}
					else { _outputFsetUMF[0][rOutput].push_back(oFuzValUMF); }

					//do clipping/implication for LMF
					if (oFuzValLMF >= *((double *)(&aFiring_level[1][rOutput]))) {
						_outputFsetLMF[1][rOutput].push_back(*((double *)(&aFiring_level[1][rOutput])));
					}
					else { _outputFsetLMF[1][rOutput].push_back(oFuzValLMF); }
					_it2_outputFset[2][rOutput].push_back(oFval);
					oFval += dQuantization;
				}
			}
			else { 
				for (int rOutput = 0; rOutput < int(dPrecssision); rOutput++)//for all discrete levels, find membership value and perform implication for the given rule
				{
					//_outputFsetUMF[_r] = zeros1;
					//_outputFsetLMF[_r] = zeros1;
					_outputFsetLMF[0][rOutput].push_back(0);
					_outputFsetLMF[1][rOutput].push_back(0);
					_it2_outputFset[2][rOutput].push_back(oFval);
					oFval += dQuantization;
				}
				}
		}
		//Find the Aggregate Set
		for (int l = 0; l < dPrecssision; l++) {
			maxValUMF = 0; maxValLMF = 0;
			for (int _r = 0; _r < stData->vstRules.size(); _r++) {
				maxValUMF = max(_outputFset[0][_r][l], maxValUMF);
				maxValLMF = max(_outputFset[1][_r][l], maxValLMF);
			}
			_it2_outputFset[0][i].push_back(maxValUMF);
			_it2_outputFset[1][i].push_back(maxValLMF);
		}
	}
	return _it2_outputFset;
}

vector<vector<double>> inference::_it2_tsk_processing(vector<double> *aInputs, vector<vector<double>> *aFiring_level, MainWindow_t *stData) {
	double tskOutputl, tskOutputu;
	QStringList slConsTockens1, slConsTockens2, slConsTockens3, slConsTockens4;
	vector<double> _y_l;
	vector<double> _y_r;
	_outputSet.clear();

	for (int _r = 0; _r < stData->vstRules.size(); _r++) {//for all rules
		QString sConsString = stData->vstRules[_r].sConsequent;//get the rule consequent from the configuration file
		QStringList slConsTockens = sConsString.split(":");//parse and extract the consequents for all rule outputs
		for (int i = 0; i < stData->vstOutputs.size(); i++) {//for all outputs
			QStringList slConsTockens2 = slConsTockens[i].split(",");//parse and extract the consequents
			tskOutputl = 0;
			tskOutputu = 0;
			for (int j = 0; j < stData->vstInputs.size(); j++) {//for all inputs
				slConsTockens3 = slConsTockens[j].split("|");
				slConsTockens4 = slConsTockens[j].split(",");
				tskOutputl += (slConsTockens4[0].toDouble() * *((double *)(&aInputs[j])));
				tskOutputu += (slConsTockens4[1].toDouble() * *((double *)(&aInputs[j])));//add the configured tsk coefficients multiplied by the respective inputs
			}
			//for each rule, yl = Col + C1l*Input1 + C2l*Input2 + ... Cpl*Inputp, yr = Cor + C1r*Input1 + C2r*Input2 + ... Cpr*Inputp
			_y_l.push_back(min(tskOutputl, tskOutputu));//push the yl tsk output for all outputs of a single rule
			_y_r.push_back(max(tskOutputl, tskOutputu));//push the yr tsk output for all outputs of a single rule
		}
	}
	//for all outputs, get the crisp output using UB output processing technique
	for (int _out = 0; _out < stData->vstOutputs.size(); _out++) {
		//construct yl and yr from rule
		vector<double> _y_l;
		vector<double> _y_r;
		double _y_l_ = 0, _y_r_ = 0;
		double fl_yl = 0, fh_yl = 0, fl_yr = 0, fh_yr = 0.0;
		double A = 0, B = 0, C = 0, D = 0, E = 0, F = 0;
		double yl_hi = 0, yr_lo = 0, yl_lo = 0, yr_hi = 0, sum_lfiring_level = 0, sum_ufiring_level = 0;
		
		//Inner Bounds Calculation
		for (int i = 0; i < stData->vstRules.size(); i++) {
			fl_yl = fl_yl + *((double *)(&aFiring_level[1][i])) * _y_l[i];//aLfiring_level[i]
			fh_yl = fh_yl + *((double *)(&aFiring_level[0][i])) * _y_l[i];//aUfiring_level[i]
			fl_yr = fl_yr + *((double *)(&aFiring_level[1][i])) * _y_r[i];//aLfiring_level[i]
			fh_yr = fh_yr + *((double *)(&aFiring_level[0][i])) * _y_r[i];//aUfiring_level[i]
			sum_lfiring_level = sum_lfiring_level + *((double *)(&aFiring_level[1][i]));
			sum_ufiring_level = sum_ufiring_level + *((double *)(&aFiring_level[0][i]));
		}
		if (sum_lfiring_level != 0 && sum_ufiring_level != 0) {//if these values are 0, it will generate _nan this is a drawback of UB
			fl_yl = fl_yl / sum_lfiring_level;
			fh_yl = fh_yl / sum_ufiring_level;
			fl_yr = fl_yr / sum_lfiring_level;
			fh_yr = fh_yr / sum_ufiring_level;

			yl_hi = min(fl_yl, fh_yl);
			yr_lo = max(fh_yr, fl_yr);

			//Outer Bounds Calculation
			for (int i = 0; i < stData->vstRules.size(); i++) {
				A = A + *((double *)(&aFiring_level[0][i])) - *((double *)(&aFiring_level[1][i]));//aUfiring_level[i] - aLfiring_level[i]
				C = C + *((double *)(&aFiring_level[0][i])) * (_y_l[i] - _y_l[0]);
				D = D + *((double *)(&aFiring_level[0][i])) * (_y_l[stData->vstRules.size() - 1] - _y_l[i]);
				E = E + *((double *)(&aFiring_level[0][i])) * (_y_r[i] - _y_r[0]);
				F = F + *((double *)(&aFiring_level[0][i])) * (_y_r[stData->vstRules.size() - 1] - _y_r[i]);
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

		_tskOutputSet[_out].push_back(_y_left);
		_tskOutputSet[_out].push_back(_y_right);
	}
	return _tskOutputSet;
}