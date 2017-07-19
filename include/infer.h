//Author: Abel Teklu Hailemichael
//athailem@aggies.ncat.edu
//NCAT ACESS LAB

#include <exception>
#include <vector>
#include "flsconfig.h"
using namespace std;

#ifndef __infer_h__
#define __infer_h__

class infer;

class infer
{
	private: double _min;
private: vector<vector<double> > _cartesian;
	private: vector<double> _firing_level;

	public: infer();
	public: ~infer();

	public: vector<double> firingLevel(vector<vector<double> > aFuzzified_val);
};

#endif
