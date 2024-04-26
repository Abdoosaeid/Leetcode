class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # Initialize the search range for the eating speed
        l, r = 1, max(piles)
        # Initialize the result with the maximum possible eating speed initially
        res = r
        
        # Perform binary search on the eating speed
        while l <= r:
            # Calculate the middle eating speed
            mid = (l + r) // 2
            # Initialize the total hours required to eat all bananas at the current speed
            count = 0

            # Calculate the total hours required for each pile at the current speed
            for pile in piles:
                count += math.ceil(pile / mid)

            # Check if the total hours required is less than or equal to the given h
            if count <= h:
                # Update the result with the minimum of the current result and the current speed
                res = min(res, mid)
                # Adjust the upper bound of the search range to continue searching for a smaller eating speed
                r = mid - 1
            else:
                # Adjust the lower bound of the search range to search for a faster eating speed
                l = mid + 1

        # Return the minimum eating speed that allows Koko to eat all bananas within h hours
        return res
