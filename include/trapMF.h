//Author: Abel Teklu Hilemichael

#include <exception>
using namespace std;

#ifndef __trapMF_h__
#define __trapMF_h__

// #include "fuzz.h"

class fuzz;
class trapMF;

/**
 * This is a class of trapezoidal membership function. When called, it receives input value and returns the membership value for the input.
 */
class trapMF
{
	/**
	 * Right most edge of the trapMF.
	 */
	private: double _a;
	/**
	 * 2nd edge from right of trapMF.
	 */
	private: double _b;
	/**
	 * 3rd edge of trapMF from right.
	 */
	private: double _c;
	/**
	 * Left most edge of trapMF.
	 */
	private: double _d;
	/**
	 * Maximum top value of the trapMF.
	 */
	private: double _pSlope;
	private: double _nSlope;
	private: double _mfVal;
	private: double _max;
	public: fuzz* _unnamed_fuzz_;

	public: trapMF();
	public: ~trapMF();

	/// <summary>
	/// When called, this operation accepts the input as well as the edges of the (model element not found) which are (model element not found), (model element not found), (model element not found), (model element not found) and (model element not found). It then returns the membership value.
	/// </summary>
	public: double returnMemVal(double aInput, double aA, double aB, double aC, double aD, double aMax);
};

#endif
