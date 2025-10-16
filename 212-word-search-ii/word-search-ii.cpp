class Solution {
public:
    struct Node {
        Node* links[26];
        bool fl = false;
        string word = "";
        bool containsKey(char ch) { return (links[ch - 'a'] != NULL); }
        void put(char ch, Node* node) { links[ch - 'a'] = node; }
        Node* get(char ch) { return links[ch - 'a']; }
        void setEnd() { fl = true; }
        bool isEnd() { return fl; }
    };
    struct Trie {
    public:
        Node* root;

        Trie() { root = new Node(); }
        void insert(string& word) {
            Node* node = root;
            for (int i = 0; i < word.size(); i++) {
                if (!node->containsKey(word[i])) {
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            }
            node->setEnd();
            node->word = word;
        }
        bool search(string& word) {
            Node* node = root;
            for (int i = 0; i < word.size(); i++) {
                if (!node->containsKey(word[i])) {
                    return false;
                }
                node = node->get(word[i]);
            }
            return node->isEnd();
        }
        bool startsWith(string& word) {
            Node* node = root;
            for (int i = 0; i < word.size(); i++) {
                if (!node->containsKey(word[i])) {
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            }
            return true;
        }
    };
    void dfs(vector<vector<char>>& board, int i, int j, Node* p,
             vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || !p->containsKey(c))
            return;
        p = p->get(c);
        if (p->word.size() > 0) {
            result.push_back(p->word);
            p->word = "";
        }

        board[i][j] = '#';
        if (i > 0)
            dfs(board, i - 1, j, p, result);
        if (j > 0)
            dfs(board, i, j - 1, p, result);
        if (i < board.size() - 1)
            dfs(board, i + 1, j, p, result);
        if (j < board[0].size() - 1)
            dfs(board, i, j + 1, p, result);
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        int n = board.size();
        Trie trie;
        int m = board[0].size();
        for (auto word : words) {
            trie.insert(word);
        }
        vector<string> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(board, i, j, trie.root, res);
            }
        }
        return res;
    }
};