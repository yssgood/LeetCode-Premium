class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(); 
        if(n <= 1) return 1; 
        vector<int> lis(n,1);  
        vector<int> count(n,1); 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(lis[j] >= lis[i]){
                        lis[i] = lis[j] + 1;  
                        count[i] = count[j]; 
                    } else if(lis[i] == lis[j] + 1){
                        count[i] += count[j]; 
                    }
                }
            }
        }

        int longest = *max_element(lis.begin(),lis.end()); 
        int answer = 0; 
        for(int i = 0; i < n; i++){
            if(lis[i] == longest) answer += count[i]; 
        }

        return answer; 
    }
};