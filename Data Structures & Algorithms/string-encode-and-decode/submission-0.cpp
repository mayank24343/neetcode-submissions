class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for (auto& s : strs){
            result += s + '\n';
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string curr = "";
        for (char c : s){
            if (c == '\n') {
                result.push_back(curr);
                curr = "";
                continue;
            }
            curr+=c;
        }

        return result;
    }
};
