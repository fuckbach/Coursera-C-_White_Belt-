// capital_directory.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

void CHANGE_CAPITAL(string country, string new_capital, map <string, string> &directory);
void RENAME(string old_country_name, string new_country_name, map <string, string>& directory);
void ABOUT(string country, const map <string, string>& directory);
void DUMP(const map <string, string>& directory);


int main()
{
    map <string, string> directory;

    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {//qantity of iteration
        string cmd,country,capital;
        cin >> cmd;
        if (cmd == "CHANGE_CAPITAL") {
            cin >> country >> capital;
            CHANGE_CAPITAL(country, capital,directory);
            /*В ответ на запрос CHANGE_CAPITAL country new_capital выведите
            Introduce new country country with capital new_capital, если страны country раньше не существовало;
            Country country hasn't changed its capital, если страна country до текущего момента имела столицу new_capital;
            Country country has changed its capital from old_capital to new_capital,
            если страна country до текущего момента имела столицу old_capital,
            название которой не совпадает с названием new_capital.
            */
           

        }
        else if (cmd == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            RENAME(old_country_name, new_country_name, directory);
            /*В ответ на запрос RENAME old_country_name new_country_name выведите
            Incorrect rename, skip, если новое название страны совпадает со старым, 
            страна old_country_name не существует или страна new_country_name уже существует;
            Country old_country_name with capital capital has been renamed to new_country_name, если запрос корректен и страна имеет столицу capital.*/

        }
        else if (cmd == "ABOUT") {
            cin >> country;
            ABOUT(country, directory);
            /*В ответ на запрос ABOUT country выведите
            Country country doesn't exist, если страны с названием country не существует;
            Country country has capital capital, если страна country существует и имеет столицу capital.*/

        }
        else if (cmd == "DUMP") {
            DUMP(directory);
            /*В ответ на запрос DUMP выведите
            There are no countries in the world, если пока не было добавлено ни одной страны;
            последовательность пар вида country/capital, описывающую столицы всех стран, если в мире уже есть хотя бы одна страна.
            При выводе последовательности пары указанного вида необходимо упорядочить по названию страны и разделять между собой пробелом.*/

        }
    }

}
void CHANGE_CAPITAL(string country, string new_capital, map <string, string> &directory) {
    int tmp = 0;
    for (auto i : directory) {
        if (i.first == country) {
            tmp ++;
            if (i.second == new_capital) {
                cout<< "Country "<< country<< " hasn't changed its capital"<<endl;
            }
            else {
                cout << "Country " << country << " has changed its capital from " << i.second << " to " << new_capital << endl;
                directory[country] = new_capital;
            }
        }
        
    }
    if (!tmp) {
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
        directory[country] = new_capital;
        tmp = 0;
    }
}
void DUMP(const map <string, string>& directory) {
    if (directory.empty()) {
        cout << "There are no countries in the world" << endl;
    }
    for (auto i : directory) {
        cout << i.first << "/" << i.second << " ";
    }
}
void ABOUT(string country,const map <string, string>& directory) {
    int tmp = 0;
    for (auto i : directory) {
        if (i.first == country) {
            tmp++;
            cout << "Country " << i.first << " has capital " << i.second << endl;
        }
    }
    if (!tmp) {
        tmp = 0;
        cout << "Country " << country << " doesn't exist" << endl;
    }
}
void RENAME(string old_country_name, string new_country_name, map <string, string>& directory) {
    int tmp = 0;
    bool flag = true;
   
    for (auto i : directory) {
        if (i.first == new_country_name) {
            cout << "Incorrect rename, skip" << endl;
            flag = false;
            tmp++;
        }
        if (i.first == old_country_name) {
            tmp++;
        }

    }
    if (!tmp) {
        cout << "Incorrect rename, skip" << endl;
        tmp = 0;
        flag = false;
    }
    if (flag) {
        string tmp = directory[old_country_name];
        directory.erase(old_country_name);
        directory[new_country_name] = tmp;
        cout << "Country " << old_country_name << " with capital " << tmp << " has been renamed to " << new_country_name << endl;
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