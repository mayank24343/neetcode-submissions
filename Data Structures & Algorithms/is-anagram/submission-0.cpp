class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char,int> s_freq;
        for (char c : s){
            s_freq[c]++;
        }

        for (char c : t){
            if (s_freq.count(c)){
                if (s_freq[c] > 0){
                    s_freq[c]--;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }

        return true;
    }
};
