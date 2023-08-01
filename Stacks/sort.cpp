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

void insertSorted(stack<int> &st ,  int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    if(st.top() < x){
        st.push(x);
        return;
    }

    int curr =  st.top();
    st.pop();
    insertSorted(st , x);
    st.push(curr);



}
void sort(stack<int> &st){
    if(st.empty()){
        return;
    }

    int curr =  st.top();
    st.pop();

    sort(st);
    insertSorted(st , curr);
}


int main(int argc, char const *argv[])
{
    stack<int> st;
    st.push(4);
    st.push(2);
    st.push(3);
    st.push(1);
    st.push(5);

    print(st);
    sort(st);
    print(st);
    return 0;
}
