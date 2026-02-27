// #include <iostream>
// using namespace std;
// int main() {
//     int choice;
//     while (true) {
//         cout << "\n1. Say Hello\n2. Say Bye\n3. Exit\nEnter choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Hello!" << endl;
//                 break;
//             case 2:
//                 cout << "Bye!" << endl;
//                 break;
//             case 3:
//                 cout << "Exiting loop..." << endl;
//                 // return 0;  // OR use `break` if no other code after loop
//                 exit (0);     // exiting the loop
//             default:
//                 cout << "Invalid choice!" << endl;
//         }
//     }
//     return 0;
// }


#include <iostream>
using namespace std;
int main() {
    int choice;
    for(int i=0;i<5;i++){
        cout << "\n1. Say Hello\n2. Say Bye\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            continue;
                cout << "Hello!" << endl;
                cout << "Hello!" << endl;
                cout << "Hello!" << endl;
                cout << "Hello!" << endl;
                break;
            case 2:
                cout << "Bye!" << endl;
                break;
            case 3:
                cout << "Exiting loop..." << endl;
            
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
