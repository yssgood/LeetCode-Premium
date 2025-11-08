class TicTacToe {
    private int[] rows; 
    private int[] cols; 
    private int diagonal; 
    private int antiDiagonal; 
    private int n; 

    public TicTacToe(int n) {
        this.n = n; 
        rows = new int[n]; 
        cols=  new int[n]; 
        diagonal = 0; 
        antiDiagonal = 0; 
    }
    
    public int move(int row, int col, int player) {
        int toAdd = (player == 1) ? 1 : -1; 

        rows[row] += toAdd; 
        cols[col] += toAdd; 

        if(row == col) {
            diagonal += toAdd; 
        }
        if(row + col == n - 1) {
            antiDiagonal += toAdd; 
        }

        int target = (player == 1) ? n : -n; 

        if(rows[row] == target || cols[col] == target || diagonal == target || antiDiagonal == target) return player; 
        return 0; 
    }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */