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

## Second project 2048 (single line)
#### 2048 game

2048 is a popular sliding puzzle game where players combine numbered tiles on a grid by sliding them in different directions. The goal is to create a tile with the number 2048. When two tiles with the same number collide during a slide, they merge into a single tile with their sum. The game continues until either:

- The player creates a tile with 2048 (victory)
- The grid fills up with no possible moves left (game over)

In this version, we focus on implementing the sliding and merging mechanics for a single line, which is a fundamental part of the full 2048 game logic.
