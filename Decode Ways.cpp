//https://leetcode.com/problems/decode-ways/
class Solution {
public:
    vector<int> dp;
    
    bool isOk(string &temp){
        int num = 0 ;
        
        for(auto c : temp){
            num *= 10 ;
            num += (c - '0');
        }

        if(num > 0 && num < 27) return true;
        return false ;
    }
    
    int find_ans(string &s, int index){
        if(index == s.size()){
            return 1;
        }
        
        if(s[index] == '0') return 0 ;
        
        if(dp[index] != -1) return dp[index] ;
        
        int cnt = 0 ;
        
        string temp = "";
        
        for(int i = index ; i < s.size() ; i++){
            temp += s[i] ;
            if(isOk(temp)){
                cnt += find_ans(s, i + 1) ;
            }
            else break ;
        }
        
        return dp[index] = cnt ;
    }
    
    int numDecodings(string s) {
        int n = s.size() ;
        dp.assign(n,-1) ;
        return find_ans(s,0) ;
    }
};
