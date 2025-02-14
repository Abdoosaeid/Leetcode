class ProductOfNumbers {
    public:
        vector<int> prefixProduct; // Stores prefix products of the numbers added
        int lastIdx; // Keeps track of the last index where a zero was encountered
    
        // Constructor to initialize the data structure
        ProductOfNumbers() {
            prefixProduct.push_back(1); // Initialize with 1 to simplify multiplication logic
            lastIdx = -1; // Initially, no zero has been encountered
        }
        
        // Adds a new number to the list
        void add(int num) {
            if (num == 0) {
                // If the number is zero, reset the prefix product array
                prefixProduct.clear();
                prefixProduct.push_back(1); // Reset with 1 to avoid division errors
                lastIdx = prefixProduct.size() - 1; // Update last index of zero
            } else {
                // Append the new product to the prefix product array
                prefixProduct.push_back(num * prefixProduct.back());
            }
        }
        
        // Returns the product of the last k numbers
        int getProduct(int k) {
            int size = prefixProduct.size(); // Get the current size of the prefix product array
            
            // If the requested range includes a zero, return 0
            if (size - k - 1 < lastIdx) {
                return 0;
            }
            
            // Compute the product using prefix division
            return prefixProduct.back() / prefixProduct[size - k - 1]; 
        }
    };
    