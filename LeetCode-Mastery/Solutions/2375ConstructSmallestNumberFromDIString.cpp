class Solution {
    public:
        string smallestNumber(string pattern) {
            string result; // This will store the final smallest number based on the pattern
            stack<int> numStack; // A stack to manage the order of digits
    
            // Loop through the pattern string and one additional iteration to handle the last number
            for (int i = 0, sz = pattern.size(); i <= sz; i++) {
                numStack.push(i + 1); // Push the current number onto the stack
    
                // If we encounter an 'I' (increasing pattern) or reach the end of the pattern
                if (pattern[i] == 'I' || i == pattern.size()) {
                    // Pop all elements from the stack and append them to the result
                    while (!numStack.empty()) {
                        result += to_string(numStack.top()); // Append the top of the stack to the result
                        numStack.pop(); // Remove the top element from the stack
                    }
                }
            }
            return result; // Return the constructed smallest number
        }
    };
    