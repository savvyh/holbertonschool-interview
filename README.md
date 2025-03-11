# ALGORITHMS

## First project SANDPILES
#### What is sandpiles ? 
A sandpile is a mathematical model that simulates the behavior and stability of sand piles. In this model, each cell of a grid contains a certain number of "grains". When a cell contains more than 3 grains, it becomes unstable and "topples", distributing its grains to neighboring cells.

The stabilization process of a sandpile follows these rules:
- If a cell has 4 or more grains, it is unstable
- An unstable cell distributes 4 of its grains to adjacent cells (top, bottom, left, right)
- This process continues until all cells are stable (3 grains or less)

This concept has applications in various fields such as:
- Physics of complex systems
- Study of avalanches and critical phenomena
- Graph theory and linear algebra

The project implements the addition of two stable sandpiles and the resulting stabilization process.
