class Trie {
    class TrieImpl{
        boolean isEnd = false; 
        Map<Character, TrieImpl> children = new HashMap<>(); 
        public TrieImpl(){
        }
    }

    TrieImpl root = new TrieImpl(); 

    public Trie() {
        
    }
    
    public void insert(String word) {
        TrieImpl curr = root; 
        for(char c : word.toCharArray()){
            if(!curr.children.containsKey(c)){
                curr.children.put(c, new TrieImpl()); 
            }
            curr = curr.children.get(c); 
        }
        curr.isEnd = true; 
    }
    
    public boolean search(String word) {
        TrieImpl curr = root; 
        for(char c : word.toCharArray()){
            if(!curr.children.containsKey(c)) return false; 
            curr = curr.children.get(c); 
        }

        return curr.isEnd; 
    }
    
    public boolean startsWith(String prefix) {
        TrieImpl curr = root; 
        for(char c : prefix.toCharArray()){
            if(!curr.children.containsKey(c)) return false; 
            curr = curr.children.get(c); 
        }
        return true; 
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */