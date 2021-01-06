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
    int minimum = INT_MAX;
    for(int k=1;k<=f;k++){
        int low;
        int high;
        if(v[k-1][e-1] != -1){
            low = v[k-1][e-1];
        }else{
            low = solve(k-1,e-1,v);
            v[k-1][e-1] = low;
        }
        if(v[f-k][e] != -1){
            high = v[f-k][e];
        }else{
            high = solve(f-k,e,v);
            v[f-k][e] = high;
        }
        int temp = 1+max(low,high);
        minimum = min(minimum,temp);
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
