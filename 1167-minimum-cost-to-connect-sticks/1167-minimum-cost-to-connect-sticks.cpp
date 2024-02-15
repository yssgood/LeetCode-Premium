class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if(sticks.size() == 1) return 0; 
        int answer = 0; 
        priority_queue<int, vector<int>, greater<int>> pq; 
        for(int i = 0; i < sticks.size(); i++){
            pq.push(sticks[i]); 
        }

        while(pq.size() > 1){

            int curr = pq.top(); 
            pq.pop(); 

            int next = pq.top();
            pq.pop(); 

            answer += curr + next; 
            pq.push(curr + next); 
        }
        return answer; 
    }
};