<a name="top"></a>

<div align="center">
  <img src="https://www.dieter-schwarz-stiftung.de/files/Projects/Project%20logos/Logo_42HN-min.jpg" alt="Logo"/>
</div>

<br>
<div align="center">

### 🛠 C++ (Object Oriented Programming)

</div>

<br>

- [CPP 00](#cpp-00-intro-to-c++): Intro to C++
- [CPP 01](#cpp-01-classes-&-instances): Classes & instances
- [CPP 02](#cpp-02): Operators' overload
- [CPP 03](#cpp-03): Inheritance
- [CPP 04](#cpp-04): Polymorphism & Interfaces
- [CPP 05](#cpp-05): Abstract Classes & Exceptions
- [CPP 06](#cpp-06): Casting
- [CPP 07](#cpp-07): Templates
- [CPP 08](#cpp-08): Containers & Algorithms
- [CPP 09](#cpp-09): Final Application

<br>

# CPP 00: Intro to C++

## ex00: Megaphone

Simple string capitalizing program. It capitalizes the string passed as parameter to the program. If no parameter is provided, it outputs a default message. Examples:

| Example                           | Output                                     |
|-----------------------------------|--------------------------------------------|
| `$ ./megaphone`                   | `$ * LOUD AND UNBEARABLE FEEDBACK NOISE *` |
| `$ ./megaphone "ssshh, be quiet!` | `$ SSSHH, BE QUIET!`                       |

<br>

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex01: Phonebook application

This exercise implements a simple phonebook application in C++, that allows users to store and retrieve contact information. The phonebook has a maximum capacity of 8 contacts. After reaching its full capacity, it then rewrites the oldest contact.<br>
The application is structured into two main classes:

**Contact Class**:<br>
	Represents a single contact in the phonebook.
	Stores details such as first name, last name, nickname, phone number, and a dark secret.

**Phonebook Class**:<br>
	Manages a collection of max 8 Contact objects.
	Provides functionality to add new contacts and search for existing ones.

<br>

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex02: Bank Account Management System

This program implements an **already developed** simple bank account management system, it provides functionality to manage multiple accounts, track deposits and withdrawals, and display account information.<br>

The purpose of the exercise is to create the body of several functions that are defined in the class per the subject, in order for the program's output to match the log file provided.

<br>

<p style="text-align: right;">
  <a href="#top">⬆️ Return to top</a>
</p>

<br>

# CPP 01: Classes & Instances

## ex00: Single Zombie Creation

This exercise implements a simple zombie simulation. It demonstrates the ability to create zombie objects, both from the stack and the heap memory.

<div align="center">
<img src="https://raw.githubusercontent.com/chrisov/CPP_Modules/58181ac91f9ebac2bb0820fd8ebcfa6533c7c5af/image.png" alt="alt text" width="400"/>
</div>

<br>

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex01: Zombie Horde Simulation

This exercise implements a zombie horde simulation. It demonstrates the ability of creating multiple zombie objects, as defined in [Single Zombie](#ex00-single-zombie-creation) exercise, dynamically.

<br>

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex02: Pointers vs References

This exercise's purpose is to make a clear difference of the functionality between a pointer and a reference in C++.

<br>

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>


## ex03: Weapon and Human Interaction Simulation

This exercise implements a simulation of humans interacting with weapons. It demonstrates the ability of composing objects of two different classed together.

**Weapon Class**:<br>
Represents a weapon of a specific type (e.g., "club", "sword").
Provides functionality to get and set the weapon's type dynamically.
The weapon's type can be changed dynamically, and the change is reflected in the attack messages of both HumanA and HumanB.


**HumanA Class**:<br>
Represents a human that always has a weapon.
The weapon is passed to the object at the time of construction.

**HumanB Class**:<br>
Represents a human that can optionally have a weapon.
The weapon can be assigned or changed dynamically after the human is created. The human can attack *only* if they have a weapon.

<br>

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex04: Sed is for Losers

This exercise implements a simple text replacing program, where it searches a .txt file for all occurences of a specified string, replaces them with another one and saves the result into a .txt.replace file:

```bash
$ ./sed text.txt search_string replace_string
```

| Arguments      | Description             |
|----------------|-------------------------|
| text.txt       | input file to search in |
| search_string  | string to search for    |
| replace_string | replacement string      |

Example:

```bash
$ cat text.txt
Hello there! Welcome to this simple text file.
This is just a test to see if your program can find certain words.
Sometimes, people say hello in different ways.
For example, "hello" can be written as hi, hey, or even hola!
However, not every sentence will contain the word hello.
Make sure your program can detect hello no matter where it appears.
At the end, we just say goodbye instead of hello.
```

```bash
$ ./sed text.txt hello hi
$ cat text.txt.replace
Hello there! Welcome to this simple text file.
This is just a test to see if your program can find certain words.
Sometimes, people say hi in different ways.
For example, "hi" can be written as hi, hey, or even hola!
However, not every sentence will contain the word hi.
Make sure your program can detect hi no matter where it appears.
At the end, we just say goodbye instead of hi.
```

<br>

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex05: Harl's Complaints

This exercise implements a simple program that simulates a character named "Harl" expressing complaints at different levels of severity.

The `Harl` class encapsulates the behavior of the character "Harl".
   - It contains four complaint levels:
     - `DEBUG`: Detailed debugging information.
     - `INFO`: General information about the program's state.
     - `WARNING`: A warning about potential issues.
     - `ERROR`: A critical error that requires immediate attention.
   - Each complaint level is implemented as a private method in the `Harl` class.

<br>

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex06: Harl's Complaints Filter

Similar to [Harl's Complaints](#ex05-harls-complaints), this exercise simulates a program that outputs all message up to the provided level of severity. So, if the *WARNING* is provided, it will output the *DEBUG* message, the *INFO* message and the *WARNING* message.

<br>

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>


# CPP 02: Operators' overload

## ex00: Fixed numbers

This exercise demonstrates the creation of a Fixed numbers class, 

<br>

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>
