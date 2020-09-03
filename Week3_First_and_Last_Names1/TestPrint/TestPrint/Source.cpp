#include <vector>
#include <string>
#include <iostream>

using namespace std;


string getres( vector<string> v) {
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


int main() {

	vector <string> v = { "1", "2","3" };
	
	cout << getres(v);

	return 0;
}