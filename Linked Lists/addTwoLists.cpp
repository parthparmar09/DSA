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


ListNode * addTwoLL(ListNode * l1 , ListNode * l2){


       ListNode *res = new ListNode(-1);
        ListNode *p3 = res;
        int rem = 0;
        int sum = 0;
        while(l1 != nullptr && l2 != nullptr){
            sum = l1 -> data + l2 ->  data + rem;
            p3 -> next = new ListNode(sum%10);
            rem = sum/10;

            l1 = l1 -> next;
            l2 = l2 -> next;
            p3 = p3 -> next;
        }

        while(l1 != nullptr){
            sum = l1 -> data + rem;
            p3 -> next = new ListNode(sum%10);
            rem = sum/10;

            l1 = l1 -> next;
            p3 = p3 -> next;
        }
        while(l2 != nullptr){
            sum = l2 -> data + rem;
            p3 -> next = new ListNode(sum%10);
            rem = sum/10;

            l2 = l2 -> next;
            p3 = p3 -> next;
        }

        if(rem > 0){
             p3 -> next = new ListNode(rem);
        }

        res = res -> next;

        return res;

}



int main(int argc, char const *argv[])
{
    ListNode * l1 = new ListNode(9  , new ListNode(8 , new ListNode (7) ));
    ListNode * l2 = new ListNode(7  , new ListNode(8 , new ListNode (9) ));

    ListNode * res =  addTwoLL(l1, l2);
    print(res);

    return 0;
}
