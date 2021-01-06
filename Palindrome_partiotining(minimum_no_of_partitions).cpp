#include<bits/stdc++.h>
using namespace std;

int minimum = INT_MAX;

bool ispalindrome(string s,int i,int j){
    int beg = i;
    int ed = j;
    while(beg<ed){
        if(s[beg]!=s[ed]){
            return false;
        }
        beg++;
        ed--;
    }
    return true;
}


int solve(string s,int i,int j){
    if(i>=j){
        return 0;
    }
    if(ispalindrome(s,i,j-1)){
        return 0;
    }
    for(int k=i;k<j;k++){
        int temp = solve(s,i,k)+solve(s,k+1,j)+1;
        if(temp<minimum){
            minimum = temp;
        }
    }
    return minimum;
}

int main(){
    string s;
    cout<<"Enter a string"<<endl;
    cin>>s;
    int op;
    op = solve(s,0,s.length());
    cout<<op<<endl;
}
