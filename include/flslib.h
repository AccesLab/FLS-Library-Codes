//Author: Abel Teklu Hilemichael
//athailem@aggies.ncat.edu
//NCAT ACESS LAB

#include <exception>
#include <vector>
#include "flsconfig.h"
#include "fuzz.h"
#include "infer.h"
#include "defuzz.h"
#include "commondef.h"
#include "XMLReader.h"
using namespace std;

#ifndef __flslib_h__
#define __flslib_h__

struct MainWindow_t;

class FLS;

/**
 * This class subscribes for ROS inputs to the fuzzy toolbox. It also publishes the final crisp values to the ROS master. This class also reads parameters.
 */
class flslib
{
	MainWindow_t stSysData;
	//MainWindow_t stSysData;

	private: fuzz _fuz;
	private: infer _infr;
	private: defuzz _defuz;

	private: vector<vector<double>> _fuzzVal; 
	private: vector<vector<double>> _umf_fuzzVal;
	private: vector<vector<double>>_lmf_fuzzVal;
	private: vector<double> _firingLevel;
	private: vector<double> _umf_firingLevel;
	private: vector<double> _lmf_firingLevel;
	private: vector<double> _output;
private: vector<double> tad;
	private:	 vector<double> ins = { 0 };
	private:	 vector<vector<vector<double>>> f;


	MainWindow_t _testData;

	public: flslib();
	public: ~flslib();
	/// <summary>
	/// This operation publishes crisp outputs which are defined in readParams() : void to ROS master.
	/// </summary>
	//public: void getParams();
	public: vector<double> runFuzzy(vector<double> aInputs);
};

#endif
