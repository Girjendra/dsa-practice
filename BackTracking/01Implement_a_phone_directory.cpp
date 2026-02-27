/*
Problem statement
You are given a list/array of strings which denotes the contacts that exist in your phone directory.
The search query on a string ‘str’ which is a query string displays all the contacts which are present
in the given directory with the prefix as ‘str’. One special property of the search function is that
when a user searches for a contact from the contact list then suggestions (contacts with prefix as the
string entered so for) are shown after the user enters each character.
*/

#include<iostream>
using namespace std;
#include<vector>
#include<string>
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

    void printsuggestions(Tn* cur, vector<string>& temp, string prefix) {
        if(cur->isend)
            temp.push_back(prefix);

        for(char ch = 'a'; ch <= 'z'; ch++) {
            Tn* next = cur->childs[ch - 'a'];

            if(next) {
                prefix.push_back(ch);
                printsuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getsuggestions(string str) {
        Tn* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for(int i = 0; i < str.size(); i++) {
            char laschar = str[i];

            prefix += laschar;
            Tn* cur = prev->childs[laschar - 'a'];

            if(cur == NULL)
                break;
            
            vector<string> temp;
            printsuggestions(cur, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = cur;
        }

        return output;
    }
};


vector<vector<string>> phoneDirectory(vector<string>& contactList, string &queryStr) {
    T* t = new T();
    int size = contactList.size();
    for(int i = 0 ; i < size; i++) {
        t->insertword(t->root, contactList[i]);
    }

    return t->getsuggestions(queryStr);   
}