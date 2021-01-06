class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size()-1;
        if(bits[len] != 0){
            return false;
        }
        int i =0;
        while(i<=len){
            if(bits[i] == 0){
                i++;
                if(i>len){
                    return true;
                }
            }
            if(bits[i] == 1){
                i = i+2;
                if(i>len){
                    return false;
                }
            }
        }
        return false;
    }
};
