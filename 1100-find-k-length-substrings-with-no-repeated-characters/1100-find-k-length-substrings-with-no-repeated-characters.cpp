class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        // We can reuse the condition from the first approach
        // as for k > 26, there can be no substrings with only unique characters
        if (k > 26)
            return 0;
        
        int answer = 0;
        int n = s.size();
        
        // Initializing the left and right pointers
        int left = 0, right = 0;
        // Initializing an empty frequency array
        int freq[26] = {0};
        
        while (right < n) {

            // Add the current character in the frequency array
            freq[s[right] - 'a']++;
            
            // If the current character appears more than once in the frequency array
            // keep contracting the window and removing characters from the
            // frequency array till the frequency of the current character becomes 1.
            while (freq[s[right] - 'a'] > 1) {
                freq[s[left] - 'a']--;
                left++;
            }
            
            // Check if the length of the current unique substring is equal to k
            if (right - left + 1 == k) {
                answer++;
                
                // Contract the window and remove the leftmost character from the
                // frequency array
                freq[s[left] - 'a']--;
                left++;
            }
            
            // Expand the window
            right++;
        }
        
        return answer;
    }
};