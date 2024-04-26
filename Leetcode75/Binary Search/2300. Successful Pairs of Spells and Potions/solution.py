class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        
        # Sort the potions list in ascending order
        potions.sort()
        
        # Initialize an empty list to store the counts of successful pairs
        ans = list()
        
        # Get the length of the potions list
        ln = len(potions)
        
        # Iterate through each spell in the spells list
        for i in spells:
            # Initialize pointers for binary search
            l, r = 0, ln - 1 

            # Perform binary search to find the count of successful pairs for the current spell
            while l <= r:
                mid = (l + r) // 2
                
                # Check if the product of the current potion and the spell is greater than or equal to the success value
                if i * potions[mid] >= success:
                    r = mid - 1  # Update the right pointer to search in the left half
                else:
                    l = mid + 1  # Update the left pointer to search in the right half

            # Append the count of successful pairs for the current spell to the ans list
            ans.append(ln - l)
        
        # Return the list containing counts of successful pairs for each spell
        return ans
