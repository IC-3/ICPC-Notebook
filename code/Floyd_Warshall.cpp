const int N = ;

long long mat[N + 1][N + 1];
int n;

vector<vector<long long>> floydWarshall() {
  vector<vector<long long>> dist(n + 1, vector<long long>(n + 1));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      dist[i][j] = mat[i][j];
    }
  }
  for(int k = 1; k <= n; ++k) {
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
        if(dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  return dist;
}

