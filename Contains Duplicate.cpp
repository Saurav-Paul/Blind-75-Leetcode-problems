//https://leetcode.com/problems/contains-duplicate/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> _set;
        
        for(auto x : nums){
            if(_set.find(x) != _set.end()) return true;
            _set.insert(x) ;
        }
        return false;
    }
};
