#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
    void reverseLL(Node* &head, Node* prev, Node* cur) {
        if(cur == NULL) {
            head = prev;
            return ;
        }        
        
        reverseLL(head, cur, cur->next);
        cur->next = prev;
    }

    int getnodes(Node* head) {
        if(head == NULL) {
            return 0;
        }
        
        return 1 + getnodes(head->next);
    }
    
  public:
    Node *reverseKGroup(Node* head, int k) {
        int nodes = getnodes(head);
        
        if(k == nodes) {
            reverseLL(head, NULL, head);
            return head;
        }
        else if(k == 0) {
            return head;
        }
        
        Node* tail = head;
        int count = 0;
        
        while(count < k - 1) {
            tail = tail->next;
            count++;
        }
        
        Node* remaining = tail->next;
        tail->next = NULL;
        tail = head;
        reverseLL(head, NULL, head);
        
        Node* temphead = remaining;
        Node* temptail = remaining;
        count = 0;
        while(temptail != NULL && count <= k - 1) {
            
            if(count == k - 1) {
                count = 0;
                Node* nexthead = temptail->next;
                
                temptail->next = NULL;
                temptail = temphead;
                
                reverseLL(temphead, NULL, temphead);
                
                tail->next = temphead; 
                tail = temptail;
                
                temphead = nexthead;
                temptail = nexthead;
            }
            else if(count < k - 1 && temptail->next == NULL) {
                reverseLL(temphead, NULL, temphead);        
                tail->next = temphead;
                break;
            }
            else {
                count++;
                temptail = temptail->next;
            }
        }
        return head;
    }
};