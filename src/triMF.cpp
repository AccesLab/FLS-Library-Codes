#include <exception>
using namespace std;

#include "triMF.h"
#include "fuzz.h"

triMF::triMF() {
}

triMF::~triMF() {
}

double triMF::returnMemVal(double aInput, double aA, double aB, double aC, double aMax) {
	_pSlope = (aMax) / (aB - aA);
		_nSlope = (-aMax) / (aC - aB);
	
		if (aInput <= aB && aInput > aA) {
			_mfVal = (_pSlope*(aInput - aA));
		}
		else if (aInput < aC && aInput >aB) {
			_mfVal = (_nSlope*(aInput - aB)) + aMax;
		}
		else {
			_mfVal = 0;
		}
	
		return _mfVal;
}

