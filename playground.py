class Solution(object):
    def areAlmostEqual(s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        diff = [(x, y) for x, y in zip(s1, s2) if x!= y]
        print(diff)
        print(not diff)
        return not diff or len(diff) == 2 and diff[0][::-1] == diff[1]


Solution.areAlmostEqual("kelp", "kelp")