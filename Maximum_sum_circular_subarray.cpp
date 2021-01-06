class Solution {
public:
    int msub(vector<int>& arr){
        int max_ending_here = arr[0];
        int max_so_far = arr[0];
        for(int i=1;i<arr.size();i++){
            max_ending_here = max(max_ending_here+arr[i],arr[i]);
            max_so_far = max(max_so_far,max_ending_here);
        }
        return max_so_far;
    }
    
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() == 0){
            return 0;
        }
        int non_circular_subarray_sum = msub(A);
        int full_arr_sum = 0;
        for(int i=0;i<A.size();i++){
            full_arr_sum = full_arr_sum+A[i];
            A[i] = -A[i];
        }
        int circular_subarray_sum = full_arr_sum+msub(A);
        if(circular_subarray_sum == 0){
            return non_circular_subarray_sum;
        }
        return max(circular_subarray_sum,non_circular_subarray_sum);
    }
};
