#include<iostream>
using namespace std;

class ListNode {

    public:
    int val;
    ListNode* next;

    ListNode(int val){
        this -> val = val;
        this -> next = nullptr;
    }
    ListNode(int val , ListNode* head){
        this -> val = val;
        this -> next = head;
    }
};
void print(ListNode * head){
        ListNode* curr = head;
        while(curr != nullptr){
            cout << curr -> val << "   " ;
            curr = curr -> next;
        }
        cout << endl;
        
    }

ListNode* findMid(ListNode* head) {
    if (!head) return NULL;
    ListNode* slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode * merge(ListNode* left , ListNode * right){

    ListNode * dummy = new ListNode(-1);
    ListNode * temp = dummy;

    while(left != nullptr && right != nullptr){
        if(left -> val > right -> val){
            temp -> next = right;
            right = right -> next;
        }else{
            temp -> next = left;
            left = left -> next;
        }

        temp = temp -> next;
    }

    if(left != nullptr){
        temp -> next = left;
    }
    if(right != nullptr){
        temp -> next = right;
    }

    return dummy -> next;
}
ListNode * mergeSort(ListNode * head){
    if(head == nullptr || head -> next == nullptr){
        return head;
    }

    ListNode * mid = findMid(head);
    ListNode * left = head;
    ListNode * right = mid -> next;
    mid -> next = nullptr;

    left = mergeSort(left);
    right = mergeSort(right);
    
    return merge(left , right);

}



int main(int argc, char const *argv[])
{
    /* code */

    ListNode * ll =  new ListNode(40 ,new ListNode(30, new ListNode(20 ,new ListNode(10 , new ListNode(5 )) )) );

    ll =  mergeSort(ll);
    print(ll);

    return 0;
}
