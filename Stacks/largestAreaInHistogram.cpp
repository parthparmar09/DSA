#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> findLeft(vector<int> vec , int n ){
        stack<int> st;
        st.push(-1);

        vector<int> res(n);

        for(int i = 0 ; i < n ; i++){
            int curr = vec[i];
            int count = i;
            while(st.top()!= -1 && vec[st.top()] >= curr){
                st.pop();
            }
            res[i] = st.top();
            st.push(i);

        }

        return res;

    }
    vector<int> findRight(vector<int> vec , int n ){
        stack<int> st;
        st.push(-1);

        vector<int> res(n);

        for(int i =n-1 ; i >= 0 ; i--){
            int curr = vec[i];
            int count = i;
            while(st.top()!= -1 && vec[st.top()] >= curr){
                st.pop();
            }
            res[i] = st.top();
            st.push(i);

        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        vector<int> prev(n);
        prev = findLeft(heights , n);

        vector<int> next(n);
        next = findRight(heights , n);

        int area = 0;

        for(int i = 0 ; i < n ; i ++){
            int l = heights[i];
            if(next[i]==-1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;

            area = max(area , l*b);
        }

        return area;
    }

int main(int argc, char const *argv[])
{
    
    return 0;
}
