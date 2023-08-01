#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// to find the maximum number of meetings that can
// be performed in a meeting room.
int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(make_pair(end[i], start[i]));
    }

    int meetings = 1;
    int prevEnd = pq.top().first;
    pq.pop();

    while (!pq.empty())
    {
        pair<int, int> curr = pq.top();
        pq.pop();

        if (curr.second > prevEnd)
        {
            meetings++;
            prevEnd = curr.first;
        }
    }
    return meetings;
}


//to find the minimum number of arrows required to burst all balloons in a plane  , where for each ballon 'i' , points[i] = [xStart , xEnd];
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), cmp);
    int arrows = 1;
    int prev = 0;
    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] > points[prev][1])
        {
            arrows++;
            prev = i;
        }
    }
    return arrows;
}