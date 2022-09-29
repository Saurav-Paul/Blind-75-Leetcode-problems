//https://leetcode.com/problems/spiral-matrix/submissions/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans ;
        int n = matrix.size();
        int m = matrix[0].size() ;
        
        int total = n * m ;
        
        vector< pair<int,int> > dimension = {
            make_pair(0,1), make_pair(1,0) ,
            make_pair(0,-1), make_pair(-1,0)
        };
        
        int i = 0 , j = 0;
        
        auto is_ok = [&](int ti, int tj){
            if(ti < 0 || tj < 0) return false;
            if(ti == n || tj == m) return false;
            if(matrix[ti][tj] == -1000) return false;
            return true;
        };
        
        if(total){
            ans.push_back(matrix[i][j]) ;
            matrix[i][j] = -1000;
            -- total;
        }
        
        while(total){
            for(auto x : dimension){
                int ti = i + x.first, tj = j + x.second ;
                
                while(is_ok(ti,tj) && total){
                    i = ti;
                    j = tj;
                    ans.push_back(matrix[i][j]);
                    matrix[i][j] = -1000;
                    ti += x.first ;
                    tj += x.second ;
                    -- total;
                }
            }
        }
        
        return ans ;
    }
};
