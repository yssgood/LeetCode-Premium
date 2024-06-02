class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.empty() || intervals.size() < 2) return true; 
        sort(intervals.begin(), intervals.end()); 
        int curr = intervals[0][1]; 
        for(int i = 1; i < intervals.size(); i++){
            int next = intervals[i][0]; 
            int nextStart = intervals[i][1]; 
            if(next < curr) return false; 
            curr = nextStart; 
        }
        return true; 
    }
};