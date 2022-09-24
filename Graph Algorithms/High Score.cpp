#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define all(c) (c).begin(), (c).end()
const int mod = 1000000007;
 
struct Edge{
	int u,v;
	ll w;
};
void solve(){
 
 	
 int n,m;
 cin>>n>>m;
 vector<Edge> e;
 for(int i=0;i<m;i++){
 	Edge x;
 	cin>>x.u>>x.v>>x.w;
	
 	e.push_back(x);
 }
 
 vector<ll> dis(n+1,LLONG_MIN);
 
 dis[1]=0;
 
 for(int i=1;i<n;i++){
 	for(int j=0;j<m;j++){
 		if(dis[e[j].u]>LLONG_MIN){
 			if(dis[e[j].v]<dis[e[j].u]+e[j].w){
 				dis[e[j].v]=dis[e[j].u]+e[j].w;
			 }
 			
 			
		 }
	 }
 }
 for(int i=1;i<=n;i++){
 	cout<<dis[i]<<" ";
 }
 
 	int f=0;
 	for(int j=0;j<m;j++){
 		if(dis[e[j].u]>LLONG_MIN){
 			if(dis[e[j].v]<dis[e[j].u]+e[j].w){
 				f=1;
 				dis[e[j].v]=dis[e[j].u]+e[j].w;
			 }
 			
 			
		 }
	 }
 
 if(f==1){
 	cout<<-1<<endl;
 	return ;
 }
 
 cout<<dis[n]<<endl;
 
 
 
 
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
