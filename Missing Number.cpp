//https://leetcode.com/problems/find-all-duplicates-in-an-array/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans ;
        
        for(int i = 0 ; i < nums.size() ; i++){
            int curr = abs(nums[i]) - 1;
            if(nums[curr] < 0) ans.push_back(curr+1) ;
            else nums[curr] = -nums[curr];
        }
        
        return ans ;
    }
};
