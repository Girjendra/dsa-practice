// #include<iostream>
// #include<vector>
// #include<set>
// using namespace std;
// int main(){
//     // vector<int> arr = {2,3,1,6,3,6,2};
//     // vector<int> arr = {5,3,1,5,1,3,4,7,4,8,8};
//     vector<int> arr = {1,3,1,3,6,6,7,10,7};
//     int size = arr.size();

//     set<int> s;
//     multiset<int> ms;
//     for(int it:arr){
//         s.insert(it);
//         ms.insert(it);
//     }

//     int uniqe;
//     for(int it:s){
//         if(ms.count(it)==1){
//             uniqe = it;
//             break;
//         }
//     }
//     cout<<"Uniqe element is: "<<uniqe<<endl;
//     return 0;
// }


// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main(){

//     // vector<int> arr = {2,3,1,6,3,6,2};   //1
//     // vector<int> arr = {5,3,1,5,1,3,4,7,4,8,8};  //7
//     vector<int> arr = {1,3,1,3,6,6,7,10,7};  //10
//     int size = arr.size();

//     sort(arr.begin(),arr.end());
//     int uniqe = -1;
//     for (int i = 0; i < size; i+=2)
//     {
//         if(i<size-1&&arr[i]!=arr[i+1]){
//             uniqe = arr[i];
//             break;
//         }
//     }
//     if(uniqe==-1)
//     cout<<"Uniqe element is: "<<arr[size-1]<<endl;
//     else
//     cout<<"Uniqe element is: "<<uniqe<<endl;
//     return 0;
// }



// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){

//     // vector<int> arr = {2,3,1,6,3,6,2};   //1
//     // vector<int> arr = {5,3,1,5,1,3,4,7,4,8,8};  //7
//     vector<int> arr = {1,3,1,3,6,6,7,10,7};  //10
//     int size = arr.size();

//     int ans = 0;
//     for(int i=0;i<size;i++){
//         ans = ans^arr[i];
//     }
//     cout<<ans<<endl;
// }