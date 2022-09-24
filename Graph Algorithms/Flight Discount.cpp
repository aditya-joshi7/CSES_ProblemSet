#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define all(c) (c).begin(), (c).end()
const int mod = 1000000007;

void solve(){
 int n,m;
 cin>>n>>m;
 vector<int> p(n+1,-1);
 vector<pair<ll,ll>> g[n+1];
 vector<ll> dis(n+1,LLONG_MAX);
 dis[1]=0;
 for(int i=0;i<m;i++){
 	ll u,v,w;
 	cin>>u>>v>>w;
 	g[u].push_back(make_pair(v,w));
 }
 
 priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
 
 pq.push(make_pair(0,1));
 
 
 while(!pq.empty()){
 	
 	ll d=pq.top().first;
 	int u=pq.top().second;
 	pq.pop();
 	
 	if(d==dis[u]){
 		for(int i=0;i<g[u].size();i++){
 			int v=g[u][i].first;
 			ll w=g[u][i].second;
 			if(dis[u]+w<dis[v]){
 				dis[v]=dis[u]+w;
 				pq.push(make_pair(dis[v],v));
 				p[v]=u;
 				
			 }
		 }
 		
	 }
 	
 	
 	
 }
 
 
  	vector<ll> path;
    for (int v = n; v != 1; v = p[v]){
    	path.push_back(v);
	}    
    path.push_back(1);
	reverse(path.begin(), path.end());
	
	for(int i=0;i<path.size();i++){
		cout<<path[i]<<" ";
	}
	cout<<endl;
	
	cout<<dis[n]<<endl;
	ll ans=dis[n];
	ll maxx=INT_MIN;
	for(int i=1;i<path.size();i++){
		int x=path[i-1];
		int y=path[i];
		for(int j=0;j<g[x].size();j++){
			if(g[x][j].first==y){
				//ans+=g[x][j].second;
				maxx=max(maxx,g[x][j].second);
			}
		}
		
	}
	
	ans=ans-maxx+(maxx/2);
	cout<<ans<<endl;
 
 


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
