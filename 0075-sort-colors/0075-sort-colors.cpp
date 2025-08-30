
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Count occurrences of each color (0, 1, 2)
        map<int,int> count; 
        
        for (int num : nums) {
            count[num]++;
        }
        
        // Reconstruct array based on counts
        int idx = 0;
        for (int color = 0; color < 3; color++) {
            for (int i = 0; i < count[color]; i++) {
                nums[idx++] = color;
            }
        }
    }
};

