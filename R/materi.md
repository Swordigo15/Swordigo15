> Syntax

```
#This is comment
#This
#is
#multiline
#comment

#Code
1 + 2 
#Output : 3
```

> Initializing Variable

```
a <- 1
3 -> b
c <- d <- e <- 7

#printing output
a #Output : 1
b #Output : 3
c #Output : 7
d #Output : 7
e #Output : 7

#Print() usually used, if you want to printing variable inside curly braces
if(a < b){
  print(a)
}else{
  print(b)
}
```
> Naming Variable

```
# Legal variable names:
myvar <- "John"
my_var <- "John"
myVar <- "John"
MYVAR <- "John"
myvar2 <- "John"
.myvar <- "John"

# Illegal variable names:
2myvar <- "John"
my-var <- "John"
my var <- "John"
_my_var <- "John"
my_v@ar <- "John"
TRUE <- "John"
```

> Data type
  - numeric (10, 34.6, 1930)
  - integer (10L, 30L, 48L, where the letter "L" declares this as an integer)
  - complex (7 + 2i, where "i" is the imaginary part)
  - character (string) --> "Hello", 'World', '34', "9.3"
  - logical (boolean) --> True and False

Use class() function to check the type of varable.

as.numeric() convert variable to numeric.

as.integer() convert variable to integer.

as.complex() convert variable to complex.

> Math
  - Operator
    | + | Addition
    | - | 
    | * | Multiplication
    | / | Division
    | % | Modulus
  - Function
