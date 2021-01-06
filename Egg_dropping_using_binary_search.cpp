#include<bits/stdc++.h>
using namespace std;


int solve(int f,int e,vector<vector<int>>& v){
    if(f == 0||f == 1){
        return f;
    }
    if(e == 1){
        return f;
    }
    if(v[f][e] != -1){
        return v[f][e];
    }
    int l = 1;
    int r = f;
    int minimum = INT_MAX;
    while(l<=r){
        int mid = l+(r-l)/2;
        int l_h = solve(mid-1,e-1,v);
        int u_h = solve(f-mid,e,v);
        minimum = min(minimum,1+max(l_h,u_h));
        if(l_h > u_h){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    v[f][e] = minimum;
    return minimum;
}

int main(){
    int f;
    cout<<"Enter the number of floors in building"<<endl;
    cin>>f;
    int e;
    cout<<"Enter the number of eggs we have to find the critical floor"<<endl;
    cin>>e;
    vector<vector<int>> v(f+1,vector<int>(e+1,-1));
    int op = 0;
    op = solve(f,e,v);
    cout<<op<<endl;
    return 0;
}
