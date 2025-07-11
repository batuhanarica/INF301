# INF301 - Programming Projects Collection

**Author:** Batuhan ARICA  
**Course:** INF301 - Algorithms and Data Structures  
**Institution:** Université Grenoble Alpes (UGA)  
**Semester:** L2 S3 (2024-2025)

---

## 📋 Table of Contents

- [Overview](#overview)
- [APP1 - Caesar Cipher Implementation](#app1---caesar-cipher-implementation)
- [APP2 - Curiosity Mars Rover Simulator](#app2---curiosity-mars-rover-simulator)
- [APP3 - Phylogenetic Trees](#app3---phylogenetic-trees)
- [Installation & Usage](#installation--usage)
- [Technologies Used](#technologies-used)
- [Project Structure](#project-structure)

---

## 🎯 Overview

This repository contains three major programming projects developed during the INF301 course, focusing on different algorithmic concepts and data structures:

1. **APP1**: Caesar Cipher encryption/decryption algorithm
2. **APP2**: Mars rover navigation simulation with path planning
3. **APP3**: Phylogenetic tree manipulation and species classification

Each project demonstrates specific programming concepts including string manipulation, graph algorithms, tree structures, and recursive algorithms.

---

## 🔐 APP1 - Caesar Cipher Implementation

### 🎯 Purpose
Implementation of the classic Caesar cipher algorithm for encrypting and decrypting text by shifting letters in the alphabet.

### 🧠 Algorithm Logic
The Caesar cipher works by shifting each letter in the text by a fixed number of positions in the alphabet:

```
Original:  A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
Shift +3:  D E F G H I J K L M N O P Q R S T U V W X Y Z A B C
```

### 🔧 Key Features
- **Character Processing**: Handles both uppercase and lowercase letters
- **Wraparound Logic**: When shifting goes beyond 'Z' or 'z', it wraps around to 'A' or 'a'
- **Non-alphabetic Preservation**: Numbers, spaces, and punctuation remain unchanged
- **Configurable Shift**: The shift amount can be modified (default: 3)

### 📊 Algorithm Complexity
- **Time Complexity**: O(n) where n is the length of the input string
- **Space Complexity**: O(1) for the transformation function

### 🚀 Usage
```bash
cd APP1
gcc -o caesar main.c
./caesar
# Enter a letter when prompted
```

### 📁 Files Structure
```
APP1/
├── App1.c                          # Initial implementation attempt
├── main.c                          # Working Caesar cipher implementation
├── APP1-chiffre.pdf               # Project specifications
├── APP1_Completed.zip             # Completed project archive
└── Exercice préparatoire/         # Preparatory exercises
```

---

## 🤖 APP2 - Curiosity Mars Rover Simulator

### 🎯 Purpose
Simulation of NASA's Curiosity rover navigating on Mars terrain, implementing pathfinding algorithms and stack-based command interpretation.

### 🧠 Algorithm Logic

#### 1. **Map Representation**
- **2D Grid System**: Mars surface represented as a character matrix
- **Terrain Types**:
  - `.` Plain terrain (navigable)
  - `#` Rocks (obstacles)
  - `~` Water (obstacles)
  - `M` Marks to collect
  - `@` Target destination
  - `C` Curiosity's starting position

#### 2. **Navigation Algorithm**
- **Position Tracking**: (x, y) coordinates with direction vector (dx, dy)
- **Movement Commands**:
  - `avancer`: Move forward in current direction
  - `gauche`/`droite`: Rotate 90° left/right
  - `marquer`: Place a mark at current position

#### 3. **Command Interpretation**
- **Stack-based Processing**: Uses LIFO structure for command execution
- **Sequence Management**: Commands organized in sequences for complex operations
- **Loop Support**: Implements repeat structures for efficient programming

#### 4. **Pathfinding Strategy**
- **Obstacle Avoidance**: Detects and navigates around rocks and water
- **Goal-oriented Movement**: Targets marks and final destination
- **Backtracking**: Returns to previous positions when needed

### 🔧 Key Features
- **Real-time Visualization**: Optional ncurses display of rover movement
- **Multiple Test Cases**: Supports different Mars terrain configurations
- **Performance Monitoring**: Tracks execution time and efficiency
- **Debug Mode**: Detailed output for algorithm analysis

### 📊 Algorithm Complexity
- **Map Loading**: O(n×m) where n,m are map dimensions
- **Pathfinding**: O(n×m) in worst case for complete map traversal
- **Command Execution**: O(k) where k is number of commands

### 🚀 Usage
```bash
cd APP2
make
./main [-d] [-carte <n>] <test_file>
# -d: debug mode
# -carte <n>: run specific test case
```

### 📁 Files Structure
```
APP2/
├── main.c                 # Main program and test launcher
├── curiosity.c/.h         # Rover logic and map management
├── interprete.c/.h        # Command interpretation engine
├── listes.c/.h           # Linked list implementation
├── type_pile.c/.h        # Stack data structure
├── Makefile              # Build configuration
└── APP2-curiosity.pdf    # Project documentation
```

---

## 🌳 APP3 - Phylogenetic Trees

### 🎯 Purpose
Implementation of phylogenetic tree data structures for biological species classification, featuring tree traversal, species search, and evolutionary relationship analysis.

### 🧠 Algorithm Logic

#### 1. **Tree Structure**
- **Binary Tree Representation**: Each node represents either a species (leaf) or a characteristic (internal node)
- **Recursive Definition**: Trees are built recursively with left and right subtrees
- **Node Types**:
  - **Leaf Nodes**: Represent individual species
  - **Internal Nodes**: Represent shared characteristics

#### 2. **Tree Construction**
- **File-based Loading**: Reads tree structure from formatted text files
- **Recursive Parsing**: Builds tree structure through recursive function calls
- **Memory Management**: Dynamic allocation for nodes and string values

#### 3. **Search Algorithms**
- **Species Count**: Recursive traversal to count leaf nodes
- **Characteristic Analysis**: Identifies internal nodes representing traits
- **Species Search**: Locates specific species within the tree structure
- **Path Finding**: Determines evolutionary relationships between species

#### 4. **Tree Manipulation**
- **Species Addition**: Inserts new species at appropriate tree positions
- **Characteristic Insertion**: Adds new evolutionary traits to existing trees
- **Tree Restructuring**: Modifies tree topology while preserving relationships

### 🔧 Key Features

#### **Acte I - Basic Operations**
- Count total number of species in a phylogenetic tree
- Count characteristics (internal nodes)
- Tree structure validation

#### **Acte II - Species Search**
- Search for specific species within the tree
- Return evolutionary path to species
- Handle multiple species with same name

#### **Acte III - Advanced Search**
- Find species possessing specific characteristics
- Analyze evolutionary relationships
- Generate species lists based on traits

#### **Acte IV - Tree Modification**
- Add new species to existing trees
- Insert characteristics at appropriate positions
- Maintain tree integrity during modifications

### 📊 Algorithm Complexity
- **Tree Traversal**: O(n) where n is number of nodes
- **Species Search**: O(h) where h is tree height (average case)
- **Tree Construction**: O(n) for reading and building
- **Species Addition**: O(h) for finding insertion point

### 🚀 Usage
```bash
cd App3/App3
make
./main [-d] <tree_file>
# -d: debug mode with detailed output
```

### 📁 Files Structure
```
App3/App3/
├── main.c                 # Main program and user interface
├── arbres.c/.h           # Basic tree operations
├── arbresphylo.c/.h      # Phylogenetic-specific functions
├── listes.c/.h           # Supporting list structures
├── common_tests.c/.h     # Testing framework
├── tests/                # Test cases for validation
├── tests_acte1/          # Acte I specific tests
├── tests_acte2/          # Acte II specific tests
├── tests_acte3/          # Acte III specific tests
├── tests_acte4/          # Acte IV specific tests
├── Makefile              # Build configuration
└── LISEZMOI.txt          # Detailed project instructions
```

---

## 🛠️ Installation & Usage

### Prerequisites
- **C Compiler**: GCC recommended
- **Make**: For building projects
- **ncurses** (optional): For APP2 visualization

### General Build Instructions
```bash
# Clone the repository
git clone https://github.com/batuhanarica/INF301.git
cd INF301

# Build individual projects
cd APP1 && gcc -o caesar main.c
cd APP2 && make
cd App3/App3 && make
```

### Running Tests
```bash
# APP2 test execution
cd APP2
./main tests/test_file.test

# APP3 test execution
cd App3/App3
./main tests/amphibians.test
```

---

## 💻 Technologies Used

- **Programming Language**: C
- **Build System**: Make
- **Libraries**: 
  - Standard C Library (stdio.h, stdlib.h, string.h)
  - ncurses (optional, for APP2 visualization)
- **Development Tools**: GCC, Debugger support
- **Version Control**: Git

---

## 📂 Project Structure

```
INF301/
│
├── APP1/                          # Caesar Cipher Implementation
│   ├── App1.c                     # Initial implementation
│   ├── main.c                     # Working implementation
│   ├── APP1-chiffre.pdf          # Project documentation
│   └── Exercice préparatoire/     # Practice exercises
│
├── APP2/                          # Curiosity Mars Rover
│   ├── *.c, *.h                  # Source and header files
│   ├── Makefile                   # Build configuration
│   └── APP2-curiosity.pdf        # Project documentation
│
├── App3/                          # Phylogenetic Trees
│   ├── App3/                     # Main implementation
│   │   ├── *.c, *.h              # Source and header files
│   │   ├── tests/                # Test cases
│   │   └── Makefile              # Build configuration
│   └── App3_final.tar.gz         # Final submission archive
│
├── AppoLab/                       # Laboratory exercises
├── pointers.pdf                   # Pointer tutorial
└── README.md                      # This file
```

---

## 🏆 Learning Outcomes

Through these projects, key programming concepts were mastered:

### **Data Structures**
- **Arrays**: 2D grids for map representation
- **Linked Lists**: Dynamic sequences and command storage
- **Stacks**: LIFO command processing
- **Binary Trees**: Hierarchical species organization

### **Algorithms**
- **String Manipulation**: Character transformation and processing
- **Graph Traversal**: Pathfinding and navigation
- **Tree Algorithms**: Recursive traversal and manipulation
- **Search Algorithms**: Linear and tree-based searching

### **Programming Techniques**
- **Recursive Programming**: Tree construction and traversal
- **Memory Management**: Dynamic allocation and deallocation
- **File I/O**: Reading structured data from files
- **Modular Programming**: Header files and code organization

---

## 📝 Notes

- All projects include comprehensive test suites
- Code follows academic standards with proper documentation
- Each project builds upon previous algorithmic concepts
- Performance considerations included in implementation

---

**Repository:** [https://github.com/batuhanarica/INF301](https://github.com/batuhanarica/INF301)

---
