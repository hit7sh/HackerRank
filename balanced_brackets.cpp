#include <bits/stdc++.h>
using namespace std;

string isBalanced(string s) {
    map<char, char>M={{'{','}'},{'(',')'},{'[',']'}};
    stack<char>S;
    for(char x:s)
        if(!S.empty()&&M[S.top()]==x)
            S.pop();
        else
            S.push(x);
    
    return S.empty()?"YES":"NO";
}
...
