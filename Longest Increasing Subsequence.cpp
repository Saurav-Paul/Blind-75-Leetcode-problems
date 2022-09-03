//https://leetcode.com/problems/longest-increasing-subsequence/
// o(n logn)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp ;
        
        int p = - 1;
        
        for(int i = 0 ;i < nums.size() ; i++){
            if(dp.empty() or dp.back() < nums[i]){
                dp.push_back(nums[i]) ;
            }
            else{
                int lowPos = lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();
                dp[lowPos] = nums[i] ;
            }
        }
        
        return dp.size();
    }
};

// o(n^2)
class Solution {
public:
    int find_ans(vector<int> &nums, int curr, vector<int> &mem){
        int cnt = 0 ;
        
        if(mem[curr] != -1) return mem[curr] ;
        
        for(int i = curr + 1; i < nums.size() ; i++){
            if(nums[i] > nums[curr]){
                cnt = max(cnt, find_ans(nums,i,mem)) ;
            }
        }
        
        return mem[curr]=cnt + 1;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> dp(nums.size() + 1, -1) ;

        int ans = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            ans = max(ans, find_ans(nums,i, dp)) ;
        }
        
        return ans ;
    }
};
