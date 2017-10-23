#include <exception>
#include <vector>
#include <iostream>

using namespace std;

#include "FLS.h"

FLS::FLS() {}
FLS::~FLS() {}

void FLS::getParams() {
	throw "Not yet implemented";
}

vector<double> FLS::runFuzzy(vector<double> aInputs) {
	if (_type == "T1") {
		if (_inference == "sugno") {
			_fuzzVal = _fuz.fuzzify(0, aInputs);
			_firingLevel = _infr.firingLevel(_fuzzVal);
			_output = _defuz.t1_tsk(aInputs, _firingLevel);
		}

		if (_inference == "Mamdani") {
			_fuzzVal = _fuz.fuzzify(0, aInputs);
			_firingLevel = _infr.firingLevel(_fuzzVal);
			_output = _defuz.centroid(aInputs, _firingLevel);
		}

		else { throw "Not yet implemented"; }
	}
	if (_type == "IT2") {
		if (_inference == "sugno") {
			if (_defuzzMethod == "UB") {
				_umf_fuzzVal = _fuz.fuzzify(1, aInputs);
				_lmf_fuzzVal = _fuz.fuzzify(2, aInputs);
				_umf_firingLevel = _infr.firingLevel(_umf_fuzzVal);
				_lmf_firingLevel = _infr.firingLevel(_lmf_fuzzVal);
				_output = _defuz.ub(aInputs, _umf_firingLevel, _lmf_firingLevel);
			}
		}

		if (_inference == "Mamdani") {
			if (_defuzzMethod == "NT") {
				_umf_fuzzVal = _fuz.fuzzify(1, aInputs);
				_lmf_fuzzVal = _fuz.fuzzify(2, aInputs);
				_umf_firingLevel = _infr.firingLevel(_umf_fuzzVal);
				_lmf_firingLevel = _infr.firingLevel(_lmf_fuzzVal);
				_output = _defuz.nt(aInputs, _umf_firingLevel, _lmf_firingLevel);
			}
		}

		else { throw "Not yet implemented"; }
	}
	if (_type == "T2") {
		if (_inference == "sugno") {
			throw "Not yet implemented";
		}
		else { throw "Not yet implemented"; }
	}
	return _output;
}