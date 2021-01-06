class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector <string> numbers;
        for (auto &num : nums){
            numbers.push_back(to_string(num));
        }
        sort(numbers.begin(),numbers.end(),[](string &s1,string &s2){
            return s1+s2>s2+s1;
        });
        string fin;
        for (string &number : numbers)
            fin = fin + number;
        if(fin[0] == '0'){
            return "0";
        }
        return fin;   
    }
};

