const int N = ;
const long long inf = 1e17;

struct edge {
  int u, v;
  long long w;
};

int n, m;
int par[N + 1];
vector<edge> edges;

pair<vector<long long>, bool> bellmanFord(int src) {
  vector<long long> dist(n + 1);
  for(int i = 1; i <= n; ++i) {
    if(i != src) dist[i] = inf;
    else dist[i] = 0;
  }
  par[src] = -1;
  for(int i = 1; i <= n; ++i) {
    for(auto x: edges) {
      int u = x.u;
      int v = x.v;
      long long w = x.w;
      if(dist[u] != inf && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        par[v] = u; 
      }
    }
  }
  for(auto x: edges) {
    int u = x.u;
    int v = x.v;
    long long w = x.w;
    if(dist[u] != inf && dist[u] + w < dist[v]) {
      return {dist, false};
    }
  }
  return {dist, true};
}