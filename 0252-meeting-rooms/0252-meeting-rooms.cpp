class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return true; 
        sort(intervals.begin(), intervals.end()); 
        for(int i = 1; i < intervals.size(); i++){
            int previous = intervals[i-1][1], current = intervals[i][0];
            if(previous > current) return false; 
        }
        return true; 
    }
};