;
class Trie {
    char data;
    Trie* children[26];
    bool isTerminal;

public:
    Trie* root;
    Trie() { root = new Trie('/'); }

    Trie(char ch) {
        this->data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isTerminal = false;
    }

    void insertUtil(Trie* root, string word, int s, int e) {
        if (s == e)
            return;
        int ind = word[s] - 'a';

        if (root->children[ind] == NULL)
            root->children[ind] = new Trie(word[s]);
        if (s == e - 1)
            root->children[ind]->isTerminal = true;

        insertUtil(root->children[ind], word, s + 1, e);
    }

    bool searchUtil(Trie* root, string word, int s, int e) {
        if (s == e)
            return root->isTerminal;
        int ind = word[s] - 'a';
        if (root->children[ind] != NULL)
            return searchUtil(root->children[ind], word, s + 1, e);

        return false;
    }

    bool prefixUtil(Trie* root, string prefix, int s, int e) {
        if (s == e)
            return true;
        int ind = prefix[s] - 'a';
        if (root->children[ind] != NULL)
            return prefixUtil(root->children[ind], prefix, s + 1, e);

        return false;
    }

    void insert(string word) { insertUtil(root, word, 0, word.length()); }

    bool search(string word) {
        return searchUtil(root, word, 0, word.length());
    }

    bool startsWith(string prefix) {
        return prefixUtil(root, prefix, 0, prefix.length());
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */