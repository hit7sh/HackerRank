/** 
 You will be provided with some random order of the english lowercase letters. Lets say, this is the new alphabetical order.

You will also be given  strings. You need to re-arrange the given  strings in such a way, that it obeys the given alphabetical order.

It means, that the strings should be sorted in non-decreasing order, with respect to the given alphabetical order.

Note : You should not permute the individual letters of any of the given strings. Rather, you need to create an ordering of the given strings.

See samples to clarify.

Input Format

The first line of the input consists of a single string of size 26, with all lowercase characters, which is the new ordering in which you have to re-arrange the strings.

Then, the next line contains a single integer , the number of strings.

Then,  lines follow, where each line contains a single string, where each character of the string is a lower case english letter.

Constraints

 ( Where  denotes the length of the string s ).


All the strings in the input contain lowercase characters.

Output Format

Print the  strings in the correct order as per the required condition.

Sample Input 0

qwertyuiopasdfghjklzxcvbnm
2
abcd
qwer
Sample Output 0

qwer    
abcd
*/

// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(x) cout << "--- " << #x << " = " << x << " ---\n";
#define findmax(v) *max_element(v.begin(), v.end())
#define _sum(a) accumulate(a.begin(), a.end(), 0)
#define tt int t;for(cin>>t; t--; )
#define f0(i, n) for(i = 0; i < (int)(n); i++)
#define f1(i, n) for(i = 1; i<= (int)(n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define EB emplace_back
#define PB push_back
#define F first
#define S second
#define endl "\n"

using namespace std;
using mii = map<int, int>;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
const int mod = 1e9+7,mxN = 1e7+5;

template<typename... Args>void print(Args... args){((cout << args << " "), ...);cout << endl;}
ll mod_pow(ll x, ll y){ll res = 1;x = x % mod;while(y>0){if(y&1)res = (res*x) % mod; y = y>>1;x = (x*x) % mod; }return res; }ll mod_inv ( ll n ){ll ans = mod_pow ( n , mod - 2 ) ;return ans ;}ll mul(ll a, ll b){a%=mod, b%=mod;return (a*b)%mod;}ll sub(ll a,ll b){a%=mod, b%=mod;return (a-b+mod)%mod;}ll add(ll a, ll b){a%=mod, b%=mod;return (a+b)%mod;}
bool _prime(ll n){if(n<2)return 0;if(n<4)return 1;if(n%2==0||n%3==0)return 0;for(ll i=5;i*i<=n;i+=6)if(n%i==0||n%(i+2)==0)return 0;return 1;}

/* #include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define iset tree<ll , null_type,less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define iof order_of_key
#define findat find_by_order */

//E

void solve(){
	string ord;
	cin >> ord;
	int i, n;
	cin >> n;
	vector<string> sts(n);
	f0(i, n)
		cin >> sts[i];
	sort(all(sts), [&](string a, string b){
			bool af=0, bf=0;
		for(int j, i=0; i<min(a.length(), b.length()); i++){
				af=bf=0;
			f0(j, 26){
				if(a[i]==ord[j])
					af=1;
				if(b[i]==ord[j])
					bf=1;
				if(af^bf^1){
					af=bf=0;
					continue;
				}
				else if(af==1)
					return true;
				else if(bf==1)
					return false;
			}
		}
		if(af==0 && bf==0)
			return a.length()<b.length();
		return false;
	});
	for(auto x:sts)
		print(x);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout);
	#endif
    __speed();
    solve();
    return 0;
}
