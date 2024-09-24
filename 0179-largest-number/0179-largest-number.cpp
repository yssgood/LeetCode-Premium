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
        int index = 0; 
        for(index = 0; index < answer.length()-1; index++){
            if(answer[index] != '0') break;
        }

        //cout << index; 

        return answer.substr(index); 
    }
};