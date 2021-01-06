#include<bits/stdc++.h>
using namespace std;
int minimum = INT_MAX;

void solve(vector<vector<int>>& v,int x,int y,int i,int j,int sum,vector<vector<int>>& explored){
	if(i<0 || j<0 || i>=v.size() || j>=v[i].size() || explored[i][j] == true){
		return;
	}
	if(i==x && j==y){
		minimum = min(sum,minimum);
		return;
		//cout<<sum<<endl;
	}
	sum = sum+v[i][j];
	explored[i][j] = true;
	solve(v,x,y,i+1,j,sum,explored);
	solve(v,x,y,i-1,j,sum,explored);
	solve(v,x,y,i,j+1,sum,explored);
	solve(v,x,y,i,j-1,sum,explored);
	sum = sum-v[i][j];
	explored[i][j] = false;
	return;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int x;
		int y;
		cin>>x;
		cin>>y;
		vector<vector<int>> v{10000,vector<int>{10000,1}};
		vector<vector<int>> explored{10000,vector<int>{10000,false}};
		int sum = 0;
		solve(v,x,y,0,0,sum,explored);
		cout<<minimum<<endl;
	}
}
