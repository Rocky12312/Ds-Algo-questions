#include<bits/stdc++.h>
using namespace std;

void nextPermutation(string &nums) {
    if(nums.size()>1){   
        int i,j,final=0,final1=0,flag=0;
            for(i=0;i<nums.size()-1;i++)
                if(nums[i]<nums[i+1])
                    final=i,flag=1;
            
            for(j=0;j<nums.size();j++)
                if(nums[j]>nums[final])
                    final1=j;
            
            int temp=nums[final];
            nums[final]=nums[final1];
            nums[final1]=temp;
            sort(nums.begin()+final+1,nums.end());
            if(flag==0)
                sort(nums.begin(),nums.end());
        }
    }

int main(){
	string nums = "1992";
	nextPermutation(nums);
	cout<<nums<<endl;
}
