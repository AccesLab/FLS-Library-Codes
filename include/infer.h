//Authors: Abel Teklu Hilemichael, Ali Karimoddini, Abdollah Homaifar
//athailem@aggies.ncat.edu
//NCAT ACESS LAB

#include <exception>
#include <vector>
#include "math.h"
#include "commondef.h"
#include "XMLReader.h"
#include <algorithm>
#include "type1mfs.h"
#include "type2mfs.h"
#include <iostream>

using namespace std;

#ifndef __infer_h__
#define __infer_h__

struct MainWindow_t;

class inference;

class type1mfs;
class type2mfs;

class inference
{
	type1mfs t1mfs;
	type2mfs t2mfs;

	private: double _min;
	private: double dVal;
	private: double dValUMF;
	private: double dValLMF;
	private: double dPrecssision;
	private: double dQuantization;
	private: double _y_left;
	private: double _y_right;
	private: QVector<double> vValues;
	private: QVector<double> vMFRanges;
	private: QVector<double> vOPRanges;
	private: QVector<double> vAntecedents;
	private: QVector<double> vAntecedentsUMF;
	private: QVector<double> vAntecedentsLMF;
	private: QVector<double> vConsequents;
	private: vector<double> _firing_level;
	private: vector<vector<double> > _firing_level_t2;
	private: vector<vector<double>> _tskOutputSet;
	private: vector<vector<vector<double>>> _outputFset;
	private: vector<vector<vector<double>>> _outputSet;
	private: vector<vector<vector<double>>> _toutputSet;
	private: vector<vector<vector<double>>> _outputFsetUMF;
	private: vector<vector<vector<double>>> _outputFsetLMF;
	private: vector<vector<vector<double>>> _it2_outputFset;
	//private: QVector<QStringList> slConsTockens2;
	//private: vector<vector<double>> _tskEachOut;
	//private: vector<vector<double>> _tskEachOut;

	public: inference();
	public: ~inference();

	public: vector<double> _t1_firing_level(vector<vector<double>> *aFuzzified_val, MainWindow_t *stData);
	public: vector<vector<double>> _it2_firing_level(vector<vector<vector<double>>> *aFuzzified_val, MainWindow_t *stData);
	public:	vector<vector<vector<double>>> _type1_mamdani_processing(vector<double> *aFiring_level, MainWindow_t *stData);
	public:	vector<vector<vector<double>>> _type1_tsk_processing(vector<double> *aInputs, MainWindow_t *stData);
	public:	vector<vector<vector<double>>> _it2_mamdani_processing(vector<vector<double>> *aFiring_level, MainWindow_t *stData);
	public:	vector<vector<double>> _it2_tsk_processing(vector<double> *aInputs, vector<vector<double>> *aFiring_level, MainWindow_t *stData);
};

#endif
