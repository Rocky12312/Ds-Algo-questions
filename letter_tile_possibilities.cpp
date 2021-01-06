class Solution {
public:
    unordered_set<string> set;
    void solve(string curr,vector<bool> &visited,string tiles)
    {
        set.insert(curr);
        if(curr.length()<tiles.length())
        {
            for(int i=0;i<tiles.length();i++)
            {
                if(!visited[i])
                {
                    curr.push_back(tiles[i]);
                    visited[i]=true;
                    solve(curr,visited,tiles);
                    visited[i]=false;
                    curr.pop_back();
                }
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        set.clear();
        int n=tiles.length();
        vector<bool> vis(n,false);
        solve("",vis,tiles);
        return set.size()-1;
    }
};
