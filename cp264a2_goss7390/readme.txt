Name: Robert Goss
ID: 180897390
Email: goss7390@mylaurier.ca
WorkID: cp264a2
Statement: I claim that the enclosed submission is my individual work 

Check list, self-evaluation/marking, marking scheme:
Note: fill self-evaluation for each of the following brackets. The field format is [self-evaluation / total marks / marker's evaluation]. For example, you put your self-evaluation, say 2, like [2/2/]. If marker gives different evaluation value say 1, it will show [2/2/1] in the marking report. 

Evaluation: [self-evaluation/total/marker-evaluation]

Q1
1. correctness of iterative_fibonacci     [3/3/]
2. correctness of recursive_fibonacci     [3/3/]
3. main function and testing              [4/4/]

Q2
1. correctness of honor's algorithm       [5/5/]
2. main function                          [3/3/]  
3. evaluation & testing                   [2/2/]

Q3
1. horner function                        [3/3/]
2. bisection function                     [5/5/]
3. robustness	                          [2/2/]

Total:                                 [30/30/]


Test result:
Q1 output: (copy the screen output of your test run) 
Iterative algorithm measurement:
iterative_fibonacci(40): 102334155
high address: 6422252
low address: 6422192
memory span: 60
time_span(iterative_fibonacci(40) for 500000 times): 74.0 (ms)

Recursive algorithm measurement:
recursive_fibonacci(40): 102334155
high address: 6422252
low address: 6420320
memory span: 1932
time_span(recursive_fibonacci(40) for 10 times): 63.0 (ms)

Comparison of recursive and iterative algorithms:
memory_span(recursive_fibonacci(40))/memory_span(iterative_fibonacci(40)): 32.2
time_span(recursive_fibonacci(40))/time_span(iterative_fibonacci(40)): 42567.6

Q2 output: (copy the screen output of your test run)
c:\cp264>a 1 2 3 4

Please enter x value (Ctrl+C or 999 to quit):
0
1.0*0.0*^3 + 2.0*0.0*^2 + 3.0*0.0*^1 + 4.0*0.0*^0= 4.0
Please enter x value (Ctrl+C or 999 to quit):
999
 
Q3 output: (copy the screen output of your test run) 
f(-2.000000): -2.000000
f(2.000000): 26.000000
root: -1.650630
f(-1.650630): -0.000004