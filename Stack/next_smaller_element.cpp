/*
You are given an array 'ARR' of integers of length N. Your task is to
find the next smaller element for each of the array elements.
Next Smaller Element for an array element is the first element to the
right of that element which has a value strictly smaller than that element.

If for any array element the next smaller element does not
exist, you should print -1 for that array element.

For Example:
If the given array is [ 2, 3, 1], we need to return [1, 1, -1].Because
for  2, 1 is the Next Smaller element. For 3, 1 is the Next Smaller element
and for 1, there is no next smaller element hence the answer for this element is -1.
*/

// O(n) O(1)
#include<bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> st;
    st.push(-1);
    
    for(int i=n-1;i>=0;i--) {
        int elem = arr[i];
        while(st.top() >= elem) {
            st.pop();
        }

        arr[i] = st.top();

        st.push(elem);
    }
    return arr;
}

// Print the vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {4, 8, 5, 2, 25};
    int n = arr.size();

    cout << "Original vector: ";
    printVector(arr);

    vector<int> result = nextSmallerElement(arr, n);

    cout << "Next smaller elements: ";
    printVector(result);

    return 0;
}