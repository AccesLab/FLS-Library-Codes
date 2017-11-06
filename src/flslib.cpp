//Authors: Abel Teklu Hilemichael, Ali Karimoddini, Abdollah Homaifar
//athailem@aggies.ncat.edu
//NCAT ACESS LAB
//The operation in this code performs type-1 and interval type-2 fuzzy logic operation. It receaves crisp inputs as vectors and returns crisp outputs as vectors.

using namespace std;

#include "flslib.h"

flslib::flslib() {}
flslib::~flslib() {}


vector<double> flslib::runFuzzy(vector<double> aInputs, MainWindow_t *stData) {
	//XMLReader Reader(&stSysData);
	//Reader.ReadXMLFile("C:/Users/X1/Desktop/config.xml");
	
	if (stData->bType1 == true && stData ->bInterval2 == false) {//if it is t1 system
		_fuzzifiedVal = _fuz.fuzzifyt1(&aInputs, stData);
		_t1FiringLevel = _infr._t1_firing_level( &_fuzzifiedVal, stData);

		if (stData->bMamdani == false && stData->bTSK == true) {
			_tskOutputSet = _infr._type1_tsk_processing(&aInputs, stData);
			_output = _defuz.t1_tsk(&_t1FiringLevel, &_tskOutputSet, stData);
		}

		else if (stData->bMamdani == true && stData->bTSK == false) {//inference is mamdani
			_mamdaniOutputSet = _infr._type1_mamdani_processing(&_t1FiringLevel, stData);
			_output = _defuz.centroid(&_mamdaniOutputSet, stData);
		}
		else { throw("Wrong configuration!"); }
	}
	else if (stData->bType1 == false && stData->bInterval2 == true) {//if it is interval type-2 system
		_it2FuzzifiedVal = _fuz.fuzzifyit2(&aInputs, stData);
		_it2FiringLevel = _infr._it2_firing_level(&_it2FuzzifiedVal, stData);

		if (stData->bMamdani == false && stData->bTSK == true) {
			_it2TSKOutputSet = _infr._it2_tsk_processing(&aInputs, &_it2FiringLevel, stData);
			_output = _defuz.ub(&_it2TSKOutputSet, stData);
		}

		else if (stData->bMamdani == true && stData->bTSK == false) {//inference is mamdani
			_mamdaniOutputSet = _infr._it2_mamdani_processing(&_it2TSKOutputSet, stData);
			_output = _defuz.nt(&_mamdaniOutputSet, stData);
		}
		else { throw("Wrong configuration!"); }
	}
	else { throw("Wrong configuration!"); }
	return _output;
}