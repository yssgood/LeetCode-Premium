class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> answer; 
        sort(arr.begin(), arr.end(), [&](int& a, int& b){
            
            if(abs(a-x) == abs(b-x)){
                return a < b; 
            }

            return abs(a - x) < abs(b - x); 
        });

        for(int i = 0; i < k; i++){
            answer.push_back(arr[i]); 
        }

        sort(answer.begin(),answer.end()); 

        return answer; 
    }
};