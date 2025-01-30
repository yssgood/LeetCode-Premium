class Solution {
    public int answer = 0; 
    class Node{
        int num; 
        boolean forWard, backWard; 
        public Node(int num, boolean forWard, boolean backWard){
            this.num = num; 
            this.forWard = forWard; 
            this.backWard = backWard; 
        }
    }
    public void dfs(List<List<Node>> adj, boolean[] visited, int node){
        visited[node] = true; 
        for(Node next : adj.get(node)){
            if(!visited[next.num]){
                //System.out.println(next.num + " " + next.forWard); 
                if(next.forWard == true) answer++; 
                dfs(adj,visited,next.num); 
            }
        }
    }
    public int minReorder(int n, int[][] connections) {
        List<List<Node>> adj = new ArrayList<>(); 
        for(int i = 0; i < n; i++){
            adj.add(new ArrayList<>()); 
        }

        for(int[] vec : connections){
            int from = vec[0], to = vec[1]; 
            Node node1 = new Node(to,true,false); 
            Node node2 = new Node(from,false,true); 
            adj.get(from).add(node1); 
            adj.get(to).add(node2); 
        }
        boolean[] visited = new boolean[n]; 
        dfs(adj,visited,0); 


        return answer; 
    }
}