class Solution {
    public int maxProduct(int n) {
        String s = String.valueOf(n); 
        char[] arr = s.toCharArray(); 
        Arrays.sort(arr); 
        return (arr[arr.length-1] - '0') * (arr[arr.length-2] - '0'); 
    }
}