//Author: Abel Teklu Hilemichael
//athailem@aggies.ncat.edu
//NCAT ACESS LAB

#include <exception>
#include <vector>
#include "flsconfig.h"
#include <iostream>
#include <algorithm>
#include "type1mfs.h"
#include <algorithm>

using namespace std;

#ifndef __defuzz_h__
#define __defuzz_h__

class defuzz;
class type1mfs;

class defuzz
{
	type1mfs t1mfs;

	private: double _y_left;
	private: double _y_right;
	private: vector<double> _y_crisp;

	public: defuzz();

	private: vector<double> _row = { 0 };

	public: vector<double> t1_tsk(vector<double> aInput, vector<double> aFiring_level);

	public: vector<double> ub(vector<double> aInput, vector<double> aFiring_level, vector<double> aUfiring_level);

	public: vector<double> centroid(vector<double> aInput, vector<double> aFiring_level);

	public: vector<double> km();

	public: vector<double> nt(vector<double> aInput, vector<double> _umf_firingLevel, vector<double> _lmf_firingLevel);

	public: vector<double> weightedAvg();

	public: vector<double> height();

	public: vector<double> defuzzify(vector<double> aFiring_level, vector<double> aUfiring_level, vector<double> aLfiring_level);
};

#endif
