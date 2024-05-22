class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
         # Initialize default dictionary where each key has a default value of an empty list
        anagram_map = defaultdict(list)
        
        # Loop through each word in the input list
        for word in strs:
            
            # Sort the characters of the word and join them back into a string
            sorted_word = ''.join(sorted(word))
            
            # Use the sorted word as a key and append the original word to the corresponding list
            anagram_map[sorted_word].append(word)
        
        # Return the list of values from the anagram_map, which are lists of anagrams
        return list(anagram_map.values())
    
    
        