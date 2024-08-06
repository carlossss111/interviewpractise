/*
To evaluate advanced AI software at <COMPANY NAME>, we have q
different programs set to undergo testing on n problems.
Each problem has its own difficulty level difficulty[i] and
a score tied to its complexity. Each AI program also comes
with a specific ability level denoted by ability[i].

In practical terms, as software encounters each problem,
it checks if its ability is sufficient to solve it. If the
ability meets or exceeds the difficulty level, the program
successfully solves the problem, earning a score equal to
the problem's complexity. The program then moves on to the
next problem. If the ability falls short, the evaluation
for that problem concludes.

Formally, given two arrays: one array ability of size q,
representing the ability level of all AI software, and another
array difficulty of size n, represetngint the difficulty level
of the problems.

Figure out the total score achieved by each of the q AI
programs. It's important to note that if a program can't
solve any problems, its score is zero.

Example:
ability[] size q = 3
ability = [5,1,4]

difficulty[] size n = 5
difficulty = [4,1,2,5,1]

Output = [13,0,7]
*/

//TODO
