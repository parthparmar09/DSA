#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int x,Node* l = nullptr, Node* r = nullptr) {
        val = x;
        left = l;
        right = r;
    }
};

class cmp{
    public:
    bool operator()(Node* first , Node* second){
        return first->val > second->val;
    }
};

void preOrder(Node* root, string temp, vector<string>& ans) {
    if(root->left == nullptr && root->right == nullptr){
        ans.push_back(temp);
        return;
    }
    preOrder(root->left, temp +'0', ans);
    preOrder(root->right, temp + '1', ans);
}

vector<string> huffmanCodes(string S, vector<int> f, int N) {
    priority_queue<Node*  , vector<Node*> , cmp> pq;

    for (int i = 0; i < N; i++) {
        Node* n = new Node(f[i]);
        pq.push(n);
    }

    while (pq.size() > 1) {
        Node* first = pq.top();
        pq.pop();
        Node* second = pq.top();
        pq.pop();

        pq.push(new Node(first->val + second->val, first, second));
    }

    Node* root = pq.top();

    vector<string> ans;
    string temp = "";

    preOrder(root , temp, ans);

    return ans;
}

int main(int argc, char const* argv[]) {
    string s = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};

    vector<string> ans = huffmanCodes(s, f, 6);

    for (auto str : ans) {
        cout << str << endl;
    }

    return 0;
}
