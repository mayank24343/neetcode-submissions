class Solution {
public:
    unordered_map<string, int> memo;
    int numDecodings(string s) {
        if (s.size() == 0) return 1;
        if (memo.count(s)) return memo[s];
        if (s[0] == '0') return memo[s] = 0;
        if (s.size() == 1){
            return memo[s] = 1;
        }
        
        int total = 0;
        total += numDecodings(s.substr(1,s.size()-1));
        
        if ((s[0]-'0')*10+(s[1]-'0') <= 26){
            total += numDecodings(s.substr(2, s.size()-2));
        }
        
       
       return memo[s] = total;
        
    }
};
