class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size()); 
        stack<pair<int,int>> stack; 
        stack.push({temperatures[0],0}); 
        for(int i = 1; i < temperatures.size(); i++){
            int curr = temperatures[i]; 
            while(!stack.empty() && curr > stack.top().first){
                answer[stack.top().second] = i - stack.top().second; 
                stack.pop(); 
            }
            stack.push({curr,i}); 
        }
        return answer; 
    }
};
