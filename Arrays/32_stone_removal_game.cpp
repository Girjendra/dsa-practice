/*
Alice and Bob are playing a game where they take turns removing stones from a pile, with Alice going first.
Alice starts by removing exactly 10 stones on her first turn.
For each subsequent turn, each player removes exactly 1 fewer stone than the previous opponent.
The player who cannot make a move loses the game.
Given a positive integer n, return true if Alice wins the game and false otherwise.

Example 1:
Input: n = 12
Output: true
Explanation:
Alice removes 10 stones on her first turn, leaving 2 stones for Bob.
Bob cannot remove 9 stones, so Alice wins.

Example 2:
Input: n = 1
Output: false
Explanation:
Alice cannot remove 10 stones, so Alice loses.

Constraints:
1 <= n <= 50
*/
#include <stdio.h>
using namespace std;









// TC : O(min(n, 10)) SC : O(1)
class Solution {
public:
    bool canAliceWin(int n) {
        int prev = 11;
        bool alice = true;
        while(true) {
            if(alice) {
                if(n < prev - 1)
                    return false;
            }
            else if(n < prev - 1)
                    return true;

            n -= prev - 1;
            prev--;
            alice = !alice;
        }

        return true;
    }
};










// TC : O(1) SC : O(1)
class Solution {
public:
    bool canAliceWin(int n) {
        return (n >= 10 && n <= 18) ||
                (n >= 27 && n <= 33) ||
                (n >= 40 && n <= 44) ||
                (n >= 49 && n <= 51) ||
                (n == 54);
    }
};