1. Give a stream of numbers, we just keep k nums, we want the average of these nums excluding the lowest and largest 5 %, when the total # num is less than k, get 90% of total num. talk about heap or tree map... he said we have some way to update heap or the tree map in O(1)，I think Olog(n)??? According to my friend, he wants us to use BST, 


2. Q1:A hashmap with time to live; easy to implement with just hashmap to pair(val, time) ; then he asked a way to do clean up of expire entries a clean api sth, I used priority queue over the time, while the peek entry time is less than current time, remove it ...  ;; Q2: extra question to think: a book content may be in many Os pages, across pages may be how to look for those pages contain the book content; talk about map reduce and statistic compare; hashmap; rolling hash, don’t know the actual thing he wants


3. Stock price api add; update ; remove; (not necessarily O(1)), but implement getcurrprive ; get max and get min in O(1); idea is just track latesttime, max, min ; we only scan the hashmap to update latesttime, max, min when remove an element of max/min/latesttime ; Q2: is friend API, check if all in one set; mentioned BFS


4. 2D matrix max path sum from top to bottom; typical dp; debug; find some bug; Q2: 1m sidewalk rain drop simulation; I used priority queue to do interval merging. A range drop represent an interval [a,b]