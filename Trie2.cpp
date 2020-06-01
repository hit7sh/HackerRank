// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
using namespace std;

struct trie{
    unordered_map<char, trie*>M;
    int cnt;
    bool end;
} *root;
typedef trie node;

node* newnode(){
    node *temp = new node;
    return (temp->end = 0,temp->cnt =0, temp);
}

void insert(string st){
    node *t = root = (root == nullptr?newnode():root);
    for(char x:st){
        if(t->M.find(x)==t->M.end())
            t->M[x] = newnode();
        t->cnt ++;
        t = t->M[x];
    }
    t->cnt++;
    t->end = true;
}
int search(string st){
    node *t=root;
    if(t==nullptr)
        return 0;
    for(char x:st){
        if(t->M[x]==nullptr)
            return 0;
        t = t->M[x];
    }
    return t->cnt>1 && t->end;
}
int main(){
    int minl=INT_MAX,tt;
    vector<string>s;
    for(cin>>tt;tt--;){
        string st;
        cin>>st;
        int l=st.length();
        minl=min(minl,l);
        s.emplace_back(st);
    }
    for(string st:s){
        insert(st);
        int l=st.length();
        for(int i=minl;i<=l;i++)
            if(search(st.substr(0,i))){
                cout<<"BAD SET\n"<<st;
                return 0;
            }
    }
    cout<<"GOOD SET";
    return 0;
}
