#include <iostream>
using namespace std;

class heap {
    public:
        int arr[100];
        int size;
    
    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int n) {
       size++;
       int index = size;
       arr[size] = n;
       while(index > 1) {
           int parent = index/2;
           if(arr[parent] < arr[index]) {
               swap(arr[parent], arr[index]);
               index = parent; // now index parent ko point karega, jisse vo aage kaa condition match karega
           } else {
               return ;
           }
       }
    }

    void deleteNode() {
        if(size == 0) {
            cout << "Go back simmon, nothing is here!" <<endl;
            return ;
        }
        arr[1] = arr[size];
        size--;

        //propogate root node to its correct position
        int index = 1;
        while(index < size) {
            int left = 2*index;  //find left children
            int right = 2*index + 1; // find right children
            // check if children's are less than size and if its value is greater than parent than swap
            if(left < size && arr[index] < arr[left]) {
                swap(arr[index], arr[left]);
                index = left;
            }
            if(right < size && arr[index] < arr[right]) {
                swap(arr[index], arr[right]);
                index = right;
            } else {
                return ;
            }
        }

    }

    void print() {
        for(int i=1;i<=size;i++) {
            cout << arr[i] <<" ";
        }
        cout << endl;
    }
};

int main () {
    heap t;
    t.insert(60);
    t.insert(50);
    t.insert(55);
    t.insert(30);
    t.insert(20);
    t.insert(70);
    t.print();
    t.deleteNode();
    t.print();
}