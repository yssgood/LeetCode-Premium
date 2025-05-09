/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 0, right = n; 
        while(left <= right){
            int mid = left + (right - left) / 2; 
            //cout << left << ' ' << right << ' ' << mid << endl; 
            if(guess(mid) == 0){
                return mid; 
            }

            if(guess(mid) == -1){
                right = mid -1; 
            } else{
                left = mid + 1; 
            }
        }
        return left; 
    }
};