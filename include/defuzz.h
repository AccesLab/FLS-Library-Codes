#include <exception>
#include <vector>
#include "fuzzyparam.h"
#include <iostream>
#include <algorithm>

using namespace std;

#ifndef __defuzz_h__
#define __defuzz_h__

class defuzz;

class defuzz
{
	private: double _y_left;
	private: double _y_right;
	private: vector<double> _y_crisp;

	public: defuzz();

	public: vector<double> t1_tsk(vector<double> aInput, vector<double> aFiring_level);

	public: vector<double> ub(vector<double> aInput, vector<double> aFiring_level, vector<double> aUfiring_level);

	public: vector<double> km();

	public: vector<double> nt();

	public: vector<double> centroid();

	public: vector<double> weightedAvg();

	public: vector<double> height();

	public: vector<double> defuzzify(vector<double> aFiring_level, vector<double> aUfiring_level, vector<double> aLfiring_level);
};

#endif
