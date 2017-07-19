//Author: Abel Teklu Hilemichael
//athailem@aggies.ncat.edu
//NCAT ACESS LAB
//Test Code

#include "iostream"
#include <vector>
#include <algorithm>
//#include "fuzzyparam.h"
//#include "fuzzyParam.h"
//#include "fuzzy.h"
#include "flslib.h"
#include <ctime>

using namespace std;

//fuzzy fuz;
flslib fuz;

int main() {
	clock_t begin = clock();
	//cout << "Hello World";
	//fuz.publishOutput();
	/*fuz.fuzzify();
	fuz.infer();
	fuz.defuzzify();*/
	vector<double> input = { 0.1,1.2,10.3 };
	vector<double> output;
	output = fuz.runFuzzy(input);
	cout << output[0] <<endl;
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << elapsed_secs << endl;
	system("pause");
	return 0;
}