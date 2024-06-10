class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return 1; 

        sort(intervals.begin(), intervals.end()); 
        priority_queue<int,vector<int>,greater<int>> pq; 
        pq.push(intervals[0][1]); 

        for(int i = 1; i < intervals.size(); i++){
            int next_start = intervals[i][0]; 
            int next_end = intervals[i][1]; 
            if(!pq.empty() && pq.top() <= next_start){
                pq.pop(); 
            } 
            pq.push(next_end);
        }

        return pq.size(); 
    }
};