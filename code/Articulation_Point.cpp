const int N = ;
const int M = ;

int n, m;
int timer;
int low_time[N], entry[N];
bool visit[N];
bool isArticulation[N];

void dfs(int u, int p = -1) {
  low_time[u] = entry[u] = timer++;
  visit[u] = true;
  int children = 0;
  for(auto v: g[u]) {
    if(v == p) continue;
    if(visit[v]) {
      low_time[u] = min(low_time[u], entry[v]);
    } else {
      dfs(v, u);
      low_time[u] = min(low_time[u], low_time[v]);
      if(low_time[v] >= entry[u] && p != -1) {
        isArticulation[u] = true;
      }
      ++children;
    }
  }
  if(p == -1 && children > 1) {
    isArticulation[u] = true;
  }
}

void articulationPoints() {
  timer = 0;
  for(int i = 1; i <= n; ++i) {
    visit[i] = false;
    isArticulation[i] = false;
    entry[i] = low_time[i] = -1;
  }
  for(int i = 1; i <= n; ++i) {
    if(visit[i] == false) {
      dfs(i);
    }
  }
}