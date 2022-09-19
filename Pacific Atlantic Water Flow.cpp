//https://leetcode.com/problems/pacific-atlantic-water-flow/
class Solution {
public:

    void bfs(vector< vector<int> > &heights, int n , int m,
    vector< vector<bool > > &isVisited, queue< pair<int, int> > &q                   
    ){
        
        auto isOk = [&](int i, int j, int val){
            if(i < 0 || i == n) return false;
            if(j < 0 || j == m) return false;
            if(isVisited[i][j] == true) return false;
            if(heights[i][j] < val) return false;
            return true;
        };
        
        
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop() ;
            
            int i = p.first, j = p.second ;
            
            if(isVisited[i][j]) continue ;
            
            isVisited[i][j] = true;
            int val = heights[i][j] ;
            
            vector< vector<int> > dimension = {
                {-1,1,0,0}, {0,0,-1,1}
            } ;
            
            for(int k = 0 ; k < 4 ; k++){
                int x = i + dimension[0][k] ;
                int y = j + dimension[1][k] ;
                if(isOk(x,y,val)){
                    q.push(make_pair(x,y)) ;
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size() ;
        
        vector< vector<bool > > a(n, vector<bool>(m,false)), b ;
        b = a;
        
        queue< pair<int,int> > qa, qb ;
        
        for(int i = 0 ; i < n ; i++){
            qa.push(make_pair(i,0)) ;
            qb.push(make_pair(i, m-1)) ;
        }
        
        for(int i = 0 ; i < m ; i++){
            qa.push(make_pair(0,i)) ;
            qb.push(make_pair(n-1, i)) ;
        }
        
        bfs(heights, n, m, a, qa) ;
        bfs(heights, n, m , b, qb) ;
        
        vector< vector<int> > ans ;
        
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m ; j++){
                if(a[i][j] && b[i][j]){
                    vector<int> v = {i, j} ;
                    ans.push_back(v) ;
                }
            }
        }
        
        return ans;
        
    }
};

