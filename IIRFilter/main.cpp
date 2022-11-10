#include <iostream>
#include "filter.h"
#include "filterbank.h"
using namespace std;

const int Order = 2;
const double NUM[3] =
{
	0.9995558103876,   -1.999111620775,   0.9995558103876
};
const double DEN[3] =
{
	1,   -1.999111423471,   0.9991118180796
};

typedef float sorce_data_type;
#define DATA_LENGTH 1000000
int main() {
	vector<sorce_data_type> data(DATA_LENGTH, 1);
	vector<double> NUM_vect(NUM, NUM + 3);
	vector<double> DEN_vect(DEN, DEN + 3);


	//Filter<sorce_data_type> test_filter(Order, NUM, DEN);
	Filter<sorce_data_type> test_filter(Order, NUM_vect, DEN_vect);
	FilterBank<sorce_data_type> test_filterbank;
	test_filterbank.AddFilter(Order, NUM, DEN);
	test_filterbank.AddFilter(Order, NUM_vect, DEN_vect);


	vector<double> filter_data_vect_1;
	filter_data_vect_1.resize(DATA_LENGTH);
	for (int i = 0; i < DATA_LENGTH; i++) {
		filter_data_vect_1[i] = test_filter.DoFilter(data[i]);
	}

	vector<double> filter_data_vect_2 = test_filter.DoFilter(data);

	vector<double> filter_data_vect_3 = test_filter.DoFilter(data.data(), data.size());

	cout << "filter finish" << endl;


	cout << "filterbank size:" << test_filterbank.GetFilterNum() << endl;
	vector<double> filter_data_vect_4;
	filter_data_vect_4.resize(DATA_LENGTH);
	for (int i = 0; i < DATA_LENGTH; i++) {
		filter_data_vect_4[i] = test_filterbank.DoFilter(data[i]);
	}

	vector<double> filter_data_vect_5 = test_filterbank.DoFilter(data);

	vector<double> filter_data_vect_6 = test_filterbank.DoFilter(data.data(), data.size());
	cout << "filterbank finish" << endl;

	return 0;
}