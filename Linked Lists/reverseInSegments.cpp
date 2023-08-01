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

ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * prev =  nullptr;
        ListNode * curr =  head;
        ListNode * temp = nullptr;

        int count = 0;

        while(curr != nullptr && count < k){
            temp = curr -> next;
            curr -> next = prev;

            prev =  curr;
            curr =  temp;

            count++;
        }


        if(curr != nullptr){
            head -> next = reverseKGroup(curr, k);
        }

        return prev;

}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
