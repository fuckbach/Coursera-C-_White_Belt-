#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Person {
public:



	string getres(vector<string> v) {
		string res;
		if (v.size() == 1) {
			res = v[0];
		}
		else if (v.size() == 2) {
			res = v[0] + " (" + v[1] + ")";
		}
		else if (v.size() > 2) {
			res = v[0] + " (";
			for (int i = 1; i != v.size() - 1; i++) {
				res += v[i] + ", ";
			}
			res += v[v.size() - 1] + ")";
		}
		return res;
	}

	string GetFullNameWithHistory(int year) {// получить все имена и фамилии по состоянию на конец года year
		bool ff = false;
		bool lf = false;
		int start;
		vector<string> result_fnames ;
		vector<string> result_lnames ;
		if (Firstname.begin()->first >= Lastname.begin()->first) {
			start = Lastname.begin()->first;
		}
		else start = Firstname.begin()->first;
		string tmpf, tmpl = "";
		for (int i = year; i >= start; i--) {
			if (Firstname.count(i)and tmpf!= Firstname[i]) {
				tmpf = Firstname[i];
				result_fnames.push_back(Firstname[i]) ;
				ff = true;

			}

			if (Lastname.count(i) and tmpl != Lastname[i]) {
				tmpl = Lastname[i];
				result_lnames.push_back(Lastname[i]);
				lf = true;
			}

		}
		if (!ff and !lf) return "Incognito";
		else if (ff and !lf) {
			string res;
			res = getres(result_fnames);
			res+= " with unknown last name";
			return res;
		}
		else if (lf and !ff) {
			string res;
			res = getres(result_lnames);
			res += " with unknown first name";
			return res;
		}
		else {
			string res;
			res = getres(result_fnames) + " ";
			res += getres(result_lnames);
			return res;
		}
	}

	void ChangeFirstName(int year, const string& first_name) {
		Firstname[year] = first_name;// добавить факт изменения имени на first_name в год year
	}
	void ChangeLastName(int year, const string& last_name) {
		Lastname[year] = last_name; // добавить факт изменения фамилии на last_name в год year
	}
	string GetFullName(int year) {
		bool foundfirst = false;//flags of search
		bool foundlast = false;
		// получить имя и фамилию по состоянию на конец года year
		string first_name, last_name;
		for (auto i : Firstname) {
			if (i.first <= year) {
				first_name = i.second;
				foundfirst = true;
			}
		} 

		for (auto i : Lastname) {
			if (i.first <= year) {
				last_name = i.second;
				foundlast = true;
			}
		}

		if (!foundfirst and !foundlast) return "Incognito";
		else if (foundfirst and !foundlast) return first_name + " with unknown last name";
		else if (foundlast and !foundfirst) return last_name + " with unknown first name";
		else return first_name + " " + last_name;
	}
private:
	
	map <int, string> Firstname; // приватные поля
	map <int, string> Lastname;
};
int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person.GetFullNameWithHistory(1990) << endl;

	person.ChangeFirstName(1966, "Pauline");
	cout << person.GetFullNameWithHistory(1966) << endl;

	person.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1961, "Ivanova");
	cout << person.GetFullNameWithHistory(1967) << endl;

	return 0;
}