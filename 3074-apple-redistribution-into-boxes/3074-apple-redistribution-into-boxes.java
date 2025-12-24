class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int sum = 0; 
        for(int n : apple) sum += n; 
        List<Integer> arr = new ArrayList<>(); 
        for(int n : capacity) arr.add(n); 
        Collections.sort(arr, Comparator.reverseOrder()); 
        int count = 0; 
        for(int n : arr){
            count++; 
            sum -= n;
            if(sum <= 0) return count; 
        }

        return count;
    }
}