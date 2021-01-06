#include<bits/stdc++.h>
using namespace std;
//Longest common substring
string longest_common_substring(string s,string t) {
    int a = s.length();
    int b = t.length();
    int ax[a+1][b+1];
    for(int i=0;i<a+1;i++){
        for(int j=0;j<b+1;j++){
            if(i==0 || j==0){
            	ax[i][j] = 0;
            }
        }
    }
    int p=0;
    int q=0;
    int resp=INT_MIN;
    for(int i=1;i<a+1;i++){
        for(int j=1;j<b+1;j++){
            if(s[i-1] == t[j-1]){
                ax[i][j] = 1+ax[i-1][j-1];
            }
            else{
            	ax[i][j] = 0;
            }
            if(ax[i][j]>resp){
                resp=ax[i][j];
                p=i;
                q=j;
            }
        }
    }
    string res;
    while(p>=0 && q>=0 && ax[p][q]!=0){
        res.push_back(s[p-1]);
        p--;
        q--;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
	string s = "abcinitindef";
    string t = "fedinitincba";
    string res;
	res = longest_common_substring(s,t);
	cout<<res<<endl;
}