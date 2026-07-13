#include<bits/stdc++.h>
using namespace std;
#define ll long long 

//Diameter of the tree is the longest path or distance between any two nodes.
//find the farthest node from any node and say it x and then find the farthest node from x say it y then x----y is the required diameter.....


vector<ll> dist;

void dfs(ll node , ll par , ll d , vector<vector<ll>> &adj) {
  dist[node] = d;

  for(auto v : adj[node]) {
    if(v != par) {
      dfs(v , node , d+1 , adj);
    }
  }
}

int main() {
  ll n;
  cin>>n;

  vector<vector<ll>> adj(n+1);
  for(int i=0; i<n-1; i++) {
    ll u,v;
    cin>>u>>v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dist.resize(n+1 , 0);

  dfs(1 , 0 , 0 , adj);

  ll x = 1;
  for(int i=1; i<=n; i++) {
    if(dist[i] > dist[x]) {
      x = i;
    }
  }

  dfs(x , 0 , 0 , adj);

  ll y = 1;
  for(int i=1; i<=n; i++) {
    if(dist[i] > dist[y]) {
      y = i;
    }
  }

  cout<<abs(dist[y] - dist[x])<<endl;
  return 0;
}