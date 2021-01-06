class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int left = 0;
        int right = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                left++;
            }
            if(s[i] == ')'){
                if(left>0){
                    left--;
                }else{
                    s[i] = '*';
                }
            }
            if(s[s.length()-i-1] == ')'){
                right++;
            }
            if(s[s.length()-i-1] == '('){
                if(right>0){
                    right--;
                }else{
                    s[s.length()-i-1] = '*';
                }
            }
        }
        s.erase(remove(s.begin(),s.end(),'*'),s.end());
        return s;
    }
};
