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

