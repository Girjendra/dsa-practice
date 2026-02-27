#include<iostream>
#include<vector>
using namespace std;
void power_set(const vector<int>& arr,vector<int>& output,vector<vector<int>>& res,int index){
    if(index == arr.size()){
        res.push_back(output);
        return;
    }

    // Excluding
    power_set(arr,output,res,index+1);

    //Including
    output.push_back(arr[index]);
    power_set(arr,output,res,index+1);
    output.pop_back();
}
int main(){
    vector<int> arr = {1,2,3};
    vector<int> output;
    vector<vector<int>> res;
    power_set(arr,output,res,0);

    for(auto row:res){
        for(auto it:row){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*
power_set(index = 0, output = [])
│
├── Exclude 1
│   └── power_set(index = 1, output = [])
│       │
│       ├── Exclude 2
│       │   └── power_set(index = 2, output = [])
│       │       ├── Exclude 3 → power_set(index = 3, output = [])       → PUSH []
│       │       └── Include 3 → power_set(index = 3, output = [3])      → PUSH [3]
│       │
│       └── Include 2 → power_set(index = 2, output = [2])
│           ├── Exclude 3 → power_set(index = 3, output = [2])          → PUSH [2]
│           └── Include 3 → power_set(index = 3, output = [2, 3])       → PUSH [2, 3]
│
└── Include 1 → power_set(index = 1, output = [1])
    │
    ├── Exclude 2 → power_set(index = 2, output = [1])
    │   ├── Exclude 3 → power_set(index = 3, output = [1])              → PUSH [1]
    │   └── Include 3 → power_set(index = 3, output = [1, 3])           → PUSH [1, 3]
    │
    └── Include 2 → power_set(index = 2, output = [1, 2])
        ├── Exclude 3 → power_set(index = 3, output = [1, 2])           → PUSH [1, 2]
        └── Include 3 → power_set(index = 3, output = [1, 2, 3])        → PUSH [1, 2, 3]

*/