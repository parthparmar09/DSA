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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {


        if(list1 == nullptr){
            return list2;
        } 
        if(list2 == nullptr){
            return list1;
        }

        ListNode * head = new ListNode(-1);
        ListNode * temp = head;

        while(list1 !=nullptr && list2 != nullptr){
            if(list1 -> val > list2 -> val){
                temp -> next = new ListNode(list2 -> val);
                list2 = list2 -> next;
            }else{
                temp -> next = new ListNode(list1 -> val);
                list1 = list1 -> next;
            }

            temp = temp -> next;
        }

        while(list1 != nullptr){
            temp -> next = new ListNode(list1 -> val);
            list1 = list1 -> next;
            temp = temp -> next;

        }
        while(list2 != nullptr){
            print(head);
            temp -> next = new ListNode(list2 -> val);
            list2 = list2 -> next;
            temp = temp -> next;
        }


        return head -> next; 

    }


int main(int argc, char const *argv[])
{
    /* code */

    ListNode * l1 = new ListNode(2 , new  ListNode(3 , new ListNode(4)) );
    ListNode * l2 = new ListNode(5 , new ListNode(7 , new ListNode(8)));

    ListNode * l3 = mergeTwoLists(l1 , l2);
    print(l3);
    return 0;
}
