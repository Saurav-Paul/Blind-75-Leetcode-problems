//https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() ;
        int m = text2.size() ;
        
        vector< vector<int> > dp(n,vector<int> (m,0)) ;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                dp[i][j] = (text1[i] == text2[j]) ;
            }
        }
        
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ;j++){
                int x = dp[i][j] ;
                if(i - 1 >= 0) x = max(x, dp[i-1][j]) ;
                if(j-1 >= 0) x = max(x,dp[i][j-1]) ;
                if(i-1 >= 0 && j-1 >= 0) x = max(x, dp[i][j] + dp[i-1][j-1]) ;
                dp[i][j] = x;
            }
        }
        
        
        return dp[n-1][m-1] ;
    }
};
