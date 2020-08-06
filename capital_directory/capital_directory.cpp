// capital_directory.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

void ABOUT(const string& country, const map<string, string >& directory);

int main()
{
    map<string , string > directory;
    directory = { {"Russia", "Moscaw"},{"Belarus","Minsk"},{"Ukraine", "Kiev"} };
 
}


void ABOUT(const string& country, const map<string, string >& directory) {
    int tmp = 0;
    for (auto i : directory) {
        if (country == i.first) 
            cout << "Country "<< i.first<< " has capital " << i.second << endl;
        tmp++;
    }
    if (tmp) {
        cout << "Country " <<country << " doesn't exis" << endl;
    }
    tmp = 0;
}

void CHANGE_CAPITAL(const string& country,const string& new_capital, map<string, string >& directory) {
    int tmp = 0;
    for (auto i : directory) {
        if (i.first == country) {
            if (i.second == new_capital)cout << "Country"<< country <<"hasn't changed its capital" << endl;
            else {
                cout << "Country "<< country<<" has changed its capital from"<<i.second<<" to "<<new_capital << endl;
                i.second = new_capital;
            }
            tmp++;
        }
        if (tmp == 0) {
            cout << "Introduce new country" << country << "with capital" << new_capital << endl;
            directory[country] = "new_capital";
        }
    }
}







// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
