/*
You are given a string 'str' of length 'N'.
Your task is to reverse the original string word by word.
There can be multiple spaces between two words and there can be leading or trailing
spaces but in the output reversed string you need to put a single space between two
words, and your reversed string should not contain leading or trailing spaces.
Example :
If the given input string is "Welcome to Coding Ninjas", then you should return
"Ninjas Coding to Welcome" as the reversed string has only a single space between
two words and there is no leading or trailing space.
*/

#include <iostream>
#include <string>
using namespace std;

string reverseString(string &str){
	string s;
	int i = str.length()-1;
	while(i>=0){
		while(i >= 0 && str[i] == ' ')
        i--;
        
		int j = i;
		while(i >= 0 && str[i] != ' ')
        i--;

		string a(str.begin()+i+1,str.begin()+j+1);
        
		s += a + " ";
	}
	if (s.back() == ' ')
    s.pop_back();
	return s;
}

int main() {
    string str = "  Welcome to Coding Ninjas  ";
    string result = reverseString(str);
    cout << '"' << result << '"' << endl;
    return 0;
}