class Solution {
public:
    int compress(vector<char>& chars) {
        string res = "";
        int left = 0, right = 0; 
        char currChar = chars[0], nextChar = chars[0];
        while(right < chars.size()){
            nextChar = chars[right]; 
            
            if(nextChar != currChar){
                res += currChar; 
                if(right - left > 1) res += to_string(right - left); 
                currChar = nextChar; 
                left = right; 
            }

            right++; 
        }


        res += chars[left]; 
        if(right - left > 1) res += to_string(right - left); 

        for(int i = 0; i < res.length(); i++){
            chars[i] = res[i]; 
        }


        return res.length(); 
    }
};