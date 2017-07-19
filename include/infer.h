//Author: Abel Teklu Hailemichael

#include <exception>
#include <vector>
#include "fuzzyparam.h"
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
