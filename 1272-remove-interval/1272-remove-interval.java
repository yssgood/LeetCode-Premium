class Solution {
    public List<List<Integer>> removeInterval(int[][] intervals, int[] toBeRemoved) {
        List<List<Integer>> answer = new ArrayList<>(); 
        for(int[] arr : intervals){

            if(arr[1] < toBeRemoved[0] || arr[0] > toBeRemoved[1]){
                answer.add(Arrays.asList(arr[0],arr[1])); 
            } else{

                if(arr[0] < toBeRemoved[0]){
                    answer.add(Arrays.asList(arr[0], toBeRemoved[0])); 
                } 
                if(arr[1] > toBeRemoved[1]){
                    answer.add(Arrays.asList(toBeRemoved[1], arr[1])); 
                }

            }
        }

        return answer; 

    }
}