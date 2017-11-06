//Authors: Abel Teklu Hilemichael, Ali Karimoddini, Abdollah Homaifar
//athailem@aggies.ncat.edu
//NCAT ACESS LAB

#include <exception>
#include <vector>
#include <iostream>
#include "fuzz.h"
#include "infer.h"
#include "defuzz.h"
#include "commondef.h"
#include "XMLReader.h"

using namespace std;

#ifndef __flslib_h__
#define __flslib_h__

struct MainWindow_t;

class flslib;

/**
 * This class subscribes for ROS inputs to the fuzzy toolbox. It also publishes the final crisp values to the ROS master. This class also reads parameters.
 */
class flslib
{
	//MainWindow_t stSysData;

	private: fuzzify _fuz;
	private: inference _infr;
	private: defuzzify _defuz;

	private: vector<double> _t1FiringLevel;
	private: vector<vector<double>> _it2FiringLevel;
	private: vector<vector<double>> _fuzzifiedVal;
	private: vector<vector<vector<double>>> _it2FuzzifiedVal;
	private: vector<vector<vector<double>>> _tskOutputSet;
	private: vector<vector<double>> _it2TSKOutputSet;
	private: vector<vector<vector<double>>> _mamdaniOutputSet;
	private: vector<double> _output;

	public: flslib();
	public: ~flslib();
	/// <summary>
	/// This operation publishes crisp outputs which are defined in readParams() : void to ROS master.
	/// </summary>
	//public: void getParams();
	public: vector<double> runFuzzy(vector<double> aInputs, MainWindow_t *stData);
};

#endif
