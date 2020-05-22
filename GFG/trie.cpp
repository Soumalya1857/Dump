#include<bits/stdc++.h>
using namespace std;

struct TrieNode
{
    struct TrieNode *children[26];
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false;
    for(int i=0;i<26;i++)
    {
        pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    TrieNode *pCrawl = root;
    for(int i=0;i<key.length();i++)
    {
        int index = key[i] - 'a';
        if(!pCrawl->children[index]) pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key)
{
    TrieNode *pCrawl = root;
    for(int i=0;i<key.length();i++)
    {
        int index = key[i] - 'a';
        if(!pCrawl->children[index]) return false;
        pCrawl = pCrawl->children[index];
    }
    if(pCrawl != NULL && pCrawl->isEndOfWord) return true;
    else return false;
}
int main()
{   
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        TrieNode *root = getNode();
        for(int i=0;i<n;i++)
        {
            cin >> s;
            insert(root,s);
        }
        cin >> s;
        cout << search(root,s) << "\n";
    }

    return 0;
}


/******

https://practice.geeksforgeeks.org/problems/trie-insert-and-search/0
****/