class Solution {
public:
    vector<vector<string>> v;
    vector<string> vs;
    bool ispalindrome(string s){
        if(s.length() == 0 || s.length() == 1){
            return true;
        }
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string s,int start){
        string temp;
        if(s.length() == start){
            v.push_back(vs);
            return;
        }
        for(int i=start;i<s.length();i++){
            temp = temp+s[i];
            if(ispalindrome(temp)){
                vs.push_back(temp);
                solve(s,i+1);
                vs.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        solve(s,0);
        return v;
    }
};
