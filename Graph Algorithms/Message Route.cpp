#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define all(c) (c).begin(), (c).end()
const int mod = 1000000007;


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
 int s=1;
 int d=n;
 bool vis[n+1]={false};
 map<int,int> c_p;
 queue<int> q;
 
 q.push(s);
 vis[s]=true;
 
 while(!q.empty()){
 	int u=q.front();
 	q.pop();
 	for(int i=0;i<g[u].size();i++){
 		int v=g[u][i];
 		if(vis[v]==false){
 			q.push(v);
 			vis[v]=true;
 			c_p[v]=u;
		 }
	 }
 }
 
 if(vis[d]==false){
 	cout<<"IMPOSSIBLE"<<endl;
 	return ;
 }
 vector<int> ans;
 
 int c=d;
 int p=c_p[c];
 ans.push_back(c);
 ans.push_back(p);
 
 while(p!=s){
 	c=p;
 	p=c_p[c];
 	ans.push_back(p);
 }
 cout<<ans.size()<<endl;
 for(int i=ans.size()-1;i>=0;i--){
 	cout<<ans[i]<<" ";
 }
 return ;

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
