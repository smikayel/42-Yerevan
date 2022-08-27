## 📝 Introduction

You will discover a popular and versatile C function: printf(). This exercise is a great
opportunity to improve your programming skills. It is of moderate difficulty.
You will discover variadic functions in C.
The key to a successful ft_printf is a well-structured and extensible code

## 📐 

• Your project must be written in accordance with the Norm. If you have bonus
files/functions, they are included in the norm check and you will receive a 0 if there
is a norm error inside.

• Your functions should not quit unexpectedly (segmentation fault, bus error, double
free, etc) apart from undefined behaviors. If this happens, your project will be
considered non functional and will receive a 0 during the evaluation.

• All heap allocated memory space must be properly freed when necessary. No leaks
will be tolerated.

• If the subject requires it, you must submit a Makefile which will compile your
source files to the required output with the flags -Wall, -Wextra and -Werror, use
cc, and your Makefile must not relink.

• Your Makefile must at least contain the rules $(NAME), all, clean, fclean and
re.

• To turn in bonuses to your project, you must include a rule bonus to your Makefile,
which will add all the various headers, librairies or functions that are forbidden on
the main part of the project. Bonuses must be in a different file _bonus.{c/h}.
Mandatory and bonus part evaluation is done separately.

• If your project allows you to use your libft, you must copy its sources and its
associated Makefile in a libft folder with its associated Makefile. Your project’s
Makefile must compile the library by using its Makefile, then compile the project.

• We encourage you to create test programs for your project even though this work
won’t have to be submitted and won’t be graded. It will give you a chance
to easily test your work and your peers’ work. You will find those tests especially
useful during your defence. Indeed, during defence, you are free to use your tests
and/or the tests of the peer you are evaluating.

• Submit your work to your assigned git repository. Only the work in the git repository will be graded.
If Deepthought is assigned to grade your work, it will be done
after your peer-evaluations. If an error happens in any section of your work during
Deepthought’s grading, the evaluation will stop.

## 💾 Mandatory part

• You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
◦ The stack b is empty.
• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:
    sa (swap a): Swap the first 2 elements at the top of stack a.
    Do nothing if there is only one or no elements.
    sb (swap b): Swap the first 2 elements at the top of stack b.
    Do nothing if there is only one or no elements.
    ss : sa and sb at the same time.
    pa (push a): Take the first element at the top of b and put it at the top of a.
    Do nothing if b is empty.
    pb (push b): Take the first element at the top of a and put it at the top of b.
    Do nothing if a is empty.
    ra (rotate a): Shift up all elements of stack a by 1.
    The first element becomes the last one.
    rb (rotate b): Shift up all elements of stack b by 1.
    The first element becomes the last one.
    rr : ra and rb at the same time.
    rra (reverse rotate a): Shift down all elements of stack a by 1.
    The last element becomes the first one.
    rrb (reverse rotate b): Shift down all elements of stack b by 1.
    The last element becomes the first one.
    rrr : rra and rrb at the same time.
 
Your project must comply with the following rules:

    • You have to turn in a Makefile which will compile your source files. It must not
    relink.
    
    • Global variables are forbidden.
    
    • You have to write a program named push_swap that takes as an argument the stack
    a formatted as a list of integers. The first argument should be at the top of the
    stack (be careful about the order).
    
    • The program must display the smallest list of instructions possible to sort the stack
    a, the smallest number being at the top.
    
    • Instructions must be separated by a ’\n’ and nothing else.
    
    • The goal is to sort the stack with the lowest possible number of operations. During
    the evaluation process, the number of instructions found by your program will be
    compared against a limit: the maximum number of operations tolerated. If your
    program either displays a longer list or if the numbers aren’t sorted properly, your
    grade will be 0.
    
    • If no parameters are specified, the program must not display anything and give the
    prompt back.
    
    • In case of error, it must display "Error" followed by a ’\n’ on the standard error.
    Errors include for example: some arguments aren’t integers, some arguments are
    bigger than an integer and/or there are duplicates.
