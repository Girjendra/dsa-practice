#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
        int roll;   string name;
        Student(int r, string n){
            roll = r;   name = n;
            cout << "Constructor called for " << name << endl; }
            void display() const{ cout << "Roll: " << roll << ", Name: " << name << endl; } };
int main(){
    // vector<int> v1;
    // v1.push_back(4);
    // v1.emplace_back(3);

    // vector<pair<int,int>> v2;
    // v2.push_back({4,6});
    // v2.emplace_back(6,3);
    
    // vector<int> v3(5,50);
    // vector<int> v4(5);
    // vector<int> v5(v3);
    
    // vector<int>::iterator iter  = v5.begin();
    
    //  printing the vector
    // for(vector<int>::iterator it = v3.begin();it!=v3.end();it++){
    //     cout<<*it<<endl;
    // }
    
    // for(auto it = v3.begin();it!=v3.end();it++){ 
    //     cout<<*it<<endl;                                // herer it is a iterator
    // }
    
    // for(auto it:v3){
    //     cout<<it<<endl;
    // }

    // int arr[] = {1,2,3,4,5,6};
    // for(auto it:arr){
    //     cout<<it<<endl;
    // }
    
    // vector<Student> students;
    // students.push_back(Student(1, "Amit"));             // push_back: needs an already created object
    // students.emplace_back(2, "Sneha");                  // emplace_back: constructs directly in-place
    // for(auto it:students){ it.display(); }

    // vector<int> v6 =  {1,2,3,4,5,6,7,8};
    // v6.erase(v6.begin());                       // 1 will erase
    // v6.erase(v6.begin()+2,v6.begin()+5);        // 3 to 5 will erase

    // v6 = {2,100};
    // v6.insert(v6.begin()+1,5);                    //  {2,5,100}
    // v6.insert(v6.begin()+2,2,300);                //  {2,5,300,300,100} means insert two 300s
    
    // vector<int> v7 = {5,45};
    // v6.insert(v6.begin()+1,v7.begin(),v7.end());  // inserts a vector in a vector

    // int arr[] = {1,2,3};
    // v7.insert(v7.begin()+1, arr, arr + 3);           // inserts a array in a vector
    // v7.pop_back();                                   // deletes last element of vector
    // v7.clear();                                      // deletes whole vector
    // v7.size();                                       // gives no. of elements in a vector

    // vector<int> v6 = {2,3,5};
    // vector<int> v7 = {8,9};
    // v6.swap(v7);                                        // swap two vectors

    // for(auto it:v6){
    //         cout<<it<<" ";
    //     }
    
    return 0;
} 