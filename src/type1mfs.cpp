//Authors: Abel Teklu Hilemichael, Ali Karimoddini, Abdollah Homaifar
//athailem@aggies.ncat.edu
//NCAT ACESS LAB
//This code returns the membership value for type 1 triangular trapezoidal and gaussina membership functions

#include "type1mfs.h"

type1mfs::type1mfs() {
}

type1mfs::~type1mfs() {
}

//Triangular MF
double type1mfs::trimf(double *aInput, double aP1, double aP2, double aP3, double aMax) {
	_pSlope = (aMax) / (aP2 - aP1);
	_nSlope = (-aMax) / (aP3 - aP2);

	if (*aInput <= aP2 && *aInput > aP1) {
		_mfVal = (_pSlope*(*aInput - aP1));
	}
	else if (*aInput < aP3 && *aInput >aP2) {
		_mfVal = (_nSlope*(*aInput - aP2)) + aMax;
	}
	else {
		_mfVal = 0;
	}

	return _mfVal;
}

//Trapezoidal MF
double type1mfs::trapmf(double *aInput, double aP1, double aP2, double aP3, double aP4, double aMax) {
	_pSlope = (aMax) / (aP2 - aP1);
	_nSlope = (-aMax) / (aP4 - aP3);

	if (*aInput < aP2 && *aInput >= aP1) {
		_mfVal = (_pSlope*(*aInput - aP1));
	}
	else if (*aInput <= aP3 && *aInput >= aP2) {
		_mfVal = aMax;
	}
	else if (*aInput <= aP4 && *aInput > aP3) {
		_mfVal = (_nSlope*(*aInput - aP3)) + aMax;
	}
	else {
		_mfVal = 0;
	}

	return _mfVal;
}

//Gaussian MF
//p1 mean, p2 sd
double type1mfs::gaussmf(double *aInput, double aP1, double aP2) {
	return (exp((-pow((*aInput - aP1), 2)) / (2 * (pow(aP2, 2)))));
}