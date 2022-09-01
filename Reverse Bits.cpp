//https://leetcode.com/problems/reverse-bits/
class Solution {
public:

    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0, bit = 31;
        while(n > 0){
            ans |= ((n&1) << bit);
            n >>= 1 ;
            --bit ;
        }
        return ans ;
    }
};
