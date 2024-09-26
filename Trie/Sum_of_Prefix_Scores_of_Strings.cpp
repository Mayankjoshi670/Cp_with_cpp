struct Node{
    Node* links[26];
    int cnt = 0;  
    bool flag = false; 

    bool isPresent(char ch){
        return links[ch - 'a'] != NULL; 
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a']; 
    }

    void increaseCount() {
        cnt++;
    }

    int getCount() {
        return cnt;
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
            node->increaseCount();   
        }
        node->setEnd(); 
    }

     int search(string word){
        Node* node = root; 
        int score = 0; 
        for(int i = 0; i < word.size(); i++){
            if(!node->isPresent(word[i])) return score; 
            node = node->get(word[i]); 
            score += node->getCount();  
        }
        return score;  
    }

    vector<int> sumPrefixScores(vector<string>& words) {
         for(auto &word : words){
            this->insert(word); 
        }
 
        vector<int> result; 
        for(auto &word : words){
            result.push_back(this->search(word)); 
        }
        return result;  
    }
};
