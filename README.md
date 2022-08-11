<sub>README still in progress</sub>  
## Description 
Push_Swap is a 42 project which aim is to sort a stack using a specific set moves

### Alowed moves
sa
```
Swap first two element of stack A
1      2
2  =>  1
3      3
```
sb  
ss  
ra  
rb  
rr  
rra  
rrb  
rrr  

### Goal
Sort the stack in the least possible number of moves.  
To get the full mark (125):   

3 numbers should be sorted in: max 2 moves  
5 numbers should be sorted in: max 12 moves  
100 numbers should be sorted in: max 700 moves   
500 numbers should be sorted in: max 5500 moves  

### How  
This is my implementation of "the best element algorithm" (as called by the original creator, see their instructions in **ressource** folder)   
### 1- Parsing:  
if the input is valid, it gets added to a doubly circular linked list called **stack_a**  
#### what's a valid input?
- contains only digits, but may contain ('+' or '-') once at the begining  
- an INT  
- no duplicates   
### 2- Best element algorithm (overview)
1. copy **STACK A**'s content in an array  
2. put the **smallest** number at the begining of the array   
3. extract the [Longuest Increasing Subsequence](https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/) from the array  
4. now returning to **STACK A**: push all numbers to **STACK B** except the elements of **LIS**   
5. loop over STACK B calculating for each element:   
	1. number of moves it'll take for the element to be **on top of STACK B** --> the result would be stored in **moves[1]**.   
		- if rb is used the number stored should be positive  
		- if rrb is used the number stored should be negative  
		- *this distinction is made to be able to use rr / rrr in case of matching sign with moves[0]*  
	2. number of moves it'll take to put the element (now hypotetically **on top of STACK A**) in its convenable place in STACK A  --> the result would be stored in **moves[0]**.    
		- if ra is used the number stored should be positive   
		- if rra is used the number stored should be negative  
		- *again, this distinction is made to be able to use rr / rrr is case of matching sign with moves[1]*   
	3. calculate the total number of moves:   
		There is 2 cases:   
		- if moves[0] and moves[1] have the same sign:   
			the total numbers of moves is the **maximum** of both *absolute* values  
		- if moves[0] and moves[1] have different signs:  
			the total numbers of moves is the **sum** of both *absolute* values  
	 4. chose the element with the _smallest_ (total number of moves) and push is to its convenable place in **STACK A**  
6. repeat step 5 until **STACK B** in empty  
7. in **STACK A**, put smallest number on the top  

#### How to find a number most convenable place in STACK A?    
