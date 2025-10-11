class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer; 
        sort(intervals.begin(), intervals.end()); 
        int prev = intervals[0][1]; 
        answer.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            int next = intervals[i][0]; 
            if(prev >= next){
                prev = max(prev,intervals[i][1]); 
                answer[answer.size()-1][1] = max(answer[answer.size()-1][1], intervals[i][1]); 
            } else{
                prev = intervals[i][1]; 
                answer.push_back(intervals[i]); 
            }
        }
        return answer; 
    }
};