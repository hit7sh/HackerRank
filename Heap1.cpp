#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5+5;
vector<int>H(mxN,INT_MIN);
int main(){
    int r=0,t,q,v;
    for(cin>>t;t--;){
        cin>>q;
        if(q==1){
            cin>>v;
            H[r]=v;
            int temp=r;
            while(H[temp/2]>H[temp])
                swap(H[temp],H[temp/2]),temp>>=1;
            r++;
        }
        else if(q==2){
            cin>>v;
            int p = 0,l;
            for(;;p++)
                if(H[p]==v)
                    break;
            H[p]=INT_MIN;l=p;
            while(l<r)
                if(H[l*2+1]<H[l*2+2])
                    swap(H[l],H[2*l+1]),l=2*l+1;
                else if(H[2*l+2]<H[2*l+1])
                    swap(H[l],H[2*l+2]),l=2*l+2;
                else
                    break;
            for(int i=0;i<r;i++)
                if(H[i]==INT_MIN && H[i+1])
                    swap(H[i],H[i+1]);
            r--;
        }
        else
            cout<<H[0]<<endl;
    }
    return 0;
}
