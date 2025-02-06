class Solution {
public:
    string compressedString(string word) {
        string comp = ""; 
        int i = 0; 
        while(i < word.length()){
            char curr = word[i]; 
            int count = 1; 
            while(i + 1 < word.length() && word[i+1] == curr && count < 9){
                count++; 
                i++; 
            }

            comp += (count + '0'); 
            comp += (curr); 
            i++; 
        }

        return comp; 
    }
};