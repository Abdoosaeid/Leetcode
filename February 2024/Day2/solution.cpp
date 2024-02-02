class Solution {
public:
    // Function to make number in size sz  in a string
    string convert(int sz)
    {
        string s = "";
        for(int i = 1; i <= sz; i++)
        {
            s += to_string(i);
        }
        return s;
    }

    // Main function to generate sequential digits within the specified range
    vector<int> sequentialDigits(int low, int high) {
        // Convert the lower limit to a string to determine the size
        string s1 = to_string(low);
        s1 = convert(s1.size());

        vector<int> ans;  // Vector to store the sequential digits within the range

        // Continue generating sequential digits until the converted number exceeds the upper limit
        while (stoll(s1) <= high)
        {
            // Add the current number to the result if it is within the specified range
            if (stoll(s1) >= low)
            {
                ans.push_back(stoll(s1));
            }

            // Increment the current sequential number
            for (int i = 0; i < s1.size(); ++i) {
                // If the digit is '9', reset to a new sequential number with an increased size
                if (s1[i] == '9')
                {
                    s1 = convert(s1.size() + 1);
                    break;
                }
                s1[i] += 1;
            }
        }

        return ans;  // Return the vector containing sequential digits within the specified range
    }
};
