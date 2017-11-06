//Authors: Abel Teklu Hilemichael, Ali Karimoddini, Abdollah Homaifar
//athailem@aggies.ncat.edu
//NCAT ACESS LAB

#include <exception>
#include <vector>
#include "commondef.h"
#include "XMLReader.h"
#include "type2mfs.h"
#include "type1mfs.h"

using namespace std;

#ifndef __fuzz_h__
#define __fuzz_h__

struct MainWindow_t;

class fuzzify;

class type1mfs;
class type2mfs;

/**
 * This class initially reads parameters defined by a user. This class then accepts inputs and calculates membership values for each inputs corresponding membership functions. The information is passed as a structure with assigned attribute values to be used by the inference system.
 */
class fuzzify
{	
	type1mfs t1mfs;
	type2mfs t2mfs;
	//MainWindow_t stSysData;

	private: vector<vector<double> > _u_fuzzified_val;
	private: vector<vector<double> > _l_fuzzified_val;
	private: vector<vector<double> > _fuzzified_val;
	private: vector<vector<vector<double>>> _fuzzified_valT2;
	private: vector<double> _row;
	private: vector<double> _gausst2MemVal;
			 
	public: fuzzify();
	public: ~fuzzify();

	/// <summary>
	/// This operation fuzzifies the inputs using the membership function classes. For each membership function defined by (model element not found), it generates the primary membership value for all inputs. The membership values are stored and passed as a pointer to vector.
	/// </summary>
	public: vector<vector<double> > fuzzifyt1(vector<double> *aInputs, MainWindow_t *stData);
	public:	vector<vector<vector<double>>> fuzzifyit2(vector<double> *aInputs, MainWindow_t *stData);
		
};

#endif
