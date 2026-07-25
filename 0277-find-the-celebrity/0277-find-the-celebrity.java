/* The knows API is defined in the parent class Relation.
      boolean knows(int a, int b); */

public class Solution extends Relation {
    public int findCelebrity(int n) {
        int[] numKnows = new int[n]; 
        int[] numKnowsWho = new  int[n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue; 
                if(knows(i,j)){
                    numKnows[j]++; 
                    numKnowsWho[i]++; 
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(numKnows[i] == n-1 && numKnowsWho[i] == 0) return i; 
        }
        return -1; 
    }
}