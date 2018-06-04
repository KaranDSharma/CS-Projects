# Algorithm: prints input
#   1. just returns what you parse into it
#   Input parameters: param of no specified type
#   Output: param
#   Returns: ø
def print_param(param):
    print (param) #just prints this thing

# Algorithm: checks if number is odd or even
#   1. if remainder when dividing input value by 2 is 0, is even. else is odd
#   Input parameters: integ
#   Output: prints odd or even
#   Returns: ø
def odd_or_even(integ):
    if integ%2 == 0: #checks if remainder when divided by 2 is 0 indicating even
        print ("even")
    else: #if not even is odd
        print("odd")

# Algorithm: goes from 1 to n printing fizz, buzz, or fizzbuzz if the number is divisible by 3, 5, or both
#   1. checks values 0 through n
#   2. if 15 (divisible by 3 and 5)
#   3. if divisible of 3 and not 0 as 0 doesnt give remainder
#   4. if divisible by 5 and not 0 as 0 doesnt give remainder
#   5. for all other values
#   Input parameters: n
#   Output: prints integer value and assorted strings
#   Returns: ø
def fizz_buzz(n):
    for i in range(0,n+1): #checks values 0 through n
        if i == 15: #if 15 (divisible by 3 and 5)
            print("FizzBuzz")
        elif i%3 == 0 and i != 0: #if divisible of 3 and not 0 as 0 doesnt give remainder
            print("Fizz")
        elif i%5 == 0 and i != 0: #if divisible by 5 and not 0 as 0 doesnt give remainder
            print("Buzz")
        else: #for all other values
            print(i)

# Algorithm: creates n number of 1s and sums up the values
#   1. holds the n number of 1s and hold the total values of summed 1s
#   2. creates the integer of 1s
#   3. stores the sum of place
#   Input parameters: n
#   Output: ø
#   Returns: sum
def oneSum(n):
    place = 0 #holds the n number of 1s
    sum = 0 #to hold the total values of summed 1s
    for i in range(0,n):
        place = 10**i + place #creates the integer of 1s
        sum = sum + place #stores the sum of place
    return sum
    
def main():
    print print_param(3) #test cases
    print print_param('hello')
    print odd_or_even(3)
    print odd_or_even(10)
    print fizz_buzz(14)
    print fizz_buzz(12)
    print oneSum(3)
    print oneSum(10)
    