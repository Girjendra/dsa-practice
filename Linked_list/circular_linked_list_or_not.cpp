/*
// best in O(n)
bool isCircular(Node* head) {
    if (head == NULL) return true;

    Node* temp = head->next;
    int steps = 0;
    int MAX_STEPS = 1e5;

    while (temp != NULL && temp != head && steps < MAX_STEPS) {
        temp = temp->next;
        steps++;
    }

    return temp == head;
}
*/