# Blip Language Interpreter
### C++ Project that interprets Blip Programming Language

Syntax for Blip Programming Language:
* **text** statements result in a text message being displayed on the screen. The text message can be either
a single word, or a quoted string. The following are examples of legal text statements  
text Hello
text “Hello World”    

* **output** statements result in a number being displayed on the screen. The number displayed is the
result of evaluating any legal Blip expression. For now, Blip only supports integer variables, and so
only integer values can be displayed. The following are examples of output statements. For more
information on Blip expressions, see below:  
output 42  
output + 1 1  
output * x x  
output + * x x * y y  

* **var** statements initialize a new variable. If a var statement specifies a variable that already exists,
then Blip must generate a warning (not an error), with the text, “variable <varName> incorrectly
re-initialized”, where <varname> is the variable’s name. Regardless of whether the warning message
is created, the result of a var statement is to ensure that there is a variable in the Blip internal memory
11
with the specified value. The variable must be set to the value of a legal Blip expression. The syntax
is: “var <varName> <expr>”. The following are examples of legal var expressions:  
var x 42  
var y + x 1  

* **set** statements are just like var statements, except a set statement should be used to re-assign a new
value to an existing variable. As such, if a set statement specifies a variable that does not already exist,
then Blip must generate a warning (not an error) with the text, “variable <varName> not declared”.
Regardless of whether the warning message is created, the result of a set statement is to ensure that
there is a variable in the Blip internal memory with the specified value. The following are examples of
legal set expressions:  
set x 42  
set x + x 1  

Input commands in txt file (.BLIP). Add txt file as arguement in main C++ file.
