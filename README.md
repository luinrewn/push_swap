*This project has been created as part of the 42 curriculum by mprokope.*

# Push Swap

## Description
This project is a sorting algorithm that sorts a stack of numbers.
The main goal is to sort the stack in the least amount of moves.
Moves are predetermined and i'm not allowed to use moves that are not part of the allowed moves.
I'm using the algorithm named radix.
It works by firstly assigning an id to each element of the list and then checking the bits of each element.
It isolates one bit and checks whether the bit is 1 or 0. If it's 1 the element is rotated, else it's moved to stack b.

### Compilation
```bash
cd <name of the folder you git cloned>
make
```
## Instructions
The arguments futher referred as ARG must be within INTMIN and INTMAX ranges.
There shouldn't be any duplicates or symbols that are not (number or -).
The ARGs should be separeted by space and nothing else.
For examples see belowe.
In case of any errors the "Error" will be printed

### Examples
For bash terminal:
```bash
./push_swap <num 1> <num 2> <num 3>...<num n>
OR
ARG="<list of args separated by space>"; ./push_swap $ARG
```
For fish Terminal:
```bash
./push_swap <num 1> <num 2> <num 3>...<num n>
OR
set ARG <num 1> <num 2> <num 3>...<num n>; ./push_swap $ARG
```
For zsh Terminal:
```bash
./push_swap <num 1> <num 2> <num 3>...<num n>
OR
ARG="<list of args separated by space>"; ./push_swap ${(z)ARG}
```
To run it with checker:
```bash
./push_swap <num 1> <num 2> <num 3>...<num n> | ./cheker $ARG
OR
ARG="<list of args separated by space>"; ./push_swap $ARG | ./checker $ARG
```
Make usage:
To recompile the binary use:
```bash
make re
```

To clean a object files use:
```bash
make clean
```
And to clean all use:
```bash
make fclean
```


## Extras
Here i will include my bash script for simplyfication of the testing of this project:

```bash
#!/bin/bash

count=$1
min=1
max=99999999

declare -A nums

while [ "${#nums[@]}" -lt "$count" ]; do
    n=$(( RANDOM % (max - min + 1) + min ))
    nums[$n]=1
done

args=$(printf "%s " "${!nums[@]}" | sort -n | tr '\n' ' ')
echo -e "Generated arguments: $args \n"
echo "Number of operations taken: "
./push_swap $args | wc -l
echo "checker response: "
./push_swap $args | ./../checker $args
valgrind ./push_swap $arg
```

## Resources
https://42-cursus.gitbook.io/guide - guided me through the the whole jorney and allowed me to start and understand it faster.
AI (ChatGPT) was used for clarifying the radix algorithm concept and for proofreading parts of this README.
No AI-generated code was used in the final version.
And some github repos that explained algorithms but i coudn't find them anymore ;9
