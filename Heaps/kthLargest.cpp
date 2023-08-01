#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    class MinHeap
    {
    private:
        vector<int> heap;

        void heapifyUp(int index)
        {
            if (index <= 1)
                return;
            int parent = index / 2;

            if (heap[parent] > heap[index])
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

            if (left < size && heap[left] < heap[larger])
            {
                larger = left;
            }
            if (right < size && heap[right] < heap[larger])
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
        MinHeap()
        {
            heap.push_back(-1);
        }

        void insert(int val)
        {
            heap.push_back(val);
            heapifyUp(heap.size() - 1);
        }

        int top()
        {
            return heap[1];
        }

        int extractMin()
        {
            int min = heap[1];
            swap(heap[1], heap[heap.size() - 1]);
            heap.pop_back();
            heapifyDown(1);
            return min;
        }
    };

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        MinHeap h;
        for (int i = k - 1; i >= 0; i--)
        {
            h.insert(nums[i]);
        }

        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > h.top())
            {
                h.extractMin();
                h.insert(nums[i]);
            }
        }

        return h.top();
    }
};