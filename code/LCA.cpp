const int N = ;

vector<int> g[N];
int n, l, timer;
int in[N], out[N], up[N][41];

void dfs(int u, int p) {
  in[u] = ++timer;
  up[u][0] = p;
  for(int i = 1; i <= l; ++i) up[u][i] = up[up[u][i - 1]][i - 1];
  for(auto v: g[u]) if(v != p) dfs(v, u);
  out[u] = ++timer;
}

inline bool is_ancestor(int u, int v) {
  return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v){
  if(is_ancestor(u, v)) return u;
  if(is_ancestor(v, u)) return v;
  for(int i = l; i >= 0; --i) 
    if(!is_ancestor(up[u][i], v))
      u = up[u][i];
  return up[u][0];
}