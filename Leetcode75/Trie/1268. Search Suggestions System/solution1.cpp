class TrieNode {
public:
    map<char, TrieNode *> next = {}; // Map to store pointers to child TrieNodes
    bool isWord = false; // Flag indicating if the current node represents the end of a word
};

class Solution {
public:
    // Function to insert a word into the Trie
    void insert(TrieNode *trie, const string &word) {
        for (char l : word) {
            if (!trie->next[l]) {
                trie->next[l] = new TrieNode(); // Create a new TrieNode if it doesn't exist
            }
            trie = trie->next[l]; // Move to the next TrieNode
        }
        trie->isWord = true; // Mark the end of the word
    }

    // Function to perform DFS to find suggestions for a given prefix
    vector<string> searchSuggestions(TrieNode *trie, const string &prefix) {
        vector<string> result;
        TrieNode *node = trie;
        for (char c : prefix) {
            if (!node->next[c]) {
                return {}; // If prefix does not exist in the Trie, return empty vector
            }
            node = node->next[c]; // Move to the next TrieNode
        }
        dfs(node, prefix, result); // Perform DFS from the node corresponding to the prefix
        return result;
    }

    // DFS traversal to find suggestions starting from a given TrieNode
    void dfs(TrieNode *trie, string pre, vector<string>& result) {
        if (result.size() == 3) {
            return; // Stop traversal if 3 suggestions are found
        }
        if (trie->isWord) {
            result.push_back(pre); // Add word to result if it represents the end of a word
        }
        for (auto &m : trie->next) {
            dfs(m.second, pre + m.first, result); // Recursively traverse child TrieNodes
        }
    }

    // Function to suggest products for a given search word
    vector<vector<string>> suggestedProducts(vector<string>& products, const string& searchWord) {
        TrieNode *trie = new TrieNode; // Create a new TrieNode
        // Insert each product into the Trie
        for (const string &s : products) {
            insert(trie, s);
        }
        vector<vector<string>> result;
        string prefix;
        // For each character in the search word, find suggestions and add them to the result
        for (char c : searchWord) {
            prefix += c;
            result.push_back(searchSuggestions(trie, prefix));
        }
        return result; // Return the final result
    }
};
