class Solution {
    class Trie {
        boolean isEnd = false; 
        String word = null; // 단어 저장용 (정답 반환)
        Map<Character, Trie> children = new HashMap<>();
    }

    Trie root = new Trie(); 
    List<String> answer = new ArrayList<>(); 
    int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    public List<String> findWords(char[][] board, String[] words) {
        
        for(String s : words){
            createTrie(s); 
        }

        int m = board.length; 
        int n = board[0].length;  
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                char first = board[i][j]; 
                if(root.children.containsKey(first)){
                    dfs(i,j,board,root); 
                }
            }
        }

        return answer; 
    }

    public void dfs(int i, int j, char[][] board, Trie curr){
        char c = board[i][j]; 
        Trie next = curr.children.get(c);
        //if (next == null) return;

        // 단어 완성
        if (next.isEnd) {
            answer.add(next.word);
            next.isEnd = false; // 중복 방지
        }

        board[i][j] = '#'; 

        for(int k = 0; k < 4; k++){
            int nX = i + dir[k][0]; 
            int nY = j + dir[k][1]; 
            if(nX >= 0 && nY >= 0 && nX < board.length && nY < board[0].length && board[nX][nY] != '#'){
                if(next.children.containsKey(board[nX][nY])){
                    //dfs(nX, nY, board, curr.children.get(board[nX][nY])); 
                    dfs(nX, nY, board, next);
                }
            }
        }
        board[i][j] =  c; 
    }

    public void createTrie(String s){
        Trie curr = root; 
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i); 
            if(!curr.children.containsKey(c)){
                curr.children.put(c, new Trie()); 
            }
            curr = curr.children.get(c); 
        }

        curr.isEnd = true; 
        curr.word = s; 
    }
}