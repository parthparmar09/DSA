#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

static bool cmp(pair<int, int> f, pair<int, int> s)
{
    return f.first > s.first;
}
int knapSack(int W, int wt[], int val[], int n)
{
    vector<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push_back(make_pair(val[i], wt[i]));
    }

    sort(pq.begin(), pq.end(), cmp);
    int profit = 0;

    for (int i = 0; i < n; i++)
    {
        if (pq[i].second <= W)
        {
            profit += pq[i].first;
            W -= pq[i].second;
        }
        else
        {
            break;
        }
    }
    return profit;
}
