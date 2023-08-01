#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


struct Job 
{ 
    int id;	
    int dead; 
    int profit; 
};

static bool cmp(Job f, Job s)
{
    return f.profit > s.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, cmp);

    vector<bool> deadline(n + 1, false);
    vector<int> res(2, 0);

    for (int j = 0; j < n; j++)
    {
        for (int i = arr[j].dead; i > 0; i--)
        {

            if (!deadline[i])
            {
                deadline[i] = true;
                res[0]++;
                res[1] += arr[j].profit;
                break;
            }
        }
    }

    return res;
}