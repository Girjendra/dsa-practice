// #include<bits/stdc++.h>
       // OR
// #include<utility>
#include<iostream>
using namespace std;

pair<int, int> getMinMax(int arr[], int n) {
    int mn = arr[0], mx = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i] < mn) mn = arr[i];
        if (arr[i] > mx) mx = arr[i];
    }

    return make_pair(mn, mx);
}

int main(){
    // only fundamental datatypes

        pair<int,int> a = {2,4};
        cout<<a.first<<" "<<a.second<<endl;
        a.first = 4;
        a.second = 7;
        //cout<<a.first<<" "<<a.second<<endl;
        a = {8,9};
        //cout<<a.first<<" "<<a.second<<endl;
    
    // pair object using make_pair() function of  STL

        auto b = make_pair(1,"bhola");
        cout<<b.first<<" "<<b.second<<endl;

    // a pair having a element of type pair

        pair<int,pair<int,int>> c = {5,{2,4}};
        cout<<c.first<<" "<<c.second.first<<" "<<c.second.second<<endl;

    // array of pairs

        pair<int,int> arr[] = {{1,2},{3,4},{5,6}};
        for (int i = 0; i < 3; i++)
        {
            cout<<arr[i].first<<" "<<arr[i].second<<" ";
        }

    // Comparision between two pair object

        pair<int, int> d(1, 2);
        pair<int, int> e(1, 3);
        if (d < e) {
            cout << "\nd is smaller"<<endl;
        }
        else 
        cout << "\ne is smaller"<<endl;

    // Returning two values from a funnction by making return type as pair
        
    int arr1[] = {5, 0, 9, 3, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    pair<int, int> result = getMinMax(arr1, n);
    cout << "Minimum: " << result.first << endl;
    cout << "Maximum: " << result.second << endl;

    return 0;
} 