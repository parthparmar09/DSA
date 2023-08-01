#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // your code here
    vector<int> res;
    for (auto i : a)
    {
        res.push_back(i);
    }
    for (auto i : b)
    {
        res.push_back(i);
    }

    n = res.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(res, n, i);
    }

    return res;
}