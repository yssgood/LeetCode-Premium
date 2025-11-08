class StringIterator {
    int index = 0; 
    int count = 0; 
    char currChar; 
    String curr; 

    public StringIterator(String compressedString) {
        curr = compressedString; 
    }
    
    public char next() {
        if(!hasNext()) return ' '; 
        if(count == 0){
            currChar = curr.charAt(index++); 
            while(index < curr.length() && Character.isDigit(curr.charAt(index))){
                count = count * 10 + (curr.charAt(index++) - '0'); 
            }
        }

        count--; 
        return currChar; 
    }
    
    public boolean hasNext() {
        return count > 0 || index < curr.length(); 
    }
}

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */