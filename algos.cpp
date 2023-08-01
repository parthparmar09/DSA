#include <iostream>
#include <vector>
using namespace std;

void printArr(int arr[], int size)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ",";
    }
    cout << "]" << endl;
}

int linearSearch(int arr[], int size, int x)
{

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int x)
{
    int start = 0, end = size - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int binRecSol(int arr[], int start, int end, int x)
{
    if (start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }

    if (arr[mid] > x)
    {
        return binRecSol(arr, start, mid - 1, x);
    }

    return binRecSol(arr, mid + 1, end, x);
}
int binarySearchRecursive(int arr[], int size, int x)
{
    return binRecSol(arr, 0, size - 1, x);
}

int *minMax(int arr[], int size)
{

    static int res[2] = {arr[0], arr[0]};
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > res[1])
        {
            res[1] = arr[i];
        }
        if (arr[i] < res[0])
        {
            res[0] = arr[i];
        }
    }
    return res;
}

void reverseArr(int arr[], int size)
{
    // using for
    //  int mid = size/2-1;

    // for(int i = 0 ;i <= mid ; i++){
    //     swap(arr[i] , arr[size-i-1])
    // }

    // using while
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        end--;
        start++;
    }
}

void selectionSort(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void countingSort(int arr[], int size, int max)
{
    int countArr[max + 1];
    int outputArr[size];

    for (int i = 0; i <= max; i++)
    {
        countArr[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        countArr[arr[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        countArr[i] += countArr[i - 1];
    }
    for (int i = 0; i < size; i++)
    {
        outputArr[countArr[arr[i]] - 1] = arr[i];
        countArr[arr[i]]--;
    }

    printArr(outputArr, size);
}

void combine(int *arr, int l, int m, int h)
{
    int s1 = m - l + 1, s2 = h - m;
    vector<int> a1(s1), a2(s2);
    for (int k = 0; k < s1; k++)
    {
        a1[k] = arr[l + k];
    }
    for (int k = 0; k < s2; k++)
    {
        a2[k] = arr[m + 1 + k];
    }

    int i = 0, j = 0, k = l;
    while (i < s1 && j < s2)
    {
        if (a2[j] > a1[i])
        {
            arr[k++] = a2[j++];
        }
        else
        {
            arr[k++] = a1[i++];
        }
    }
    while (i < s1)
    {
        arr[k++] = a1[i++];
    }
    while (j < s2)
    {
        arr[k++] = a2[j++];
    }
}
void mergeSort(int *arr, int l, int h)
{
    if (l < h)
    {
        int m = l + (h - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);
        combine(arr, l, m, h);
    }
}


int partition(int *arr , int l , int h ){
    int pivot = arr[h];
    int i = l-1;
    for(int j = l ; j <= h ;j++){
        if(arr[j] < pivot){
            swap(arr[j] , arr[++i]);
        }
    }
    swap(arr[i+1] , arr[h]);

    return i+1;
}
void quickSort(int *arr , int l ,int h){
    if(l < h){
        int pi = partition(arr , l , h);
        quickSort(arr , l , pi-1);
        quickSort(arr , pi+1 , h);
    }
}


int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // int * res = minMax(arr , 10);
    // cout << "minmax ::: min = " <<res[0] << "max = " <<res[1]  << endl;

    // reverseArr(arr , 10);
    // cout << "reversed array ::: [";
    // for(int i = 0 ;i < 10 ; i++){
    //     cout << arr[i] << " , ";
    // }
    // cout << "]" << endl;
    // binary search
    // cout <<"using linear search :" << linearSearch(arr ,10, 111) << endl;
    // cout << "using binary search :" << binarySearch(arr2 , 10 , 111) << endl;
    // cout << "using binary search(Recursive) :" << binarySearch(arr2 , 10 , 2) << endl;

    // selection sort
    //  int arr3[8] = {7,6,5,4,3,2,1,0};
    //  selectionSort(arr3 , 8);
    //  printArr(arr3 , 8);

    // insertion sort
    //  int arr4[8] = {7,6,5,1,3,4,5,3};
    //  insertionSort(arr4 , 8);
    //  printArr(arr4 , 8);

    // bubble sort
    // int arr5[8] = {7,6,5,4,3,2,1,0};
    // bubbleSort(arr5 , 8);
    // printArr(arr5 , 8);

    // counting sort
    // int arr6[8] = {7,6,5,4,7,2,1,0};
    // countingSort(arr6 , 8  , 7);

    // // merge sort
    // int arr7[8] = {7, 6, 5, 4, 7, 2, 1, 0};
    // mergeSort(arr7 , 0 , 7);
    // printArr(arr7 , 8);

    // // quick sort
    // int arr8[8] = {7, 6, 5, 4, 7, 2, 1, 0};
    // quickSort(arr8 , 0 , 7);
    // printArr(arr8 , 8);
    // return 0;
}
