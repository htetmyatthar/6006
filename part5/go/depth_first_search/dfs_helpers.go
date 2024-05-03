package main

// NOTE: iterating through a built in map of golang is non-deterministic in order.
// meaning the order giving back from the map is not the same for every time a function
// call is being ran.

// Dfs is the depth_first_search algorithm for finding the connected components
// of the startVertex returning the parent vertices map. Returns an error if there's any.
func (G *Graph) Dfs(startVertex rune) (map[rune]rune, error) {
	if G == nil {
		return nil, ErrGraphNil
	}
	var vertex *Vertix
	var exists bool
	if vertex, exists = G.adjList[startVertex]; !exists {
		return nil, ErrVertexNotFound
	}
	queue := make([]rune, 0, vertex.outDegree)
	parentVertices := make(map[rune]rune, G.totalVertices)
	parentVertices[startVertex] = startVertex
	G.dfsRecursion(startVertex, parentVertices, queue)
	return parentVertices, nil
}

// dfsRecursion is the depth_first_search algorithm helper method for finding the connected components
// returning the topological order of the graph.
func (G *Graph) dfsRecursion(source rune, parentVertices map[rune]rune, queue []rune) []rune {
	for e := G.adjList[source].edges.Front(); e != nil; e = e.Next() {
		visitingVertex := e.Value.(*Edge).vertixName
		if _, visited := parentVertices[visitingVertex]; !visited {
			parentVertices[visitingVertex] = source
			queue = G.dfsRecursion(visitingVertex, parentVertices, queue)
		}
	}
	queue = append(queue, source)
	return queue
}

// FullDfs is for finding the connected components of the whole graph.
// Returning parent vertices, and the topological order of the graph.
// Returns an error if there's any.
func (G *Graph) FullDfs() (map[rune]rune,[]rune, error) {
	if G == nil {
		return nil, nil, ErrGraphNil
	}
	var order []rune = make([]rune, 0, G.totalVertices)
	parentVertices := make(map[rune]rune, G.totalVertices)

	// for every vertex in the graph
	for vertex := range G.adjList {
		// if the vertex is not visited before.
		if _, visited := parentVertices[vertex]; !visited {
			// mark it as visited vertex
			parentVertices[vertex] = vertex
			// run dfs on that vertex
			order = G.dfsRecursion(vertex, parentVertices, order)
		}
	}
	return parentVertices, order, nil
}
