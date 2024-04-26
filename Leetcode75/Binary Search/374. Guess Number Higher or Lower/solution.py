class Solution:
    def guessNumber(self, n: int) -> int:
        l, r, ans = 1, n, n  # Initialize the search range and the answer

        # Binary search loop
        while l <= r:
            mid = (l + r) // 2  # Calculate the middle value
            
            # Guess the number and check the result
            if guess(mid) == 0:  # If the guess is correct
                ans = mid  # Update the answer
                break  # Exit the loop
            elif guess(mid) == -1:  # If the guess is higher than the picked number
                r = mid - 1  # Adjust the upper bound of the search range
            else:  # If the guess is lower than the picked number
                l = mid + 1  # Adjust the lower bound of the search range
        
        return ans  # Return the answer
