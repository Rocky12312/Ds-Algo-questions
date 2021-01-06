//Detecting cycles in a undirected graph
#include<bits/stdc++.h>

using namespace std;
const int N = 10000;
vector<int> graph[N];

void add_edges(int a,int b){
    graph[a].push_back(b);
    graph[b].push_back(a);
}


bool isCyclic_util(int u, vector<int> visited, int parent,vector<int> adj[]){
    visited[u] = true;
    for(int j=0;j<adj[u].size();++j){
        if(visited[adj[u][j]]==false){
            if(isCyclic_util(adj[u][j],visited,u,adj)){
                return true;
            }
        }
        else if(adj[u][j]!=parent){
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V)
{
   vector<int> visited(V,false);
   for(int i=0;i<V;++i){
        if(visited[i] == false){
            if(isCyclic_util(i,visited,-1,adj)){
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
    add_edges(4,2);
    cout << isCyclic(graph, 5)<<endl;
}
