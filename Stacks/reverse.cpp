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

void insertAtBottom(stack<int> &st , int x){
    if(st.empty()){
        st.push(x);
        return;
    }

    int curr = st.top();
    st.pop();
    insertAtBottom(st , x);
    st.push(curr);

}

void reverse(stack<int> & st){
    if(st.empty()){
        return ;
    }

    int curr =  st.top();
    st.pop();

    reverse(st);
    insertAtBottom(st , curr);
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
    reverse(st);
    print(st);
    return 0;
}
