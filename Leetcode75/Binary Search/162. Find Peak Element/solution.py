class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        # Get the size of the array - 1 (index of last element)
        sz = len(nums) - 1
        # Initialize left and right pointers for binary search
        l, r = 0, sz

        while l <= r:
            # Calculate the middle index
            mid = l + (r - l) // 2

            # Check if the middle element is less than its left neighbor
            if mid > 0 and nums[mid] < nums[mid - 1]:
                # If so, move the right pointer to mid - 1
                r = mid - 1
            # Check if the middle element is less than its right neighbor
            elif mid < sz and nums[mid] < nums[mid + 1]:
                # If so, move the left pointer to mid + 1
                l = mid + 1
            else:
                # If the above conditions are not met, it means we've found a peak
                return mid
            
        # Return mid if no peak is found (should not happen for valid inputs)
        return mid
