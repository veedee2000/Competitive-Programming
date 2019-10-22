class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        ans = ""
        pre_ans = ""
        if len(strs) == 0: return ""
        for prefix in strs[0]:
            pre_ans += prefix 
            for word in strs:
                if word.startswith(pre_ans): continue
                else: return ans
            ans = pre_ans
        return ans
