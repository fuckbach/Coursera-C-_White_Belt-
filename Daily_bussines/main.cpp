#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ADD(int day, string bussines, vector<vector<string>> &monthly_bussines);
void DUMP(int day, const vector<vector<string>> &monthly_bussines);
void NEXT(vector<vector<string>>& monthly_bussines, int& num_of_month, const vector <int>& days_in_month);

int main()
{
	const vector <int> days_in_month = { 31,28,31,30,31,30,31,31,30,31,30,31 };//quantity of days in month
	int n = 0;
	int num_of_month = 0;
	vector<vector<string>> monthly_bussines(days_in_month[num_of_month]);
	
	 
	cin >> n;//quantity of iterations
	for (int i = 0; i < n; i++) {
		string cmd,bussines;
		int day;
		cin >> cmd;
		if (cmd == "ADD") {//case ADD
			cin >> day >> bussines;
			ADD(day, bussines, monthly_bussines);
		}
		else if (cmd == "DUMP") {//case DUMP
			cin >> day;
			DUMP(day, monthly_bussines);
		}
		else if (cmd == "NEXT") {//case NEXT
			NEXT(monthly_bussines, num_of_month, days_in_month);
		}
	}
}

void ADD(int day,string bussines, vector<vector<string>> &monthly_bussines) {
	monthly_bussines[day-1].push_back(bussines);
}

void DUMP(int day, const vector<vector<string>> &monthly_bussines) {
	for (auto i : monthly_bussines[day-1]) {
		cout << i << endl;
	}
}

void NEXT(vector<vector<string>>& monthly_bussines,int &num_of_month, const vector <int> &days_in_month) {
	num_of_month++;
	vector<vector<string>> new_monthly_bussines(days_in_month[num_of_month]);
	cout << monthly_bussines.size() << endl;
	cout << new_monthly_bussines.size() << endl;
	if (new_monthly_bussines.size() < monthly_bussines.size()) {
		for (int tmp = monthly_bussines.size(); tmp = new_monthly_bussines.size();tmp--) {
			for (auto i : monthly_bussines[tmp]) {
				new_monthly_bussines[monthly_bussines.size() - 1].push_back(i);
			}
		}
	}
}

