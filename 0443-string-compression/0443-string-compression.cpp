class Solution {
public:
    int compress(vector<char>& chars) {
        int left = 0, right = 0;
        while(right < chars.size()){
            int keepCount = 1; 
            while(right + keepCount < chars.size() && chars[right + keepCount] == chars[right]){
                keepCount++; 
            }

            chars[left] = chars[right];
            left++; 

            if(keepCount > 1){
                for(char& c : to_string(keepCount)){
                    chars[left] = c;
                    left++; 
                }
            }

            right += keepCount; 
        }


        return left; 
    }
};