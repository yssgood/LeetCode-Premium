class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> answer;  
        stack<int> numStack; 
        bool flag = true; 
        for(int i = 0; i < asteroids.size(); i++){
            int currRock = asteroids[i]; 
            while(!numStack.empty() && flag){
                int prevRock = numStack.top(); 
                if(currRock < 0 && prevRock > 0){
                    int absCurr = abs(currRock), absPrev = abs(prevRock); 
                    if(absCurr > absPrev){
                        numStack.pop(); 
                    } else{
                        flag = false; 
                        if(absCurr == absPrev) numStack.pop(); 
                        break; 
                    }
                } else{
                    break; 
                }
            }
            numStack.push(currRock); 
            if(!flag) numStack.pop(); 
            flag = true; 
        }

        while(!numStack.empty()){
            answer.push_back(numStack.top()); 
            numStack.pop(); 
        }

        reverse(answer.begin(),answer.end()); 

        return answer; 
    }
};