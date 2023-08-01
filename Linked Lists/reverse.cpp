#include<iostream>
#include<map>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = nullptr;
    }
} ;

Node* reverse(Node* head){
        Node * prev =  nullptr;
        Node * curr =  head;

        while(curr != nullptr){
            Node * temp = curr -> next;
            curr -> next = prev;

            prev =  curr;
            curr =  temp;
        }
        
        return prev;

    }