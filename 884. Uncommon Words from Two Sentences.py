class Solution(object):
    def uncommonFromSentences(self, s1, s2):
        s1 += " " + s2
        s1 = s1.split()
        dic = {}
        for i in s1:
            if i not in dic:
                dic[i] = 0
            dic[i] += 1
        return [x for x in dic if dic[x] == 1]
        