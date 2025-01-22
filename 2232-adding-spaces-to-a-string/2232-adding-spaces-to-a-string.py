class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        # Initialize a list to store the resulting characters.
        result = []
        
        # Pointer to iterate over the spaces array.
        space_index = 0
        
        # Traverse the string.
        for i, char in enumerate(s):
            # If the current index matches a space index, add a space.
            if space_index < len(spaces) and i == spaces[space_index]:
                result.append(' ')
                space_index += 1
            
            # Add the current character to the result.
            result.append(char)
        
        # Join the result list into a single string and return it.
        return ''.join(result)