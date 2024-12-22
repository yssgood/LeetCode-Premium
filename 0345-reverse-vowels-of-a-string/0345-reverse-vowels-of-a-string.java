class Solution {
    public String reverseVowels(String s) {
        int start = 0, end = s.length()-1; 
        Set<Character> set = Set.of('a','e','i','o','u'); 
        char[] charVec = s.toCharArray(); 
        while(start < end){
            char a = Character.toLowerCase(s.charAt(start)); 
            char b = Character.toLowerCase(s.charAt(end)); 

            if(set.contains(a) && set.contains(b)){
                char tmp = charVec[start]; 
                charVec[start] = charVec[end]; 
                charVec[end] = tmp; 
                start++;
                end--; 
            } else{
                if(!set.contains(a)) start++; 
                if(!set.contains(b)) end--; 
            }


        }
        return new String(charVec); 
    }
}