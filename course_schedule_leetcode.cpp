class Solution {
public:
    //0--means(not visited)
    //1--means(visited)
    //2--means(visited and fully explored)
    //We wre checking for cycles in graph if any cycle present then it is not possible to complete the courses(DAG)
    bool iscyclic(vector<vector<int>>& adj,vector<int>& visited,int i){
        if(visited[i] == 1){
            return true;
        }
        visited[i] = 1;
        for(int j=0;j<adj[i].size();j++){
            if(visited[adj[i][j]]!=2){
                if(iscyclic(adj,visited,adj[i][j])){
                    return true;
                }
            }
        }
        visited[i] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();++i){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visited[i] == 0){
                if(iscyclic(adj,visited,i)){
                    return false;
                }
            }
        }
        return true;
    }
};

