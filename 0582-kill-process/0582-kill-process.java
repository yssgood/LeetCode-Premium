class Solution {

    boolean[] visited = new boolean[50001]; 
    HashMap<Integer,Integer> hashMap = new HashMap<>(); 

    public void dfs(List<List<Integer>> adj, int kill, List<Integer> answer){
        answer.add(kill); 
        for(Integer next : adj.get(kill)){
            if(!visited[next] && hashMap.get(kill) != next){
                visited[next] = true;
                dfs(adj,next,answer); 
            }
        }
        
    }
    public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
        List<Integer> answer = new ArrayList<>(); 
        List<List<Integer>> adj = new ArrayList<>(); 
        for(int i = 0; i < 50001; i++){
            adj.add(new ArrayList<>()); 
        }

        for(int i = 0; i < pid.size(); i++){
            if(ppid.get(i) == 0) continue; 

            adj.get(pid.get(i)).add(ppid.get(i)); 
            adj.get(ppid.get(i)).add(pid.get(i)); 
            hashMap.put(pid.get(i), ppid.get(i)); 
        }
        visited[kill] = true; 
        dfs(adj,kill,answer); 
        return answer; 
    }
}