Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

For example, "great acting skills" and "fine drama talent" are similar, if the similar word pairs are pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is not transitive. For example, if "great" and "fine" are similar, and "fine" and "good" are similar, "great" and "good" are not necessarily similar.

However, similarity is symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].

Note:

The length of words1 and words2 will not exceed 1000.
The length of pairs will not exceed 2000.
The length of each pairs[i] will be 2.
The length of each words[i] and pairs[i][j] will be in the range [1, 20].

# Solution

Store pairs in a hash table for convenience, and compare the sentences in one pass.

遇到了一些坑：

### map和unordered_map之间的区别，前者key值需要的是比较函数，后者需要hash函数

发现这个问题：2018-06-30

    unordered_set<pair<string, string>> word_pairs; 编译错误
    set<pair<string, string>> word_pairs; 编译正确

由于set的key值需要hash函数：pair没有默认的hash函数.你需要自己传一个进去。

### unordered_map 或 map 的 find() 和 count() 的区别

见代码中 8 ms例程。对方喜欢用count()，当然我觉得它这样是不严谨的，现在仅仅是记录下：

+ find()：如果key存在，则find返回key对应的迭代器，如果key不存在，则find返回unordered_map::end
+ count(): count函数用以统计key值在unordered_map中出现的次数。实际上，c++ unordered_map不允许有重复的key。因此，如果key存在，则count返回1，如果不存在，则count返回0.