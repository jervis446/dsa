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

Node* merge(Node* list1, Node* list2) {
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    
    if(list1->data < list2->data)
    {
        list1->next = merge(list1->next,list2);
        return list1;
    }
    else
    {
        list2->next = merge(list1,list2->next);
        return list2;
    }
}