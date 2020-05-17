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
void solve(){
  int n,k;
  cin>>n>>k;
  int a[n];
  rep(i,0,n) cin>>a[i];
  ll ans=0;
  for(int i=0;i<n;){
    int x=k,flag=0;
    while(a[i]==x && x!=0){
      flag=1;
      i++;
      x--;
    }
    if(flag==0) i++;
    if(x==0) ans++;
  }
  cout<<ans<<endl;
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

