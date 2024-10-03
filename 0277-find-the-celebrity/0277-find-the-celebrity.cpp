/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int celeb = 0; 
        cout << n; 
        for(int i = 0; i < n; i++){
            if(i == celeb) continue; 
            if(knows(celeb, i)){
                celeb = i; 
            }
        }

        //cout << celeb; 

        for(int i = 0; i < n; i++){
            if(i == celeb) continue; 
            if(knows(celeb,i) || !knows(i,celeb)){
                return -1; 
            }
        }

        return celeb; 
    }
};

//[[1,0],
// [0,1]]