//Author: Abel Teklu Hailemichael
//athailem@aggies.ncat.edu
//NCAT ACESS LAB

#include <exception>
#include <vector>
#include "math.h"
#include "flsconfig.h"
#include "commondef.h"
#include "XMLReader.h"
#include <algorithm>
#include "gaussMF.h"
#include "triMF.h"
#include "trapMF.h"
#include "T2_MF.h"
#include "type1mfs.h"

using namespace std;

#ifndef __infer_h__
#define __infer_h__

struct MainWindow_t;

class infer;

class type1mfs;

class infer
{
	type1mfs t1mfs;

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
	private: vector<vector<double>> _outputFset;
	private: vector<vector<double>> _outputSet;
	private: vector<vector<double>> _outputFsetUMF;
	private: vector<vector<double>> _outputFsetLMF;
	private: vector<vector<vector<double>>> _it2_outputFset;
	//private: QVector<QStringList> slConsTockens2;
	//private: vector<vector<double>> _tskEachOut;
	//private: vector<vector<double>> _tskEachOut;

	public: infer();
	public: ~infer();

	public: vector<double> _t1_firing_level(vector<vector<double>> *aFuzzified_val, MainWindow_t *stData);
	public: vector<vector<double>> _it2_firing_level(vector<vector<vector<double>>> *aFuzzified_val, MainWindow_t *stData);
	public:	vector<vector<double>> _type1_mamdani_processing(vector<double> *aFiring_level, MainWindow_t *stData);
	public:	vector<vector<double>> _type1_tsk_processing(vector<double> *aInputs, MainWindow_t *stData);
	public:	vector<vector<vector<double>>> _it2_mamdani_processing(vector<vector<double>> *aFiring_level, MainWindow_t *stData);
	public:	vector<vector<double>> _it2_tsk_processing(vector<double> *aInputs, vector<vector<double>> *aFiring_level, MainWindow_t *stData);
};

#endif
