class Solution {
    public int compress(char[] chars) {
        int index = 0; 
        int end = 0; 
        while(end < chars.length){
            char curr = chars[end]; 
            int count = 0; 
            while(end < chars.length && chars[end] == curr){
                count++; 
                end++; 
            }

            chars[index++] = curr; 
            if(count > 1){
                String num = String.valueOf(count); 
                for(char c : num.toCharArray()) chars[index++] = c; 
            }
        }

        return index; 
    }
}