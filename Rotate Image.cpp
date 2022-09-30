//https://leetcode.com/problems/rotate-image/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size();
        
        // transposing each matrix
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < m ; j++){
                swap(matrix[i][j], matrix[j][i]) ;
            }
        }
        
        // reversing each row
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m / 2; j++){
                swap(matrix[i][j], matrix[i][m-j-1]) ;
            }
        }
        
    }
};
