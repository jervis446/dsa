#include <iostream>
using namespace std;


// stack implementation using linked list;
class Node {
    public: 
        int data;
        Node* next;
        Node(int d) {
            this->data = d;
            this->next = NULL;
        } 
};
Node* top = NULL;

void push(int data) {
    Node* temp = new Node(data);

    if(!temp) {
        cout << "Stack Overflow" << endl;
        return;
    }
    temp -> next = top;
    top = temp;
}

void pop() {
    if(top == NULL) {
        cout << "Stack Underflow" <<endl;
        return;
    }

    Node* temp = top;
    top = top->next;
    free(temp);
}
bool isEmpty() {
    if(top == NULL) {
        return true;
    }
    else {
        return false;
    }
}
int peek() {
    if(isEmpty()) {
        return -1;
    }
    else {
        return top->data;
    }
}

void display() {
    if(top == NULL) {
        cout << "Stack is Empty" <<endl;
        return;
    }
    Node* temp = top;
    while(temp!=NULL) {
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

// stack implementation using array;

class Stack {
    public: 
        int *arr;
        int size;
        int top;
        Stack(int d) {
            this->size = d;
            arr = new int[size];
            this->top = -1;
        }
        void push(int d) {
            if(size-top>1) {
                top++;
                arr[top] = d;
            }
            else {
                cout << "Stack OverFlow" << endl;
            }
        }
        bool isEmpty() {
            if(top == -1)
                return true;
            else 
                return false;
        }
        void pop() {
            if(top >= 0) {
                top--;
            } else {
                cout << "Stack is empty" <<endl;
            }
        }
        int peek() {
            if(top >= 0)
                return arr[top];
            else return top;
        }
};

int main() {

    display();
    push(34);
    push(35);
    push(24);
    pop();
    display();
    int d = peek();
    cout << d <<endl;
    // Stack st(5);
    // st.pop();
    // st.push(45);
    // st.push(72);
    // st.push(12);
    // // st.push(45);
    // // st.push(72);
    // // st.push(12);

    // st.pop();
    // int d = st.peek();
    // cout << d << endl;

}