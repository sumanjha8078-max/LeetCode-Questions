class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 3){
            int prod = 1;
            for(int i = 0 ; i < 3 ; i++){
                prod*=nums[i];
            }
            return prod;
        }
        sort(nums.begin(),nums.end());
        return max(nums[0]*nums[1]*nums[n-1],nums[n-1]*nums[n-2]*nums[n-3]);
    }
};