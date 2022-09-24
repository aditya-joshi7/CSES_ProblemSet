#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define all(c) (c).begin(), (c).end()
const int mod = 1000000007;
void dfs(int** mat,int n,int m,int r,int c){
	if(r<0 || c<0 || r>=n || c>=m || mat[r][c]==0){
		return;
	}
	
	mat[r][c]=0;
	
	int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};
    for(int i=0;i<4;i++){
        dfs(mat,n,m,r+x[i],c+y[i]);
    }
}

void solve(){
 int n,m;
 cin>>n>>m;
 
 int** mat=new int*[n];
 for(int i=0;i<n;i++){
 	mat[i]=new int[m];
 	for(int j=0;j<m;j++){
 		mat[i][j]=0;
	 }
 }
 
 for(int i=0;i<n;i++){
 	for(int j=0;j<m;j++){
 		char c;
 		cin>>c;
 		if(c=='#'){
 			mat[i][j]=0;
		 }
		 else{
		 	mat[i][j]=1;
		 }
	 }
 }
 
 int ans=0;
 for(int i=0;i<n;i++){
 	for(int j=0;j<m;j++){
 		if(mat[i][j]==1){
 			dfs(mat,n,m,i,j);
 			ans++;
		 }
	 }
 }
 
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
