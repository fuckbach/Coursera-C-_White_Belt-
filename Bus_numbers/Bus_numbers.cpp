// Bus_numbers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n,q = 0;
    map<int, vector<string>> bus_stops;
    string stop;
    vector<string> stops;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> stop;
            stops.push_back(stop);
        }

        bus_stops[i + 1] = stops;
        stops.clear();
    }
}

