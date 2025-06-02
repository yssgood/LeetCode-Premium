class Solution {
public:
    //2 3 4
    int memo[20001]; 
    map<int,int> hashMap; 
    int deleteAndEarn(vector<int>& nums) {
        memset(memo,-1,sizeof(memo)); 
        sort(nums.begin(),nums.end());  
        for(int n : nums) hashMap[n]+=n; 
        return solution(nums,nums[nums.size()-1]); 
    }
    
    int solution(vector<int>& nums, int n){
        if(n <= 1) return hashMap[n]; 

        int& ret = memo[n]; 
        if(ret > -1) return ret; 

        ret = max(solution(nums,n-2) + hashMap[n], solution(nums,n-1)); 
        
        return ret; 
    }

};


/*

4 
3           2
2  1         1    0 


*/ 