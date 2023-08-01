#include<iostream>
using namespace std;

class Queue{
    private : 
    int front ,rear ,*arr ,size;

    public:

    Queue(int s){
        arr = new int[s];
        front = rear = -1;
        size = s;
    }

    void push(int x){
        if(rear+1 == size){
            cout << "Queue overflow" << endl;
            return;
        }
        arr[++rear] = x;

        if(front == -1){
            front++;
        }

        cout << "Pushed" << endl;

    }

    void pop(){
        if(front == -1){
            cout << "Queue underflow" << endl;
            return;
        }

        front++;
        if(front > rear){
            front = rear = -1;

        }
        cout << "Poped" << endl;

    }

    int getFront(){
        if(front == -1){
            cout << "Queue underflow" << endl;
            return -1;
        }

        return arr[front];

    }
    int getRear(){
        if(rear == -1){
            cout << "Queue underflow" << endl;
            return -1;
        }

        return arr[rear];

    }
    int getSize(){
         if(rear == -1){
            cout << "Queue underflow" << endl;
            return -1;
        }
        return rear-front +1;
        
    }

};

int main(int argc, char const *argv[])
{
    /* code */
    Queue  *q =  new Queue(6);
    q->push(10);
    q->push(20);
    q->push(30);
    q->push(40);
    q->push(40);
    q->push(40);
    q->push(40);
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    q->pop();

    cout << q->getFront() << endl;
    cout << q->getRear() << endl;
    cout << q->getSize() << endl;
    return 0;
}
