class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); 
        priority_queue<int,vector<int>,greater<int>> pq; 
        pq.push(intervals[0][1]); 
        for(int i = 1; i < intervals.size(); i++){
            int nextStart = intervals[i][0];
            int nextEnd = intervals[i][1]; 

            if(!pq.empty() && pq.top() < nextStart){
                pq.pop(); 
            }
            pq.push(nextEnd); 
        }

        return pq.size(); 
    }
};