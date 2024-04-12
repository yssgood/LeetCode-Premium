class Solution {
public:
    string getSmallestString(string s, int k) {
        string answer = ""; 
        
        for(int i = 0; i < s.length(); i++){
            int left = s[i] - 'a'; 
            int right = 'z' - s[i] + 1; 
            int min_ = min(left, right); 

            if(k >= min_){
                answer += 'a'; 
                k -= min_; 
            } else{
                answer += s[i] - k;
                k = 0; 
            }
        }
        return answer; 
    }
};