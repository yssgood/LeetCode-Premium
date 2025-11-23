class FileSystem {
    class File {
        boolean isFile;  
        String content; 
        TreeMap<String,File> children; 
        public File(){
            isFile = false; 
            content = ""; 
            this.children = new TreeMap<>(); 
        }
    }

    private File root;

    public FileSystem() {
        root = new File(); 
    }
    
    public List<String> ls(String path) {
        File file = findPath(path); 
        List<String> answer = new ArrayList<>(); 
        if(file.isFile){
            String[] split = path.split("/"); 
            answer.add(split[split.length-1]); 
            return answer; 
        }

        for(String remaining : file.children.keySet()){
            answer.add(remaining); 
        }

        return answer; 

    }
    
    public void mkdir(String path) {
        createPath(path); 
    }
    
    public void addContentToFile(String filePath, String content) {
        File file = createPath(filePath); 
        file.isFile = true; 
        file.content += content;
    }
    
    public String readContentFromFile(String filePath) {
        File file = findPath(filePath);
        return file.content; 
    }

    public File findPath(String path){
        String[] pathArray = path.split("/"); 
        File curr = root; 
        for(int i = 1; i < pathArray.length; i++){
            String nextPath = pathArray[i]; 
            curr = curr.children.get(nextPath); 
        }
        return curr; 
    }

    public File createPath(String path){
        String[] pathArray = path.split("/"); 
        File curr = root; 
        for(int i = 1; i < pathArray.length; i++){
            String nextPath = pathArray[i]; 
            if(!curr.children.containsKey(nextPath)){
                curr.children.put(nextPath, new File()); 
            }
            curr = curr.children.get(nextPath); 
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