class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        for(int i = 0; i < citations.size(); i++){
            int hIndex = citations.size() - i; 
            if(citations[i] >= hIndex) return hIndex; 
        }
        return 0;  
    }
};