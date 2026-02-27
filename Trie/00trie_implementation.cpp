#include<iostream>
using namespace std;
class Tn {
public:
    char data;
    Tn* childs[26];
    bool isend;

    Tn(char data){
        this->data = data;
        for(int i = 0; i < 26; i++){
            childs[i] = NULL;
        }
        isend = false;
    }
};

class T {   
public:
    Tn* root;

    T() {
        root = new Tn('\0');
    }

    // TC: O(length of word) SC O(1)
    // insert function recursive
    void insertword(Tn* root, string word) {
        if(word.length() == 0) {
            root->isend = 1;
            return;
        }

        int index = word[0] - 'A';
        Tn* child;

        if(root->childs[index] != NULL) {
            child = root->childs[index];
        }
        else {
            child = new Tn(word[0]);
            root->childs[index] = child;
        }

        insertword(child, word.substr(1));
    }


    // TC: O(length of word)
    // search function recursive
    bool searchword(Tn* root, string word) {
        if(word.length() == 0) 
            return root->isend;

        int index = word[0] - 'A';

        if(root->childs[index] != NULL)
           return searchword(root->childs[index], word.substr(1));
        else
            return false;
    }


    // TC: O(length of word)
    // delete function recursive but not complete deletion of nodes
    void Deleteword1(Tn* root, string word) {
        if(word.length() == 0) {
            root->isend = false;
            return;
        }

        int index = word[0] - 'A';

        if(root->childs[index] != NULL) {
            Deleteword1(root->childs[index], word.substr(1));
        }
    }

    // TC: O(length of word)
    // delete function recursive but complete deletion of nodes
    void Deleteword2(Tn* root, string word) {
        if(word.length() == 0) {
            root->isend = false;
            return;
        }

        int index = word[0] - 'A';

        if(root->childs[index] == NULL) {
            return ;
        }
        
        Deleteword2(root->childs[index], word.substr(1));

        // check whether child node can be deleted or not
        Tn* child = root->childs[index];

        if(child == NULL) {
            return;
        }

        if(child->isend == false) {
            for(int i = 0; i < 26; i++) {
                if(child->childs[i] != NULL) {
                    return;
                }
            }
            delete child;
            root->childs[index] = NULL;
        }
    }
};

int main(){
    T* t = new T();

    t->insertword(t->root, "ABCDE");
    t->insertword(t->root, "TIME");
    t->insertword(t->root, "CART");

    cout << "Present: " << t->searchword(t->root, "CART") << endl;
    t->Deleteword1(t->root, "CART");
    cout << "Present: " << t->searchword(t->root, "CART") << endl;

    return 0;
}