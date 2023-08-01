#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char ch;
    vector<TrieNode *> v;
    bool isTerminal;

    TrieNode(char c) : ch(c), isTerminal(false), v(26, nullptr)
    {
    }
};

class Trie
{
private:
    void insertThis(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->v[index] == nullptr)
        {
            root->v[index] = new TrieNode(word[0]);
            child = root->v[index];
        }
        else
        {
            child = root->v[index];
        }

        return insertThis(child, word.substr(1));
    }

    bool searchThis(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->v[index] != nullptr)
        {
            return searchThis(root->v[index], word.substr(1));
        }
        return false;
    }

public:
    TrieNode *root;

    Trie()
    {
        this->root = new TrieNode('/0');
    }
    void insertWord(string word)
    {
        insertThis(this->root, word);
    }
    bool searchword(string word)
    {
        return searchThis(this->root, word);
    }
};