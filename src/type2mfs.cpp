//Authors: Abel Teklu Hilemichael, Ali Karimoddini, Abdollah Homaifar
//athailem@aggies.ncat.edu
//NCAT ACESS LAB
//When called, operations in this code return a fuzzy interval type-2 membership value

#include "type2mfs.h"

type2mfs::type2mfs() {
}

type2mfs::~type2mfs() {
}

vector<double> type2mfs::gausst2mf(double *aInput, double aP1, double aP2, double aP3) {
	//p1 mean 1, p2 mean2, p3 sd
	//_mfval vector. first elemenet is umf while 2nd element is lmf
	_mfVal.clear();
	if (*aInput < aP1) {
		_mfVal.push_back(exp((-pow((*aInput - aP1), 2)) / (2 * (pow(aP3, 2)))));
	}
	if (*aInput >= aP1 && *aInput <= aP2) {
		_mfVal.push_back(1);
	}
	else {
		_mfVal.push_back(exp((-pow((*aInput - aP2), 2)) / (2 * (pow(aP3, 2)))));
	}

	if (*aInput <= ((aP1 + aP2)/2)) {
		_mfVal.push_back(exp((-pow((*aInput - aP2), 2)) / (2 * (pow(aP3, 2)))));
	}
	else {
		_mfVal.push_back(exp((-pow((*aInput - aP1), 2)) / (2 * (pow(aP3, 2)))));
	}

	return (_mfVal);
}