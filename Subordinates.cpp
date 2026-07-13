#include<bits/stdc++.h>
using namespace std;
#define ll long long 

vector<vector<ll>> adj;
vector<ll> subtree_sz;

void dfs(ll node , ll par) {
  subtree_sz[node] = 1;
  for(auto v : adj[node]) {
    if(v != par) {
      dfs(v , node);
      subtree_sz[node] += subtree_sz[v];
    }
  }
}

int main() {
  ll n;
  cin>>n;

  adj.resize(n+1);
  subtree_sz.resize(n+1);

  for(int i=2; i<=n; i++) {
    ll x;
    cin>>x;

    adj[i].push_back(x);
    adj[x].push_back(i);
  }

  dfs(1 , 0);

  for(int i=1; i<=n; i++) {
    cout<<subtree_sz[i]-1<<" ";
  }
  cout<<endl;
  return 0;
}