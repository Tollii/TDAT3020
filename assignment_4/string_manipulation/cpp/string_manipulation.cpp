#include <iostream>
#include <string>

using namespace std;

string manipulate_string(const string &text);

int main() {
	
	string text;
	getline(cin, text);

	string res = manipulate_string(text);

	cout << res << endl;



	return 0;
}

string manipulate_string(const string &text) {

	string new_string = text;

	for(size_t i = 0; i < new_string.length(); i++) {
		
		if(new_string[i] == '&') {
			new_string.replace(i, 1, "&amp");
		}
		else if (new_string[i] == '<') {
			new_string.replace(i, 1, "&lt");
		}
		else if (new_string[i] == '>') {
			new_string.replace(i, 1, "&gt");
		}
	}
	return new_string;
}
