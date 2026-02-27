#include<iostream>
#include<vector>
using namespace std;

// TC: O(N*min_length) SC O(1)
string longestCommonPrefix(vector<string> &arr, int n) {
    string ans = {};
    int fs = arr[0].size();
    for(int i = 0; i < fs; i++) {
        int flag = true;
        char ch = arr[0][i];
        for(int j = 1; j < n; j++) {
            if(ch != arr[j][i])
                flag = false;
        }

        if(flag == true) {
            ans = ans + ch;
        }
        else
            return ans;
    }
}



// TC = O(N*M) SC O(N*M)
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
            root->isend = true;
            return;
        }

        int index = word[0] - 'a';
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
};

string findpre(Tn* root) {
    string ans = "";

    Tn* chi = root;
    while(chi != NULL) {
        int counts = 0;
        Tn* tempchi = NULL;
        for(int i = 0; i < 26; i++) {
            if(chi->childs[i] != NULL) {
                counts++;
                tempchi = chi->childs[i];
            }
        }
        if(counts == 1) {
            ans += tempchi->data;
            chi = tempchi;
        }
        else
            return ans;
    }
}

string longestCommonPrefix(vector<string> &arr, int n) {
    T* t = new T();
    for(int i = 0; i < n; i++) {
        t->insertword(t->root, arr[i]);
    }

    return findpre(t->root);
}