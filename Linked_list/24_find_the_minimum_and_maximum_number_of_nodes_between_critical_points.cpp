/*
A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].
*/
#include<iostream>
#include<vector>
using namespace std;


    
//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

// TC : O(n) where n is the number of nodes in the linked list
// SC : O(n) where n is the number of critical points in the linked list
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head->next;

        if(!temp)
            return {-1, -1};

        int i = 2;
        ListNode* prev = head;
        vector<int> points;

        while(temp->next) {
            if(temp->val > prev->val && temp->val > temp->next->val ||
               temp->val < prev->val && temp->val < temp->next->val)
                points.push_back(i);

            i++;
            prev = temp;
            temp = temp->next;
        }

        if(points.size() < 2)
            return {-1, -1};

        int mind = points[1] - points[0];
        int maxd = points[points.size()-1] - points[0];

        for(int j = 1; j < points.size(); j++) {
            if(mind > points[j] - points[j-1])
                mind = points[j] - points[j-1];
        }

        return {mind, maxd};
    }
};