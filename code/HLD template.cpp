const int max_n = 1e5 + 5;
int par[max_n][21],chainNo = 0,chainHead[max_n],chainLength[max_n],nodeChain[max_n],nodePos[max_n],sub[max_n];
vector<int> arr,decarr[max_n],adj[max_n];
int dfs(int s,int p){
	sub[s] = 1;
	par[s][0] = p;
	bool flag = true;
	for(auto u:adj[s]){
		if(u != p){
			flag = false;
			sub[s] += dfs(u,s);
		}
	}
	return sub[s];
}
void hld(int cur,int par){
	if(chainHead[chainNo] == -1){
		chainHead[chainNo] = cur;
	}
	nodeChain[cur] = chainNo;
	nodePos[cur] = chainLength[chainNo];
	chainLength[chainNo]++;
	decarr[chainNo].push_back(arr[cur]);
	int ind = -1,maxval = -1;
	for(auto u:adj[cur]){
		if(u != par){
			if(sub[u] > maxval){
				maxval = sub[u];
				ind = u;
			}
		}
	}
	if(ind != -1)
		hld(ind,cur);
	for(auto u:adj[cur]){
		if(u != par && u != ind){
			chainNo++;
			hld(u,cur);
		}
	}
}

long long query(int u,int v){
	if(u == v)
		return arr[u];
	int uchain,vchain;
	long long ans = 0;
	vchain = nodeChain[v];
	while(1){
		uchain = nodeChain[u];
		if(uchain == vchain){
			/*ans += Some segment tree query function Eg:query_tree(0,chainLength[uchain]-1,0,nodePos[v],nodePos[u],uchain);*/
			break;
		}
		/*ans += Some segment tree query function Eg: query_tree(0,chainLength[uchain]-1,0,0,nodePos[u],uchain);*/
		u = chainHead[uchain];
		u = par[u][0];
	}
	return ans;
}