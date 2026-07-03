class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int mx = heights[0], curr;
        heights.push_back(0);
        
        for (int i = 0; i < heights.size(); i++){
            
            while (!s.empty() && heights[s.top()] > heights[i]){
                int ind = s.top();
                s.pop();
                curr = s.empty() ? heights[ind]*(i) : heights[ind]*(i - s.top()-1);
                mx = max(mx, curr);
            }
            s.push(i);
        }

        return mx;
    }
};
