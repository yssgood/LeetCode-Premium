class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer; 
        sort(intervals.begin(), intervals.end(),[](vector<int>& a, vector<int>& b){
            return a[0] < b[0]; 
        }); 

        for(int i = 0; i < intervals.size();){
            int currRight = intervals[i][1]; 
            int currLeft = intervals[i][0]; 
            while(i + 1 < intervals.size() && currRight >= intervals[i+1][0]){
                currRight = max(currRight, intervals[i+1][1]); 
                i++; 
            }

            answer.push_back({currLeft,currRight}); 
            i++; 
        }

        return answer; 
    }
};