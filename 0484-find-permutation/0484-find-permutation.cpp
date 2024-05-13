class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> answer; 
        int cnt = 1; 
        stack<int> stack; 

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'I'){
                answer.push_back(cnt++); 
                while(!stack.empty()){
                    answer.push_back(stack.top()); 
                    stack.pop(); 
                }
            } else{
                stack.push(cnt++); 
            }
        }

        answer.push_back(cnt); 
        while(!stack.empty()){
            answer.push_back(stack.top()); 
            stack.pop(); 
        }
        return answer; 
    }
};