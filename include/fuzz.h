//Author: Abel Teklu Hilemichael
//athailem@aggies.ncat.edu
//NCAT ACESS LAB

#include <exception>
#include <vector>
#include "flsconfig.h"

#include "gaussMF.h"
#include "triMF.h"
#include "trapMF.h"
#include "T2_MF.h"

#include "type1mfs.h"

using namespace std;

#ifndef __fuzz_h__
#define __fuzz_h__


class fuzz;

class type1mfs;

/**
 * This class initially reads parameters defined by a user. This class then accepts inputs and calculates membership values for each inputs corresponding membership functions. The information is passed as a structure with assigned attribute values to be used by the inference system.
 */
class fuzz
{	
	 type1mfs t1mfs;

	private: int _numofuMFs;
	private: int _numoflMFs;
	private: int _numofMFs;
	private: int _u_local_index;
	private: int _l_local_index;
	private: int _local_index;
	private: vector<vector<double> > _u_fuzzified_val;
	private: vector<vector<double> > _l_fuzzified_val;
	private: vector<vector<double> > _fuzzified_val;
	private: vector<double> _row;
	public: gaussMF* _unnamed_gaussMF_;
	public: triMF* _unnamed_triMF_;
	public: trapMF* _unnamed_trapMF_;
	public: T2_MF* _unnamed_T2_MF_;

	public: fuzz();
	public: ~fuzz();

	/// <summary>
	/// This operation fuzzifies the inputs using the membership function classes. For each membership function defined by (model element not found), it generates the primary membership value for all inputs. The membership values are stored and passed as a pointer to vector.
	/// </summary>
	public: vector<vector<double> > fuzzify(int aSetID, vector<double> aInputs);
};

#endif
