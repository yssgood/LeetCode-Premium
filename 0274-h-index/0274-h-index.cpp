class Solution {
public:
    int hIndex(vector<int>& citations) {
        //0 1 3 5 6
        sort(citations.begin(), citations.end()); 
        for(int i = 0; i < citations.size(); i++){
            int h = citations.size() - i; 
            if(citations[i] >= h){
                return h; 
            }
        }
        return -1; 
    }
};