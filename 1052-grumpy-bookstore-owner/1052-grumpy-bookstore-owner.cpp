class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int max_minute = 0; 
        for(int i = 0; i < customers.size(); i++){
            int grump = grumpy[i]; 
            if(grump == 0) max_minute += customers[i]; 
        }

        int start = 0, end = 0; 
        int tmpMax = max_minute; 
        while(end < grumpy.size()){

            if(grumpy[end] == 1){
                tmpMax += customers[end]; 
                //cout << start << ' ' << end << ' ' << tmpMax << endl; 
            }

            while(end - start + 1 >= minutes){
                //cout << start << ' ' << end << ' ' << tmpMax << endl; 
                max_minute = max(max_minute, tmpMax); 
                if(grumpy[start] == 1){
                    tmpMax -= customers[start];
                }
                start++; 
            }
            end++; 
        }

        return max_minute; 
    }
};