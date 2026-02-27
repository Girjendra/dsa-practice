#include<bits/stdc++.h>
using namespace std;
int main(){
    // Max Heap (Default)
    priority_queue<int> pq;

    pq.push(5);       // {5}
    pq.push(2);       // {5, 2}
    pq.push(8);       // {8, 5, 2}
    pq.emplace(10);   // {10, 8, 5, 2}

    cout << pq.top() << endl;  // prints 10 (highest element)

    pq.pop();                  // removes 10 → {8, 5, 2}

    cout << pq.top() << endl;  // prints 8

    // size(), swap(), empty() same as other containers


    // Min Heap using greater<int>
    priority_queue<int, vector<int>, greater<int>> pq2;

    pq2.push(5);       // {5}
    pq2.push(2);       // {2, 5}
    pq2.push(8);       // {2, 5, 8}
    pq2.emplace(10);   // {2, 5, 8, 10}

    cout << pq2.top() << endl; // prints 2 (lowest element)
    return 0;
}