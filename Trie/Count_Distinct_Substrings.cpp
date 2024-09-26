struct Node {
    Node* links[26]; 
    bool flag = false;
    
    Node() {
        for (int i = 0; i < 26; i++) links[i] = nullptr;
    }

    bool isPresent(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

int countDistinctSubstrings(string &s) {
    Node *root = new Node();
    int cnt = 0;
    
    for (int i = 0; i < s.length(); i++) {
        Node* node = root;  
        for (int j = i; j < s.length(); j++) {
            if (!node->isPresent(s[j])) {
                cnt++;
                node->put(s[j], new Node());
            }
            node = node->get(s[j]);  
        }
    }
    
    return cnt + 1;  
}
