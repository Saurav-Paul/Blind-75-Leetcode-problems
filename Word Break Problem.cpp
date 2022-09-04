//https://leetcode.com/problems/word-break/
class Solution {
public:
    unordered_set<string> _set;
    vector<int> mem;
    bool check(string &s, int st){
        
        if(s.size() == st) return mem[st]=true ;
        if(mem[st] != -1) return mem[st] ;
        string temp = "" ;
        
        for(int i = st ;i < s.size() ; i++){
            temp += s[i] ;
            
            if(_set.find(temp) != _set.end()){
                bool isOk = check(s,i+1) ;
                if(isOk) return mem[st]=true ;
            }
        }
        
        return mem[st]=false ;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        mem.assign(s.size() + 1, -1) ;
        for(auto s : wordDict){
            _set.insert(s) ;
        }
        return check(s,0);   
    }
};
