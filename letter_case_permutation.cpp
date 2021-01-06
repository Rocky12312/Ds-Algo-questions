class Solution {
public:
    vector<string> ans;
    string st = "";
    void dfs(int index, string str) {
        if(index > str.size()) {
            ans.push_back(st);
            return;
        }
        
        if(str[index] >= 'a' && str[index] <= 'z') {
            char ch = str[index];
            ch = ch - 32;
            st.push_back(ch);
            dfs(index+1, str);
            st.erase(st.length()-1);
        }
        
        if(str[index] >= 'A' && str[index] <= 'Z') {
            char ch = str[index];
            ch = ch + 32;
            st.push_back(ch);
            dfs(index+1, str);
            st.erase(st.length()-1);
        }
        st.push_back(str[index]);
        dfs(index+1, str);
        st.erase(st.length()-1);
    }
    vector<string> letterCasePermutation(string S) {
        dfs(0, S);
        return ans;
    }
};
