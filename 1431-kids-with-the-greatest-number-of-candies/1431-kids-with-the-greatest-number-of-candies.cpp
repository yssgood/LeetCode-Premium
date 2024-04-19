class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_ = *max_element(candies.begin(),candies.end()); 
        vector<bool> answer(candies.size(), false); 
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= max_){
                answer[i] = true; 
            }
        }

        return answer; 
    }
};