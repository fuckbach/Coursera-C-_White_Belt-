// Bus_Stops.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
void NEW_BUS();
void BUSES_FOR_STOP();
void STOPS_FOR_BUS();
void ALL_BUSES();
//void printmap(const map<string, vector<string>>& bus_stopsp);

map <string, vector<string>> bus_stops;


int main()
{
    bus_stops["93"] = { "SH1","SH2","SH3" ,"SH4","SH5"};
    bus_stops["72"] = { "SH1","SH3" ,"SH4" };
    bus_stops["9"] = { "SH3","SH4","SH5" ,"SH6","SH7" };

    string bus;
    cin >> bus;
    for (auto i : bus_stops[bus]) {//i - stops for user input bus
        cout << i<<" ";
        for (auto g : bus_stops) {//g - pairs of map
            for (auto t : g.second) {//t - stops in all map
                if (t == i) {
                    cout << g.first << " ";
                }
                
            }
            
        }
        cout << endl;
    }
   /* int n = 0;
    cin >> n;
    string cmd;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "NEW_BUS") {
            NEW_BUS();
        }
        if (cmd == "BUSES_FOR_STOP") {
            BUSES_FOR_STOP();
        }
        if (cmd == "ALL_BUSES") {
            ALL_BUSES();
        }
    }*/
}
//
//void ALL_BUSES() {
//    for (auto item : bus_stops) {
//        cout << item.first << " ";
//        for (auto t : item.second) {
//            cout << t << " ";
//        }
//        cout << endl;
//    }
//}
//
//void NEW_BUS() {
//    int  stop_count = 0;
//    vector<string> stops;
//    string stop, bus;
//    cin >> bus >> stop_count;
//    for (int g = 0; g < stop_count; g++) {
//        cin >> stop;
//        stops.push_back(stop);
//    }
//    bus_stops[bus] = stops;
//}
//
//void BUSES_FOR_STOP() {
//    string stop;
//    cin >> stop;
//    for (auto i : bus_stops) {
//        for (auto g : i.second) {
//            if (g == stop) {
//                cout << i.first << " ";
//            }
//        }
//    }
//    cout << endl;
//}

void STOPS_FOR_BUS() {
    string bus;
    cin >> bus;
    for (auto i : bus_stops[bus]) {//i - stops for user input bus
        cout << i;
        for (auto g : bus_stops) {//g - pairs of map
            for(auto t:g.second){//t - stops in all map
                if (t == i) {
                    cout << g.first << " ";
                }
            }
        }
    }
}



