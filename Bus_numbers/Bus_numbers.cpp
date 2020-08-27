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
        int tmp = 0;
        int num;
        for (auto g : bus_stops) {
            if (g.second == stops) {
                tmp++;
                num = g.first;
            }
        }
        if (tmp != 0) {
            cout << "Already exists for " << num<<endl;
            tmp = 0;
            stops.clear();
        }
        else {
            num = bus_stops.size() + 1;
            bus_stops[num] = stops;
            stops.clear();
            cout << "New bus " << num << endl;
        }
        
    }
}

