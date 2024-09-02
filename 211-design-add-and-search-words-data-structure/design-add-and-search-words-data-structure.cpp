class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        this->data = ch;
        for (int i = 0; i < 26; i++) {
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class WordDictionary {

public:
    TrieNode* root;
    WordDictionary() { root = new TrieNode('/'); }

    void insertion(TrieNode* root, string word, int s, int e) {
        if (s == e)
            return;
        // BAT, BAD
        int ind = word[s] - 'a';
        if (root->children[ind] == NULL)
            root->children[ind] = new TrieNode(word[s]);
        if (s == e - 1)
            root->children[ind]->isTerminal = true;

        insertion(root->children[ind], word, s + 1, e);
    }

    bool searching(TrieNode* root, string word, int s, int e) {
        /* two criteria
            1. All characters need to be present
            2. last character should be marked as terminal

            // BATS
        */

        if (s == e)
            return root->isTerminal;

        // dfs
        if(word[s] == '.') {
            for (int i = 0; i < 26; i++) {
                if (root->children[i] && searching(root->children[i], word, s+1, e)) {
                    return true;
                }
            }
            return false;
        }

        else {
            int ind = word[s] - 'a';
            if(root->children[ind] == NULL) return false;
            return searching(root->children[ind], word, s+1, e);
        }

        return 0;
    }

    void addWord(string word) { insertion(root, word, 0, word.length()); }

    bool search(string word) { return searching(root, word, 0, word.length()); }
};
