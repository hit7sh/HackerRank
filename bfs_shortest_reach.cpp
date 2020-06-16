#include <bits/stdc++.h>
using namespace std;

int dist[1001];

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<int>adj[n+1];
    vector<bool>visited(n+1);
    vector<int>dist(n+1,-1);
    queue<int>q;
    for(int i=0;i<m;i++){
        int u,v;
        u=edges[i][0],v=edges[i][1];
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    visited[s]=1;
    dist[s]=0;
    q.push(s);
    while(!q.empty()){
        int c=q.front();q.pop();
        for(auto u:adj[c]){
            if(!visited[u]){
                dist[u]=dist[c]+6;
                visited[u]=1;
                q.push(u);
            }
        }
    }
    dist.erase(dist.begin()+s);
    dist.erase(dist.begin());
    return dist;
}
