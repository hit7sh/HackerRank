#include<stdio.h>
int main()
{
    int m,n,r,i,j,c=0;
    scanf("%d %d %d",&m,&n,&r);
    int A[m][n],B[m*n];
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    scanf("%d",&A[i][j]);
    for(i=0;i<=m/2;i++)
    {
        for(j=i;j<n-i;j++)
        B[c++]=A[i][j];
        if(c==m*n)break;
        for(j=i+1;j<m-i;j++)
        B[c++]=A[j][n-i-1];
        if(c==m*n)break;
        for(j=n-i-1-1;j>=i;j--)
        B[c++]=A[m-i-1][j];
        if(c==m*n)break;
        for(j=m-i-1-1;j>=i+1;j--)
        B[c++]=A[j][i];
        if(c==m*n)break;
    }

    int x=0,m1=m,n1=n,cc=-1,R[m1*n1];c=-1;
    for(i=0;i<(m1<n1?m1+1:n1+1)/2;i++)
    {
        int pp=((m==1||n==1)?m*n:(m+n)*2-4);
        int T[pp];
        for(x=0;x<pp;x++)
        T[x]=B[++c];
        
        for(x=r;x<pp+r;x++)
        R[++cc]=T[x%(pp)];
        
    m-=2;n-=2;
    }

    m=m1;n=n1;c=0;
    for(i=0;i<=m/2;i++)
    {
        for(j=i;j<n-i;j++)
        A[i][j]=R[c++];
        if(c==m*n)break;
        for(j=i+1;j<m-i;j++)
        A[j][n-i-1]=R[c++];
        if(c==m*n)break;
        for(j=n-i-1-1;j>=i;j--)
        A[m-i-1][j]=R[c++];
        if(c==m*n)break;
        for(j=m-i-1-1;j>=i+1;j--)
        A[j][i]=R[c++];
        if(c==m*n)break;
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }
    return 0;
}
