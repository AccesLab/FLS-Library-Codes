//Author: Abel Teklu Hilemichael
//athailem@aggies.ncat.edu
//NCAT ACESS LAB
//The operation in this code performs fuzzification of all inputs and returns the fuzzified values

#include <exception>
#include <vector>
using namespace std;

#include "fuzz.h"


fuzz::fuzz() {
}
fuzz::~fuzz() {
}

vector<vector<double> > fuzz::fuzzify(vector<double> *aInputs, MainWindow_t *stData) {
	/*MainWindow_t stData;
	XMLReader Reader(&stData);
	Reader.ReadXMLFile(QString(sFIleName_i.c_str()));
	B->bInterval2 = 0;*/
	//vector<double> Inputs = *aInputs;
	_fuzzified_val.clear();
	_l_fuzzified_val.clear();
	_u_fuzzified_val.clear();

	if (stData->bType1 == true) {//if it is t1 system
					  //create vector of vector storage place for fuzzified value of LMF
		for (int i = 0; i < stData->vstInputs.size(); i++)
		{
			_fuzzified_val.push_back(_row);
		}
		//For all inputs for T1
		for (int i = 0; i < stData->vstInputs.size(); i++) {

			//InputData_t stInput= stData->vstInputs[i];

			//Fuzzify T1 MFs 
			for (int j = 0; j < stData->vstInputs[i].vstMF.size(); j++) {

				//InputMF_t stMF = stData->vstInputs[i].vstMF[j];
				if (stData->vstInputs[i].vstMF[j].sType == "tri") {
					_fuzzified_val[i].push_back(t1mfs.trimf((double *)(&aInputs[i]), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2, stData->vstInputs[i].vstMF[j].dP3, stData->vstInputs[i].vstMF[j].dMaximum));
				}
				if (stData->vstInputs[i].vstMF[j].sType == "trap") {
					_fuzzified_val[i].push_back(t1mfs.trapmf((double *)(&aInputs[i]), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2, stData->vstInputs[i].vstMF[j].dP3, stData->vstInputs[i].vstMF[j].dP4, stData->vstInputs[i].vstMF[j].dMaximum));
				}
				if (stData->vstInputs[i].vstMF[j].sType == "gauss") {
					_fuzzified_val[i].push_back(t1mfs.gaussmf((double *)(&aInputs[i]), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2));
				}
			}
		}// end of For all inputs for T1
	}//end of if type 1
	
	
	
	return _fuzzified_val;
}

vector<vector<vector<double>>> fuzz::fuzzifyt2(vector<double> *aInputs, MainWindow_t *stData)
{
	_fuzzified_valT2.clear();
	_row.clear();
	_u_fuzzified_val.clear();
	_l_fuzzified_val.clear();

		for (int i = 0; i < stData->vstInputs.size(); i++)
		{
			_u_fuzzified_val.push_back(_row);
			_l_fuzzified_val.push_back(_row);
		}

		//For all inputs for UB
		for (int i = 0; i < stData->vstInputs.size(); i++) {

			//Fuzzify UMFss
			for (int j = 0; j < stData->vstInputs[i].vstMF.size(); j++) {

				//InputMF_t stMF = stData->vstInputs[i].vstMF[j];
				if (stData->vstInputs[i].vstMF[j].sType == "utri") {
					_u_fuzzified_val[i].push_back(t1mfs.trimf((double *)(&aInputs[i]), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2, stData->vstInputs[i].vstMF[j].dP3, stData->vstInputs[i].vstMF[j].dMaximum));
				}
				if (stData->vstInputs[i].vstMF[j].sType == "utrap") {
					_u_fuzzified_val[i].push_back(t1mfs.trapmf((double *)(&aInputs[i]), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2, stData->vstInputs[i].vstMF[j].dP3, stData->vstInputs[i].vstMF[j].dP4, stData->vstInputs[i].vstMF[j].dMaximum));
				}
				if (stData->vstInputs[i].vstMF[j].sType == "ugauss") {
					_u_fuzzified_val[i].push_back(t1mfs.gaussmf((double *)(&aInputs[i]), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2));
				}
				if (stData->vstInputs[i].vstMF[j].sType == "ltri") {
					_l_fuzzified_val[i].push_back(t1mfs.trimf((double *)(&aInputs[i]), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2, stData->vstInputs[i].vstMF[j].dP3, stData->vstInputs[i].vstMF[j].dMaximum));
				}
				if (stData->vstInputs[i].vstMF[j].sType == "ltrap") {
					_l_fuzzified_val[i].push_back(t1mfs.trapmf((double *)(&aInputs[i]), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2, stData->vstInputs[i].vstMF[j].dP3, stData->vstInputs[i].vstMF[j].dP4, stData->vstInputs[i].vstMF[j].dMaximum));
				}
				if (stData->vstInputs[i].vstMF[j].sType == "lgauss") {
					_l_fuzzified_val[i].push_back(t1mfs.gaussmf((double *)(&aInputs[i]), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2));
				}
			}			
		}// end of For all inputs for UB for upper bound or NT

		_fuzzified_valT2.push_back(_u_fuzzified_val);
		_fuzzified_valT2.push_back(_l_fuzzified_val);

	return _fuzzified_valT2;
}