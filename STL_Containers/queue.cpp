#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int> q;

    q.push(1);        // {1}
    q.push(2);        // {1, 2}
    q.emplace(4);     // {1, 2, 4}

    q.back() += 5;    // last element becomes 4 + 5 = 9 → {1, 2, 9}

    cout << q.back() << endl;   // prints 9

    // Queue is now: {1, 2, 9}
    cout << q.front() << endl;  // prints 1

    q.pop();                    // removes front → {2, 9}

    cout << q.front() << endl;  // prints 2

    // size(), swap(), empty() work same as stack
    return 0;
}