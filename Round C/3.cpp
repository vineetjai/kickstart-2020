#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define pi 3.14159
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
const ll mod=1e9+7;
#define f first
#define s second
#define pii pair< int, int >
#define tc int t; cin >> t; while(t--)
using namespace std;

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll power(ll x,ll y){
    if(y<=0) return 1;
    ll z=power(x,y/2);
    if(y%2) return (((z*z)%mod)*x)%mod;
    else return ((z*z)%mod);
}
ll invmod(ll x){
    return power(x,mod-2);
}
bool check(ll x){
  ll z=sqrt(x);
  return z*z==x;
}
const int mxN=1e5;
int n, a[mxN],c[2*100*mxN+1];
void solve(){
  cin >> n;
  // finding range of summation of subarray
	int s1=0, s2=0;
  for(int i=0; i<n; ++i) {
		cin >> a[i];
		if(a[i]<0)
			s1-=a[i];
		else
			s2+=a[i];
	}

  // coninuous subarray sum from index =0 till index=i
	int t=0;
	ll ans=0;
  // frequency of 0 is 1 for finding single perfect square
	++c[s1];

	for(int i=0; i<n; ++i) {
    // prefix sum till i
		t+=a[i];
    // making all perfect squares
		for(int j=0; j*j<=s2; ++j) {
      // checking if index > 0
			if(s1+(t-j*j)>=0)
			ans+=c[s1+(t-j*j)];
		}
    // increasing count
		++c[s1+t];
	}
	cout << ans << "\n";
	memset(c, 0, 4*(s1+s2+1));

}
int main(){
    optimizeIO();
    ll t,k=1;
    cin>>t;
    while(t--){
      cout<<"Case #"<<k++<<": ";
      solve();
    }
}

