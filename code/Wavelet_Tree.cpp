
class wavelet_tree {
	int lo,hi;
	vector<int> v;
	wavelet_tree *l,*r;
	int lc;
public:
	wavelet_tree(vector<int>::iterator f,vector<int>::iterator t,int x,int y){
		lo = x;hi = y;
		if(lo == hi || f>t) return;
		int mid = (lo + hi)>>1;
		v.reserve(t-f+1);
		auto c = [mid](int x){ return x<=mid;};
		v.push_back(0);
		for(auto it=f;it!=t;it++){
			v.push_back(v.back() + c(*it));
		}
		auto piv = stable_partition(f,t,c);
		l = new wavelet_tree(f,piv,lo,mid);
		r = new wavelet_tree(piv,t,mid+1,hi);
	}
	int kth(int l,int r,int k){
		if(l>r) return 0;
		if(k==0) return lo;
		if(lo == hi) return lo;
		int ub = v[r];
		int lb = v[l-1];
		int lsize = ub - lb;
		if(k<=lsize) return this->l->kth(lb+1,ub,k);
		else return this->r->kth(l-lb,r-ub,k-lsize);
	}
};