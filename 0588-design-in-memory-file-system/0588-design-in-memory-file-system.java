class File {
    boolean isFile; 
    String content; 
    TreeMap<String, File> children = new TreeMap<>(); 
    public File(){
        this.isFile =false; 
        this.content = ""; 
    }
}
class FileSystem {

    File root; 

    public FileSystem() {
        root = new File(); 
    }
    
    public List<String> ls(String path) {
        File lastPath = updatePath(path); 
        List<String> answer = new ArrayList<>(); 
        if(lastPath.isFile){
            String[] split = path.split("/"); 
            answer.add(split[split.length-1]); 
            return answer; 
        }
        for(String p : lastPath.children.keySet()){
            answer.add(p); 
        }
        return answer; 
    }
    
    public void mkdir(String path) {
        updatePath(path); 
    }
    
    public void addContentToFile(String filePath, String content) {
        File lastPath = updatePath(filePath); 
        lastPath.isFile = true; 
        lastPath.content += content; 
    }
    
    public String readContentFromFile(String filePath) {
        File lastPath = updatePath(filePath); 
        return lastPath.content; 
    }
    public File updatePath(String path){
        if(path.equals("/")){
            return root; 
        }

        String[] pathSplit = path.split("/"); 
        File curr = root; 
        for(int i = 1; i < pathSplit.length; i++){
            String pathName = pathSplit[i]; 
            if(!curr.children.containsKey(pathName)){
                curr.children.put(pathName, new File()); 
            }
            curr = curr.children.get(pathName); 
        }

        return curr;
    }
}

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * List<String> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * String param_4 = obj.readContentFromFile(filePath);
 */