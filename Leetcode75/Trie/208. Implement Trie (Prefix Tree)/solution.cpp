class TrieNode {
public:
    map<char, TrieNode *> next = {}; // Map to store links to the next nodes
    bool isWord = false; // Flag to indicate if the current node represents the end of a word
};

class Trie {
public:
    TrieNode* root; // Pointer to the root node of the Trie

    // Constructor to initialize the Trie with an empty root node
    Trie() {
        root = new TrieNode();
    }

    // Function to insert a word into the Trie
    void insert(string word) {
        TrieNode *node = root;
        // Traverse each character in the word
        for (char &c : word) {
            // If the current character is not in the next nodes map, create a new TrieNode
            if (!node->next[c]) {
                node->next[c] = new TrieNode();
            }
            // Move to the next node
            node = node->next[c];
        }
        // Mark the last node as representing the end of a word
        node->isWord = true;
    }

    // Function to search for a word in the Trie
    bool search(string key, bool prefix = false) {
        TrieNode *p = root;
        // Traverse each character in the key
        for (auto &a : key) {
            // If the current character is not in the next nodes map, the word does not exist
            if (!p->next[a]) return false;
            // Move to the next node
            p = p->next[a];
        }
        // If the search is for an exact word, return true only if the last node represents a word
        if (prefix == false) return p->isWord;
        // If the search is for a prefix, return true as long as the key characters are found in the Trie
        return true;
    }

    // Function to check if there exists any word in the Trie that starts with the given prefix
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};
