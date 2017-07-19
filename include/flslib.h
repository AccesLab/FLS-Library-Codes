//Author: Abel Teklu Hilemichael

#include <exception>
#include <vector>
#include "fuzzyparam.h"
#include "fuzz.h"
#include "infer.h"
#include "defuzz.h"
using namespace std;

#ifndef __flslib_h__
#define __flslib_h__

class FLS;

/**
 * This class subscribes for ROS inputs to the fuzzy toolbox. It also publishes the final crisp values to the ROS master. This class also reads parameters.
 */
class flslib
{
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

	public: flslib();
	public: ~flslib();
	/// <summary>
	/// This operation publishes crisp outputs which are defined in readParams() : void to ROS master.
	/// </summary>
	public: void getParams();
	public: vector<double> runFuzzy(vector<double> aInputs);
};

#endif
