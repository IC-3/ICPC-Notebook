const int N = ;
 
int n;
vector<int> g[N];
vector<int> rg[N];
vector<int> topo;
int component[N];
bool visit[N];
 
void dfs(int u) {
  visit[u] = true;
  for(auto v: g[u]) {
    if(!visit[v]) {
      dfs(v);
    }
  }
  topo.emplace_back(u);
}
 
void rdfs(int u, int cur) {
  visit[u] = true;
  component[u] = cur;
  for(auto v: rg[u]) {
    if(!visit[v]) {
      rdfs(v, cur);
    }
  }
}
 
void kosaraju() {
  for(int i = 1; i <= n; ++i) {
    if(!visit[i]) {
      dfs(i);
    }
  }
  reverse(topo.begin(), topo.end());
  memset(visit, false, sizeof visit);
  int cur = 0;
  for(auto u: topo) {
    if(!visit[u]) {
      ++cur;
      rdfs(u, cur);
    }
  }
}