//Author: Abel Teklu Hilemichael
//athailem@aggies.ncat.edu
//NCAT ACESS LAB
//The operation in this code performs fuzzy inference operation. It receaves crisp inputs and returns crisp outputs

#include <exception>
#include <vector>
#include <iostream>

using namespace std;

#include "flslib.h"

flslib::flslib() {}
flslib::~flslib() {}


vector<double> flslib::runFuzzy(vector<double> aInputs) {
	XMLReader Reader(&stSysData);
	Reader.ReadXMLFile("C:/Users/Abel/Desktop/hi.xml");
	//_testData = &stSysData;
	//vector<double> ins = { 0 };
	 //vector<vector<vector<double>>> f;// (4, vector<double>(5)));
	
	if (_type == "T1") {
		if (_inference == "TSK") {
			f = _fuz.fuzzifyt2(&aInputs, &stSysData);
			_fuzzVal = _fuz.fuzzify( &aInputs, &stSysData);
			_firingLevel = _infr._t1_firing_level(&_fuzzVal, &stSysData);
			_output = _defuz.t1_tsk(aInputs, _firingLevel);
		}

		if (_inference == "Mamdani") {
			_fuzzVal = _fuz.fuzzify(&aInputs, &stSysData);
			_firingLevel = _infr._t1_firing_level(&_fuzzVal, &stSysData);
			_output = _defuz.centroid(aInputs, _firingLevel);
		}

		else { throw "Not yet implemented"; }
	}
	//throw "not";
	/*if (_type == "IT2") {
		if (_inference == "TSK") {
			if (_defuzzMethod == "UB") {
				_umf_fuzzVal = _fuz.fuzzify(1, aInputs, "Desktop/example1.xml");
				_lmf_fuzzVal = _fuz.fuzzify(2, aInputs, "Desktop/example1.xml");
				_umf_firingLevel = _infr._t1_firing_level(_umf_fuzzVal, "C:/Users/Abel/Desktop/hi.xml");
				_lmf_firingLevel = _infr._t1_firing_level(_lmf_fuzzVal, "C:/Users/Abel/Desktop/hi.xml");
				_output = _defuz.ub(aInputs, _umf_firingLevel, _lmf_firingLevel);
			}
		}

		if (_inference == "Mamdani") {
			if (_defuzzMethod == "NT") {
				_umf_fuzzVal = _fuz.fuzzify(1, aInputs, "Desktop/example1.xml");
				_lmf_fuzzVal = _fuz.fuzzify(2, aInputs, "Desktop/example1.xml");
				_umf_firingLevel = _infr._t1_firing_level(_umf_fuzzVal, "C:/Users/Abel/Desktop/hi.xml");
				_lmf_firingLevel = _infr._t1_firing_level(_lmf_fuzzVal, "C:/Users/Abel/Desktop/hi.xml");
				_output = _defuz.nt(aInputs, _umf_firingLevel, _lmf_firingLevel);
			}
		}

		else { throw "Not yet implemented"; }
	}
	if (_type == "T2") {
		if (_inference == "TSK") {
			throw "Not yet implemented";
		}
		else { throw "Not yet implemented"; }
	}*/
	return _output;
}