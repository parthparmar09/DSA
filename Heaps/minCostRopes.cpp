#include <iostream>
#include <queue>
using namespace std;

long long minCost(long long arr[], long long n) {
        // Your code here
        long long sum = 0;
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(int i = 0 ; i < n ; i ++){
            pq.push(arr[i]);
        }
        
        while(n -- > 1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            
            sum+= a+b;
            pq.push(a+b);
        }
        
        
        return sum;
    }