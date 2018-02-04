Several friends at a cinema ticket office would like to reserve consecutive available seats.
Can you help to query all the consecutive available seats order by the seat_id using the following cinema table?

	| seat_id | free |
	|---------|------|
	| 1       | 1    |
	| 2       | 0    |
	| 3       | 1    |
	| 4       | 1    |
	| 5       | 1    |
Your query should return the following result for the sample case above.

	| seat_id |
	|---------|
	| 3       |
	| 4       |
	| 5       |
Note:
The seat_id is an auto increment int, and free is bool ('1' means free, and '0' means occupied.).
Consecutive available seats are more than 2(inclusive) seats consecutively available.

## Need delicate thoughts about how to find the consecutive elements

To find consecutive seats that are free, for a seat whose "free" is true:
+ see if the elements before or below it is true

How to arrange the sql clauses and achieve minimum cost need delicate design.


### One thing about alias

+ in sql, all temp table need an alias
+ except the temp table after "IN" and "NOT IN"

A (very unefficient) solution of this problem brought me to this understanding:

	select a1.seat_id
	from cinema a1
	where a1.free = 1 and (
	    a1.seat_id + 1 in (select seat_id from cinema where free = 1)
	    or
	    a1.seat_id - 1 in (select seat_id from cinema where free = 1)
	);
	
	# in this code, note that: only when we use "IN" or "NOT IN", the temp table after that does not need an alias.

**Note that:**  
Of course, "IN" and "NOT IN" are very unefficient. We should always replace them by table join (It is faster since it operates according to curtain index)