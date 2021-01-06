class Solution {
public:
    int max_score = INT_MIN;
    static bool compare(pair<int,int> a,pair<int,int> b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        for(int i=0;i<scores.size();i++){
            pair<int,int> p;
            p.first = ages[i];
            p.second = scores[i];
            v.push_back(p);
        }
        sort(v.begin(),v.end(),compare);
        for(int i=0;i<v.size();i++){
            cout<<v[i].first<<endl;
            cout<<v[i].second<<endl;
        }
        vector<int> lis(v.size(),-1);
        for(int i=0;i<lis.size();i++){
            lis[i] = v[i].second;
            for(int j=0;j<i;j++){
                if((v[i].second >= v[j].second) && lis[j]+v[i].second > lis[i]){
                    lis[i] = lis[j]+v[i].second;
                }
            }
        }
        for(int i=0;i<lis.size();i++){
            max_score = max(max_score,lis[i]);
        }
        return max_score;
    }
};
