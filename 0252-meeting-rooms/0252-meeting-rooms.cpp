class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.empty()) return true; 
        sort(intervals.begin(), intervals.end(),[](vector<int>& a, vector<int>& b){
            return a[0] < b[0]; 
        });

        int currEnd = intervals[0][1]; 

        for(int i = 1; i < intervals.size(); i++){
            int nextStart = intervals[i][0]; 
            int nextEnd = intervals[i][1]; 

            if(nextStart < currEnd) return false; 

            currEnd = nextEnd; 
        }

        return true; 
    }
};