#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Person {
public:



	Person(string firstname,string lastname,int year) {
		Firstname[year] = firstname;
		Lastname[year] = lastname;
	}

	

	string GetFullNameWithHistory(int year) const   {

		if (born(year)) {
			return "No person";
		}
		bool ff = false;
		bool lf = false;
		int start;
		vector<string> result_fnames;
		vector<string> result_lnames;
		map <int, string> Firstname1 = Firstname;// приватные поля
		map <int, string> Lastname1 = Lastname;
		if (Firstname1.begin()->first >= Lastname1.begin()->first) {
			start = Lastname1.begin()->first;
		}
		else start = Firstname1.begin()->first;
		string tmpf, tmpl = "";

		for (int i = year; i >= start; i--) {
			if (Firstname1.count(i) and tmpf != Firstname1[i]) {
				tmpf = Firstname1[i];
				result_fnames.push_back(Firstname1[i]);
				ff = true;
			}
			if (Lastname1.count(i) and tmpl != Lastname1[i]) {
				tmpl = Lastname1[i];
				result_lnames.push_back(Lastname1[i]);
				lf = true;
			}
		}
		if (!ff and !lf) return "Incognito";
		else if (ff and !lf) {
			string res;
			res = getres(result_fnames);
			res += " with unknown last name";
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
		if (born(year)) {
			return;
		}
		Firstname[year] = first_name;// добавить факт изменения имени на first_name в год year
	}
	void ChangeLastName(int year, const string& last_name) {
		if (born(year)) {
			return;
		}
		Lastname[year] = last_name; // добавить факт изменения фамилии на last_name в год year
	}
	string GetFullName(int year) const{
		if (born(year)) {
			return "No person";
		}
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


	string getres(vector<string> v) const {
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



	bool born(int year) const {
		int start;
		if (Firstname.begin()->first >= Lastname.begin()->first) {
			start = Lastname.begin()->first;
		}
		else start = Firstname.begin()->first;

		if (start > year) {
			return true;
		}
		else return false;
	}
	



};

int main() {
	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;
}
