#include <bits/stdc++.h>
using namespace std;
#include "../code/Wavelet_Tree.cpp"
#define ll long long
int n,q;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin>>n>>q;
	v = vector<int>(n,0);
	for(int i=0;i<v.size();i++)
		cin>>v[i];
	wavelet_tree w(v.begin(),v.end(),*min_element(v.begin(), v.end()),*max_element(v.begin(), v.end()));

	while(q--){
		int l,r,k;
		cin>>l>>r>>k;
		l--;r--;k--;
		cout<<w.kth(l,r,k)<<endl;
	}
}