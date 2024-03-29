#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    };
    ~Node(){
        if(this -> next != NULL){
            delete next;
            this->next = NULL;
        }
    };
};

class node {
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    };
    ~Node(){
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
            this -> prev = NULL;
        }
    };
};

// deleting linked List
void deleteAtNode(Node* &head, int pos){
    if(pos == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    } else {
        int count = 1;
        Node* curr = head;
        Node* prev = NULL;
        while(count < pos){
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

//inserting
void insertAtBegin(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}
void insertAtEnd(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = tail -> next;
    // cout << tail -> data << endl;
}
void insetAtPostion(Node* &head, Node* &tail, int data, int pos){
    if(pos == 1){
        insertAtBegin(head, data);
        return;
    }
    int count=1;
    Node* temp = head;
    while(count < pos -1){
        temp = temp -> next;
        count++;
    }
    if(temp->next == NULL){
        insertAtEnd(tail, 100);
        return;
    }
    Node* temp2 = new Node(data);
    temp2->next = temp -> next;
    temp -> next = temp2;

}

// traversing
void printLL(Node* &head, Node* &tail){
     Node* temp = head;
     while(temp !=NULL){
         cout << temp->data << " ";
         temp = temp->next;
     }
     cout << endl;
     cout << "head: " << head->data << endl;
     cout << "tail: " << tail->data << endl;
     return;
}

//reverse
void reverse(Node* &head, Node* &tail){
    Node* curr = head;
    tail = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr != NULL){
        next = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    // debug point
    //cout << "check" << head -> next->data <<endl;
}

//reverse in a group
Node* reverseByGroup(Node* &head, Node* &tail,int k){
    if(head == NULL) return NULL;
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count=0;
    while(curr != NULL && count < k){
        next = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next != NULL){
        head->next = reverseByGroup(next,k);
    }
    return prev;
}

//reverse by recusion
void reverseByRecursion(Node* &head, Node* &curr, Node* &prev){
    if(curr == NULL){
        head = prev;
        return;
    }
    Node* next = curr -> next;
    reverseByRecursion(head, next, curr);
    curr->next = prev;
}

void reverseCall(Node* &head, Node* &tail){
    Node* curr = head;
    Node* prev = NULL;
    tail  = head;
    reverseByRecursion(head, curr, prev);
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtBegin(head, 20);
    insertAtBegin(head, 50);
    // insertAtBegin(head, 60);
    // printLL(head, tail);
    insertAtEnd(tail, 80);
    insertAtEnd(tail, 90);
    insertAtEnd(tail, 100);
    printLL(head, tail);
    //deleteAtNode(head, 5);
    // reverse(head,tail);
    //reverseCall(head, tail);
    // insetAtPostion(head, tail ,120,7);
    head = reverseByGroup(head,tail, 2);
    printLL(head, tail);
    //insetAtPostion(head, tail ,120,6);
    //printLL(head, tail);
    return 0;
}