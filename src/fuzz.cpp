//Author: Abel Teklu Hilemichael
//athailem@aggies.ncat.edu
//NCAT ACESS LAB
//The operation in this code performs fuzzification of all inputs and returns the fuzzified values

#include <exception>
#include <vector>
using namespace std;

#include "fuzz.h"

fuzz::fuzz() {
	_numofuMFs = 0;
	_numoflMFs = 0;
	_numofMFs = 0;
	_u_local_index = 0;
	_l_local_index = 0;
	_local_index = 0;
}
fuzz::~fuzz() {
}

vector<vector<double> > fuzz::fuzzify(int aSetID, vector<double> aInputs) {

	if (aSetID == 0) {//if it is t1 system
					  //create vector of vector storage place for fuzzified value of LMF
		for (int i = 0; i < _numInputs; i++)
		{
			_fuzzified_val.push_back(_row);
		}
		//For all inputs for T1
		for (int i = 0; i < _numInputs; i++) {

			_local_index = 4;
			_numofMFs = _InputMatrix[i][2];

			//Fuzzify T1 MFs 
			for (int j = 0; j < _numofMFs; j++) {
				
				if (_InputMatrix[i][3] == 0) {
					_fuzzified_val[i].push_back(t1mfs.trimf(aInputs[i], _InputMatrix[i][_local_index], _InputMatrix[i][_local_index + 1], _InputMatrix[i][_local_index + 2], _InputMatrix[i][_local_index + 4]));
					_local_index += 7;
				}
				if (_InputMatrix[i][3] == 1) {
					_fuzzified_val[i].push_back(t1mfs.trapmf(aInputs[i], _InputMatrix[i][_local_index], _InputMatrix[i][_local_index + 1], _InputMatrix[i][_local_index + 2], _InputMatrix[i][_local_index + 3], _InputMatrix[i][_local_index + 4]));
					_local_index += 7;
				}
				if (_InputMatrix[i][3] == 2) {
					_fuzzified_val[i].push_back(t1mfs.gaussmf(aInputs[i], _InputMatrix[i][_local_index], _InputMatrix[i][_local_index + 1]));
					_local_index += 7;
				}
			}
		}// end of For all inputs for T1
	}//end of if set id 0

	if (aSetID == 1) {//if it it it2 ub system for upper bound or NT
					  //create vector of vector storage place for fuzzified value of UMF
		for (int i = 0; i < _numInputs; i++)
		{
			_u_fuzzified_val.push_back(_row);
		}
		
		//For all inputs for UB
		for (int i = 0; i < _numInputs; i++) {
			_u_local_index = 4;
			_numofuMFs = _uInputMatrix[i][2];

			//Fuzzify UMFss
			for (int j = 0; j < _numofuMFs; j++) {

				if (_uInputMatrix[i][3] == 0) {
					_u_fuzzified_val[i].push_back(t1mfs.trimf(aInputs[i], _uInputMatrix[i][_u_local_index], _uInputMatrix[i][_u_local_index + 1], _uInputMatrix[i][_u_local_index + 2], _uInputMatrix[i][_u_local_index + 4]));
					_u_local_index += 7;
				}
				if (_uInputMatrix[i][3] == 1) {
					_u_fuzzified_val[i].push_back(t1mfs.trapmf(aInputs[i], _uInputMatrix[i][_u_local_index], _uInputMatrix[i][_u_local_index + 1], _uInputMatrix[i][_u_local_index + 2], _uInputMatrix[i][_u_local_index + 3], _uInputMatrix[i][_u_local_index + 4]));
					_u_local_index += 7;
				}
				if (_uInputMatrix[i][3] == 2) {
					_u_fuzzified_val[i].push_back(t1mfs.gaussmf(aInputs[i], _uInputMatrix[i][_u_local_index], _uInputMatrix[i][_u_local_index + 1]));
					_u_local_index += 7;
				}
			}
		}// end of For all inputs for UB for upper bound or NT
		_fuzzified_val = _u_fuzzified_val;
	}//end of if set id ==1
	if (aSetID == 2) {//if it is it2 ub or NT system for lower bound
		//create vector of vector storage place for fuzzified value of LMF
		for (int i = 0; i < _numInputs; i++)
		{
			_l_fuzzified_val.push_back(_row);
		}
		
		//For all inputs for UB
		for (int i = 0; i < _numInputs; i++) {
			_l_local_index = 4;
			_numoflMFs = _lInputMatrix[i][2];
			
			//Fuzzify LMFs
			for (int j = 0; j < _numoflMFs; j++) {

				if (_lInputMatrix[i][3] == 0) {
					_l_fuzzified_val[i].push_back(t1mfs.trimf(aInputs[i], _lInputMatrix[i][_l_local_index], _lInputMatrix[i][_l_local_index + 1], _lInputMatrix[i][_l_local_index + 2], _lInputMatrix[i][_l_local_index + 4]));
					_l_local_index += 7;
				}
				if (_lInputMatrix[i][3] == 1) {
					_l_fuzzified_val[i].push_back(t1mfs.trapmf(aInputs[i], _lInputMatrix[i][_l_local_index], _lInputMatrix[i][_l_local_index + 1], _lInputMatrix[i][_l_local_index + 2], _lInputMatrix[i][_l_local_index + 3], _lInputMatrix[i][_l_local_index + 4]));
					_l_local_index += 7;
				}
				if (_lInputMatrix[i][3] == 2) {
					_l_fuzzified_val[i].push_back(t1mfs.gaussmf(aInputs[i], _lInputMatrix[i][_l_local_index], _lInputMatrix[i][_l_local_index + 1]));
					_l_local_index += 7;
				}
			}
		}// end of For all inputs for UB for lower bound
		_fuzzified_val = _l_fuzzified_val;
	}//end of if set id ==2
	
	return _fuzzified_val;
}