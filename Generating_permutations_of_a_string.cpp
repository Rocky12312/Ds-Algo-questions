#include<bits/stdc++.h>
using namespace std;
vector<string> v;
static int permutation_count = 0;

void solve(string s,string t,int idx,vector<bool>&present){
	if(t.length()-1 == s.length()-1){
		permutation_count++;
		v.push_back(t);
		return;
	}
	for(int i=0;i<s.length();i++){
		if(!present[i]){
			present[i] = true;
			t.push_back(s[i]);
			solve(s,t,i+1,present);
			present[i] = false;
			t.pop_back();
		}
	}
	return;
}

int main(){
	string a = "abcdefghij";
	string op = "";
	vector<bool> present(a.size(),false);
	solve(a,op,0,present);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	cout<<"The number of permutation of string is "<<permutation_count<<endl;
	return 0;
}
