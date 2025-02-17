class Solution {
    public:
        // Recursive function to generate all possible sequences using the tiles
        void generateSequences(string& tiles, string current, vector<bool>& used, unordered_set<string>& sequences) {
            // Insert the current sequence into the set (ensures uniqueness)
            sequences.insert(current);
    
            // Iterate over each character in the tiles string
            for (int i = 0; i < tiles.size(); i++) {
                if (!used[i]) { // If the current tile is not used yet
                    used[i] = true; // Mark it as used
                    generateSequences(tiles, current + tiles[i], used, sequences); // Recursively add the next tile
                    used[i] = false; // Backtrack (undo the change) to explore other possibilities
                }
            }
        }
    
        // Function to calculate the number of unique sequences that can be formed
        int numTilePossibilities(string tiles) {
            unordered_set<string> sequences; // Stores unique sequences
            vector<bool> used(tiles.size(), false); // Keeps track of used tiles during recursion
    
            generateSequences(tiles, "", used, sequences); // Start the recursive sequence generation
    
            return sequences.size() - 1; // Subtract 1 to exclude the empty sequence
        }
    };
    