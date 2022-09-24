#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define all(c) (c).begin(), (c).end()
const int mod = 1000000007;

void solve(){
 int n,m;
 cin>>n>>m;
 
 vector<int> g[n+1];
 vector<int> ind(n+1,0);
 for(int i=0;i<m;i++){
 	int u,v;
 	cin>>u>>v;
 	ind[v]++;
 	g[u].push_back(v);
 
 }
 
 queue<int> q;
 int n_p=0;
 for(int i=1;i<=n;i++){
 	if(ind[i]==0){
 		q.push(i);
	 }
 }
 vector<int> ans;
 
 while(!q.empty()){
 	int u=q.front();
 	q.pop();
 	n_p++;
 	ans.push_back(u);
 	for(int i=0;i<g[u].size();i++){
 		int v=g[u][i];
 		ind[v]--;
 		if(ind[v]==0){
 			q.push(v);
		 }
	 }
 }
 if(n_p!=n){
 	cout<<"IMPOSSIBLE"<<endl;
 	return ;
 }
 for(int i=0;i<n;i++){
 	cout<<ans[i]<<" ";
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
