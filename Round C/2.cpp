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
int r,c;
vector<string> v(31);
vector<vector<int>> vis(31,vector<int>(31,0));
vector<vector<pii>> v2(31,vector<pii>());
bool check(char x){
  auto comp=[](pii &z, pii &y){
    if(z.s==y.s) return z.f>y.f;
    return z.s>y.s;
  };
  sort(v2[x-'A'].begin(),v2[x-'A'].end(),comp);

  int flag=0;
  rep(i,0,(int)v2[x-'A'].size()){
    pii y=v2[x-'A'][i];
    if(y.f==r-1) {
      vis[y.f][y.s]=1;continue;
    }
    else{
      if(vis[y.f+1][y.s]){
        vis[y.f][y.s]=1;continue;
      }
      else{
        flag=1;
        break;
      }
    }
  }
  if(flag){
    rep(i,0,v2[x-'A'].size()) vis[v2[x-'A'][i].f][v2[x-'A'][i].s]=0;
    return false;
  }
  return true;
}
void solve(){

  set<char> s;
  rep(i,0,31) rep(j,0,31) vis[i][j]=0;
  rep(i,0,31) v2[i].clear();

  cin>>r>>c;
  rep(i,0,r) cin>>v[i];

  rep(i,0,c) rep(j,0,r) v2[v[j][i]-'A'].pb({j,i});

  rep(i,0,c){
    s.insert(v[0][i]);
    rep(j,1,r) s.insert(v[j][i]);
  }

  string ans="";
  auto itr=s.begin();
  while(itr!=s.end()){
    ans+=*itr;
    itr++;
  }

  string final_ans="";
  while(ans.length()>0){
    int flag=0;
    rep(i,0,ans.length()){
      char x=ans[i];
      if(check(x)){
        final_ans+=ans[i];
        ans.erase(i,1);
        flag=1;
        break;
      }
    }
    if(!flag) {final_ans="-1"; break;}
  }
  cout<<final_ans<<endl;
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

