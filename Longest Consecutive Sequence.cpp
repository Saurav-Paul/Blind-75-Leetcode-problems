//https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> _set(nums.begin(), nums.end()) ;
        
        int ans = 0, temp = 0 ;
        
        for(auto x : _set){
            if(_set.find(x-1) == _set.end()){
                int num = x;
                int temp = 1;
                
                while(_set.find(num+1) != _set.end()){
                    ++num;
                    ++temp;
                }
                ans = max(ans, temp) ;
            }
        }
        
        return ans;
    }
};
