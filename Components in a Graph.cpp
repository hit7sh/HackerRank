#include <bits/stdc++.h>

using namespace std;
int n, c=0, vis[30001];
vector<int>adj[30001];
void dfs(int u){
    vis[u]=1;
    c++;
    for(int x:adj[u])
        if(!vis[x])
            dfs(x);
        
}
int main(){
    int u, v, i;
    cin >> n;
    for(i=0;i<n;i++)
        cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
    int mn=INT_MAX, mx=INT_MIN;
    for(i=1;i<=2*n;i++)
        if(!vis[i]&&!adj[i].empty()){
            c=0;
            dfs(i);
            mn=min(mn, c);
            mx=max(mx, c);
        }
    cout << mn << ' ' << mx;
    return 0;
}
