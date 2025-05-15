class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> answer; 
        stack<int> stack;  
        for(int n : asteroids){
            
            if(n < 0){
                int curr = abs(n); 
                bool exploaded = false; 
                while(!stack.empty() && stack.top() > 0){
                    if(stack.top() >= curr){
                        exploaded = true;
                        if(stack.top() == curr) stack.pop(); 
                        break; 
                    }
                    stack.pop(); 
                }

                if(exploaded) continue; 
            }
            stack.push(n); 
        }

        while(!stack.empty()){
            answer.push_back(stack.top()); 
            stack.pop(); 
        }


        reverse(answer.begin(),answer.end());  

        return answer; 
    }
};