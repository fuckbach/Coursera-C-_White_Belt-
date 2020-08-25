#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ADD(int day, string bussines, vector<vector<string>>& monthly_bussines);
void DUMP(int day, const vector<vector<string>>& monthly_bussines);
void NEXT(vector<vector<string>>& monthly_bussines, int& num_of_month, const vector <int>& days_in_month);

int main()
{
    const vector <int> days_in_month = { 31,28,31,30,31,30,31,31,30,31,30,31 };//quantity of days in month
    int n = 0;
    int num_of_month = 0;
    vector<vector<string>> monthly_bussines(days_in_month[num_of_month]);


    cin >> n;//quantity of iterations
    for (int i = 0; i < n; i++) {
        string cmd, bussines;
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

void ADD(int day, string bussines, vector<vector<string>>& monthly_bussines) {
    monthly_bussines[day - 1].push_back(bussines);
}

void DUMP(int day, const vector<vector<string>>& monthly_bussines) {
    cout << monthly_bussines[day - 1].size() << " ";
    for (auto i : monthly_bussines[day - 1]) {
        cout << i << " ";
    }
    cout << endl;
}

void NEXT(vector<vector<string>>& monthly_bussines, int& num_of_month, const vector <int>& days_in_month) {
    num_of_month++;
    if (num_of_month == 12) {
        num_of_month = 0;
    }
    vector<vector<string>> new_monthly_bussines(days_in_month[num_of_month]);

    if (new_monthly_bussines.size() < monthly_bussines.size()) {
        for (int i = 0; i < new_monthly_bussines.size(); i++) {
            new_monthly_bussines[i] = monthly_bussines[i];
        }
        for (int i = monthly_bussines.size() - 1; i != new_monthly_bussines.size() - 1; i--) {
            for (auto g : monthly_bussines[i]) {
                new_monthly_bussines[new_monthly_bussines.size() - 1].push_back(g);
            }
        }
    }
    else if (new_monthly_bussines.size() > monthly_bussines.size())
    {
        for (int i = 0; i < monthly_bussines.size(); i++) {
            new_monthly_bussines[i] = monthly_bussines[i];
        }
    }

    else new_monthly_bussines = monthly_bussines;


    monthly_bussines = new_monthly_bussines;
    
}