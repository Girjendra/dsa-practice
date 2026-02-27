#include<bits\stdc++.h>
using namespace std;
class Heap{
public:
    int arr[100];
    int size;
    Heap(){
        arr[0]=-1;
        size=0;
    }
    
    // Function to print the heap
    void print() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    // Function to insert an element into the heap
    void insert(int vlaue) {
        size++;
        int index = size;
        arr[index] = vlaue;
        while(index > 1) {
            int parent = index / 2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return ;           
        }
    }

    // Function to delete the root element from the heap
    void Delete() {
        if(size == 0) {
            cout << "Nothing to delete" << endl;
            return ;
        }

        // Step 1: Put the last element into the root
        arr[1] = arr[size];
        
        //  Step 2: Remove the last element
        size--;

        // Step 3: Take root to its correct position
        int i = 1;
        while(i <= size) {
            int largest = i;
            int lindex = 2*i;
            int rindex = 2*i + 1;

            if(lindex <= size && arr[lindex] > arr[largest])
                largest = lindex;
            if(rindex <= size && arr[rindex] > arr[largest])
                largest = rindex;
            
            if(largest != i) {
                swap(arr[largest], arr[i]);
                i = largest;
            }
            else
                return ;
        }
    }
};

void heapify(int arr[], int size, int index) {
    int largest = index;
    int leftindex = 2*largest;
    int rihgtindex = 2*largest + 1;

    if(leftindex <= size && arr[leftindex] > arr[largest]) {
        largest = leftindex;
    }
    if(rihgtindex <= size && arr[rihgtindex] > arr[largest]) {
        largest = rihgtindex;
    }

    if(largest != index) {
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }
}

// Heap Sort function
void heapsort(int* arr, int size) {
    int temp = size;
     
    while(temp > 1) {
        swap(arr[temp], arr[1]);
        temp--;

        heapify(arr, temp, 1);
    }
}

int main(){
    Heap h;

    // Inserting elements into the heap
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();

    // Deleting elements from the heap
    // h.Delete();
    // h.print();


    // Heapify an array
    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i > 0; i--) {
        heapify(arr, n, i);
    }
    cout << "Printing heap now:\n";
    for(int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
    

    // Heap Sort
    
    // int arr[] = {-1, 54, 34, 55, 42, 50};
    // int n = 5;
    // for(int i = n/2; i > 0; i--) {
    //     heapify(arr, n, i);
    // }

    // // Performing heap sort
    // heapsort(arr, n);

    // // Printing sorted array
    // for(int i = 1; i <= n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;




    return 0;
}