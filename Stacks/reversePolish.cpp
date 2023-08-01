#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

void print(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " , " ;
        st.pop();
    }
    cout << endl;
}

void doOperation(stack<int> &st , string op){
    if(st.size() <=1){
        return ; 
    }

    int n1 = st.top();
    st.pop();
    int n2 = st.top();
    st.pop();

    int res = 0;

    switch (op[0])
    {
    case ('+'):
        res = n1 + n2;
        break;
    case ('-'):
        res = n2 - n1;
        break;
    case ('*'):
        res = n1 * n2;
        break;
    case ('/'):
        res = n2 / n1;
        break;
    
    }

    st.push(res);

}

int evalRPN(vector<string>& tokens) {
    stack<int> st;

    for(int i = 0 ; i < tokens.size() ; i ++){
        string curr = tokens[i];
        if(curr== "+" || curr == "-" || curr== "*" || curr == "/" ){
            doOperation(st , curr);
        }else{
            st.push(stoi(curr));
        }
    }

    return st.top();
}

int main(int argc, char const *argv[])
{
    vector<string> tokens = {"4","3","-"};

    cout << evalRPN(tokens) << endl;
    return 0;
}
