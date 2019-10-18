class dsu {
public:
  dsu(int n) {
    node_size = n;
    parent = vector<int>(n + 1);
    sz = vector<int>(n + 1);
    makeSet();
  }
  int find(int vertex) {
    if(vertex == parent[vertex]) {
      return vertex;
    } else {
      return parent[vertex] = find(parent[vertex]);
    }
  }
  void unite(int u, int v) {
    parent[u] = v;
    sz[v] += sz[u];
    sz[u] = 0;
  }
private:
  int node_size;
  vector<int> parent;
  vector<int> sz;
  void makeSet(){
    for(int i = 1; i <= node_size; ++i) {
      parent[i] = i;
      sz[i] = 1;
    }
  }
};

vector<pair<int, pair<int, int>>> edges;

class kruskal {
public:
  kruskal(int n) {
    node_size = n;
    tot_weight = 0;
    sort(edges.begin(), edges.end());
    construct();
  }
  inline long long getWeight() {return tot_weight;}
  inline vector<pair<int, pair<int, int>>> getMST() {return mst;}
private:
  int node_size;
  long long tot_weight;
  vector<pair<int, pair<int, int>>> mst;
  void construct(){
    dsu d(node_size);
    for(auto e: edges) {
      int w = e.first;
      int u = e.second.first;
      int v = e.second.second;
      int u_par = d.find(u);
      int v_par = d.find(v);
      if(u_par != v_par) {
        tot_weight += w;
        mst.emplace_back(e);
        d.unite(u_par, v_par);
      }
    }
  }  
};