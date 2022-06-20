class Trie {
public:
    bool isLeaf;
    vector<Trie*> children;
    Trie() {
        isLeaf = true;
        for(int i=0;i<26;i++) children.push_back(NULL);
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie* trie = new Trie();
        unordered_map<Trie*,int>mp;
        for(int i=0;i<words.size();i++) {
            Trie* cur = trie;
            for(int j=words[i].length()-1;j>=0;j--) {
                char ch = words[i][j];
                if(cur->children[ch-'a'] == NULL) {
                    cur->children[ch-'a'] = new Trie();
                    cur->isLeaf = false;
                }
                cur = cur->children[ch-'a'];
            }
            mp[cur] = i;
        }
        
        unordered_map<Trie*,int> :: iterator it;
        int ans = 0;
        for(it = mp.begin(); it!= mp.end(); it++) {
            if(it->first->isLeaf) {
                ans += words[it->second].length() + 1;
            }
        }
        return ans;
    }
};