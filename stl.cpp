#include <iostream>
using namespace std;
#include<array>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<algorithm>

//stl contains containers and algorithms

int main(int argc, char const *argv[])
{
    //arrays - static 
    array<int , 4> arr = {1,2,3,4};
    cout << arr.size() << arr.at(2) << arr.empty() << arr.front() << arr.back() << endl;

    //vectors - dynamic arrays
    //same methods as arrays
    vector<int> vec = {1,2,3,4};
    cout << vec.capacity() <<vec.size() << endl;
    vec.push_back(1) ; //adds atlast
    vec.pop_back();//removes from last
    vec.clear();//clears all values 

    vector<int> vec2(10 , 0); //10-size , all with value = 0;

        //stacks
    stack<int> st;
    st.push(1);
    st.pop();
    st.top();
    st.empty(); //empty or not
    st.size();

    //lists
    list<int> l;
    l.size();
    l.push_back(1);
    l.push_front(1);
    l.pop_front();
    l.pop_back();
    list<int> l2(5,100) ; //5 elements - each with 100 value



    //queues
    queue<int> q ;
    q.push(1);
    q.push(2);
    q.pop();
    q.front() ; //q.back()
    q.empty(); // returns 1(true) if empty

    //doubly ended queue - deque
    //same methods as arrays
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(1);
    dq.pop_front();
    dq.pop_back();
    dq.at(2);
    dq.begin();//dq.end()
    dq.clear();
    dq.erase(dq.begin() , dq.end() -1);

    //priority queue
    //max-heap -  gives maximum element when popped
    priority_queue<int> maxq;
    //min-heap -  gives minimum element when popped
    priority_queue<int , vector<int> , greater<int>> minq;
    //both have samem methods
    maxq.push(1);
    maxq.pop();
    minq.empty();
    minq.size();


    //sets - contains unique elements
    //unordered_set - not in sorted manner
    set<int> set1;
    set1.begin() ; //set.end()
    set1.insert(11);
    set1.count(11) ; //returns 1(true) if element is present

    //maps - stores data in key value forms
    // unordered_map -  not in sorted mannerr
    map<int , string> mp ;
    mp[1] = "hello";
    mp[2] = "world";
    mp.insert({3,"cpp"});
    mp.count(2) ; //1(true) if key 2 is present

    for(auto i : mp){
        cout << i.first << " " << i.second << endl;
    }

    auto it = mp.find(3); // returns iterator for that key
    for(auto i = it ; i != mp.end() ; i++){
        cout << (*i).first << endl;
    }

    //stl algorithms

    cout << binary_search(vec.begin() , vec.end() , 4) << endl;
    cout << max(10,20) << " , " << min(10,20)  << endl;
    string str = "hello";
    reverse(str.begin() , str.end());
    swap(str[1] , str[3]);
    rotate(str.begin() , str.begin() + 2 , str.end()); //(start , mid , end) - to rotate
    sort(vec.begin() , vec.end());
}
