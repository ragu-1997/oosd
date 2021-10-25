#include <bits/stdc++.h>
#define lli long long int
#define p 1000000007

using namespace std;

struct DSU{
	lli n;
	vector<lli> parent, rank;

	DSU(){}
	DSU(int a){
		n=a;
		parent.resize(n+1);
		rank.resize(n+1);
		for (int i = 1; i <= n; ++i)
		{
			parent[i]=i;
			rank[i]=1;
		}
	}

	lli find(int x){
		if (parent[x]!=x)
		{
			return (parent[x] = find(parent[x]));
		}
		return parent[x];
	}

	void merge(lli x, lli y){
		lli xr = find(x);
		lli yr = find(y);
		if (xr!=yr)
		{
			if (rank[xr]>rank[yr])
			{
				parent[yr] = xr;
				rank[xr] += rank[yr];
			}else{
				parent[xr] = yr;
				rank[yr] += rank[xr];
			}
		}
	}
};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    lli n1,m;
    cin>>n1>>m;
    DSU dsu = DSU(n1);
    vector<pair<lli, pair<lli, lli>>> v;
    for (int i = 0; i < m; ++i)
    {
    	lli a,b,c;
    	cin>>a>>b>>c;
    	v.push_back({c, {a,b}});
    }

    sort(v.begin(), v.end());

    lli cnt = 0;
    lli mst = 0;
    for (int i = 0; i < m; ++i)
    {
    	lli cost = v[i].first;
    	lli a = v[i].second.first;
    	lli b = v[i].second.second;

    	if (dsu.find(a)!=dsu.find(b))
    	{
    		dsu.merge(a,b);
    		cnt++;
    		mst += cost;
    	}
    }

    if (cnt==n1-1)
    {
    	cout<<mst<<"\n";
    }else{
    	cout<<"IMPOSSIBLE\n";
    }
    


}