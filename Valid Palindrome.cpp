//https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        
        for(auto x : s){
            if((x >= 'a' and x <='z') or (x >= 'A' and x <= 'Z')
              or (x >= '0' and x <= '9')){
                if(x >= 'A' and x <= 'Z'){
                    temp += (x - 'A' + 'a') ;
                }
                else
                    temp += x;
            }
        }
        
        for(int i = 0, j = temp.size() -1 ; i < j ; i++, j--){
            if(temp[i] != temp[j]){
                return false;
            }
        }
        
        return true;
    }
};
