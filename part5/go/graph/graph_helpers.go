package main;

type Graph struct {
	totalVertices int;
	graphMap map[rune][]OutNeighbor;
}

type OutNeighbor struct {
	vertice rune;
	weight int;
}
