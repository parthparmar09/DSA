#include<iostream>
#include<vector>

using namespace std;

    bool isOk(vector<vector<int>> &m , vector<vector <bool>> &visited , int i, int j , int n){
            
            //out of matrix?
            if(i >= n || j >= n || i < 0 || j < 0){
                return false;
            }
            //is open?
            if(m[i][j] == 0){
                return false;
            }
            //already visited?
            if(visited[i][j] == 1){
                return false;
            }
            
            //can go 
            return true;
        }
    
    void solve(vector<vector<int>> &m , int n , int i, int j , vector<vector <bool>> &visited , string &temp , vector<string> &res){
        //mark visit
        visited[i][j] = 1;
        //destination reached?
        if(i == n-1 && j == n-1){
            res.push_back(temp);
            visited[i][j] = 0;

            return;
        }
        
        //find adjacent unvisited node
        int x , y;
        
        //right
        x = i;
        y = j + 1;
        if(isOk(m ,  visited , x  , y , n)){
            temp.push_back('R');
            solve(m , n , x , y , visited , temp , res);
            temp.pop_back();
            
        }
        
        //down
        x = i + 1;
        y = j ;
        if(isOk(m ,  visited , x  , y , n)){
            temp.push_back('D');
            solve(m , n , x , y , visited , temp , res);
            temp.pop_back();
            
        }
        
        //left
        x = i;
        y = j - 1;
        if(isOk(m ,  visited , x  , y , n)){
            temp.push_back('L');
            solve(m , n , x , y , visited , temp , res);
            temp.pop_back();
            
        }
        
        //up
        x = i - 1;
        y = j ;
        if(isOk(m ,  visited , x  , y , n)){
            temp.push_back('U');
            solve(m , n , x , y , visited , temp , res);
            temp.pop_back();
            
        }
        
        
        //mark unvisited
        visited[i][j] = 0;
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
  
        string temp;
        
        vector<vector <bool>> visited(n , vector<bool> (n , 0));
        
        solve(m , n , 0 , 0 , visited , temp , res);
        
        
        return res;
        
    }

int main () {
    vector<vector <int>> m = {{1,0,0,0} , {1,1,0,1} ,{1,1,0,0} ,{0,1,1,1}};
    vector<string> s = findPath(m , 4);
    for(auto str : s){
        cout << str << "    " ;
    }

  
    return 0;
}