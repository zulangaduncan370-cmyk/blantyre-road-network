# Blantyre Road Network — Dijkstra's Algorithm

An interactive browser-based shortest-route finder for a model weighted, undirected graph of 20 selected Blantyre locations. Distances are assignment graph weights in kilometres, not live navigation distances.

## Live application
https://zulangaduncan370-cmyk.github.io/blantyre-road-network/

## Run locally
Open `index.html` in a modern web browser. Select a source and destination and choose **Find Shortest Path**. No installation is required.

## Algorithms
The web application uses Dijkstra's algorithm to find a shortest path on the graph. The C++ implementation is provided in `main.cpp` in the repository. The corrected graph contains 20 vertices and 27 undirected weighted edges.

## Example
Source: 1 (Limbe Market)  
Destination: 20 (St. Montfort Catholic Parish)  
Shortest distance: **7.30 km**  
Route: **1 → 2 → 3 → 8 → 20**

## Technologies
HTML, CSS, JavaScript, C++ and GitHub Pages.


The interactive graph layout follows the node arrangement in the supplied reference drawing. The same weighted edges power both the drawing and Dijkstra route calculations.
