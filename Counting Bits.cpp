//https://leetcode.com/problems/counting-bits/
class Solution {
public:
    int count_bit(int n){
        if(n == 0) return 0;
        return (n&1) + count_bit(n >> 1) ;
    }
    vector<int> countBits(int n) {
        vector<int> ans ;
        for(int i = 0 ; i <= n ; i++){
            ans.push_back(count_bit(i)) ;
        }
        return ans ;
    }
};
