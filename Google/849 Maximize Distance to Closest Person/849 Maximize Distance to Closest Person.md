In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to closest person.

Example 1:

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Note:

1 <= seats.length <= 20000
seats contains only 0s or 1s, at least one 0, and at least one 1.

## My solution: 比较暴力

O(n) time, O(n) space:  
用一个和input同样大小的数组dist记录这个位置与距离它最近的人的距离。

具体实现为：遍历一遍input， 先从左往右记录当前位置与“左边最近的人”的距离，等遇到了右侧最近的人再倒回来用与“右边最近的人”的距离覆盖“两个有人位置之间”的后一半位置。
+ 如果这一位为0， 则dist[i] = dist[i-1]+1;
+ 如果这一位为1， 则dist[i] = 0, 此时（需要用一个int记录前一个有人位置的index）:
	+ 1）要倒回去处理与前一个有人位置之间的后一半位置，从后往前用1开始覆盖，nums[j] = nums[j+1]+1
	+ 2) 特殊情况：前面没有人。上一条的终止条件记得分情况讨论。