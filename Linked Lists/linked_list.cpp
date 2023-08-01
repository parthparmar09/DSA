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

class LinkList{

public:
    Node * head;

    LinkList(){
        this ->  head = nullptr;
    }

    void insertAtBegining( int val){
        Node* newNode = new Node(val);
        newNode -> next = this -> head;
        this -> head =  newNode;

    }

    void insertAtEnd(int val){
        Node* newNode =  new Node(val);
        
        Node* curr = head;
        Node *prev = head;
        while(curr != nullptr){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = newNode;

    }

    void insertAt(int val  , int index){
        Node* newNode =  new Node(val);
        
        Node* curr = head;

        if(head == nullptr && index == 0){
            head = newNode;
            return;
        }

        int count = 0;
        while(count < index-1){
            if(curr ==  nullptr){
                cout << "Index unavailable" << endl;
                return;
            }
            curr = curr -> next;
            count++;
        }
        newNode -> next = curr -> next;
        curr -> next = newNode ;

    }

    void deleteNode(int val){
        if(head == nullptr){
            cout << "List is already empty" << endl ;
            return;
        }

        if(head -> data == val){
            Node * temp = head;
            head = temp ->next;
            delete temp;
            cout << "Node deleted" << endl;

        }
        Node * curr = head;
        Node * prev = nullptr;
        while(curr -> next != nullptr){

            if(curr -> data == val){
                prev -> next = curr -> next;
                delete curr;
                cout << "Node deleted" << endl;

                return;
            }
            prev = curr;
            curr = curr -> next;

        }

        cout << "No node found" << endl;
    }

    void print(){
        Node* curr = head;
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

    void reverse(){
        Node * prev =  nullptr;
        Node * curr =  head;

        while(curr != nullptr){
            Node * temp = curr -> next;
            curr -> next = prev;

            prev =  curr;
            curr =  temp;
        }

        this -> head = prev;

    }

    //reverse in k groups
    Node* reverseInK(int k , Node * head){

        Node * prev =  nullptr;
        Node * curr =  head;
        Node * temp = nullptr;

        int count = 0;

        while(curr != nullptr && count < k){
            temp = curr -> next;
            curr -> next = prev;

            prev =  curr;
            curr =  temp;

            count++;
        }


        if(curr != nullptr){
            head -> next = this->reverseInK(k, curr);
        }
        this -> head =  prev;
        return prev;

    }
};

bool checkCircular(LinkList * ll){
    Node * curr = ll -> head;

    while(curr != nullptr){
        curr = curr -> next;
        if(curr == ll -> head){
            return true;
        }
    }

    return false;
}

bool detectLoop( LinkList *ll){
    map<Node * , bool> mp;
    Node* curr = ll -> head;

    while(curr != nullptr){

        if(mp[curr] == true){
            //can also return 'curr' or index using count
            //can also remove loop by going back one step and mark prev -> next = null
            return true;
        }
        mp[curr] = true;
        curr =  curr -> next;

    }
    return false;
}

bool floydLoopDetect(LinkList *ll){
    Node * slow = ll -> head;
    Node * fast = ll -> head;

    while (fast != nullptr)
    {
        if(fast == slow){
            return true;
        }

        slow = slow -> next;
        fast = fast -> next;
        
        if(fast != nullptr){
            fast = fast -> next;
        }

    }

    return false;
    
}

void removeDuplicatesSorted(LinkList * ll){
    Node * curr = ll -> head;
    Node * temp = nullptr;
    while(curr != nullptr){
        temp = curr -> next;
        if((temp != nullptr) && (curr -> data == temp -> data)){
            curr -> next = temp -> next;
            delete temp;
        }
        curr = curr -> next;
    }

}

void removeDuplicatesUnsorted(LinkList * ll){
    map <int , bool> mp;

    Node * curr = ll -> head;
    Node * prev = nullptr;
    Node * temp = nullptr;

    while(curr != nullptr){
        if(mp[curr -> data] ){
            temp = curr;
            prev-> next = temp -> next;
            delete temp;
        }else{
            mp[curr ->data] = true;
        }

        prev =  curr;
        curr = curr -> next;
    }

}

int main(int argc, char const *argv[])
{
    /* code */

    LinkList* ll = new LinkList();
    ll->insertAtBegining(10);
    ll->insertAtBegining(20);
    ll->insertAtBegining(20);
    ll->insertAtBegining(30);
    ll->insertAtBegining(50);
    ll->insertAtBegining(50);
    // ll->insertAtEnd(49);
    // ll->insertAtEnd(59);
    // ll->insertAtEnd(69);
    // ll->insertAt(40 , 3);
    // ll->insertAt(233 , 3);
    // ll->deleteNode(10);
    ll->print();
    // ll->reverse();
    // ll->print();
    // ll->reverseInK(3 , ll->head);
    // ll->print();
    removeDuplicatesSorted(ll);
    // removeDuplicatesUnsorted(ll); //incomplete
    ll->print();
    cout << ll->size() << endl;


    return 0;
}
