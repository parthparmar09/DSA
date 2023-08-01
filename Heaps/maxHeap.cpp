#include <iostream>
#include <vector>
using namespace std;

// in max heap - all childs are smaller than the parent nodes
// parent of i = (i/2)
// left child of i = 2*i;
// right child of i = 2*i +1;

class MaxHeap
{
private:
    vector<int> heap;

    void heapifyUp(int index)
    {
        if(index <= 1) return;
        int parent = index / 2;

        if (heap[parent] < heap[index])
        {
            swap(heap[parent], heap[index]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index)
    {
        int size = heap.size();
        int left = 2 * index;
        int right = 2 * index + 1;
        int larger = index;

        if (left < size && heap[left] > heap[larger])
        {
            larger = left;
        }
        if (right < size && heap[right] > heap[larger])
        {
            larger = right;
        }

        if (index != larger)
        {
            swap(heap[larger], heap[index]);
            heapifyDown(larger);
        }
    }

public:
    MaxHeap()
    {
        heap.push_back(-1);
    }

    void insert(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void print()
    {
        for (int i = 1; i < heap.size(); i++)
        {
            cout << heap[i] << " , ";
        }
        cout << endl;
    }

    int extractMax()
    {
        int max = heap[1];
        swap(heap[1], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(1);
        return max;
    }
};


int main(int argc, char const *argv[])
{

    MaxHeap mh;
    mh.insert(10);
    mh.insert(20);
    mh.insert(30);
    mh.insert(40);
    mh.insert(50);

    mh.print();


    return 0;
}
