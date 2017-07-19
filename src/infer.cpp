//Author: Abel Teklu Hilemichael
//athailem@aggies.ncat.edu
//NCAT ACESS LAB
//The operation in this code performs fuzzy inference operations and returns firing level

#include <exception>
#include <vector>
#include <iostream>
using namespace std;

#include "infer.h"
infer::infer() {
}
infer::~infer() {
}

vector<double> infer::firingLevel(vector<vector<double> > aFuzzified_val) {
	_firing_level.clear();
	//find cartesian product
	_cartesian = { {} };
	//_cartesian.clear();
	/*vector<vector<double>> _tmp;
	vector<vector<double>> _tmp3;
	vector<vector<double>> _tmp4;*/
		for (auto& _tmp1 : aFuzzified_val) {
			vector<vector<double>> _tmp2;
			for (auto& _tmp3 : _cartesian) {
				for (auto _tmp4 : _tmp1) {
					_tmp2.push_back(_tmp3);
					_tmp2.back().push_back(_tmp4);
				}
			}
			_cartesian.swap(_tmp2);
		}
		
		/*for (size_t i = 0; i < _cartesian.size(); i++) {
			for (size_t j = 0; j < _cartesian[i].size(); j++) {
				cout << _cartesian[i][j] << "\t";
			}
			cout << std::endl;
		}
		cout << _cartesian.size() << "\t";*/

	//find t norm, s norm 
		if (_andMethod == "min") {
			for (size_t i = 0; i < _cartesian.size(); i++) {
				_min = _cartesian[i][0];
				for (size_t j = 0; j < _cartesian[i].size(); j++) {
					if (_cartesian[i][j] < _min)
						_min = _cartesian[i][j];
					else {}
					//cout << _cartesian[i][j] << "\t";
				}
				_firing_level.push_back(_min);
				//cout << std::endl;
			}
		}
		else {
			throw "Not yet Implemented";
		}
		return _firing_level;
}

