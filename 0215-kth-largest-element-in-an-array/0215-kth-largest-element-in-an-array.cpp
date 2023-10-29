class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int answer = 0; 
        priority_queue<int, vector<int>> pq; 
        for(int num : nums) pq.push(num); 
        for(int i = 0; i < k; i++){
            answer = pq.top(); 
            pq.pop(); 
        }
        return answer; 
    }
};