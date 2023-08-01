#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = nullptr;
    }
} ;

class CircularLinkList{
public:
    Node * head;

    CircularLinkList(){
        this ->  head = nullptr;
    }

    void insertAtBegining( int val){
        Node * newNode =  new Node(val);
        if(this -> head == nullptr){
            this -> head = newNode;
            head -> next =  head;
            return;
        }

        newNode -> next = head;
        this -> head =  newNode;

        Node * curr = head;
        while(curr -> next != head){
            curr = curr -> next;
        }
        curr -> next = newNode;

    }

    void insertAtEnd(int val){
        Node * newNode =  new Node(val);
        newNode -> next =  head;

        Node * curr = head;
        while(curr -> next != head){
            curr = curr -> next;
        }
        curr -> next = newNode;

    }

    void insertAt(int val  , int index){
        Node* newNode =  new Node(val);
        
        Node* curr = head;
        int count = 0;
        while(count < index-1){
            curr = curr -> next;
            count++;
        }
        newNode -> next = curr -> next;
        curr -> next = newNode ; 
    }

    void deleteNode(int val){
        
    }

    void print(){
        Node* curr = this -> head;
        while(curr != nullptr){
            cout << curr -> data << "   " ;
            curr = curr -> next;
        }
        cout << endl;
        
    }

    int size(){
        int count = 1;
        Node* curr = this -> head;
        while(curr -> next != nullptr){
            curr = curr -> next;
            count++;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    CircularLinkList* cll =  new CircularLinkList();



    return 0;
}