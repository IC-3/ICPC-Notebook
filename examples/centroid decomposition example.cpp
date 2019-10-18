/*Template by hemnath_d(Enlightened by chamow)*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vec vector<ll>
#define pll pair<ll,ll>
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define fx first
#define sx second
#define inf 100000000000000
#define minf -100000000000000
#define maxi 100005
int n,k;
set<int> adj[maxi];
int dist[maxi];
int sub[maxi],nodes;
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
	dist[depth] += val;
	for(auto v:adj[s]){
		if(v != p)
			dfs3(v,s,depth+1,val);
	}
}
ll dfs4(int s,int p,int depth){
	ll ans = 0;
	if(depth == k)
		ans += (2 * dist[0]);
	else if(depth < k)
		ans += dist[k - depth];
	for(auto v:adj[s])
		if(v != p)
			ans += dfs4(v,s,depth+1);
	return ans;
}
ll ans = 0;
void decompose(int s){
	for(int i=0;i<n&&dist[i];i++)
		dist[i] = 0;
	nodes = 0;
	dfs1(s,s);
	int centroid = dfs2(s,s);
	dfs3(centroid,centroid,0,1);
	ll val = 0;
	for(auto u:adj[centroid]){
		dfs3(u,centroid,1,-1);
		val += dfs4(u,centroid,1);
		dfs3(u,centroid,1,1);
	}
	ans += val/2;
	for(auto u:adj[centroid]){
		adj[u].erase(centroid);
		decompose(u);
	}
}
int main()
{
    fastread;
    cin>>n>>k;
    for(int i=1;i<n;i++){
    	int u,v;
    	cin>>u>>v;
    	adj[u].insert(v);
    	adj[v].insert(u);
    }
    decompose(1);
    cout<<ans<<endl;
    return 0;
}