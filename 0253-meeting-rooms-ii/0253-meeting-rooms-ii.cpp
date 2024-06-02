class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return 1; 
        int answer = 1; 
        sort(intervals.begin(),intervals.end()); 
        priority_queue<int,vector<int>,greater<int>> pq; 
        pq.push(intervals[0][1]); 

        for(int i = 1; i < intervals.size(); i++){
            int next = intervals[i][0], nextStart = intervals[i][1]; 
            if(pq.top() > next){
                pq.push(nextStart); 
            } else{
                pq.pop(); 
                pq.push(nextStart); 
            }
        }
        
        return pq.size(); 
    }
};
