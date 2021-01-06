class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        //Our approach will be using indegree and outdegree for each node
        vector<int> indegree(n + 1 , 0);
        vector<int> outdegree(n + 1 , 0);
        map<pair<int, int> , int> mp;
        for(int i=0;i<n;i++){
            int rc = rightChild[i];
            int lc = leftChild[i];
            if(leftChild[i] != -1){
                indegree[leftChild[i]]++;
                outdegree[i]++;
                if(mp[{lc,i}]){
                    //If already a connection from lc to i exist then return false it is not possible to make connection from i to lc
                    return false;
                }
                mp[{i,lc}]++;
            }
            if(rightChild[i] != -1){
                indegree[rightChild[i]]++;
                outdegree[i]++;
                if(mp[{rc,i}]){
                    return 0;
                }
                mp[{i,rc}]++;
            }
        }
        int var = 0;
        for(int i = 0;i < n;i++){
            if(outdegree[i] > 2 || indegree[i] > 1 || var > 1){
                return 0;
            }
            if((!indegree[i] && (leftChild[i] != -1 || rightChild[i] != -1)))
                var++;
        }
        return (var?1:(n==1?1:0));
    }
};
