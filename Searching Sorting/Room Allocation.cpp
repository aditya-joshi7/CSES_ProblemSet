#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define all(c) (c).begin(), (c).end()
const int md = 1000000007;

vector<vector<ll>> multiply(vector<vector<ll>> x, vector<vector<ll>> y,int m) {
    vector<vector<ll>> z(m, vector<ll>(y[0].size()));
    for (int i = 0; i < m; i++) 
        for (long unsigned int j = 0; j < y[0].size(); j++) 
            for ( int k = 0; k < m; k++) 
                (z[i][j] += x[i][k]*y[k][j]);
    return z;
}






void solve(){
 int n;
 cin>>n;
 vector<pair<int,int>> arr(n);
 vector<pair<int,int>> dep(n);
 vector<int> plt(n,-1);
 
 for(int i=0;i<n;i++){
 	int a,b;
 	
 	cin>>arr[i].first>>dep[i].first;
 //	dep[i].first;
 	arr[i].second=i;dep[i].second=i;
 	
 }
 
 
 sort(arr.begin(),arr.end());sort(dep.begin(),dep.end());
 plt[arr[0].second]=1;
 int len=1;
 int ans=INT_MIN;int i=1;int j=0;
 
 //plt[arr[i].second]=len;
 while(i<n && j<n){
 	if(arr[i].first<=dep[j].first){
 		len++;
 		if(arr[i].second!=-1){
 			plt[arr[i].second]=len;
		 }
 		
 		i++;
	 }
	 else{
	 	len--;
	 	
	 	if(arr[i].second!=-1){
 			plt[dep[i].second]=len;
		 }
	 	j++;
	 	
	 }
 	
 	ans=max(ans,len);
 	
 }
 
 
 cout<<ans<<endl;
 for(int i=0;i<n;i++){
 	cout<<plt[i]<<" ";
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
