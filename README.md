<div align="center">
  <img src="https://www.dieter-schwarz-stiftung.de/files/Projects/Project%20logos/Logo_42HN-min.jpg" alt="Logo"/>
</div>

<br>
<div align="center">

### 🛠 C++ (Programming Language)

</div>

<br>

# CPP 00

## ex00: Megaphone

Simple string capitalizing program.

## ex01: Phonebook Application

This exercise implements a simple phonebook application in C++ that allows users to store and retrieve contact information. The application is structured into two main classes:

Contact Class:<br>
	Represents a single contact in the phonebook.
	Stores details such as first name, last name, nickname, phone number, and a dark secret.

Phonebook Class:<br>
	Manages a collection of Contact objects.
	Provides functionality to add new contacts and search for existing ones.

## ex02: Bank Account Management System

This exercise implements a simple bank account management system, it provides functionality to manage multiple accounts, track deposits and withdrawals, and display account information.

<br>

# CPP 01

## ex00: Single Zombie Creation

This exercise implements a simple zombie simulation in C++. It demonstrates the creation and management of zombie objects, showcasing object-oriented programming principles such as encapsulation and dynamic memory allocation.

## ex01: Zombie Horde Simulation

This exercise implements a zombie horde simulation in C++. It demonstrates the creation of multiple zombie objects dynamically and their management using object-oriented programming principles.

## ex02: Pointers vs References

This exercise's purpose is to make a clear difference of the functionality between a pointer and a reference in C++.

## ex03: Weapon and Human Interaction Simulation

This exercise implements a simulation of humans interacting with weapons in C++. It demonstrates object-oriented programming principles such as encapsulation, composition, and dynamic behavior through the use of classes and objects.

Weapon Class:<br>
Represents a weapon with a type (e.g., "club", "sword").
Provides functionality to get and set the weapon's type dynamically.

HumanA Class:<br>
Represents a human that always has a weapon.
The weapon is passed to the human at the time of construction.
The human can attack using the weapon, and the attack message includes the weapon's type.

HumanB Class:<br>
Represents a human that can optionally have a weapon.
The weapon can be assigned or changed dynamically after the human is created. The human can attack only if they have a weapon.

Dynamic Behavior:<br>
The weapon's type can be changed dynamically, and the change is reflected in the attack messages of both HumanA and HumanB.

Encapsulation and Composition:<br>
The project demonstrates encapsulation by keeping class members private and exposing functionality through public methods.
Composition is used to associate humans with weapons.