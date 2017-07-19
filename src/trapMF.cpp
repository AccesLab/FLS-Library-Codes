//Author: Abel Teklu Hilemichael

#include <exception>
using namespace std;

#include "trapMF.h"
#include "fuzz.h"

trapMF::trapMF() {
}
trapMF::~trapMF() {
}

double trapMF::returnMemVal(double aInput, double aA, double aB, double aC, double aD, double aMax) {
		_pSlope = (aMax) / (aB - aA);
		_nSlope = (-aMax) / (aD - aC);
	
		if (aInput < aB && aInput >= aA) {
			_mfVal = (_pSlope*(aInput - aA));
		}
		else if (aInput <= aC && aInput >= aB) {
			_mfVal = aMax;
		}
		else if (aInput <= aD && aInput > aC) {
			_mfVal = (_nSlope*(aInput - aC)) + aMax;
		}
		else {
			_mfVal = 0;
		}
	
		return _mfVal;
}

