Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.

# Hard for an "Easy" problem - the hard part is understanding the definition of this problem

太痛苦了，因为题意没有理解好，这简单道题竟然花了很多很多时间，这里就用中文总结一下，更言简意赅直中要害。

## 题意

（首先由树形结构，确定了本题使用DFS。）

在这棵树中寻找一条每个节点的值相同的路径。注意，这个路径不是一定从上往下的，题意说了，路径长度由两个节点之间的edge个数决定，说明这是一个无向图。  
所以在递归中，对一个当前的根节点来说，最长的路径为：**一个根节点到左边的最长路径+到右边的最长路径**。
+ 当我们求最大值时，是不断记录左右和根节点相同值节点的路径长度之和
+ 向上一层返回时，只返回左或右的最长路径，而不是返回其和，因为path不会经过当前的根节点了

具体来说：  
+ 如果左右子节点（或其中之一）和它的值相同，则为左右各自的路径长度分别+1（1即为子节点和当前根节点间的多出来的这一条edge数，而不是节点数或是别的什么，心里一定要清楚）之后相加，并通过比较记录下这个最长的路径长度
  + 需要注意的是，递归往上返回的值并不是这个最大长度！！因为返回时
+ 如果左右子节点任意点和当前root的值不同，则直接递归调用dfs(left)或right，而不收取其返回值，l或r = 0，至少对本根节点的反馈是0，最大值需要它自己在子节点中去找。
  + 调用dfs(left)或right时，需要让它知道当前最大路径长度的历史记录，所以需要把这个最大值传给它，我在代码里为了访问方便，直接设置为了类的私有变量，可以供子函数自己获取，不需要传来传去。但核心思想是要把最长的历史记录传给它，并且记录下来最长值（鉴于函数返回值是左右边的最长path，并不是这个左右path之和最大值，所以如果用传的话，只能传这个值的引用，要允许子函数改变它才行）

### 这道题很多地方容易出错，看代码。