const int max_n = 1e5 + 5;
int n,k;
set<int> adj[max_n];
int dist[max_n];
int sub[max_n],nodes;
int dfs1(int s,int p){
	sub[s] = 1;
	nodes++;
	for(auto u:adj[s])
		if(u != p)
			sub[s] += dfs1(u,s);
	return sub[s];
}

int dfs2(int s,int p){
	for(auto u:adj[s]){
		if(u != p && sub[u] > nodes/2)
			return dfs2(u,s);
	}
	return s;
}

void dfs3(int s,int p,int depth,int val){
	//Insert the code here
}
long long dfs4(int s,int p,int depth){
	long long ans = 0;
	//Insert the code here
	return ans;
}
long long ans = 0;
void decompose(int s){
	for(int i=0;i<n&&dist[i];i++)
		dist[i] = 0;
	nodes = 0;
	dfs1(s,s);
	int centroid = dfs2(s,s);
	//Initial computation - dfs3
	for(auto u:adj[centroid]){
		//Remove branch computation - dfs3
		//Add branch answer - dfs4
		//Add branch computation - dfs3
	}
	for(auto u:adj[centroid]){
		adj[u].erase(centroid);
		decompose(u);
	}
}