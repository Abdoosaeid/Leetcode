class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();

        // Sort the array in ascending order
        sort(arr.begin(), arr.end());

        // Arrays to store the length of the divisible subset and the previous index
        vector<int> lis(n, 1);
        vector<int> prev_idx(n, -1);

        int max_len = 1, last_index = 0;

        // Dynamic programming to find the length of the divisible subset
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (arr[i] % arr[j] == 0 && lis[j] + 1 > lis[i]) {
                    lis[i] = lis[j] + 1;
                    prev_idx[i] = j;
                }
            }

            // Update the maximum length and last index
            if (lis[i] > max_len) {
                max_len = lis[i];
                last_index = i;
            }
        }

        // Reconstruct the largest divisible subset
        vector<int> divisible_subset;
        while (last_index != -1) {
            divisible_subset.push_back(arr[last_index]);
            last_index = prev_idx[last_index];
        }

        // Reverse the result to get the correct order
        reverse(divisible_subset.begin(), divisible_subset.end());

        return divisible_subset;
    }
};
