#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define all(c) (c).begin(), (c).end()
const int mod = 1000000007;
bool isBip(vector<int>* g,int* col,int s){
queue<int> q;
  q.push(s);
  col[s]=1;
   while(!q.empty()){
  	int u=q.front();
  	q.pop();
  	for(int i=0;i<g[u].size();i++){
  		int v=g[u][i];
  		if(col[v]==-1){
  			q.push(v);
  			col[v]=1-col[u];
		  }
		else if(col[u]==col[v]){
			
			return false ;
		}  
	  }
  }
  
  return true;
	
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
  int* col=new int[n+1];
  for(int i=1;i<=n;i++){
  		col[i]=-1;
  }
  
  
  for(int i=1;i<=n;i++){
  	 if(col[i]==-1){
  	 	if(isBip(g,col,i)==false){
  	 		cout<<"IMPOSSIBLE"<<endl;
  	 		return ;
		   }
	   }
  }
  for(int i=1;i<=n;i++){
  	if(col[i]==0){
  		cout<<2<<" ";
	  }
	  else{
	  	cout<<col[i]<<" ";
	  }
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
