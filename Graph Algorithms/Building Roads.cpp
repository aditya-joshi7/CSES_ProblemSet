#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define all(c) (c).begin(), (c).end()
const int mod = 1000000007;
void dfs(vector<int>* g,bool* vis,int s){
	if(vis[s]==true){
		return ;
	}
	vis[s]=true;
	
	for(int i=0;i<g[s].size();i++){
		int v=g[s][i];
		dfs(g,vis,v);
	}
}

void solve(){
 int n,m;
 cin>>n>>m;
 
 vector<int> g[n+1];
 for(int i=0;i<m;i++){
 	int u,v;
 	cin>>u>>v;
 	g[u].push_back(v);
 	g[v].push_back(u);
 }
  bool* vis=new bool[n+1];
  for(int i=1;i<=n;i++){
  	vis[i]=false;
  }
  vector<int> x;
  int ans=-1;
  for(int i=1;i<=n;i++){
  	if(vis[i]==false){
  		dfs(g,vis,i);
  		x.push_back(i);
  		ans++;
	  }
  }
   cout<<ans<<endl;
   for(int i=1;i<x.size();i++){
   	cout<<x[i-1]<<" "<<x[i]<<endl;
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
