# Submission Results

## Submission 1 (ID: 767073)
- Status: Accepted
- Score: 100/100
- All 10 test cases passed
- Git commit: 58919872249f8d7f3916187d5153c3f0fcad1724

## Solution Approach
The solution implements a Pacman simulation following the right-hand rule:
1. Reads a 10x10 grid with walls (0), empty spaces (1), beans (2), ghosts (3), and starting position (4)
2. Pacman moves from the starting position initially upward
3. At each step, follows the right-hand rule priority: Right Turn > Straight > Left Turn > U-turn
4. Detects infinite loops by tracking visited states (position + direction)
5. Calculates score: +2 for each bean eaten (once), -500 when hitting a ghost
6. Outputs 'Silly Pacman' if entering infinite loop, otherwise outputs final score

