class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(),s.end()); 
        int start = 0, end = 0; 
        bool flag = false; 
        while(end < s.size()){
            
            if(s[end] == ' '){
                flag = true; 
                int tmpStart = start;
                int tmpEnd = end - 1; 
                while(tmpStart < tmpEnd){
                    swap(s[tmpStart], s[tmpEnd]); 
                    tmpStart++;
                    tmpEnd--;
                }

                start = end + 1; 
            }


            end++; 
        }

        if(start > 0){
            int tmpStart = start;
            int tmpEnd = end - 1; 
            while(tmpStart < tmpEnd){
                swap(s[tmpStart], s[tmpEnd]); 
                tmpStart++;
                tmpEnd--;
            }
        } else{
            reverse(s.begin(), s.end()); 
        }
    }
};