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
        this -> prev = nullptr;
    }
} ;

class DoublyLinkList{
public:
    Node * head;

    DoublyLinkList(){
        this ->  head = nullptr;
    }

    void insertAtBegining( int val){
        Node * newNode =  new Node(val);

        if(head != nullptr){
        head -> prev = newNode;
        }

        newNode ->next = this -> head;
        this -> head = newNode;

  
    }

    void insertAtEnd(int val){
        Node * newNode =  new Node(val);

        Node * curr = this -> head;
        while(curr -> next != nullptr){
            curr = curr -> next;

        }

        curr->next = newNode;
        newNode -> prev = curr;
     
    }

    void insertAt(int val  , int index){
        Node * newNode =  new Node(val);

        Node * curr = this -> head;
        int count = 0;
        while(count < index -1){
            curr = curr -> next;
            count++;
        }
        Node * temp = curr ->next;
        temp -> prev = newNode;
        curr -> next = newNode;
        newNode -> prev = curr;
        newNode -> next = temp;

       
    }

    void deleteNode(int val){
        if(head == nullptr){
            cout << "List is already empty" << endl ;
            return;
        }

        if(head -> data == val){
            Node * temp = head;
            head = temp ->next;
            head -> prev = nullptr;
            delete temp;
            cout << "Node deleted" << endl;

        }
       Node * curr = head;
        while(curr -> next != nullptr){

            if(curr -> data == val){
                Node *currPrev = curr -> prev;
                Node *currNext = curr -> next;
                currPrev -> next= currNext;
                currNext -> prev = currPrev;
                delete curr;
                 cout << "Node deleted" << endl;

                return;
            }
            curr = curr -> next;

        }

        cout << "No node found" << endl;
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
    DoublyLinkList* dll =  new DoublyLinkList();
    dll->insertAtBegining(10);
    dll->insertAtBegining(20);
    dll->insertAtBegining(30);
    dll->insertAtEnd(40);
    dll->insertAtEnd(50);
    dll->insertAtEnd(60);
    dll->insertAt(79,3);
    dll->insertAt(89,3);
    dll->deleteNode(40);
    dll->print();
    cout << dll->size() << endl;



    return 0;
}