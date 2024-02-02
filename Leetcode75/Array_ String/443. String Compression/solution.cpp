class Solution
{
public:
    // Function to compress a character array in-place and return the length of the compressed result
    int compress(vector<char> &chars)
    {
        unordered_map<char, int> mp;  // Map to store character frequencies
        string str = "";  // String to store the compressed result

        // Iterate through the characters in the array
        for (int i = 0; i < chars.size(); i++)
        {
            // Check if the current character is repeated or if the map is empty
            if (mp.count(chars[i]) || mp.empty())
                mp[chars[i]]++;  // Increment the count if the character is repeated or if the map is empty
            else if (mp.size() > 0)
            {
                // If a new character is encountered, append the previous character and its count to the result string
                string temp = to_string(mp[chars[i - 1]]);
                str += chars[i - 1];
                if (temp.compare("1") != 0)
                    str += temp;  // Append count only if it's greater than 1
                mp.clear();  // Clear the map for the new character
                mp[chars[i]] = 1;  // Initialize count for the new character
            }
        }

        // Process the last character and its count
        string temp1 = to_string(mp[chars[chars.size() - 1]]);
        str += chars[chars.size() - 1];
        if (temp1.compare("1") != 0)
            str += temp1;

        // Update the original character array with the compressed result
        for (int i = 0; i < str.length(); i++)
            chars[i] = str[i];

        // Return the length of the compressed result
        return str.length();
    }
};
