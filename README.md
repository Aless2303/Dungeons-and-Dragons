# Dungeons & Dragons - C++ OOP Implementation

## Project Overview

A comprehensive single-player Dungeons & Dragons game implementation demonstrating advanced object-oriented programming concepts through a text-based RPG with character creation, exploration, and combat mechanics.

## Core OOP Concepts Implementation

### 1. Interfaces & Abstract Classes

- **IRasa**: Pure virtual interface defining the contract for all race implementations
- **IClasa**: Interface ensuring all character classes implement required combat abilities  
- **IExceptie**: Custom exception handling interface for standardized error management
- **CARasa**: Abstract base class providing common race functionality
- **CAClasa**: Abstract base class for character class implementations

### 2. Inheritance Hierarchy

- **Multi-level inheritance**: IRasa → CARasa → (Orc, Elf, Human, Goblin)
- **Multi-level inheritance**: IClasa → CAClasa → (Fighter, Sorcerer, Warrior, Ninja)
- **Interface implementation**: All concrete classes implement pure virtual functions
- **Virtual destructors**: Ensures proper cleanup in polymorphic hierarchies

### 3. Design Patterns

#### **Singleton Pattern**
- **Dungeon_Master**: Ensures single game instance management
- **Private constructor**: Prevents external instantiation
- **Static instance management**: Thread-safe implementation with atexit cleanup

#### **Factory Pattern**
- **Factory_rasa**: Creates race objects based on string input
- **Factory_clasa**: Creates class objects dynamically
- **Encapsulated object creation**: Hides instantiation complexity from client code

#### **Strategy Pattern**
- **Skill implementations**: Each race/class provides unique ability strategies
- **Runtime behavior selection**: Polymorphic skill execution based on object type

### 4. Polymorphism Demonstrations

- **Virtual function overriding**: skill1() and skill2() in all derived classes
- **Dynamic binding**: Base pointers accessing derived implementations
- **Interface-based programming**: Code depends on abstractions, not concrete types
- **Runtime type resolution**: Combat system uses polymorphic ability calls

### 5. Encapsulation

- **Private data members**: All class attributes hidden from direct access
- **Public interfaces**: Controlled access through getters/setters
- **Data validation**: Attribute boundaries enforced (MIN_ATRIBUTE to MAX_ATRIBUTE)
- **Information hiding**: Internal implementation details protected from clients

### 6. Advanced C++ Features

#### **Operator Overloading**
- Output stream operator (<<) for enums: rasa_nume, clasa_nume, Trecut
- Enables intuitive enum printing without switch statements

#### **STL Container Usage**
- **std::vector**: Dynamic storage for room contents (books, portals, enemies)
- **std::string**: Modern string handling throughout
- **std::random_device & std::mt19937**: Modern C++ random number generation
- **std::uniform_int_distribution**: Proper dice roll implementation

#### **Modern C++ Practices**
- **auto keyword**: Type inference in iterator loops
- **Range-based for loops**: Clean iteration over containers
- **nullptr**: Type-safe null pointer constant
- **Default member initializers**: Cleaner constructor implementations

### 7. Composition & Aggregation

- **Composition**: Personaj owns Atribute (lifetime dependency)
- **Aggregation**: Personaj references IRasa* and IClasa* (independent lifetime)
- **Association**: Room contains collections of game objects
- **Dependency**: Combat system depends on dice roll mechanics

### 8. Memory Management

- **Dynamic allocation**: Factory patterns return heap-allocated objects
- **Manual memory management**: Proper delete in destructors
- **RAII principle**: Resource acquisition in constructors, release in destructors
- **Pointer ownership**: Clear ownership semantics for dynamically allocated objects

### 9. Exception Handling

- **Custom exception hierarchy**: IExceptie interface with Exceptie implementation
- **Meaningful error messages**: Context-specific error reporting
- **Exception safety**: Try-catch blocks at appropriate levels
- **Error propagation**: Exceptions thrown up the call stack when needed

### 10. File I/O Architecture

- **Modular file structure**: Separate files for each room component type
- **Data-driven design**: Game content loaded from external files
- **Extensibility**: New rooms/items added without code changes
- **Error handling**: Robust file reading with exception handling

## Architecture Components

### Core Systems
- **Dungeon_Master**: Central game controller managing state and flow
- **Room**: Container and manager for all interactable objects
- **Personaj**: Base character implementation with attribute management
- **Enemy**: AI-controlled characters with random ability selection

### Interaction System
- **Unified interaction interface**: All objects share common interaction patterns
- **Attribute-based challenges**: Different objects test different attributes
- **Dice roll mechanics**: D20 system with attribute modifiers
- **Success/failure consequences**: Dynamic attribute modification

### Combat System
- **Turn-based mechanics**: Player and enemy alternate actions
- **Polymorphic ability usage**: Runtime skill selection
- **HP management**: Constitution-based health scaling
- **Victory conditions**: Experience gain through constitution increase

## SOLID Principles Application

1. **Single Responsibility**: Each class has one clear purpose
2. **Open/Closed**: New races/classes added without modifying existing code
3. **Liskov Substitution**: Derived classes properly substitute base classes
4. **Interface Segregation**: Focused interfaces without unnecessary methods
5. **Dependency Inversion**: High-level modules depend on abstractions

## Key Achievements

- **64 unique character combinations**: Dynamic character creation system
- **Extensible architecture**: Easy addition of new content
- **Type safety**: Strong typing with proper abstractions
- **Code reusability**: Shared functionality in base classes
- **Maintainable codebase**: Clear separation of concerns
- **Professional error handling**: Robust exception management
- **Modern C++ usage**: Leveraging C++11/14 features appropriately

## Example:

![image](https://github.com/user-attachments/assets/227acfb8-cbfc-4523-a43b-0267f788bde6)
![image](https://github.com/user-attachments/assets/d88018bb-2b7a-42a3-916e-5cf1cb41d4d0)
![image](https://github.com/user-attachments/assets/a19235be-9261-43f0-bd96-3c916f2ab245)


