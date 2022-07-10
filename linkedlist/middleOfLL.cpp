#include <iostream>
using namespace std;

// Linked List Node
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
// Inset in to Linked List
void insertAtEnd(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = tail -> next;
    // cout << tail -> data << endl;
}

//find middle of the Linked list
void middle(Node* &head){
    Node* slow = head;
    Node* fast = head;
    int count = 1;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        count++;
    }
    cout << "Middle Element's data: "<< slow->data << " Position: "<<count <<endl;
}

// traversing
void printLL(Node* &head, Node* &tail){
     Node* temp = head;
     while(temp !=NULL){
         cout << temp->data << " ";
         temp = temp->next;
     }
     cout << endl;
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

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtEnd(tail, 10);
    insertAtEnd(tail, 20);
    insertAtEnd(tail, 30);
    insertAtEnd(tail, 50);
    insertAtEnd(tail, 80);
    insertAtEnd(tail, 100);
    printLL(head, tail);
    middle(head);
    return 0;
}