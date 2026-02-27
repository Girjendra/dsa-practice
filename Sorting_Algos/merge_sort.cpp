#include<iostream>
#include<vector>
using namespace std;
void merge(int* arr,int s,int e){
    int mid = s+(e-s)/2;
    
    int l1 = mid-s+1;
    int l2 = e-mid;

    int* arr1 = new int[l1];
    int* arr2 = new int[l2];

    int arrindex = s;
    for(int i=0;i<l1;i++){
        arr1[i] = arr[arrindex++];
    }

    arrindex = mid+1;
    for(int i=0;i<l2;i++){
        arr2[i] = arr[arrindex++];
    }

    int i1 = 0;
    int i2 = 0;
    arrindex  = s;

    // while(i1 < l1 && i2 < l2) {
    //     if(arr1[i1] < arr2[i2]) {
    //         arr[arrindex++] = arr1[i1++];
    //     } else {
    //         arr[arrindex++] = arr2[i2++];
    //     }
    // }

    // while(i1 < l1) {
    //     arr[arrindex++] = arr1[i1++];
    // }

    // while(i2 < l2) {
    //     arr[arrindex++] = arr2[i2++];
    // }


    // ✅ Single while loop
    while (i1 < l1 || i2 < l2) {
        if (i1 < l1 && (i2 >= l2 || arr1[i1] <= arr2[i2])) {
            arr[arrindex++] = arr1[i1++];
        } else {
            arr[arrindex++] = arr2[i2++];
        }
    }

    delete[] arr1;
    delete[] arr2;
}

void mergesort(int* arr,int s,int e){
    if(s>=e)
        return ;
    
    int mid = s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
}

int main(){
    int arr[] =  {4,3,2,-1,3,11,15,3};
    int n = 8;

    mergesort(arr,0,n-1);
    for(int it:arr)
        cout<<it<<" ";
    return 0;
}

/*
mergesort(0, 7)
│   ├── mergesort(0, 1)
│   │   ├── mergesort(0, 0)  → return
│   │   ├── mergesort(1, 1)  → return
│   │   └── merge(0, 1)      → [3,4]
│   ├── mergesort(2, 3)
│   │   ├── mergesort(2, 2)  → return
│   │   ├── mergesort(3, 3)  → return
│   │   └── merge(2, 3)      → [-1,2]
│   └── merge(0, 3)          → [-1,2,3,4]
├── mergesort(4, 7)
│   ├── mergesort(4, 5)
│   │   ├── mergesort(4, 4)  → return
│   │   ├── mergesort(5, 5)  → return
│   │   └── merge(4, 5)      → [3,11]
│   ├── mergesort(6, 7)
│   │   ├── mergesort(6, 6)  → return
│   │   ├── mergesort(7, 7)  → return
│   │   └── merge(6, 7)      → [3,15]
│   └── merge(4, 7)          → [3,3,11,15]
└── merge(0, 7)              → [-1,2,3,3,3,4,11,15]

*/