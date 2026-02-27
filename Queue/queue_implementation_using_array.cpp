// #include<iostream>
// #include<queue>
// using namespace std;
// class Queue {
//     int* queue;
//     int size;
//     int front;
//     int back;

// public:

//     // Contructor
//     Queue(int size) {
//         this->size = size;
//         queue = new int[this->size];
//         this->front = -1;
//         this->back = -1; 
//     }

//     // Destructor
//     ~Queue() {
//         delete[] queue;
//     }

//     //To Push elements in back
//     void push(int elem) {
//        if(back == size - 1) {
//             cout << "Queue overflow" << endl;
//             return ;
//         }

//         // If initialy queue is empty
//         if (front == -1) front = 0;

//         // Normal pushing
//         back++;
//         queue[back] = elem;
//     }
    
//     // To Pop elements from front
//     void pop() {

//         // If queue is empty
//         if(front == -1 && back == -1) {
//             cout << "Queue underflow" << endl;
//             return ;
//         }

//         // If last element is being poped
//         if(back == 0) {
//             back = -1;
//             front = -1;
//             return ;
//         }

//         // Normal poping
//         for(int i = 0; i < back; i++) {
//             queue[i] = queue[i + 1];
//         }
//         back--;
//     }

//     // To get size of current queue
//     int Size() {
//         if(this->size == 0 || front == -1)
//             return 0;
        
//         return back + 1;
//     }

//     // Checking if queue is empty
//     bool empty() {
//         return front == -1;
//     }


//     // To get front element of queue
//     int Front() {
//         if(front == -1) {
//             cout << "Queue is empty" << endl;
//             return -1;
//         }
//         else 
//             return queue[front];
//     }
    

//     // To get last element of queue
//     int Back(){
//         if(back == -1) {
//             cout << "Queue is empty" << endl;
//             return -1;
//         }
//         return queue[back];
//     }
// };

// int main() {
//     Queue q(5);

//     q.pop(); // underflow
//     q.push(10);
//     q.push(20);
//     q.push(30);
//     cout << q.Front() << endl; // 10
//     cout << q.Back() << endl;  // 30
//     cout << q.Size() << endl;  // 3
//     q.pop();
//     cout << q.Front() << endl; // 20
//     q.push(40);
//     q.push(50);
//     q.push(60);
//     q.push(70); // should overflow here
//     cout << q.Size() << endl;  // 5
// }






#include<iostream>
#include<queue>
using namespace std;
class Queue {
    int* arr;
    int qfront;
    int rear;
    int size;
public:

    // Contructor
    Queue() {
        size = 10001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    // o(1)
    //To Push elements in back
    void push(int data) {
        if(rear == size) {
            return ;
        }
        else { 
            arr[rear] = data;
            rear++;
        }
    }
    
    // o(1)
    // To Pop elements from front
    void pop() {
        if(rear == qfront){
            cout << "Queue underflow" << endl;
            return ;
        }
        else {
            arr[qfront] = -1;
            qfront++;
            if(rear == qfront) {
                rear = 0;
                qfront = 0;
            }
        }
    }

    // o(1)
    // To get size of current queue
    int Size() {
        if(rear == qfront)
            return -1;
        
        return rear - qfront;
    }

    // o(1)
    // Checking if queue is empty
    bool empty() {
        if(rear == qfront) {
            return true;
        }
        else {
            return false;
        }
    }


    // o(1)
    // To get front element of queue
    int Front() {
        if(rear == qfront) {
            return -1;
        }
        else {
            return arr[qfront];
        }
    }
    

    // o(1)
    // To get last element of queue
    int Back(){
        if(rear == qfront) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear-1];
    }
};

int main() {
    Queue q;

    q.pop(); // underflow
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.Front() << endl; // 10
    cout << q.Back() << endl;  // 30
    cout << q.Size() << endl;  // 3
    q.pop();
    cout << q.Front() << endl; // 20
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    cout << q.Size() << endl; // 7
}