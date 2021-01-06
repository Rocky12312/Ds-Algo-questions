#include<bits/stdc++.h>
using namespace std;

string longest_common_subsequence(string s,string t) {
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
    for(int i=1;i<a+1;i++){
        for(int j=1;j<b+1;j++){
            if(s[i-1] == t[j-1]){
                ax[i][j] = 1+ax[i-1][j-1];
            }
            else{
            	ax[i][j] = max(ax[i-1][j],ax[i][j-1]);
            }
        }
    }
    int i=a;
    int j=b;
    string res;
    while(i>=0 && j>=0){
        if(s[i-1] == t[j-1]){
            res.push_back(s[i-1]);
            i--;
            j--;
        }else{
            if(ax[i][j-1]>ax[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
	string s = "aacecaaa";
    string t = "aabcdeaa";
    string res;
	res = longest_common_subsequence(s,t);
	cout<<res<<endl;
}