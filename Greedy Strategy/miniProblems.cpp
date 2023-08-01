#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// buying a candy gives K candies for free
// goal is to find the minimun and maximum amount to be spent to buy all of the candies
vector<int> candyStore(int candies[], int N, int K)
{
    sort(candies, candies + N);
    vector<int> ans(2, 0);

    int last = N - 1;
    for (int i = 0; i <= last; i++)
    {
        ans[0] += candies[i];
        last -= K;
    }
    last = 0;
    for (int i = N - 1; i >= last; i--)
    {
        ans[1] += candies[i];
        last += K;
    }

    return ans;
}

// Input: S = i.like.this.program.very.much
// Output: much.very.program.this.like.i
string reverseWords(string S)
{
    string temp = "";
    string ans = "";
    int dot = S.size();
    for (int i = S.size() - 1; i >= 0; i--)
    {
        if (S[i] == '.')
        {
            for (int j = i + 1; j < dot; j++)
            {
                temp += S[j];
            }
            ans += temp + '.';
            dot = i;
            temp = "";
        }
    }

    for (int i = 0; i < dot; i++)
    {
        ans += S[i];
    }

    return ans;
}

// N – The maximum unit of food you can buy each day.
// S – Number of days you are required to survive.
// M – Unit of food required each day to survive.
//find minimum days to buy food , start from monday , can't buy on sundays

int minimumDays(int S, int N, int M){
        int days = -1;
        if(N < M) return days;
        
        int totlFood = S*M ;
        
        if(totlFood % N == 0) {days = totlFood/N;}
        else {days = totlFood /N + 1;}
        
        if(days <= S - S/7){//days other than sundays
            return days;
        }
        
        return -1;
        
    }