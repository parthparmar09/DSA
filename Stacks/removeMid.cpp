#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " , " ;
        st.pop();
    }
    cout << endl;
}

void solve(stack<int> &st , int size , int count){
    if(size/2 == count){
        st.pop();
        return;
    }

    int curr = st.top();
    st.pop();

    solve(st , size , ++count);

    st.push(curr);

}
void removeMid(stack<int> &st){
    int size = st.size();
    int count = 0;
    solve(st , size , count);
}
int main(int argc, char const *argv[])
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    print(st);
    removeMid(st);
    print(st);


    return 0;
}
