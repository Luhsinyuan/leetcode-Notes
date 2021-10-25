#include"iostream"
#include"vector"
#include"cstring"
#include"algorithm"

using namespace std;


class Trie {
private:
    bool IsEnd;
    Trie* next[26];
public:
    
    /** Initialize your data structure here. */
    Trie()
    {
        IsEnd=false;
        memset(next,0,sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root=this;
        for(char bit:word)
        {
            if(root->next[bit-'a']==nullptr)
            {
                root->next[bit-'a']=new Trie();
            }
            root=root->next[bit-'a'];
        }
        root->IsEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root=this;
        for(char bit:word)
        {
            root=root->next[bit-'a'];
            if(root==nullptr)
            {
                return false;
            }
        }
        return root->IsEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root=this;
        for(char bit:prefix)
        {
            root=root->next[bit-'a'];
            if(root==nullptr)
            {
                return false;
            }
        }
        return true;
    }
};

