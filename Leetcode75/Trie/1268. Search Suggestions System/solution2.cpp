class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res; // Result vector to store product suggestions for each prefix
        sort(products.begin(), products.end()); // Sort the products lexicographically
        int l = 0, r = products.size() - 1; // Initialize left and right pointers for binary search

        // Iterate through each character in the search word
        for (int i = 0; i < searchWord.size(); ++i) {
            char c = searchWord[i];

            // Binary search to find the leftmost index where the ith character matches
            while (l <= r && (products[l].size() <= i || products[l][i] != c)) {
                l++;
            }

            // Binary search to find the rightmost index where the ith character matches
            while (l <= r && (products[r].size() <= i || products[r][i] != c)) {
                r--;
            }

            vector<string> v; // Vector to store product suggestions for the current prefix

            int remain = r - l + 1; // Calculate the number of remaining elements in the range [l, r]

            // Add up to 3 product suggestions to the result vector
            for (int j = 0; j < min(3, remain); ++j) {
                v.push_back(products[l + j]);
            }

            res.push_back(v); // Add product suggestions for the current prefix to the result
        }

        return res; // Return the final result
    }
};
