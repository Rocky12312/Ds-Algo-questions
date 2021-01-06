class Solution {
public:
    void solve(int i,int j,int a,int b,vector<vector<int>> &grid,vector<string> &v,string &s){
        if(i == a && j == b){
            v.push_back(s);
            return;
        }
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        s.push_back('h'-32);
        solve(i,j+1,a,b,grid,v,s);
        s.pop_back();
        grid[i][j] = 1;
        s.push_back('v'-32);
        solve(i+1,j,a,b,grid,v,s);
        s.pop_back();
        grid[i][j] = 1;
        return;
    }
    string kthSmallestPath(vector<int>& destination, int k) {
        vector<string> v;
        string s = "";
        int a = destination[0];
        int b = destination[1];
        vector<vector<int>> grid(a+1,vector<int>(b+1,1));
        solve(0,0,a,b,grid,v,s);
        sort(v.begin(),v.end());
        int count = 0;
        string op;
        for(int i = 0;i<v.size();i++){
            if(count+1 == k){
                op = v[i];
                break;
            }
            count++;
        }
        return op;
    }
};
