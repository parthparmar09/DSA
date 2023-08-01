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

int maximalRectangle(vector<vector<char>>& matrix) {
    int len = matrix[0].size() ;
    vector<int> hist(len , 0);
    
    int area = 0;

    for(int row = 0 ; row < matrix.size() ; row++){

        for(int i = 0 ; i < len; i ++){
        hist[i] = (matrix[row][i] == '1') ? ++hist[i] : 0;
        }

        area = max(area , largestRectangleArea(hist));
    }

    return area;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<vector<char>> mat = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << maximalRectangle(mat) << endl;

    return 0;
}
