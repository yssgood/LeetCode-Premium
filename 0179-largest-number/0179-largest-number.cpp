class Solution {
public:
    string largestNumber(vector<int>& nums) {


        sort(nums.begin(), nums.end(), [](int& a, int& b){
            string t1 = to_string(a); 
            string t2 = to_string(b); 

            return t1 + t2 > t2 + t1; 
        });

        string answer = ""; 

        for(int n : nums){
            string next = to_string(n);
            answer += next; 
        }

        if(answer[0] == '0'){
            return "0"; 
        }

        return answer.empty() ? "0" : answer; 
    }
};