A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

## Backtracking

There are two DFS in each DFS step:
+ find sum that contain current number
+ find sum that not contain current number, and find the sum start from the next bit

使用回溯法，递归的出口为num=0；对10个灯做深度优先搜索，注意需要剪枝，即小时要小于12，分钟要小于60，参见代码文件。

### Pruning the backtracking tree

## Bit map

I have not tried this! the solution is simple but hard to understand for now:

对小时h和分钟m进行遍历，总共有12\*60种可能（分别为12小时和60分钟），之后将小时h左移6位（右边6位为分钟m的二进制）转换成题目要求的10个二进制，并调用bitset的count计算二进制中1的个数，若1的个数等于num，则该时间满足题目要求，这里需要注意时间的格式。

	vector<string> readBinaryWatch(int num) {
	    vector<string> rs;
	    for (int h = 0; h < 12; h++)
	    for (int m = 0; m < 60; m++)
	        if (bitset<10>(h << 6 | m).count() == num)
	            rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
	    return rs;
	}