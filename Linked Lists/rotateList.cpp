#include<iostream>
using namespace std;

class ListNode {

    public:
    int data;
    ListNode* next;

    ListNode(int val){
        this -> data = val;
        this -> next = nullptr;
    }
    ListNode(int val , ListNode* head){
        this -> data = val;
        this -> next = head;
    }
};
void print( ListNode * head){
    ListNode* curr = head;
    while(curr != nullptr){
        cout << curr -> data << "   " ;
        curr = curr -> next;
    }
    cout << endl;
    
}

    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        int count = 1;
        ListNode * temp = head;
        while(temp->next != nullptr){
            count++;
            temp = temp -> next;
        }

        temp -> next = head;

        count = count - (k%count);

        int st = 1;
        temp = head;
        while(st < count){
            temp = temp->next;
            st++;
        }

        head = temp -> next;
        temp->next = nullptr;

        return head;

    }

    int main(int argc, char const *argv[])
    {
        
        ListNode * ll = new ListNode(1  , new ListNode(2 , new ListNode (3 , new ListNode(4 , new ListNode(5))) ));
        print(ll);
       print( rotateRight(ll , 2));

        return 0;
    }
    