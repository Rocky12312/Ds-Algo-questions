#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string s){
    if(s.length() == 0 || s.length() == 1){
        return true;
    }
    int beg = 0;
    int ed = s.length()-1;
    while(beg<ed){
        if(s[beg]!=s[ed]){
            return false;
        }
        beg++;
        ed--;
    }
    return true;
}

void solve(string s,int start,vector<vector<string>>& v,vector<string>& vs){
    string temp;
    if(start = s.length()){
        v.push_back(vs);
        return;
    }
    for(int i=start;i<s.length();i++){
        temp = temp+s[i];
        if(ispalindrome(temp)){
            vs.push_back(temp);
            solve(s,i+1,v,vs);
            vs.pop_back();
        }
    }
    return;
}

int main(){
    string s;
    cout<<"Enter the string"<<endl;
    cin>>s;
    vector<string> vs;
    vector<vector<string>> v;
    solve(s,0,v,vs);
    for(auto i:v){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
