//Detecting cycles in a directed graph(graph coloring)
#include<bits/stdc++.h>

using namespace std;
const int N = 10000;
vector<int> graph[N];

void add_edges(int a,int b){
    graph[a].push_back(b);
}
bool isCyclic_util(vector<int> adj[], vector<int> visited, int curr)
{
    if(visited[curr]==1){
        return true;
    }
    
    visited[curr] = 1;
    for(int j=0;j<adj[curr].size();++j)
    {
        if(visited[adj[curr][j]]!=2){
            if(isCyclic_util(adj,visited,adj[curr][j])){
                return true;
            }
        }
    }
    visited[curr] = 2;
    return false;
}

bool isCyclic(vector<int> adj[], int V){
    vector<int> visited(V,0);
    for(int i=0;i<V;++i){
        if(visited[i] == 0){
            if(isCyclic_util(adj,visited,i)){
                return true;
            }
        }
   }
   return false;
}

int main(){
    add_edges(0,1);
    add_edges(1,2);
    add_edges(2,3);
    add_edges(3,4);
    add_edges(4,0);
    bool op = isCyclic(graph, 5);
    if(op){
        cout<<"There is cycle"<<endl;
    }else{
        cout<<"There is no cycle"<<endl;
    }
    return 0;
}
