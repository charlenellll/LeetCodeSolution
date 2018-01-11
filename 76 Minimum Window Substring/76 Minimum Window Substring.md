Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

## Sliding window - hard

思路:Sliding Window，
1. 先找到包含 T 的第一个字串，然后把左边界缩小到最小但包含 T 的状态，这是第一个 Candidate。
2. 然后左边界前移，重复第一步，找到所有 Candidates。最终找到最小值并返回。

// O(n)