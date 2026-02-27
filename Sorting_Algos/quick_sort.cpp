#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>& arr,int s,int e){
    int pivotelem = arr[s];
    int count = 0;
    for(int i=s+1;i<=e;i++){
        if(arr[i] < pivotelem){
            count++;
        }
    }

    int pivotindex = s+count;
    swap(arr[s],arr[pivotindex]);

    int i=s,j=e;
    while(i < pivotindex && j > pivotindex){
        while(arr[i] < pivotelem){
            i++;
        }
        while(arr[j] > pivotelem){
            j--;
        }

        if(i < pivotindex && j > pivotindex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotindex;
}
void quicksort(vector<int>& arr,int s,int e){
    if(s>=e)
        return ;
    
    int pivotindex = partition(arr,s,e);

    quicksort(arr,s,pivotindex-1);

    quicksort(arr,pivotindex+1,e);
}
int main(){
    // vector<int> arr = {3,6,0,6,4,9,7,3};
    vector<int> arr = {1,4,-4,2,-1,2,6};
    int n = arr.size();

    cout<<"Before sorting:";
    for(int it:arr)
        cout<<it<<" ";
        
    quicksort(arr,0,n-1);

    cout<<"\nAfter sorting:";
    for(int it:arr)
        cout<<it<<" ";

    return 0;
}

/*
quicksort(0, 7)                          → pivot = 3 at index 1
├── quicksort(0, 0)                     → base case
└── quicksort(2, 7)                     → pivot = 0 at index 2
    ├── quicksort(2, 1)                → base case
    └── quicksort(3, 7)                → pivot = 6 at index 6
        ├── quicksort(3, 5)            → pivot = 4 at index 4
        │   ├── quicksort(3, 3)        → base case
        │   └── quicksort(5, 5)        → base case
        └── quicksort(7, 7)            → base case

*/