# Lexical Analyzer

Lexical Analyzer is used to analysis lexemes which is nothing but a sequence of strings.

<div align="center">
  <img src="https://binaryterms.com/wp-content/uploads/2021/11/Lexical-Analysis-in-Compiler.jpg">
  <br>
  <p>Lexical Analyzer</p>
</div>

`Token` (language): a set of strings 

    – if, identifier, relop

`Pattern` (grammar): a rule defining a token

    – if: if
    – identifier: letter followed by letters and digits
    – relop: < or <= or = or <> or >= or >

`Lexeme` (sentence): a string matched by the pattern of a token 

    – if, Pi, count, <, <=

`Attributes` are used to distinguish different lexemes in a token

    – < if, >
    – < identifier, pointer to symbol table entry > – < relop, ‘=’ >
    – < number, value >

The role of the Lexical analyzer is to:-

Classify program substrings according to the token class. 

Communicate tokens to the parser.

              <Id, “max”> 
              <Op, “=“>
              <Int, “50”>

Token class <STC, “;”> String(also called as Lexeme)

## Token Class: 
Operator, Whitespace, Keyword, Identifier, Number

## Special Token Class(STC): 
( ); = (Also called as single character string)

An Implementation must do the following two things:-

 - 1. Recognize `substrings` corresponding to tokens: `The lexemes`
 - 2. Identify the `token class` of each lexeme: Create a separate array for all token class

Step1: `Partitioning the string`: Read the string left to right and recognize one token at a time.
  Step1.1: Perform `Lookahead` to decide where one token ends and the next token begins.
Step2: Identify the `Token class` : Write the separate function to compare the token from the array of token class

## To run the C program

```shell
gcc analyzer.c -o analyzer
./analyzer
```
