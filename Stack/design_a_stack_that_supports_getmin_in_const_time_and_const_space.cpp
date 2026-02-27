// /*
// Create a stack data structure that allows operations such as push (adding an element),
// pop (removing the top element), top (retrieving the top element), and also provides
// a way to retrieve the minimum element in constant time.
// */

// #include<bits/stdc++.h>
// using namespace std;

// class SpecialStack {
//     private:
//         stack<int> mainst;
//         stack<int> subst;
//     public:
//         void push(int data) {
//             mainst.push(data);

//             if(subst.empty()) 
//                 subst.push(data);  
//             else
//                 subst.push(min(data,subst.top()));
//         }

//         void pop() {
//             if(mainst.empty()) 
//                 return ;

//             mainst.pop();
//             subst.pop();
//         }

//         int top() {
//             if(mainst.empty()) 
//                 return -1;

//             return mainst.top();
//         }

//         int getMin() {
//             if(mainst.empty()) 
//                 return -1;

//             return subst.top();
//         }
// };
// int main() {
//     SpecialStack s;
//     s.push(5);
//     s.push(2);
//     s.push(8);
//     s.push(1);

//     cout << "Top: " << s.top() << endl;      // Should print 1
//     cout << "Min: " << s.getMin() << endl;   // Should print 1

//     s.pop();
//     cout << "Top: " << s.top() << endl;      // Should print 8
//     cout << "Min: " << s.getMin() << endl;   // Should print 2

//     s.pop();
//     cout << "Top: " << s.top() << endl;      // Should print 2
//     cout << "Min: " << s.getMin() << endl;   // Should print 2

//     s.pop();
//     cout << "Top: " << s.top() << endl;      // Should print 5
//     cout << "Min: " << s.getMin() << endl;   // Should print 5

//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
class SpecialStack {
    private:
        stack<int> st;
        int mini;
    public:

        void push(int data) {
            if(st.empty()) {
                st.push(data);
                mini = data;
            }
            else{ 
                if(mini > data) {
                    st.push(2*data - mini);
                    mini = data;
                }
                else {
                    st.push(data);
                }
            } 
        }

        void pop() {
            if(st.empty()) 
                return ;
            
            int current = st.top();
            st.pop();

            if(current < mini) {
                mini = 2*mini - current;
            }
        }

        int top() {
            if(st.empty()) 
                return -1;
            
            int current = st.top();
            if(current < mini) {
                return mini;
            }
            else {
                return current;
            }
        }

        int getMin() {
            if(st.empty()) 
                return -1;

            return mini;
        }
};
int main() {
    SpecialStack s;

    s.push(5);
    s.push(2);
    s.push(8);
    s.push(1);

    cout << "Top: " << s.top() << endl;      // Should print 1
    cout << "Min: " << s.getMin() << endl;   // Should print 1

    s.pop();
    cout << "Top: " << s.top() << endl;      // Should print 8
    cout << "Min: " << s.getMin() << endl;   // Should print 2

    s.pop();
    cout << "Top: " << s.top() << endl;      // Should print 2
    cout << "Min: " << s.getMin() << endl;   // Should print 2

    s.pop();
    cout << "Top: " << s.top() << endl;      // Should print 5
    cout << "Min: " << s.getMin() << endl;   // Should print 5

    return 0;
}
