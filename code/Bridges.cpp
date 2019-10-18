const int N = ;
const int M = ;

int n, m;
int timer;
int low_time[N], entry[N];
bool visit[N];
bool isBridge[M];

void dfs(int u, int p = -1) {
  low_time[u] = entry[u] = timer++;
  visit[u] = true;
  for(auto e: g[u]) {
    int v = e.first;
    int id = e.second;
    if(v == p) continue;
    if(visit[v]) {
      low_time[u] = min(low_time[u], entry[v]);
    } else {
      dfs(v, u);
      low_time[u] = min(low_time[u], low_time[v]);
      if(low_time[v] > entry[u]) {
        isBridge[id] = true;
      }
    }
  }
}

void bridges() {
  timer = 0;
  for(int i = 1; i <= n; ++i) {
    visit[i] = 0;
    low_time[i] = entry[i] = -1;
  }
  for(int i = 1; i <= m; ++i) {
    isBridge[i] = false;
  }
  for(int i = 1; i <= n; ++i) {
    if(visit[i] == false) {
      dfs(i);
    }
  }
}