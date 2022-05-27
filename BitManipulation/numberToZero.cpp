// Brute force approach

class Solution {
public:
    int numberOfSteps(int num) { // number of steps to reach 0
        int count=0; // count of steps
        while(num){ // while num is not 0
            if(num%2) // if num is odd
                --num; // decrement num
			else // if num is even
                num=num/2; // divide num by 2
            ++count; // increment count
        }
        return count; // return count    
    }
};

// Bit Manipulation technique
class Solution {
public:
int numberOfSteps(int num) { //  number of steps to reach 0    
        int count = 0; // number of steps 
        while(num){ // while n is not 0
            num = num & 1 ? num - 1 : num >> 1; // if n is odd, subtract 1, else right shift by 1
            count++; // increment count
        }
        return count; // return count
    }
};