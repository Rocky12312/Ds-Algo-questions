class Solution {
public:
    int res = 0;
    vector<string> op;
    string p = "";
    void solve(vector<char>& v,string &ip,int n,int idx){
        if(ip.length() == n){
            p = ip;
            sort(p.begin(),p.end());
            if(p != ip){
                return;
            }
            op.push_back(ip);
            return;
        }
        if(idx > v.size()){
            return;
        }
        for(int i=0;i<v.size();i++){
            ip.push_back(v[i]);
            solve(v,ip,n,i+1);
            ip.pop_back();
        }
        return;
    }
    int countVowelStrings(int n) {
        vector<char> v={'a','e','i','o','u'};
        string ip = "";
        solve(v,ip,n,0);
        for(int i=0;i<op.size();i++){
            cout<<op[i]<<endl;
        }
        return op.size();
    }
};
