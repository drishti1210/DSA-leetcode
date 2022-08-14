class Solution {
public:
    
    const static int MAXN = 505;
    const static int INF = 0x3f3f3f3f;
    int n;
    vector<int> adj[MAXN];
    int dis[MAXN];
    bool visited[MAXN];
    
    int get_diff(const string& s1, const string& s2) {
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) cnt += s1[i] != s2[i];
        return cnt;
    }
    
    void dfs(int src, int dest, vector<vector<int>>& paths, vector<int>& path) {
        if (src == dest) {
            paths.push_back(path);
            return;
        }
        for (int each: adj[src]) {
            if (dis[each] == dis[src] - 1) {
                path.push_back(each);
                dfs(each, dest, paths, path);
                path.pop_back();
            }
        }
    }
    
    vector<vector<int>> get_paths(int from, int to) {
        dis[from] = 0;
        queue<int> q;
        q.push(from);
        visited[from] = true;
        memset(dis, 0x3f, sizeof(dis));
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            for (int each : adj[tmp]) {
                if (!visited[each]) {
                    visited[each] = true;
                    dis[each] = dis[tmp] + 1;
                    q.push(each);
                }
            }
        }
        vector<vector<int>> res;
        if (dis[to] == INF) return res;
        vector<int> path;
        path.push_back(to);
        dfs(to, from, res, path);
        for (int i = 0; i < res.size(); i++) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        n = wordList.size();
        int snode = -1;
        int enode = -1;
        for (int i = 0; i < n; i++) {
            if (wordList[i] == beginWord) {
                snode = i;
            }
            if (wordList[i] == endWord) {
                enode = i;
            }
        }
        vector<vector<string>> res;
        if (enode == -1) return res;
        if (snode == -1) {
            snode = n;
            for (int i = 0; i < n; i++) {
                if (get_diff(beginWord, wordList[i]) == 1) {
                    adj[n].push_back(i);
                    adj[i].push_back(n);
                } 
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (get_diff(wordList[i], wordList[j]) == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<vector<int>> paths = get_paths(snode, enode);
        for (const vector<int>& path: paths) {
            vector<string> s;
            for (int each : path) {
                if (each == n) s.push_back(beginWord);
                else s.push_back(wordList[each]);
            }
            res.push_back(s);
        }
        return res;
    }
};