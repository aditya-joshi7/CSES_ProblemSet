#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define all(c) (c).begin(), (c).end()
const int mod = 1000000007;

struct Edge {
    int u, v;
	ll weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int comp(int n,int* c){
    if(n==c[n]){
        return n;
    }
    c[n]=comp(c[n],c);
    return c[n];
}


void solve(){
 int n,m;
 cin>>n>>m;
 
vector<Edge> edges;
for(int i=0;i<m;i++){
	Edge x;
	cin>>x.u>>x.v>>x.weight;
	edges.push_back(x);
}
sort(edges.begin(),edges.end());

int *c =new int[n+1];
for(int i=1;i<=n;i++){
	c[i]=i;
}
ll ans=0;
int to_e=0;
for(int i=0;i<edges.size();i++){
	int u=edges[i].u;
	int v=edges[i].v;
	ll w=edges[i].weight;
	
	int pu=comp(u,c);
    int pv=comp(v,c);

        if(pu!=pv){
        	ans+=w;
        	to_e++;
            c[max(pu,pv)]=min(pu,pv);
        }
}
if(to_e==n-1){
	cout<<ans<<endl;
}
else{
	cout<<"IMPOSSIBLE"<<endl;
}

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    int t=1;
	//cin>>t;

	while(t--){
		solve();
	}	
	
	
	
	
}
