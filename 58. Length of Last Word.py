class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        sWords = s.split()
        return len(sWords[-1])