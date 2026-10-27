#include <bits/stdc++.h>
using namespace std;








// TC O(n + m) SC : O(m)
class Solution {
public:
    void constructLps(string& pat, vector<int>& lsp) {
        int len = 0;
        lsp[0] = 0;
        int i = 1;

        while(i < pat.size()) {
            if(pat[i] == pat[len]) {
                len++;
                lsp[i] = len;
                i++;
            }
            else if(len != 0)
                len = lsp[len - 1];
            else
                lsp[i++] = 0;
        }
    }

    vector<int> search(string &pat, string &txt) {
        int n = txt.length();
        int m = pat.length();

        vector<int> ans;
        vector<int> lsp(m);

        constructLps(pat, lsp);

        int i = 0;
        int j = 0;

        while(i < n) {
            if(txt[i] == pat[j]) {
                i++;
                j++;

                if(j == m) {
                    ans.push_back(i - j);
                    j = lsp[j - 1];
                }
            }
            else if(j != 0)
                j = lsp[j - 1];
            else
                i++;
        }

        return ans;
    }
};