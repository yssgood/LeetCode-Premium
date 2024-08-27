class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.empty()) return true; 
        sort(intervals.begin(), intervals.end()); 
        int currTime = intervals[0][1]; 

        for(int i = 1; i < intervals.size(); i++){
            int startTime = intervals[i][0]; 
            int endTime = intervals[i][1]; 

            if(currTime  > startTime) return false; 
            currTime = endTime; 
        }
        return true; 
    }
};