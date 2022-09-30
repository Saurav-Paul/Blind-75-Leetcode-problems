//https://leetcode.com/problems/word-search/
class Solution {
public:
    int n, m ;
    
    vector< pair<int,int> > direction = {
            make_pair(0,1), make_pair(0,-1),
            make_pair(1,0), make_pair(-1,0)
        };
    
    bool check(vector<vector<char>> &board, string &word,int i,int j,int index,vector<vector<bool>> &isVisited){
        if(word.size() == index) return true;

        if(i < 0 || j < 0) return false;
        
        if(i == n or j == m) return false;
        
        if(board[i][j] != word[index]) return false;
        
        if(isVisited[i][j]){
            return false;
        }

        
        if(board[i][j])
        
        isVisited[i][j] = true;
        
        for(auto x : direction){
            int ti = i + x.first ;
            int tj = j + x.second ;
            bool is_ok = check(board,word,ti,tj,index+1,isVisited) ;
            if(is_ok) return true;
        }
        isVisited[i][j] = false;
        return false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size() ;
        m = board[0].size() ;
        
        vector<vector<bool> > isVisited(n, vector<bool>(m,false)) ;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                bool is_ok = check(board,word,i,j,0,isVisited) ;
                
                if(is_ok) return true;
            }
        }
        
        return false;
        
    }
};
