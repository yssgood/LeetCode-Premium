/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> visited; 
    Node* cloneGraph(Node* node) {
        if(!node){
            return {}; 
        }

        if(visited[node]){
            return visited[node]; 
        }

        Node* clone = new Node(node->val); 
        visited[node] = clone; 

        for(auto& next : node->neighbors){
            clone->neighbors.push_back(cloneGraph(next)); 
        }

        return clone; 
    }
};