# Mini STL

A custom implementation of core C++ STL components built from scratch to understand the internal design of containers, iterators, and data structures.

Implemented using modern C++ with templates, generic programming, and manual memory management.

---

## Implemented Components

### Containers
- **Vector** - Dynamic array with resizing, reserve, copy/move semantics, and iterators.
- **Pair** - Generic key-value structure similar to `std::pair`.
- **Linked List** - Doubly linked list with insertion, deletion, and traversal.
- **Stack** - LIFO container adapter.
- **Queue** - FIFO container adapter.
- **Map** - Ordered key-value container built on a Red-Black Tree.
- **Set** - Ordered unique container built on a Red-Black Tree.

### Trees
- **Binary Search Tree**
  - Insert, search, delete
  - Custom comparators
  - Deep copy support
  - Iterator traversal

- **Red-Black Tree**
  - Left/right rotations
  - Insert balancing
  - Delete balancing
  - O(log n) search, insertion, and deletion

### Iterators
Custom STL-style iterators supporting:

- Dereference (`*`)
- Member access (`->`)
- Prefix/postfix increment
- Prefix/postfix decrement
- Iterator comparison
- Ordered traversal

---

## Design Highlights

- Fully template-based generic containers
- Manual memory management
- Copy and move semantics
- Custom comparators
- STL-inspired API design
- Modular header-only architecture

---

## Project Structure
Mini-STL
│
├── include/
│ ├── vector.h
│ ├── list.h
│ ├── stack.h
│ ├── queue.h
│ ├── bst.h
│ ├── rbtree.h
│ ├── map.h
│ └── set.h
│
└── test/
└── component tests


---

## Technologies

- C++
- Templates
- Data Structures
- Object-Oriented Programming
- Memory Management

---

## Purpose

This project recreates the core ideas behind the C++ STL while developing a deeper understanding of data structures, iterators, and library design.