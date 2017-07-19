//Author: Abel Teklu Hilemichael
//athailem@aggies.ncat.edu
//NCAT ACESS LAB
//The operation in this code returns the membership value for a gaussian MF

#include <exception>
using namespace std;

#include "gaussMF.h"
#include "fuzz.h"

gaussMF::gaussMF() {
}
gaussMF::~gaussMF() {
}

double gaussMF::returnMemVal(double aInput, double aSD, double aMean, double aMax) {
	return (exp((-pow((aInput - aMean), 2)) / (2 * (pow(aSD, 2)))));//add maximum
}

