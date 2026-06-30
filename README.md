# Implementation of Dijkstra's Algorithm using Object-Oriented Programming in C++

This project presents an object-oriented implementation of Dijkstra's Shortest Path Algorithm in C++. The program computes the shortest path from a source node to all other nodes in a weighted graph with non-negative edge weights.

The implementation was developed as part of an Object-Oriented Programming coursework exercise and demonstrates the practical application of graph theory, shortest-path routing, inheritance, polymorphism, exception handling, and class-based software design.

---

## Project Objectives

- Implement Dijkstra's Shortest Path Algorithm
- Apply Object-Oriented Programming concepts in a real problem
- Demonstrate graph traversal and path optimization
- Develop a modular and reusable software structure

---

## Overview

Dijkstra's Algorithm is one of the most widely used graph traversal algorithms for determining the shortest path between nodes in a weighted graph.

This project allows users to:

- Create a custom graph through console input
- Define nodes and weighted edges
- Calculate shortest paths from a source node
- Display optimal routes and corresponding distances
- Handle invalid graph inputs through exception handling

---

## Features

- Object-Oriented C++ implementation
- Graph representation using adjacency matrix
- Shortest path computation using Dijkstra's Algorithm
- Inheritance and Function Overriding
- Exception Handling
- Dynamic graph creation through user input
- Console-based execution

---

## OOP Concepts Demonstrated

The primary focus of this project was the implementation of Dijkstra's Algorithm using Object-Oriented Programming principles.

## Classes and Objects

Two separate classes were designed:

### BaseGraph

Responsible for:

- Graph creation
- Storage of edge weights
- Basic graph operations

### DijkstraGraph

Derived from `BaseGraph` and responsible for:

- Shortest path calculations
- Distance tracking
- Parent node tracking
- Path reconstruction

This separation improves code organization and maintainability.

---

## Encapsulation

Graph data is protected within classes using access specifiers.

```cpp
protected:
    int numNodes;
    int graph[MAX_NODES][MAX_NODES];
```

and

```cpp
private:
    int distance[MAX_NODES];
    bool visited[MAX_NODES];
    int parent[MAX_NODES];
```

Internal data structures cannot be directly modified from outside the class.

---

## Inheritance

The project uses single inheritance.

```cpp
class DijkstraGraph : public BaseGraph
```

The derived class reuses graph functionality from the base class while extending it with Dijkstra-specific operations.

Benefits:

- Code reuse
- Reduced redundancy
- Better organization

---

## Polymorphism (Function Overriding)

The `addEdge()` function is overridden in the derived class.

### Base Class

```cpp
virtual void addEdge(int u, int v, int weight)
```

### Derived Class

```cpp
void addEdge(int u, int v, int weight) override
```

The derived implementation introduces validation for edge weights before adding them to the graph.

This demonstrates runtime polymorphism and specialization of behavior.

---

## Constructors

Constructors are used to initialize graph data structures.

### BaseGraph Constructor

```cpp
BaseGraph(int n)
```

Initializes:

- Number of nodes
- Adjacency matrix

### DijkstraGraph Constructor

```cpp
DijkstraGraph(int n)
```

Initializes:

- Distance array
- Visited array
- Parent array

This ensures all structures are correctly prepared before execution.

---

## Destructors

Both classes contain destructors.

```cpp
virtual ~BaseGraph()
```

```cpp
~DijkstraGraph() override
```

Although no dynamic memory allocation is used in this implementation, destructors were included to demonstrate proper OOP design practices.

---

## Exception Handling

Exception handling was implemented to improve program reliability.

### Invalid Node Input

```cpp
throw out_of_range(...)
```

### Invalid Edge Weight

```cpp
throw invalid_argument(...)
```

### Error Handling

```cpp
try
{
    ...
}
catch(const exception& e)
{
    ...
}
```

This prevents program crashes caused by incorrect user input.

---

## Class Structure

### BaseGraph

Responsible for:

- Graph creation
- Edge storage
- Basic graph operations

### DijkstraGraph

Extends the base graph and provides:

- Shortest path calculation
- Distance tracking
- Path reconstruction
- Output generation

---

## Algorithm Workflow

1. Initialize all node distances to infinity.
2. Set source node distance to zero.
3. Select the nearest unvisited node.
4. Update distances of neighboring nodes.
5. Repeat until all nodes are processed.
6. Display shortest paths and distances.

---

## Example Graph

A ----(5)---> B ----(5)---> D ----(2)---> E
 \                           ^          ^
  \                         /          /
   \                       /          /
   (3)                   (4)        (6)
     \                   /          /
      \                 /          /
       \               /          /
        \             /          /
         \           /          /
          \         /          /
           \       /          /
            \     /          /
             \   /          /
              \ /          /
               C ---------

## Sample Input

```text
Nodes = 5

A -> B (5)
A -> C (3)

B -> D (5)

C -> D (4)
C -> E (6)

D -> E (2)
```

---

## Example Output

```text
Shortest path from A to B: A B
Distance: 5

Shortest path from A to C: A C
Distance: 3

Shortest path from A to D: A C D
Distance: 7

Shortest path from A to E: A C E
Distance: 9
```

---

## Execution

The program accepts:

- Number of nodes
- Number of edges
- Destination nodes
- Edge weights

and computes the shortest path tree from node A.

### Sample Execution

![Execution Result](images/execution_result.png)

---

## Technologies Used

- C++
- Object-Oriented Programming
- Graph Theory
- Code::Blocks IDE

---

## Applications

- Network Routing
- GPS Navigation Systems
- Path Planning
- Transportation Networks
- Communication Networks

---

## References

- Dijkstra's Algorithm Documentation
- GeeksforGeeks
- Wikipedia
- Javatpoint

---

## Author

**Kamalaksh Dessai**
Bachelor of Engineering  
Automation and Robotics Engineering  
KLE Technological University

---

## License

This project is shared for educational and academic purposes.