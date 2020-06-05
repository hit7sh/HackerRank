#include<bits/stdc++.h>
using namespace std;
struct trie{
    unordered_map<char,trie *>M;
    int cnt;
};

void insert(trie *root, string st){
    for(char x:st){
            if(!(root->M.count(x)))
                root->M[x]=new trie();
        root->M[x]->cnt ++;
        root=root->M[x];
    }
}
int find(trie *root,string st){
    for(char x:st){
        if(!(root->M.count(x)))
            return 0;
        root=root->M[x];
    }
    return root->cnt;
}
int main(){
    trie *root=new trie();
    int tt;
    for(cin>>tt;tt;tt--){
        string ch,st;
        cin>>ch>>st;
        if(ch=="add")
            insert(root,st);
        else
            cout<<find(root,st)<<endl;
    }
    return 0;
}
