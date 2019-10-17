const int N = ;

int n;
vector<pair<int, long long>> graph[N];
int par[N + 1];

vector<long long> dijkstra(int src) {
  set<pair<long long, int>> pq;
  vector<long long> dist(n + 1);
  for(int i = 1; i <= n; ++i) {
    if(i != src) dist[i] = 1e17;
    else dist[i] = 0;
    pq.insert({dist[i], i});
  }
  par[src] = -1;
  while(pq.size()) {
    auto f = *pq.begin();
    int u = f.second;
    pq.erase(pq.begin());
    for(auto x: graph[u]) {
      int v = x.first;
      long long w = x.second;
      if(dist[v] > dist[u] + w) {
        pq.erase({dist[v], v});
        dist[v] = dist[u] + w;
        par[v] = u;
        pq.insert({dist[v], v});
      }
    }
  }
  return dist;
}