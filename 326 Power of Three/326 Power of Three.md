Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

## Brutal-force

### Recursively

See the code.

Use 1 as the base case.

### Iteratively

See the code.

# Follow up: without using any loop / recursion

## It's all about MATH!

### Method 1

Find the maximum integer that is a power of 3 and check if it is a multiple of the given input. (related post)

	public boolean isPowerOfThree(int n) {
	    int maxPowerOfThree = (int)Math.pow(3, (int)(Math.log(0x7fffffff) / Math.log(3)));
	    return n>0 && maxPowerOfThree%n==0;
	}

Or simply hard code it since we know maxPowerOfThree = 1162261467:

	public boolean isPowerOfThree(int n) {
	    return n > 0 && (1162261467 % n == 0);
	}


**Note that:**
It is worthwhile to mention that Method 1 works **only when the base is prime**. For example, we cannot use this algorithm to check if a number is a power of 4 or 6 or any other composite number.

### Method 2

If log10(n) / log10(3) returns an int (more precisely, a double but has 0 after decimal point), then n is a power of 3.

But be careful here, you cannot use log (natural log) here, because it will generate round off error for n=243. This is more like a coincidence. I mean when n=243, we have the following results:

	log(243) = 5.493061443340548    log(3) = 1.0986122886681098
	   ==> log(243)/log(3) = 4.999999999999999

	log10(243) = 2.385606273598312    log10(3) = 0.47712125471966244
	   ==> log10(243)/log10(3) = 5.0   
This happens because log(3) is actually slightly larger than its true value due to round off, which makes the ratio smaller.

	public boolean isPowerOfThree(int n) {
	    return (Math.log10(n) / Math.log10(3)) % 1 == 0;
	}

### Method 3

	public boolean isPowerOfThree(int n) {
	    return n==0 ? false : n==Math.pow(3, Math.round(Math.log(n) / Math.log(3)));
	}

### Method 4

	public boolean isPowerOfThree(int n) {
	    return n>0 && Math.abs(Math.log10(n)/Math.log10(3)-Math.ceil(Math.log10(n)/Math.log10(3))) < Double.MIN_VALUE;
	}