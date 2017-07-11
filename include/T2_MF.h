#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __T2_MF_h__
#define __T2_MF_h__

// #include "fuzz.h"

class fuzz;
class T2_MF;

class T2_MF
{
	private: string _uMF_type;
	private: string _lMF_type;
	private: double _a;
	private: double _b;
	private: double _c;
	private: double _d;
	private: double _uMF_max;
	private: double _lMF_max;
	public: vector<double> _membershipValues;
	public: fuzz* _unnamed_fuzz_;

	public: T2_MF();
	public: ~T2_MF();

	public: vector<double> memVal();
};

#endif
