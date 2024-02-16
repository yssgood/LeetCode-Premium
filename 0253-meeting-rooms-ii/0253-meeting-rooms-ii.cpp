class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq; 
        sort(intervals.begin(), intervals.end()); 

        pq.push(intervals[0][1]); 

        for(int i = 1; i < intervals.size(); i++){
            int currTime = intervals[i][0]; 
            int currTimeEnd = intervals[i][1]; 
            int prevTime = pq.top(); 
            
            if(currTime >= prevTime){
                pq.pop(); //if the next start time is bigger than the prevTime, we can use that room immediately
            }
            pq.push(currTimeEnd); 
        }

        return pq.size(); 
    }
};