#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> twosum(vector<int>& v,int target,int start){
	vector<vector<int>> res;
	int left = start;
	int right = v.size()-1;
	while(left<right){
		int comb_sum = v[left]+v[right];
		if(comb_sum<target || (left>start && v[left] == v[left-1])){
			++left;
		}
		else if(comb_sum>target || (right<v.size()-1 || v[right] == v[right-1])){
			++right;
		}
		else{
			res.push_back({v[left++],v[right--]});
		}
	}
	return res;
}

vector<vector<int>> ksum(vector<int>& v,int target,int start,int k){
	vector<vector<int>> res;
	if(start == v.size() || v[start]*3>target || v.back()*3<target){
		return res;
	}
	if(k == 2){
		return twosum(v,target,start);
	}
	for(int i=start;i<v.size();++i){
		if(i == start || v[i-1]!=v[i]){
			for(auto &p:ksum(v,target-v[i],i+1,k-1)){
				res.push_back({v[i]});
				res.back().insert(end(res.back()),begin(p),end(p));
			}
		}
	}
	return res;
}

vector<vector<int>> solve(vector<int>& v,int target,int k){
	sort(begin(v),end(v));
	return ksum(v,target,0,k);
}

int main(){
	int target;
	cout<<"Enter the target sum of which you want pairs"<<endl;
	cin>>target;
	int k;
	cout<<"Enter the value of k(the size of subsets which you want to take sum of from input vector)"<<endl;
	cin>>k;
	vector<int> v={-1,0,1,2,-1,-4};
	vector<vector<int>> op;
	op = solve(v,target,k);
	for(int i=0;i<op.size();i++){
		for(int j=0;j<op[i].size();j++){
			cout<<op[i][j];
		}
		cout<<endl;
	}
}
