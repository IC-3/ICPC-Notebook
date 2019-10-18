const int N = ;
const int K = ;

int sparse[N][K];
int logs[N];
int arr[N];
int n;

int f(int a, int b) {
  
}

void precomp()  {
  logs[1] = 0;
  for(int i = 2; i < N; i++) {
    logs[i] = logs[i/2] + 1;
  }
}

void build() {
  for(int i = 0; i < n; i++) {
    sparse[i][0] = arr[i];
  }

  for(int j = 1; j <= K; j++) {
    for(int i = 0; i + (1 << j) <= n; i++) {
      sparse[i][j] = f(sparse[i][j-1], sparse[i + (1 << (j - 1))][j - 1]);
    }
  }
}

int query(int l, int r) {
  int j = logs[r - l + 1];
  return f(sparse[l][j], sparse[r - (1 << j) + 1][j]);
}
