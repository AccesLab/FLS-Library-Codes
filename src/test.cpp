//Authors: Abel Teklu Hilemichael, Ali Karimoddini, Abdollah Homaifar
//athailem@aggies.ncat.edu
//NCAT ACESS LAB
//Test Code

#include "iostream"
#include <vector>
#include <algorithm>
#include "flslib.h"
#include <ctime>
#include "commondef.h"
#include "XMLReader.h"
#include <QMessageBox>

using namespace std;
std::string sFIleName_i;

//fuzzy fuz;
flslib fuz;

int main() {
	clock_t begin = clock();
	//cout << "Hello World";
	//fuz.publishOutput();
	/*fuz.fuzzify();
	fuz.infer();
	fuz.defuzzify();*/
	MainWindow_t stData;
	XMLReader Reader(&stData);
	sFIleName_i = "C:/Users/Abel/Desktop/hi.xml";
	Reader.ReadXMLFile(QString(sFIleName_i.c_str()));
	
	cout << stData.vstInputs.size() << endl << 1200 << endl;
		
	QString sString = "1,2,3,4";
	QStringList slTockens = sString.split(",");
	QVector<int> vValues;
	foreach(QString sItem, slTockens)
	{
		vValues.push_back(sItem.toInt());
	}
	foreach (int var, vValues)
	{
		cout << "\n" << var;
	}
	/*for each(int var in vValues) // This is not a qt stuff. can use only for wind
	{
		cout << "\n" << var;
	}*/

	cout << "test";
	//	QMessageBox::information(0, "", "test message");
	
	vector<double> input = { 0.1,1.2,10.3 };
	vector<double> output;
	/*output = fuz.runFuzzy(input);
	cout << output[0] <<endl;
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << elapsed_secs << endl;
	system("pause");*/
	system("pause");
	return 0; 
}