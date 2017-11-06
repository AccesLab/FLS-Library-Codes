//Authors: Abel Teklu Hilemichael, Ali Karimoddini, Abdollah Homaifar
//athailem@aggies.ncat.edu
//NCAT ACESS LAB

#include <exception>
#include <vector>
#include <iostream>
#include <algorithm>
#include "type1mfs.h"
#include "type2mfs.h"
#include "commondef.h"
#include "XMLReader.h"

using namespace std;

#ifndef __defuzz_h__
#define __defuzz_h__

struct MainWindow_t;

class defuzzify;
class type1mfs;
class type2mfs;

class defuzzify
{
	type1mfs t1mfs;
	type2mfs t2mfs;

	private: double _y_left;
	private: double _y_right;
	private: vector<double> _y_crisp;
	private: vector<double> _uStar;

	public: defuzzify();
	public: ~defuzzify();

	public: vector<double> t1_tsk(vector<double> *aFiring_level, vector<vector<vector<double>>> *aOutFSet, MainWindow_t *stData);
	public: vector<double> ub(vector<vector<double>> *_tskOutputSet, MainWindow_t *stData);
	public: vector<double> centroid(vector<vector<vector<double>>> *_outputSet, MainWindow_t *stData);
	public: vector<double> km();
	public: vector<double> nt(vector<vector<vector<double>>> *_it2_outputFset, MainWindow_t *stData);
	public: vector<double> weightedAvg();
	public: vector<double> height();
	public: vector<double> gaussianMF();
	public: vector<double> triangularMF();
	public: vector<double> trapezoidalMF();
	public: vector<double> it2Gaussian();
};

#endif