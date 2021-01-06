#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
vector<int> graph[N];
vector<int> cycles[N];

void DFSCycle(int u, int p, int color[], int mark[], int par[], int& cyclenumber){

   if (color[u] == 2) {
      return;
   }

   if (color[u] == 1) {
      cyclenumber++;
      int cur = p;
      mark[cur] = cyclenumber;
      while (cur != u) {
         cur = par[cur];
         mark[cur] = cyclenumber;
      }
      return;
   }

   par[u] = p;
   color[u] = 1;

   for (int v : graph[u]) {
      if (v == par[u]) {
         continue;
      }
      DFSCycle(v, u, color, mark, par, cyclenumber);
   }
   color[u] = 2;
}

void insert(int u, int v){
   graph[u].push_back(v);
   graph[v].push_back(u);
}

void printCycles(int edges, int mark[], int& cyclenumber){

   for (int i = 1; i <= edges; i++) {
      if (mark[i] != 0)
         cycles[mark[i]].push_back(i);
   }

   for (int i = 1; i <= cyclenumber; i++) {
      cout << "Cycle " << i << ": ";
      for (int x : cycles[i])
         cout << x << " ";
      cout << endl;
   }
}

int main(){
   insert(0, 1);
   insert(1, 2);
   insert(2, 3);
   insert(3, 4);
   insert(4, 1);
   //insert(3, 5);
   insert(5, 6);
   insert(6, 7);
   insert(5, 7);
   //new component
   insert(8,10);
   insert(9, 10);
   insert(10, 11);
   insert(11, 9);
   insert(11,0);

   int color[N];
   int par[N];
   int mark[N];
   int cyclenumber = 0;

   cout<<"Cycles in the Graph are :\n";
   int edges = 12;
   for(int i=0;i<edges;i++){
      DFSCycle(i, -1, color, mark, par, cyclenumber);
   }
   printCycles(edges, mark, cyclenumber);
}
