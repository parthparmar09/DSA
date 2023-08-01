#include<iostream>
#include<stack>
#include<string>
using namespace std;

void print(stack<char> st){
    while(!st.empty()){
        cout << st.top() << "" ;
        st.pop();
    }
    cout << endl;
}


string simplifyPath(string path) {
    stack<string> st;
    string res = "/";

    for(int i = 0 ; i < path.length() ;i++){
        if(path[i] == '/'){
            continue;
        }

        string temp;
        while (i < path.length() && path[i] != '/')
        {
            temp += path[i];
            i++;
        }

        if(temp == "."){
            continue;

        }else if(temp == ".."){
            if(!st.empty()){
                st.pop();
            }
        }else{
            st.push(temp);
        }
        
    }

    while(!st.empty()){
        res  = "/" + st.top() + res;
        st.pop();
    }

    if(res.length() == 0){
        return "/";
    }
    return res;
}

int main(int argc, char const *argv[])
{
    /* code */
    string str = "/..";
    cout << simplifyPath(str) << endl;
    return 0;
}
