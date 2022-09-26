class Solution {
public:
    int Find(vector<int>&parent,int a)
    {
        if(parent[a]==-1) return a;
        parent[a] = Find(parent,parent[a]);
        return parent[a];
    }
    
    void Union(vector<int>&parent,int a,int b)
    {
        int p1 = Find(parent,a);
        int p2 = Find(parent,b);
        if(p1==p2) return;
        parent[p1] = p2;
    }
    
    bool equationsPossible(vector<string>& eq) {
        vector<int>parent(26,-1);
        for(int i=0;i<eq.size();i++)
        {
            string s = eq[i];
            if(s[1]=='=')
            {
                Union(parent,s[0]-'a',s[3]-'a');
            }
        }
        
        for(int i=0;i<eq.size();i++)
        {
            string s = eq[i];
            if(s[1]=='!')
            {
                if(Find(parent,s[0]-'a')==Find(parent,s[3]-'a'))
                    return false;
            }
        }
        
        return true;
    }
};