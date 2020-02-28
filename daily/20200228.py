class Solution:
  def lengthOfLongestSubstring(self, s):
    # Fill this in.
    n = len(s)
    se = set()
    ret, i, j = 0, 0, 0
    while i < n and j < n:
      if s[j] not in se:
        j = j+1
        se.add(s[j-1])
        ret = max(ret, j - i)
      else:
        se.discard(s[i+1])
        i = i + 1
    return ret

print Solution().lengthOfLongestSubstring('abrkaabcdefghijjxxx')
#10
