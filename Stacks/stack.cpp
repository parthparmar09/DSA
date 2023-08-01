#include<iostream>
using namespace std;

class Stack{
    private:
    int *arr;
    int size;
    int top;

    public:

    Stack(int size){
        this -> size =  size;
        this -> arr = new int[size];
        this -> top = -1;
    }

    void push(int val){
        if(top + 1 >= this -> size ){
            cout << "stack overflow" << endl;
            return;
        }

        arr[++top] = val;

    }
    void pop(){
        if(top == -1){
            cout << "stack underflow" << endl;
            return;
        }
        top -- ;
    }
    int peek(){
         if(top == -1){
            cout << "empty stack" << endl;
            return -1;
        }
        return arr[top];

    }
    bool isEmpty(){
       return top == -1;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Stack * s = new Stack(5);
    s->push(10);
    s->push(20);
    s->pop();
    s->pop();
    s->pop();       
                                             

    cout << s->peek() << endl;


    return 0;
}
