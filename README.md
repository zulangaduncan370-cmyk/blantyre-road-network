# Blantyre Road Network — Dijkstra's Algorithm

## Project Overview

This project implements Dijkstra's shortest-path algorithm on an undirected, weighted road network based on selected locations in Blantyre, Malawi. The network contains 20 locations and 26 weighted edges, with distances represented in kilometres.

The project includes a C++ implementation and an interactive browser-based application.

## Live Application

Try the application online: 
https://zulangaduncan370-cmyk.github.io/blantyre-road-network/

The application allows users to select a starting location and a destination, calculate the shortest route, view the total distance, and identify the route through the network.

## Project Files

- `main.cpp` - C++ implementation of Dijkstra's algorithm.
- `index.html` - Interactive web application built with HTML, CSS, and JavaScript.
- `README.md` - Project documentation and instructions.

## How to Use the Web Application

1. Open the [live application](https://zulangaduncan370-cmyk.github.io/blantyre-road-network/).
2. Select a starting location.
3. Select a destination.
4. Run the shortest-path calculation.
5. Review the shortest distance and route displayed by the application.

## Running the C++ Implementation

The C++ source code is provided in `main.cpp`.

To run it locally:

1. Install a C++ compiler or an IDE such as Dev-C++.
2. Open `main.cpp` in the IDE.
3. Compile the source code.
4. Run the compiled program and review the calculated shortest route.

## Algorithm

Dijkstra's algorithm calculates the shortest paths in a graph with non-negative edge weights. In this project, the edge weights represent road distances in kilometres.

The graph is represented using an adjacency list, and the algorithm maintains tentative distances and predecessor information to determine the shortest route.

## Example Result

For the route from **Limbe Market (Vertex 1)** to **St. Montfort Catholic Parish (Vertex 20)**, the expected result is:

- Shortest distance: 6.40 km
- Route: Limbe Market → NACIT → Chichiri Mall → St. Montfort Catholic Parish
- Vertex sequence: 1 → 2 → 3 → 20

## Technologies Used

- C++
- HTML
- CSS
- JavaScript
- GitHub
- GitHub Pages

## Purpose

The project demonstrates graph representation, shortest-path computation, algorithm implementation, testing, and deployment through an accessible web application.
