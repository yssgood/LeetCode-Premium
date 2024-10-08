class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]){
                return a[1] < b[1]; 
            }

            return a[0] < b[0]; 
        });
        
        priority_queue<int, vector<int>, greater<int>> pq; 
        pq.push(intervals[0][1]); 

        for(int i = 1; i < intervals.size(); i++){
            int startTime = intervals[i][0]; 
            int endTime = intervals[i][1]; 

            if(!pq.empty() && pq.top() <= startTime){
                pq.pop(); 
            }

            pq.push(endTime); 
        }

        return pq.size(); 
    }
};