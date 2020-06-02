Is it possible to have a recursive inline function?

Ans: Although you can call an inline function from within itself, 
the compiler may not generate inline code since the compiler cannot determine 
the depth of recursion at compile time. A compiler with a good optimizer can inline 
recursive calls till some depth fixed at compile-time (say three or five recursive calls), 
and insert non-recursive calls at compile time for cases 
when the actual depth gets exceeded at run time.