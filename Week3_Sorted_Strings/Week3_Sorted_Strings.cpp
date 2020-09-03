// Week3_Sorted_Strings.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        sorted_s.push_back(s);// добавить строку s в набор
    }
    vector<string> GetSortedStrings() {
        sort(sorted_s.begin(), sorted_s.end());
        return sorted_s;// получить набор из всех добавленных строк в отсортированном порядке
    }
private:
    string s;
    vector<string> sorted_s;// приватные поля
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main()
{
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;

}
