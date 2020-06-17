#include <bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    for(cin>>tt;tt--;){
        int n,x,y;
        map<int,int>M;
        cin >> n;
        while(n--)
            cin >> x >> y, M[x] = y;
        cin >> n;
        while(n--)
            cin >> x >> y, M[x] = y;
        queue<int>q;
        q.push(1);
        vector<bool>visited(101);
        vector<int>dist(101);
        dist[100]=-1;
        while(!q.empty()){
            int p = q.front();
            q.pop();
            visited[p]=true;
            for(int c=0,i = p+1; i<=p+6 && i<=100; ++i){
                if(M.count(i) && !visited[M[i]])
                    q.push(M[i]), dist[M[i]]=dist[p]+1, visited[M[i]]=true;
                else if(!visited[i] && !M.count(i))
                    q .push(i), dist[i]=dist[p]+1, visited[i]=true;
            }
        }
        cout << dist[100] << endl;
    }
}
