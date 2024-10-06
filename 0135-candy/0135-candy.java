class Solution {
    public int candy(int[] ratings) {
        int[] maps = new int[ratings.length]; 
        Arrays.fill(maps,1); 

        for(int i = 1; i < ratings.length; i++){
            if(ratings[i] > ratings[i-1]){
                maps[i] = maps[i-1] + 1; 
            }
        }

        for(int i = ratings.length-2; i>= 0; i--){
            if(ratings[i] > ratings[i+1]){
                maps[i] = maps[i+1] + 1; 
            }
        }

        int answer = 0;
        for(int n : maps){
            answer += n; 
        }

        //1 3 2 2 1 
        //1 1 1 1 1

        //1 2 1 1 1 
        //  3  1  2 1

        return answer; 
    }
}