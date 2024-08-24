/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int celeb = 0; 
        for(int i = 0; i < n; i++){
            if(celeb == i) continue; 

            if(knows(celeb,i)){
                celeb = i; 
            }
        }

        for(int i = 0; i < n; i++){
            if(celeb == i) continue; 
            if(!knows(i,celeb) || knows(celeb,i)) return -1; 
        }

        return celeb; 
    }
};