#include <bits/stdc++.h>
using namespace std;

int pageCount(int n, int p) {
    return min(p/2,(n-p+(n&1^1))/2);
}
...
