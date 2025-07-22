# Compiler-Design-Basics
Company : CODETECH IT SOLUTION 
Name : Priyanshu Goyal 
Intern id : CT08DG1149 
Domain : C++ Developer 
Duration : 8 Weeks 

In this task, I made a small C++ program that can take basic arithmetic expressions as input, parse them, and calculate the result.
The program supports operators like +, -, *, / and also handles brackets () for grouping.

## What it does:
It reads an expression from the user.

It can work with multi-digit numbers and decimal points too.

If there’s an invalid expression, like missing brackets or division by zero, it shows an error message.

## How it works :
I used a method called recursive descent parsing.
Basically, the code is divided into small parts:

expr() handles addition and subtraction.

term() handles multiplication and division.

factor() handles numbers and brackets.

It checks each part of the expression step by step and calculates the answer correctly by following the proper order of operations (like BODMAS).

 In the end:
When I run the program, it asks me to enter an expression (like (2+3)*4) and then prints the result.
It keeps asking for new expressions until I type exit.

This was a simple but interesting way to learn how compilers and parsers work at a basic level.

## OUTPUT
##<img width="1150" height="548" alt="Screenshot 2025-07-22 150213" src="https://github.com/user-attachments/assets/7ecd4d86-7e90-4fc0-a2de-c18ca28934f5" />

