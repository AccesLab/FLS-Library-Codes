#include <exception> 

using namespace std;

#ifndef _numInputs
#define _numInputs 3
#endif

#ifndef _maxNumIpMF
#define _maxNumIpMF 4
#endif

#ifndef _sysName
#define _sysName "Abel"
#endif

#ifndef _type
#define _type "IT2"
#endif

#ifndef _inference
#define _inference "Mamdani"
#endif

#ifndef _numOutputs
#define _numOutputs 2
#endif

#ifndef _version
#define _version 1.0
#endif

#ifndef _numRules
#define _numRules 8
#endif

#ifndef _maxNumRules
#define _maxNumRules 8
#endif

#ifndef _andMethod
#define _andMethod "min"
#endif

#ifndef _orMethod
#define _orMethod "max"
#endif

#ifndef _impMethod
#define _impMethod "prod"
#endif

#ifndef _aggMethod
#define _aggMethod "max"
#endif

#ifndef _defuzzMethod
#define _defuzzMethod "NT"
#endif

#ifndef _precision
#define _precision 3
#endif

#ifndef _maxNumOpMF
#define _maxNumOpMF 3
#endif

#ifndef FUZZYPARAM_H 
#define FUZZYPARAM_H 

static double _outputSet[_numRules][_precision] = { 0 };
static double _uoutputSet[_numRules][_precision] = { 0 };
static double _loutputSet[_numRules][_precision] = { 0 };
static double _uInputMatrix[][31] = { { 0.0, 1.0, 2, 0, -0.4, 0.0, 0.4, 0, 1, 0, 0, 0.1, 0.5, 0.9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0.1, 15.0, 1, 0, -0.4, 0.0, 0.4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0.0, 100.0, 4, 0, -0.4, 0.0, 0.4, 0, 0, 0, 0, 0.1, 0.5, 0.9, 0, 0, 0, 0, 0.1, 0.5, 0.9, 0, 0, 0, 0, 0.1, 0.5, 0.9, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
static double _lInputMatrix[][31] = { { 0.0, 1.0, 2, 0, -0.4, 0.0, 0.4, 0, 0, 0, 0, 0.1, 0.5, 0.9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0.1, 15.0, 1, 0, -0.4, 0.0, 0.4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0.0, 100.0, 4, 0, -0.4, 0.0, 0.4, 0, 0, 0, 0, 0.1, 0.5, 0.9, 0, 0, 0, 0, 0.1, 0.5, 0.9, 0, 0, 0, 0, 0.1, 0.5, 0.9, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
static double _uOutputMatrix[][31] = { { 0.0, 1.0, 2, 0, -0.4, 0.0, 0.4, 0, 1, 0, 0, 0.1, 0.5, 0.9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0.1, 15.0, 1, 0, -0.4, 0.0, 0.4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0.0, 100.0, 4, 0, -0.4, 0.0, 0.4, 0, 0, 0, 0, 0.1, 0.5, 0.9, 0, 0, 0, 0, 0.1, 0.5, 0.9, 0, 0, 0, 0, 0.1, 0.5, 0.9, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
static double _lOutputMatrix[][31] = { { 0.0, 1.0, 2, 0, -0.4, 0.0, 0.4, 0, 0, 0, 0, 0.1, 0.5, 0.9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0.1, 15.0, 1, 0, -0.4, 0.0, 0.4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0.0, 100.0, 4, 0, -0.4, 0.0, 0.4, 0, 0, 0, 0, 0.1, 0.5, 0.9, 0, 0, 0, 0, 0.1, 0.5, 0.9, 0, 0, 0, 0, 0.1, 0.5, 0.9, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
static double _InputMatrix[][31] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
static double _OutputMatrix[][24] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
static double _ruleMatrix[][12] = { { 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1 },{ 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1 },{ 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1 },{ 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1 },{ 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1 },{ 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

#endif