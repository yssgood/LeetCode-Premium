class WordDictionary {
    class Trie {
        boolean isEnd;  
        Map<Character, Trie> children; 
        public Trie(){
            this.isEnd = false; 
            this.children = new HashMap<>(); 
        }
    }

    Trie root = new Trie(); 

    public WordDictionary() {
        
    }
    
    public void addWord(String word) {
        Trie curr = root; 
        for(char c : word.toCharArray()){
            if(!curr.children.containsKey(c)){
                curr.children.put(c, new Trie()); 
            }
            curr = curr.children.get(c); 
        }
        curr.isEnd = true; 
    }
    
    public boolean search(String word) {
        return searchHelper(word, 0, root); 
    }

    public boolean searchHelper(String word, int index, Trie root){
        if(index == word.length()){
            return root.isEnd; 
        }

        char c = word.charAt(index); 

        if(word.charAt(index) == '.'){
            for(Trie child : root.children.values()){
                if(searchHelper(word, index+1, child)){
                    return true; 
                }
            }
            return false; 
        } else{
            if(!root.children.containsKey(c)){
                return false; 
            }
            return searchHelper(word, index +1, root.children.get(c)); 
        }
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */