class Solution { 
    public:     
        // Helper function to calculate the sum of digits of a given number
        int digits(int num) {         
            int sum = 0;         
            while(num) {  
                // Extract the last digit and add it to the sum           
                sum += (num % 10);             
                num /= 10;  // Remove the last digit        
            }         
            return sum;  // Return the sum of digits    
        }     
    
        // Function to find the maximum sum of two numbers having the same digit sum
        int maximumSum(vector<int>& nums) {         
            ios_base::sync_with_stdio(false); 
            cout.tie(NULL); 
            cin.tie(NULL);  
            // This speeds up input/output operations (useful in competitive programming)
    
            int res = -1; // Variable to store the maximum sum, initialized to -1 (for no valid pair)
    
            int arr[82] = {}; // Array to store the maximum number encountered for each digit sum (0 to 81)
    
            // Iterate over each number in the given array
            for(int &num : nums) {             
                int digitSum = digits(num); // Calculate the digit sum of the number             
    
                // If a number with the same digit sum already exists in the array
                if(arr[digitSum]) {                 
                    res = max(res, arr[digitSum] + num); // Update the maximum sum if the pair sum is larger
                }             
    
                // Store the maximum number encountered for this digit sum
                arr[digitSum] = max(arr[digitSum], num);         
            }         
            
            return res; // Return the maximum sum found    
        } 
    };
    