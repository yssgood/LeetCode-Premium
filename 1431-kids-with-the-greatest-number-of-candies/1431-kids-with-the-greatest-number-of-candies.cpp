class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> answer(candies.size(),false); 
        int max_ = 0;
        for(int n : candies) max_ = max(max_,n); 
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= max_){
                answer[i] = true; 
            }
        }
        return answer; 
    }
};