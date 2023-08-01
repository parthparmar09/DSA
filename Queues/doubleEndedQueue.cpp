#include <iostream>
using namespace std;

class Dequeue
{
private:
    int front, rear, size, *arr;

public:
    Dequeue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void push_front(int x)
    {
    }

    void push_back(int x)
    {
        if (rear + 1 == size)
        {
            cout << "Queue overflow" << endl;
            return;
        }
        arr[++rear] = x;

        if (front == -1)
        {
            front++;
        }
        cout << "Pushed" << endl;
    }

    void pop_front()
    {

        if (front == -1)
        {
            cout << "Queue underflow" << endl;
            return;
        }

        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
        cout << "Poped" << endl;
    }

    void pop_back()
    {
    }

    int getFront()
    {
        if (front == -1)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }

        return arr[front];
    }
    int getRear()
    {
        if (rear == -1)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }

        return arr[rear];
    }
    int getSize()
    {
        if (rear == -1)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }
        return rear - front + 1;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
