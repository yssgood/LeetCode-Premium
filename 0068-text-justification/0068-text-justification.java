class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> answer = new ArrayList<>(); 
        int i = 0;
        while(i < words.length){
            StringBuilder sb = new StringBuilder(); 
            int curr = 0; 
            int j = i; 

            while(j < words.length && curr + words[j].length() + (j - i) <= maxWidth){
                curr += words[j].length(); 
                j++; 
            }

            int wordCount = j - i; 
            int spaceNeeded = maxWidth - curr; 

            if(j == words.length || wordCount == 1){
                for(int k = i; k < j; k++){
                    sb.append(words[k]); 
                    if(k < j - 1) sb.append(" "); 
                }
                sb.append(" ".repeat(maxWidth - sb.length())); 
            }
            else{
                int gaps = wordCount - 1; 
                int base = spaceNeeded / gaps; 
                int extra = spaceNeeded % gaps; 

                for(int k = i; k < j; k++){
                    sb.append(words[k]);
                    if(k < j - 1){
                        int space = base + (k - i < extra ? 1 : 0); 
                        sb.append(" ".repeat(space)); 
                    }
                }
            }

            answer.add(sb.toString()); 
            i = j; 
        }

        return answer; 
    }
}