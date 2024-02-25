# Madlib-Solver
A short and sweet madlib solver written in C. 


## How To Use
As the "usage" (from running with no arguments) implies, you must provide a words file and a madlib file. The details of which are provided below.


### Madlib File
A madlib file is simply a text file that contains word keys to be filled in by the madlib solver. A word key follows the following format:
`\<token\_name\>`

Here is an example for the the file: "My friend, \<noun\>, is a(n) \<adjective\> \<noun\> when they want to be."


### Word File
A word file is a structured text file that contains line-separated key/value pairs representing the type of word to replace and the word being placed respectively. A standard pair follows the following format:
`\<type\>:\<word\>`

Here is an example for the the file:
```
adjective:weird
adjective:green
noun:grape
adverb:longingly
```


### Organizing Everything
As was hopefully evident in the above examples, the word types in the words file should match the word key in the madlib file. Each word of a given type is given the same weight in terms of chances to be used. To change these weights, simply repeat the type/word pair in the file to add weight to it. For example, "pear" will be twice as likely to be chosen for the madlib as "apple" with the following words file:
...
noun:pear
noun:pear
noun:apple
...


## So Why Did You Do This in C??
Well, to be honest...I just wanted to learn C, and this was a problem my girlfriend gave me to solve. I immediately knew it would require some data structures and basic string manipulation to do, which is a real annoying thing to work with in C (compared to other languages), so I knew it would be perfect for a first attempt into relearning C. The reason I used a Linked List instead of an Array List (or "*vector*" as it is known to be called in C/C++) is because it would require me to mess around with structs and pointers just a little more. I am fully aware that the performance is far worse (and my implemenation likely leaks memory like CRAZY thanks to having no dispose function), but it is more educational for me this time around, so yeah, you're gonna have to mad your libs with cache misses and memory leaks...deal with it.
