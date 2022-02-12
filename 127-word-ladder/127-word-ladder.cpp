class Solution {
public:
    int ladderLength(string st, string en, vector<string>& words) {
        set<string>s;
        for(int i=0;i<words.size();i++) s.insert(words[i]);
        if(s.count(en) == 0) return 0;
        queue<pair<string,int> >q;
        unordered_map<string,bool>visited;
        visited[st] = true;
        q.push(make_pair(st,1));
        while(!q.empty()) {
            string w = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(w == en) return dist;
            for(int i=0;i<w.length();i++) {
                for(int j=0;j<26;j++) {
                    string temp = w;
                    temp[i] = 'a'+j;
                    if(s.count(temp) > 0 && visited[temp] == false) {
                        visited[temp] = true;
                        q.push(make_pair(temp,dist+1));
                    }
                }
            }
        }
        return 0;
    }
};