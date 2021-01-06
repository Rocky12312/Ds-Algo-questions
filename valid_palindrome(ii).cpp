//Gives runtime error(stack overflow as input size is 50000)
class Solution {
public:
    bool ispalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        if(s.length() == 0){
            return true;
        }
        if(ispalindrome(s)){
            return true;
        }
        cout<<"pico"<<endl;
        string p = s;
        cout<<p<<endl;
        reverse(p.begin(),p.end());
        cout<<p<<endl;
        int ax[s.length()+1][p.length()+1];
        for(int i=0;i<s.length()+1;i++){
            for(int j=0;j<p.length()+1;j++){
                if(i==0 || j==0){
                    ax[i][j] = 0;
                }
            }
        }
        for(int i=1;i<s.length()+1;i++){
            for(int j=1;j<p.length()+1;j++){
                if(s[i-1] == p[j-1]){
                    ax[i][j] = 1+ax[i-1][j-1];
                }else{
                    ax[i][j] = max(ax[i-1][j],ax[i][j-1]);
                }
            }
        }
        if(ax[s.length()][p.length()] == s.length()-1){
            return true;
        }
        return false;
    }
};

//Runs fine

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return isPalindrome(i+1, j, s) || isPalindrome(i, j-1, s);
            }
            i++;
            j--;
        }
        return true;
    }
    
    bool isPalindrome(int i, int j, string& s) {
        while(i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

