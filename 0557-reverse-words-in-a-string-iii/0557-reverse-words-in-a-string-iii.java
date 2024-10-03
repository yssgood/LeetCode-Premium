class Solution {
    public void reverse(char[] charArray, int start, int end){
        while(start < end){
            char curr = charArray[start]; 
            charArray[start] = charArray[end]; 
            charArray[end] = curr; 
            start++;
            end--;
        }
    }
    public String reverseWords(String s) {
        char[] charArr = s.toCharArray(); 
        int start = 0, end = 0; 
        while(end < charArr.length){

            while(end < charArr.length && charArr[end] != ' '){
                end++; 
            }
            reverse(charArr,start,end-1); 
            end++; 
            start = end; 
        }
        return new String(charArr); 
    }
}