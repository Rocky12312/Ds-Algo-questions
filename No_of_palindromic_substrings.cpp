class Solution {
public:
    int countSubstrings(string s) {
        int len=s.length();
        int i;
        int count=len;
        int low;
        int high;
        for(i=1;i<len;i++){   
            low=i-1;
            high=i;
            while(low>=0&&high<len&& s[low]==s[high]){
                count++;
                low--;
                high++;
            } 
            low=i-1;
            high=i+1;
            while(low>=0&&high<len&& s[low]==s[high]){
                count++;
                low--;
                high++;
            }
        }
        return count;
    }
};
