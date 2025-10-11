class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer; 
        int index = 0;
        for(int i = index; i < intervals.size(); i++){
            if(intervals[i][1] < newInterval[0]){
                answer.push_back(intervals[i]);
                index++; 
            }
        }

        for(int i = index; i < intervals.size(); i++){
            int start = intervals[i][0]; 
            if(start <= newInterval[1]){
                newInterval[0] = min(newInterval[0], start);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                index++; 
            }
        }

        answer.push_back(newInterval); 

        for(int i = index; i < intervals.size(); i++){
            answer.push_back(intervals[i]); 
        }

        return answer; 
    }
};