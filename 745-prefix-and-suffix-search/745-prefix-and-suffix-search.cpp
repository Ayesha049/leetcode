class Trie {
public:
    vector<int>count;
    vector<Trie*> children;
    Trie() {
        for(int i=0;i<27;i++) children.push_back(NULL);
    }
};

class WordFilter {
public:
    Trie* trie1;
    Trie* trie2;
    unordered_map<string,int>memo;
    
    void insertTrie(Trie* cur, string w, int i) {
        for(int j=0;j<w.length();j++) {
            int fnd;
            if(w[j] == '#') {
                fnd = 26;
            } else {
                fnd = w[j]-'a';
            }
            
            if(cur->children[fnd] == NULL) {
                Trie* node = new Trie();
                node->count.push_back(i);
                cur->children[fnd] = node;
            } else {
                cur->children[fnd]->count.push_back(i);
            }
            cur = cur->children[fnd];
        }
    }
    
    WordFilter(vector<string>& words) {
        trie1 = new Trie();
        
        for(int i=0;i<words.size();i++) {
            string w = "#" + words[i];
            insertTrie(trie1,w,i);
            for(int j=words[i].length()-1;j>=0;j--) {
                w = words[i][j] + w;
                insertTrie(trie1,w,i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s = suffix + "#" + prefix;
        if(memo.find(s) == memo.end()) {
            Trie* cur = trie1;
            for(int i=0;i<s.length();i++) {
                int fnd;
                if(s[i] == '#') {
                    fnd = 26;
                } else {
                    fnd = s[i]-'a';
                }

                if(cur->children[fnd] == NULL) return -1;
                cur = cur->children[fnd];
            }
            memo[s] = cur->count.back();
        }
        
        return memo[s];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */