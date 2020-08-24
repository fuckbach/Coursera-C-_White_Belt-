#include <iostream>
#include <vector>
#include <string>

using namespace std;


void printv(vector<vector<string>> );

int main()
{
    vector<vector<string>> monthly_bussines(5);
    vector<vector<string>> new_monthly_bussines_more_days(5);
    vector<vector<string>> new_monthly_bussines_less_days(3);
    monthly_bussines = { {"1","11"},{"2","22"},{"3","33"},{"4","44"},{"5","55"} };


    //case 1(new_more)
  /*  for (int i = 0; i < monthly_bussines.size(); i++) {
        new_monthly_bussines_more_days[i] = monthly_bussines[i];
    }*/

    //case 2(less_days)
    for (int i = 0; i < new_monthly_bussines_less_days.size(); i++) {
        new_monthly_bussines_less_days[i] = monthly_bussines[i];
    }
    for (int i = monthly_bussines.size()-1; i != new_monthly_bussines_less_days.size()-1; i--) {
        for (auto g : monthly_bussines[i]) {
            new_monthly_bussines_less_days[new_monthly_bussines_less_days.size() - 1].push_back(g);
        }
    }
    printv(new_monthly_bussines_less_days);
}

void printv(vector<vector<string>>  v) {
    for (auto i : v) {
        for (auto g : i) {
            cout << g << " ";
        }
        cout << endl;
    }
}
/*void NEXT(vector<vector<string>>& monthly_bussines, int& num_of_month, const vector <int>& days_in_month) {
    num_of_month++;
    vector<vector<string>> new_monthly_bussines(days_in_month[num_of_month]);
    cout << monthly_bussines.size() << endl;
    cout << new_monthly_bussines.size() << endl;
    if (new_monthly_bussines.size() < monthly_bussines.size()) {
        for (int tmp = monthly_bussines.size(); tmp = new_monthly_bussines.size(); tmp--) {
            for (auto i : monthly_bussines[tmp]) {
                new_monthly_bussines[monthly_bussines.size() - 1].push_back(i);
            }
        }
    }
}*/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
