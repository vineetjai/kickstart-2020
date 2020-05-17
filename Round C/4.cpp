#include <iostream>
#include <vector>
#include <queue> //priority queue
#include <stack>
#include <map> // multimap
#include <set> //multiset
#include <list>
#include <utility> // pair
#include <iterator>
#include <deque> // insertion as both ends
#include <string>
// g1=s.substr(0,n/2);
// g2=s.substr(n/2+n%2,n/2);
#include <cctype> //isaplha
#include <iomanip>      // std::setprecision
#include <algorithm> //binary_search,sort, next_permutation in lexicographically greater permutation, fill(it1,it2,val)
#include <cmath>
#include <limits.h> //INT_MIN,INT_MAX
#include <numeric>  //iota,partial_sum,inner_product,accumulate(begin,end,num)
#include <functional>  //Arithmetic, comparators, logical
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
// #include <bits/stdc++.h>
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
#define mod 1000000007
#define f first
#define s second
#define pii pair< int, int >
#define tc int t; cin >> t; while(t--)
const int N=2e5+10;
using namespace std;
string repeat(string s, int n) {
    string s1 = s;
    for (int i=1; i<n;i++)
        s += s1;
    return s;
}
string getString(char x) {
    string s(1, x);
    return s;
}

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int gcd(int a, int b){
    if (a == 0)  return b;
    return gcd(b % a, a);
}

struct tree_node{
    // ll max_sufix,max_prefix,sum,maxsum;
    ll maxsum,sum,l1,r1;
};
ll A[N];
tree_node tree[N*4];
tree_node merge(tree_node &l,tree_node &r){
    tree_node result;
    int sign = -1;
    if((l.r1-l.l1)%2 ) sign=1;
    ll add = l.r1-l.l1+1;
    result.l1=l.l1;
    result.r1=r.r1;
    result.sum = l.sum+sign*(r.sum);
    result.maxsum = l.maxsum+sign*(r.maxsum+r.sum*add);
    // result.max_prefix=max(l.max_prefix,l.sum+r.max_prefix);
    // result.max_sufix=max(l.max_sufix+r.sum,r.max_sufix);
    // result.maxsum= max(max(result.max_prefix, max(result.max_sufix, max(l.maxsum, max(r.maxsum, l.max_sufix + r.max_prefix)))),result.sum);
    return result;
}
void build_tree(int node,int l,int r){
    if(l==r) {
      ll val=A[l];
      tree[node].l1=tree[node].r1=l;
      tree[node].maxsum=val;
      tree[node].sum=val;
      return ;
    }
    build_tree(node*2, l, (l+r)/2);
    build_tree(node*2+1, 1+(l+r)/2, r);
    tree[node]=merge(tree[2*node],tree[node*2+1]);
}

void update(int node,int l,int r,int x,int val){
    if(l==r){
        // tree[node].max_prefix=tree[node].max_sufix=tree[node].sum=tree[node].maxsum=val; return;
        tree[node].l1=tree[node].r1=l;
        tree[node].maxsum=val;
        tree[node].sum=val;
        return ;
    }
    if (x <= (l+r)/2)
        update(2*node, l, (l+r)/2, x, val);
    else
        update(2*node+1, (l+r)/2+1, r, x, val);
     tree[node]=merge(tree[2*node],tree[node*2+1]);
}

tree_node query(int node,int l,int r,int x,int y){
    if(l==x && r==y) return tree[node];
    int mid=(l+r)/2;
    if(x>mid) return query(2*node+1,mid+1,r,x,y);
    if(y<=mid) return query(2*node,l,mid,x,y);

    tree_node w=query(2*node,l,mid,x,mid);
    tree_node z=query(2*node+1,mid+1,r,mid+1,y);
    tree_node result=merge(w,z);
    return result;
}
void solve(){
  int n,m,x,y;
  cin>>n>>m;;
  rep(i,0,n) cin>>A[i];

  build_tree(1,0,n-1);
  ll ans=0;
  rep(i,0,m){
    char type;
    cin>>type;
    if(type=='U'){
        cin>>x>>y;
        update(1,0,n-1,x-1,y);
    }
    else {
        cin>>x>>y;
        x-=1,y-=1;
        ans+=query(1,0,n-1,x,y).maxsum;
    }
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

