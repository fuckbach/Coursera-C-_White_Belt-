
#include <string>
#include <iostream>

using namespace std;

class  ReversibleString {

public:
	string str;
	ReversibleString( const string &s) {
		str = s;
}
	ReversibleString() {
		str = "";
	}
	 string ToString() const {
		return str;
	}

	string Reverse() {
		string res;
		for (int i = str.size() - 1; i >= 0;i--) {
			res += str[i];
		}
		str = res;
		return res;
	}

};
int main() {
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;

	return 0;
}
