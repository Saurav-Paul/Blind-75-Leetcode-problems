//https://leetcode.com/problems/palindromic-substrings/
class Solution {
public:
    int getCount(string &s, int l, int r){
        int cnt = 0 ;
        while(l >=0 and r < s.size()){
            if(s[l] != s[r]) break;
            ++ cnt ;
            l--, r++;
        }
        return cnt ;
    }
    
    int countSubstrings(string &s) {
        long long sum = 0 ;
        
        for(int i = 0 ; i < s.size() ; i++){
            sum += getCount(s, i, i) ;
            
            if(i + 1 < s.size()){
                sum += getCount(s, i, i+1) ;
            }
        }
        
        return sum;
    }
};
