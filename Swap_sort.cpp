#include<bits/stdc++.h>
using namespace std;

void swap(int*a,int*b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void solve(vector<int>& v){
	int i=0;
	while(i<v.size()){
		if(v[i]!=v[v[i]-1]){
			swap(&v[i],&v[v[i]-1]);
		}else{
			i++;
		}
	}
	for(int i=0;i<v.size();i++){
		if(v[i]!=i+1){
			cout<<"The missing number is "<<i+1<<endl;
			cout<<"The duplicate number is "<<v[i]<<endl;
		}
	}
}

int main(){
	int n;
	cout<<"Enter the size of array"<<endl;
	cin>>n;
	vector<int> v;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		v.push_back(temp);
	}
	solve(v);
	return 0;
}

