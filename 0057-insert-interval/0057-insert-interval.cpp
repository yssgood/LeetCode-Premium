class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()) return {{newInterval[0],newInterval[1]}}; 
        vector<vector<int>> answer; 
        bool flag = false; 
        for(int i = 0; i < intervals.size(); i++){
            vector<int> curr = intervals[i]; 
            if(curr[1] >= newInterval[0] && !flag){
                flag = true; 
                if(newInterval[1] < curr[0]){
                    answer.push_back(newInterval); 
                    answer.push_back(curr); 
                    continue; 
                }
                curr[0] = min(curr[0],newInterval[0]); 
                curr[1] = max(curr[1],newInterval[1]); 
                while(i + 1 < intervals.size() && newInterval[1] >= intervals[i+1][0]){
                    curr[1] = max(curr[1],intervals[i+1][1]); 
                    i++; 
                }
            }
            answer.push_back(curr); 
        }
        if(!flag) answer.push_back(newInterval);
        return answer;  
    }
};