#include<iostream>
#include <climits>
#include <vector>
using namespace std;

// overall TC of this problem is O(n*logn) because we are building the segment tree in O(n) and then performing queries and updates in O(logn) each.


// TC : O(n)
// Build the segment tree from the given array
void buildSegmentTree(int* arr, int* segTree, int st, int end, int index) {
    // Base case
    if(st == end) {
        segTree[index] = arr[st];
        return;
    }

    int mid = st + (end - st) / 2;
    // Recursively build the left and right subtrees
    buildSegmentTree(arr, segTree, st, mid, 2 * index + 1);
    buildSegmentTree(arr, segTree, mid + 1, end, 2 * index + 2);

    // Merge the results from the left and right subtrees
    int left = segTree[2 * index + 1];
    int right = segTree[2 * index + 2];
    
    // Store the minimum value in the current node
    segTree[index] = min(left, right);
}

// TC : O(log n)
// Query the minimum value in the range [l, r] in the segment tree
int query(int* segTree, int st, int end, int l, int r, int index) {
    // No overlap
    if(r < st || l > end) {
        return INT_MAX;
    }

    // Complete overlap
    if(l <= st && r >= end) {
        return segTree[index];
    }

    // Partial overlap
    int mid = st + (end - st) / 2;
    int left = query(segTree, st, mid, l, r, 2 * index + 1);
    int right = query(segTree, mid + 1, end, l, r, 2 * index + 2);

    return min(left, right);
}


// TC : O(log n)
// Update the value at index i in the original array and segment tree
void update(int* arr, int* segTree, int st, int end, int index, int i, int value) {
    // Base case: If the index to be updated is out of bounds
    if(i < st || i > end) {
        return;
    }

    // Leaf node: Update the value in the original array and segment tree
    if(st == end) {
        arr[i] = value;
        segTree[index] = value;
        return;
    }

    int mid = st + (end - st) / 2;

    // Recursively update the left or right subtree based on the index to be updated
    update(arr, segTree, st, mid, 2 * index + 1, i, value);
    update(arr, segTree, mid + 1, end, 2 * index + 2, i, value);

    // Update the current node after updating the child nodes
    segTree[index] = min(segTree[2 * index + 1], segTree[2 * index + 2]);
}

// TC : O(n) because we are updating the values in the range [l, r] in the original array and segment tree
// Update the values in the range [l, r] in the original array and segment tree
void updateRange(int* arr, int* segTree, int st, int end, int index, int l, int r, int value) {
    // No overlap
    if(r < st || l > end) {
        return;
    }

    // Leaf node: Update the value in the original array and segment tree
    if(st == end) {
        arr[st] += value; // Increment the value at the leaf node
        segTree[index] = arr[st]; // Update the segment tree node
        return;
    }

    int mid = st + (end - st) / 2;

    // Recursively update the left and right subtrees
    updateRange(arr, segTree, st, mid, 2 * index + 1, l, r, value);
    updateRange(arr, segTree, mid + 1, end, 2 * index + 2, l, r, value);

    // Update the current node after updating the child nodes
    segTree[index] = min(segTree[2 * index + 1], segTree[2 * index + 2]);
}

int main() {
    int arr[] = {7, 3, 5, 7, 9, 11};

    int n = sizeof(arr) / sizeof(arr[0]);
    int* segTree = new int[4 * n];

    buildSegmentTree(arr, segTree, 0, n - 1, 0);
    // Query the minimum value in the range [0, 3]
    cout << "Minimum value in the range [0, 3]: " << query(segTree, 0, n - 1, 0, 3, 0) << endl; // Output: 3
    
    // Update the value at index 1 to 10
    update(arr, segTree, 0, n - 1, 0, 1, 10);
    
    // Query the minimum value in the range [0, 3] after the update
    cout << "Minimum value in the range [0, 3] after update: " << query(segTree, 0, n - 1, 0, 3, 0) << endl; // Output: 5
    
    // Update the values in the range [1, 4] by adding 5
    updateRange(arr, segTree, 0, n - 1, 0, 1, 4, 5);
    
    // Query the minimum value in the range [0, 3] after the range update
    cout << "Minimum value in the range [0, 3] after range update: " << query(segTree, 0, n - 1, 0, 3, 0) << endl; // Output: 7
    delete[] segTree;

    return 0;
}