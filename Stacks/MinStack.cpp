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

class MinStack{
public:
    int min;
    stack<int> st;


    void push(int val){
        if(st.empty()){
            this -> min =val;
            st.push(val);

            return ;
        }

        if(val < min){
            int x= 2*val - min;
            this ->min = val;
            st.push(x);  
        }else{
            st.push(val);
        }
    }
    void pop(){
        if(st.empty()){
            return;
        }

        if(st.top() > min){
            st.pop();
            return;
        }

        min = 2*min - st.top();
        st.pop();
    }
    int top(){

        if(st.empty()){
            return -1;
        }

        if(st.top() > min){
            return st.top();
        }

        return min;
    }
    int getMin(){
        return min;
    }

};

int main(int argc, char const *argv[])
{
    /* code */

    MinStack *st = new MinStack();

    st->push(40);
    st->push(30);
    st->push(20);
    st->push(10);
    return 0;
}
