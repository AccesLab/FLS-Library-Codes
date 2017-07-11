#include <exception>
using namespace std;

#ifndef __triMF_h__
#define __triMF_h__

// #include "fuzz.h"

class fuzz;
class triMF;

/**
 * This is a class of triangular membership function. When called, it receives input value and returns the membership value for the input.
 */
class triMF
{
	/**
	 * left edge of the triMF.
	 */
	private: double _left;
	/**
	 * Middle edge of the triMF.
	 */
	private: double _mid;
	/**
	 * Right edge of the triMF.
	 */
	private: double _right;
	/**
	 * Maximum top value of the triMF.
	 */
	private: double _pSlope;
	private: double _nSlope;
	private: double _mfVal;
	private: double _max;
	public: fuzz* _unnamed_fuzz_;

	public: triMF();
	public: ~triMF();

	/// <summary>
	/// When called this function returns the membership of the input. It receives the input value, (model element not found), (model element not found), (model element not found) and (model element not found).
	/// </summary>
	public: double returnMemVal(double aInput, double aA, double aB, double aC, double aMax);
};

#endif
