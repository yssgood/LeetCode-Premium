class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> answer; 
        stack<int> numStack; 
        bool popChance = false; 
        for(int& n : asteroids){
            int currRock = n; 
            popChance = false; 
            while(!numStack.empty() && numStack.top() > 0 && currRock < 0){
                int absCurr = abs(currRock); 
                int prevRock = abs(numStack.top()); 

                if(absCurr > prevRock){
                    numStack.pop(); 
                } else{
                    if(absCurr == prevRock){
                        numStack.pop(); 
                    }
                    popChance = true; 
                    break; 
                }
            }

            numStack.push(currRock); 
            if(popChance) numStack.pop(); 
        }

        while(!numStack.empty()){
            answer.push_back(numStack.top()); 
            numStack.pop(); 
        }

        reverse(answer.begin(),answer.end()); 

        return answer; 
    }
};