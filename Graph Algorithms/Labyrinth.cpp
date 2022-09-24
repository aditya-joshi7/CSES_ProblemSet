#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define all(c) (c).begin(), (c).end()
const int mod = 1000000007;
bool isValid(int** mat,int n,int m,int r,int c){
	if(r<0 || c<0 || r>=n || c>=m || mat[r][c]==0){
		return false;
	}
	return true;
	

}
char findD(pair<int,int> p,pair<int,int> c){
	int x1=p.first;
	int y1=p.second;
	int x2=c.first;
	int y2=c.second;
	
	if(x1-1==x2 && y1==y2){
		return 'U';
	}
	if(x1==x2 && y1+1==y2){
		return 'R';
	}
	if(x1+1==x2 && y1==y2){
		return 'D';
	}
	if(x1==x2 && y1-1==y2){
		return 'L';
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
 pair<int,int> s;
 pair<int,int> d;
 
 for(int i=0;i<n;i++){
 	for(int j=0;j<m;j++){
 		char c;
 		cin>>c;
 		if(c=='#'){
 			mat[i][j]=0;
		 }
		 else if(c=='.') {
		 	mat[i][j]=1;
		 }
		 else if(c=='A'){
		 	 mat[i][j]=2;
		 	s=make_pair(i,j);
		 }
		 else if(c=='B'){
		 	d=make_pair(i,j);
		 	mat[i][j]=3;
		 	
		 }
	 }
 }
 
 map<pair<int,int>,pair<int,int>> c_p;
 queue<pair<int,int>> q;
 
 q.push(s);
 mat[s.first][s.second]=0;
 
 while(!q.empty()){
 	pair<int,int> u=q.front();
 	q.pop();
 	int u_x=u.first;
 	int u_y=u.second;
 	//isko loop se kar sakte hai
 	//up
 	 if(isValid(mat,n,m,u_x-1,u_y)){
 	    mat[u_x-1][u_y]=0;
 	    q.push({u_x-1,u_y});
 	    c_p[{u_x-1,u_y}]=u;
 	}
 	//down
 	if(isValid(mat,n,m,u_x+1,u_y)){
 	    mat[u_x+1][u_y]=0;
 	    q.push({u_x+1,u_y});
 	    c_p[{u_x+1,u_y}]=u;
 	}
 	
 	//left
 		if(isValid(mat,n,m,u_x,u_y-1)){
 	    mat[u_x][u_y-1]=0;
 	    q.push({u_x,u_y-1});
 	    c_p[{u_x,u_y-1}]=u;
 	}
 	//right
 		if(isValid(mat,n,m,u_x,u_y+1)){
 	    mat[u_x][u_y+1]=0;
 	    q.push({u_x,u_y+1});
 	    c_p[{u_x,u_y+1}]=u;
 	}
 	
 }
 if(mat[d.first][d.second]!=0){
 	cout<<"NO"<<endl;
 }
 else{
 	pair<int,int> c=d;
 	pair<int,int> p=c_p[c];
 	string ans="";
 	ans.push_back(findD(p,c));
 	
 	while(p!=s){
 		c=p;
 		p=c_p[c];
 		ans.push_back(findD(p,c));
	 }
	 reverse(ans.begin(),ans.end());
	 cout<<"YES"<<endl;
	 cout<<ans.size()<<endl;
	 cout<<ans<<endl;
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
