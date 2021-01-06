class Solution {
public:
    bool detect_cycle_util(int curr,vector<vector<int>>& adj,vector<int>& visited){
        if(visited[curr] == 1){
            return true;
        }
        if(visited[curr] == 2){
            return false;
        }
        visited[curr] = 1;
        for(int i=0;i<adj[curr].size();i++){
            if(detect_cycle_util(adj[curr][i],adj,visited)){
                return true;
            }
        }
        visited[curr] = 2;
        return false;
    }
    bool detectCycle(vector<vector<int>>& adj,int n){
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                if(detect_cycle_util(i,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    void dfs(vector<vector<int>>& adj,int curr,vector<bool>& visited,stack<int>& s){
        visited[curr] = true;
        for(int i=0;i<adj[curr].size();i++){
            if(!visited[adj[curr][i]]){
                dfs(adj,adj[curr][i],visited,s);
            }
        }
        s.push(curr);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> ans;
        if(detectCycle(adj,numCourses)){
            return ans;
        }
        stack<int> s;
        vector<bool> visited(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                dfs(adj,i,visited,s);
            }
        }
        while(s.empty() == false){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
