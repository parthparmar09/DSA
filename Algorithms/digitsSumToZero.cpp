#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool checkSum(vector<int> digits , int index, string &ans, int currSum){
  //base case
  if(index == digits.size()){
    if(currSum == 0){
    return true;
    }
    return false;
  }
  //for -
  if(checkSum(digits , index + 1, ans , currSum - digits[index])){
    ans.push_back('-');
    return true;
  }
  //for +
  if(checkSum(digits , index + 1, ans , currSum + digits[index])){
    ans.push_back('+');
    return true;
  }

  return false;

}

string MathChallenge(int num) {
  
  // code goes here  '
  vector<int> digits;
  string ans = "";
  while(num > 0){
    digits.push_back(num % 10);
    num /= 10;
  }

  int n =  digits.size();
  for(int i = 0 ; i < n/2 ; i++){
    swap(digits[i] , digits[n -i -1]);
  }

  if(checkSum(digits, 1 , ans , digits[0])){
     reverse(ans.begin() , ans.end());
     return ans;
  };

  return "not possible";

}

int main(void) { 
   
  // keep this function call here
  cout << MathChallenge(26712);
  return 0;
    
}