<a name="top"></a>

<div align="center">
  <img src="https://www.dieter-schwarz-stiftung.de/files/Projects/Project%20logos/Logo_42HN-min.jpg" alt="Logo"/>
</div>

<br>
<div align="center">

### 🛠 C++ (Object Oriented Programming)

</div>

<br>

- [CPP 00](#cpp-00-intro-to-c): Intro to C++
- [CPP 01](#cpp-01-classes-instances): Classes & instances
- [CPP 02](#cpp-02): Operators' overload
- [CPP 03](#cpp-03): Inheritance
- [CPP 04](#cpp-04): Polymorphism & Interfaces
- [CPP 05](#cpp-05): Abstract Classes & Exceptions
- [CPP 06](#cpp-06): Casting
- [CPP 07](#cpp-07): Templates
- [CPP 08](#cpp-08): Containers & Algorithms
- [CPP 09](#cpp-09): Final Application

<br>

# CPP 00: Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuf

## ex00: Megaphone

Simple string capitalizing program. It capitalizes the string passed as parameter to the program. If no parameter is provided, it outputs a default message. Examples:

| Example                           | Output                                     |
|-----------------------------------|--------------------------------------------|
| `$ ./megaphone`                   | `$ * LOUD AND UNBEARABLE FEEDBACK NOISE *` |
| `$ ./megaphone "ssshh, be quiet!` | `$ SSSHH, BE QUIET!`                       |

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex01: My Awesome PhoneBook

This exercise implements a simple phonebook application in C++, that allows users to store and retrieve contact information. The phonebook has a maximum capacity of 8 contacts. After reaching its full capacity, it then rewrites the oldest contact.<br>
The application is structured into two main classes:

**Contact Class**:<br>
	Represents a single contact in the phonebook.
	Stores details such as first name, last name, nickname, phone number, and a dark secret.

**Phonebook Class**:<br>
	Manages a collection of max 8 Contact objects.
	Provides functionality to add new contacts and search for existing ones.

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex02: The Job Of Your Dreams

This program implements an **already developed** simple bank account management system, it provides functionality to manage multiple accounts, track deposits and withdrawals, and display account information.<br>

The purpose of the exercise is to create the body of several functions that are defined in the class per the subject, in order for the program's output to match the log file provided.

<p style="text-align: right;">
  <a href="#top">⬆️ Return to top</a>
</p>

<br>

# CPP 01: Memory allocation, pointers to members, references and switch statements

## ex00: BraiiiiiiinnnzzzZ

This exercise implements a simple zombie simulation. It demonstrates the ability to create zombie objects, both from the stack and the heap memory.

<div align="center">
<img src="https://raw.githubusercontent.com/chrisov/CPP_Modules/58181ac91f9ebac2bb0820fd8ebcfa6533c7c5af/image.png" alt="alt text" width="400"/>
</div>

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex01: Moar brainz!

This exercise implements a zombie horde simulation. It demonstrates the ability of creating multiple zombie objects, as defined in [BraiiiiiiinnnzzzZ](#ex00-single-zombie-creation) exercise, dynamically.

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex02: HI THIS IS BRAIN

This exercise's purpose is to make a clear difference of the functionality between a pointer and a reference in C++, by printing both the address and the value of both a reference and a pointer to an original variable.

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>


## ex03: Unnecessary violence

This exercise implements a simulation of humans interacting with weapons. It demonstrates the ability of composing objects of two different classes together.

**HumanA Class**:<br>
Represents a human that always has a weapon.
The weapon is passed to the object at the time of construction.

**HumanB Class**:<br>
Represents a human that can optionally have a weapon.
The weapon can be assigned or changed dynamically after the human is created. The human can attack *only* if they have a weapon.

**Weapon Class**:<br>
Represents a weapon of a specific type (e.g. "club", "sword", etc).
Provides functionality to get and set the weapon's type dynamically.
The weapon's type can be changed dynamically, and the change is reflected in the attack messages of both HumanA and HumanB.

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex04: Sed is for Losers

This exercise implements a simple text replacing program, where it searches a .txt file for all occurences of a specified string, replaces them with another one and saves the result into a .txt.replace file:

```bash
$ ./sed text.txt search_string replace_string
```

| Parameters     | Description             |
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

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex05: Harl 2.0

This exercise implements a simple program that simulates a character named "Harl" expressing complaints at different levels of severity.

The `Harl` class encapsulates the behavior of the character "Harl".
   - It contains four complaint levels:
     - `DEBUG`: Detailed debugging information.
     - `INFO`: General information about the program's state.
     - `WARNING`: A warning about potential issues.
     - `ERROR`: A critical error that requires immediate attention.
   - Each complaint level is implemented as a private method in the `Harl` class.

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex06: Harl Filter

Similar to [Harl 2.0](#ex05-harls-complaints), this exercise simulates a program that outputs all message up to the provided level of severity. So, if the *WARNING* is provided, it will output the *DEBUG* message, the *INFO* message and the *WARNING* message.

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>


# CPP 02: Ad-hoc polymorphism, operator overloading and the Orthodox Canonical class form

This project demonstrates the creation of a Fixed point numbers class. It is overloading the basic mathematical operators (+, -, *, /), so that it will be able to function as a custom numeric type of variable.

A Fixed point type of number is a way of representing real numbers (numbers with fractional parts) using integers, while keeping the decimal point in a fixed position.

Our Fixed point numbers class will hold 8 bits of decimal places. This means that the true value of the number will be mulitplied by 2^8 = 256 before stored in the corresponding class's attribute.

**NOTE**: Every exercise builds on top of the previous one

<br>

## ex00: My First Class in Orthodox Canonical Form

This exercise demonstarates the creation of **0** as a Fixed point number. 

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex01: Towards a more useful fixed-point number class

This exercise extends the Fixed class's functionality, by adding parameterized constructors and supporting convertion of a Fixed point type to classic numberical types (int, float).

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex02: Now we’re talking

This exercise demonstrates the overloading functionality of most mathematical operators (+, -, *, /), as well as the creation of a min/max function.

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex03: BSP

This exercise demonstrates the *point-in-triangle* functionality of the program, using the BSP method *(Barycentric Subdivion Procedure*). It is a way of locating a Point inside (or around) a triangle using weights relative to the triangle's vertices. If all weights are non-negative and sum to 1, then the Point in question belongs to the triangle. If any of those weights are negative, the Point is outside.
 
**NOTE**: In this implementation, if the Point is located *on* any of the triangle's vertices, it is considered to be *outside* the triangle.

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

# CPP 03: Inheritance

This projects demonstrates the functionality of the inheritance property in Object Orienting C++, where a class can be derived as a child class of a parent one, inheriting its functions. In this project, there are different types of robot classes, others functioning as parents, others as children inheriting different type of functions as the project progresses.

Every robot class is described by the same private attributes, but of different values, as seen in the corresponding exercises, as well as a special function.

Every main function is showcasing the robots interacting with each other.

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex00: Aaaaand... OPEN!

**ClapTrap** will be used as the parent class  in the following exercises, inheriting its functions.

<div align="center">
<img src="https://raw.githubusercontent.com/chrisov/CPP_Modules/8c925b57761c9026ae9f233a6f5a78a057d9882c/claptrap.png" alt="ClapTrap"/>
</div>

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex01: Serena, my love!

**ScavTrap** is the first child class derived from ClapTrap, inheriting its functions.

<div align="center">
<img src="https://raw.githubusercontent.com/chrisov/CPP_Modules/8c925b57761c9026ae9f233a6f5a78a057d9882c/scavtrap.png" alt="ScavTrap"/>
</div>

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

# ex02: Repetitive work

**FragTrap** is the another child class derived from ClapTrap, ihneriting its function and also having a special function, unique to the class.

<div align="center">
<img src="https://raw.githubusercontent.com/chrisov/CPP_Modules/8c925b57761c9026ae9f233a6f5a78a057d9882c/fragtrap.png" alt="FragTrap"/>
</div>

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

# ex03: Now it’s weird!

**DiamondTrap** is the last child class derived from ClapTrap's children ScavTrap and FragTrap, creating a so called Diamond class. The DiamondTrap inherits different attributes from both parents and has a special function, unique to the class.

<div align="center">
<img src="https://raw.githubusercontent.com/chrisov/CPP_Modules/8c925b57761c9026ae9f233a6f5a78a057d9882c/diamondtrap.png" alt="DiamondTrap"/>
</div>

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

# CPP 04: Subtype Polymorphism, Abstract Classes, and Interfaces

## ex00: Polymorphism

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex01: I don’t want to set the world on fire

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex02: Abstract class

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>

## ex03: Interface & recap

<div align="right">
  <a href="#top">⬆️ Return to top</a>
</div>

<br>
