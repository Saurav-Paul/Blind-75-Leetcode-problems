//https://leetcode.com/problems/longest-repeating-character-replacement/
class Solution {
public:
    int freq(unordered_map<char,int> _mp){
        int mx = 0 ;
        for(auto x : _mp){
            mx = max(mx, x.second) ;
        }
        return mx;
    }
    int characterReplacement(string &s, int k) {
        int n = s.size() ;

        unordered_map<char, int > _mp ;
        
        int l=0, r=0, ans=0 ;
        
        while(r < n){
            _mp[s[r]] ++;
            
            int f = freq(_mp);
            
            if(f + k >= r - l + 1){
                ans = max(ans, r - l + 1);
            }
            else{
                _mp[s[l]] --;
                ++l;
            }
            
            ++ r;
            
        }
        
        return ans;
    }
};
