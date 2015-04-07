#C8 Interpreter
Timeline:  November 2012

An interpreter for a simple imperative programming language for instructional purposes.

Overview
--------

In theory of computation, two core subjects are finite state machines and context-free grammars.  The main applications of these two topics in day-to-day life are for programming language definition.  A useful way then to master such subjects is to apply them to a language.

For my theory course in Fall 2012, the instructors prepared a simple toy language called C7.  The language included common features of imperative languages:  conditionals, loops, variables, scoping, function definitions, and recursion.  The task then was to build an interpreter for the language.  The translation half of a compiler (producing assembly) was beyond the scope of the course.

As a young graduate student I gleefully completed the assignment.  I put together a nice, clean implementation of the Interpreter pattern from the Gang of Four book, made sure to use Flex and Bison properly, and even built a full set of test cases.  The test cases proved valuable when I was developing new features, both to make sure I had implemented the new features correctly, and had not damaged previous features in the process.

After the course was finished I was still on a buzz of optimism and youthful energy.  I decided I would expand my project to include other common features of programming languages such as classes and templates.  I decided I would make the 'C8' language, a step up from the C7 language of the course.  This would be my 'perfect' language interpreter, developed with every design principle out there in mind.

In the end, the C8 project did not flourish.  I began research work at the end of the semester of the theory course, and went heavy into it the following semester.  The project was left to the side, as it was more of a fun exercise than it was useful towards academia at large.  I may return to it one day for fun.  For now though, as with many other projects, it will sit here, showing what I have learned.