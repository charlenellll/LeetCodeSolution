Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,

	add(1); add(3); add(5);
	find(4) -> true
	find(7) -> false

## Data structure I choose is important: unordered_map

Because in this problem it emphasizes "pair of numbers", since I can find an element in the map, I don't need an ordered data structure(such as array) to use collider pointers. I don't need collider pointers at all!

My understanding of collider pointer upgrade a level:  
I only need to use collider pointers on the data structures that I cannot know all elements' values such as a sorted array. On data sructure such as map and set I can know all the keys so there is no need for two pointers.