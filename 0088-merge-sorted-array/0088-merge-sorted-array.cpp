class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1; 
        int p1 = m-1; 
        int p2 = n-1; 
        while(p1 >= 0 && p2 >= 0){
            if(nums1[p1] > nums2[p2]){
                //cout << "HH" << endl; 
                nums1[last--] = nums1[p1--]; 
            } else{
                //cout << p1 << ' ' << p2 << endl; 
                nums1[last--] = nums2[p2--]; 
            }
        }

        while(p2 >= 0){
            nums1[last--] = nums2[p2--]; 
        }
    }
};