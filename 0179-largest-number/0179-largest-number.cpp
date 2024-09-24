class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string answer = ""; 
        sort(nums.begin(), nums.end(),[](int& a, int& b){
            string tmp = to_string(a); 
            string tmp2 = to_string(b);  
            return (tmp + tmp2) > (tmp2 + tmp); 
        });

        for(int n : nums){
            answer += to_string(n); 
        }
        

        if(answer[0] == '0') return "0"; 

        return answer; 
    }
};