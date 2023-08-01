#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int val){
        this -> data = val;
        this -> next = nullptr;
    }
    Node(int val , Node* head){
        this -> data = val;
        this -> next = head;
    }
};

int findMiddle(Node* head) {
    if (!head) return NULL;
    Node* slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow -> data;
}

int main(int argc, char const *argv[])
{
    Node * ll = new Node(9 , new Node(8 , new Node(12)));
    cout << findMiddle(ll) << endl;

    return 0;
}
