#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int value;
    int weight;
};

static bool cmp(pair<double, Item> f , pair<double, Item> s){
    return f.first > s.first;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    vector<pair<double, Item>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push_back(make_pair((1.0*arr[i].value)/ arr[i].weight, arr[i]));
    }

    sort(pq.begin(), pq.end(), cmp);
    double profit = 0;
    for(int i = 0 ; i < n ; i++){

        int w = pq[i].second.weight, p = pq[i].second.value;

        if (w <= W)
        {
            profit += p;
            W -= w;
        }
        else
        {
            profit += W * pq[i].first;
            break;
        }
    }

    return profit;
}

int main(int argc, char const *argv[])
{
    Item arr[3];
    arr[0].value = 60;
    arr[0].weight = 10;
    arr[1].value = 100;
    arr[1].weight = 20;
    arr[2].value = 120;
    arr[2].weight = 30;

    cout << fractionalKnapsack(50 , arr , 3) << endl;
    return 0;
}
