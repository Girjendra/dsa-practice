// #include <bits/stdc++.h> 
// using namespace std;
// string replaceSpaces(string &str){
// 	// Write your code here.
// 	int n = str.size();
// 	string s;
// 	for(int i=0;i<n;i++){
// 		if(str[i]!=' '){
// 			s.push_back(str[i]);
// 		}
// 		else{
// 			s.push_back('@');
// 			s.push_back('4');
// 			s.push_back('0');
// 		}
// 	}
// 	return s;
// }
// int main(){
//     string str = "Coding Ninjas Is A Coding Platform";
//     str = replaceSpaces(str);
//     cout<<str<<endl;
//     return 0;
// }




// #include <bits/stdc++.h> 
// using namespace std;
// string replaceSpaces(string &str){
// 	for(int i=0;i < str.length();i++){
// 		if(str[i]==' '){
//             str.erase(i, 1);
// 			str.insert(str.begin()+i,'@');
// 			i++;
// 			str.insert(str.begin()+i,'4');
// 			i++;
// 			str.insert(str.begin()+i,'0');
// 		}
// 	}
// 	return str;
// }
// int main(){
//     string str = "Coding Ninjas Is A Coding Platform";
//     str = replaceSpaces(str);
//     cout<<str<<endl;
//     return 0;
// }




// #include <bits/stdc++.h> 
// using namespace std;
// string replaceSpaces(string &str){
// 	for(int i=0;i < str.length();i++){
// 		if(str[i]==' '){
//             str.erase(i, 1);
// 			str.insert(i, "@40");
//             i += 2;
// 		}
// 	}
// 	return str;
// }
// int main(){
//     string str = "Coding Ninjas Is A Coding Platform";
//     str = replaceSpaces(str);
//     cout<<str<<endl;
//     return 0;
// }