struct Node{
    Node* links[10]; 
    bool flag = false; 

    bool isPresent(char ch){
        return links[ch - '0'] != NULL; 
    }

    void put(char ch, Node* node){
        links[ch - '0'] = node;
    }

    Node* get(char ch){
        return links[ch - '0']; 
    }

    void setEnd(){
        flag = true; 
    }

    bool isEnd(){
        return flag; 
    }
};

class Solution {
    private: 
    Node* root; 
    public:
    Solution(){
        root = new Node(); 
    }

    void insert(string word){
        Node* node = root; 
        for(int i = 0; i < word.size(); i++){
            if(!node->isPresent(word[i])){
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]); 
        }
        node->setEnd(); 
    }

    int search(string word){
        Node* node = root; 
        for(int i = 0; i < word.size(); i++){
            if(!node->isPresent(word[i])) return i; 
            node = node->get(word[i]); 
        }
        return word.size() ; 
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for(auto it : arr2){
            this->insert(to_string(it)); 
        }   
        int maxi = 0; 
        for(auto it : arr1){
            maxi = max(maxi , this->search(to_string(it)));    
        } 
        return maxi; 
    }
};
