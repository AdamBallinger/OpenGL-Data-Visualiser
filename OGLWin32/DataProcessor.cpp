#include "DataProcessor.h"

#include <iostream>
#include <fstream>
#include <vector>s
#include <string>
#include <sstream>

using namespace std;

//void DataProcessor::ReadCsv()
//{
//	vector<tuple<int, string, string, int, string, string, string, string, int, int, int, string, string>> data;
//
//	ifstream fs("G:\\data_samples_01\\testdata.csv");
//
//	string titles;
//	getline(fs, titles);
//
//	while (fs)
//	{
//		string line;
//		// if it can't read the file, break.
//		if (!getline(fs, line))
//		{
//			break;
//		}
//
//		istringstream iss(line);
//
//		while (iss)
//		{
//			string age;
//			getline(iss, age, ',');
//			int agei = atoi(age.c_str());
//
//			string employment;
//			getline(iss, employment);
//
//			string edu;
//			getline(iss, edu);
//
//			string s_edu_years;
//			getline(iss, s_edu_years);
//			int edu_years = atoi(s_edu_years.c_str());
//
//			string marital;
//			getline(iss, marital);
//
//			string occupation;
//			getline(iss, occupation);
//
//			string race;
//			getline(iss, race);
//
//			string gender;
//			getline(iss, gender);
//
//			string s_capital_gain;
//			getline(iss, s_capital_gain);
//			int capital_gain = atoi(s_capital_gain.c_str());
//
//			string s_capital_loss;
//			getline(iss, s_capital_loss);
//			int capital_loss = atoi(s_capital_loss.c_str());
//
//			string s_hours;
//			getline(iss, s_hours);
//			int hours = atoi(s_hours.c_str());
//
//			string country;
//			getline(iss, country);
//
//			string salary;
//			getline(iss, salary);
//			
//
//			//cout << age << employment << edu << edu_years << marital << occupation << race << gender << capital_gain << capital_loss << hours << country << salary << endl;
//
//			tuple<int, string, string, int, string, string, string, string, int, int, int, string, string> entry(agei, employment, edu, edu_years, marital, occupation, race, gender,
//				capital_gain, capital_loss, hours, country, salary);
//			data.push_back(entry);
//		}
//	}
//
//	for (auto elem : data)
//		cout << get<0>(elem) << get<1>(elem) << endl;
//}

void DataProcessor::ReadCsv(std::string fileDir)
{
	ifstream file (fileDir);
	string dataCategories;
	getline(file, dataCategories);
	stringstream categories = stringstream(dataCategories);


	file.close();
}