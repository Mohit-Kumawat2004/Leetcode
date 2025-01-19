class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        words = []
        for i in range(len(sentence)):
            if sentence[i] == " ":
                # Check the char before and after space
                if sentence[i - 1] != sentence[i + 1]:
                    return False
        return sentence[0] == sentence[len(sentence) - 1]
        