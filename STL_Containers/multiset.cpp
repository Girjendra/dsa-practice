#include<bits/stdc++.h>
using namespace std;
int main(){
// Everything is same as set
// only stores duplicate elements also

multiset<int> ms;
ms.insert(1);       // {1}
ms.insert(1);       // {1, 1}
ms.insert(1);       // {1, 1, 1}

// ms.erase(1);        // all 1's erased

// ms.erase(ms.find(1));           // erase one element
// int cnt = ms.count(1);          // gives the number of elements


ms.erase(ms.find(1), next(ms.find(1), 2));          // erase two occurrences

for(int it:ms){
    cout<<it<<" ";
}

// rest all functions same as set
return 0;
}