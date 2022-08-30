//https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n+1,1), prefix(n,1), ans;
        
        for(int i = 0 ; i < n ; i++){
            if(i){
                prefix[i] = prefix[i-1] * nums[i] ;
            }
            else prefix[i] = nums[i] ;
        }
        
        
        for(int i = n - 1; i >= 0 ; i--){
            if(i < n - 1){
                suffix[i] = suffix[i+1] * nums[i] ;
            }
            else suffix[i] = nums[i] ;
        }
        
        for(int i = 0 ; i < n ; i++){
            if(i == 0){
                ans.push_back(suffix[i+1]) ;
            }
            else if(i == n - 1){
                ans.push_back(prefix[i-1]) ;
            }
            else ans.push_back(prefix[i-1] * suffix[i+1]) ;
        }
        
        return ans ;
        
    }
};
