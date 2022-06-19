class Trie {
public:
    vector<int>count;
    vector<Trie*> children;
    Trie() {
        for(int i=0;i<26;i++) children.push_back(NULL);
    }
};

class Solution {
public:
    void insertTrie(Trie* cur, string w, int i) {
        for(int j=0;j<w.length();j++) {
            int fnd = w[j]-'a';
            
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
    
    vector<vector<string>> suggestedProducts(vector<string>& words, string w) {
        sort(words.begin(),words.end());
        Trie* trie = new Trie();
        for(int i=0;i<words.size();i++) {
            insertTrie(trie,words[i],i);
        }
        vector<vector<string>> ans;
        Trie* cur = trie;
        for(int i=0;i<w.length();i++) {
            vector<string>v;
            if(cur!=NULL) {
                if(cur->children[w[i]-'a'] != NULL) {
                    cur = cur->children[w[i]-'a'];
                    for(int j=0;j<3;j++) {
                        if(j>=cur->count.size()) break;
                        v.push_back(words[cur->count[j]]);
                    }
                } else {
                    cur = NULL;
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};