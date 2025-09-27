class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1; 
        int p1 = m-1; 
        int p2 = n-1;
        if(p1 < 0){
            nums1[0] = nums2[0]; 
            return; 
        }
        while(p2 >= 0){
            //cout << p1 << ' ' << p2 << endl; 
            if(nums1[p1] > nums2[p2]){
                nums1[index--] = nums1[p1--]; 
            } else{
                nums1[index--] = nums2[p2--]; 
            }
        }
    }
};


//1 2 3 3 5 6         2 5 6 
//  p1               p2