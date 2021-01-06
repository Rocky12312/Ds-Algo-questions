//Prims_algo
#include<bits/stdc++.h>
using namespace std;
#define V 6

int find_min_of_all(vector<int>& value,vector<bool>& include_nodes){
	int min_val = INT_MAX;
	int vertex;
	for(int i=0;i<V;i++){
		if(include_nodes[i] == false && value[i]<min_val){
			min_val = value[i];
			vertex = i;
		}
	}
	return vertex;
}

void prims_mst(int graph[V][V]){
	int parent[V];
	vector<bool> include_nodes(V,false);
	vector<int> value(V,INT_MAX);

	parent[0] = -1;
	value[0] = 0;

	for(int i=0;i<V-1;i++){
		int min_val_index = find_min_of_all(value,include_nodes);
		include_nodes[min_val_index] = true;

		for(int j=0;j<V;j++){
			if(graph[min_val_index][j] != 0 && graph[min_val_index][j]<value[j]){
				value[j] = graph[min_val_index][j];
				parent[j] = min_val_index;
			}
		}
	}
	for(int i=0;i<V;i++){
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";
	}

}

int main(){
	int graph[V][V] = {{0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0}};
	prims_mst(graph);
	return 0;
}
