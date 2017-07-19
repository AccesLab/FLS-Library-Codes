//Author: Abel Teklu Hilemichael
//athailem@aggies.ncat.edu
//NCAT ACESS LAB

#include <exception>
using namespace std;

#ifndef __gaussMF_h__
#define __gaussMF_h__

// #include "fuzz.h"

class fuzz;
class gaussMF;

/**
 * This is a class of gaussian membership function. When called, it receives input value and returns the membership value for the input.
 */
class gaussMF
{
	/**
	 * Standard deviation of the gaussMF.
	 */
	private: double _sD;
	/**
	 * Mean value of gaussMF.
	 */
	private: double _mean;
	/**
	 * Maximum value of the gaussMF.
	 */
	private: double _max;
	public: fuzz* _unnamed_fuzz_;

	public: gaussMF();
	public: ~gaussMF();

	/// <summary>
	/// This operation accepts the input, (model element not found), (model element not found) as well as (model element not found) of the (model element not found) and returns the membership value of the given input.
	/// </summary>
	public: double returnMemVal(double aInput, double aSD, double aMean, double aMax);
};

#endif
