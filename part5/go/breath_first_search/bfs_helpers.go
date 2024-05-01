package main

// FindPath finds the minimum length path between source and destination
// vertices, using the Breath first search algorithm. This method doesn't
// consider the weight of the edges, and the lenght is calculated by the
// number of vertices.
func (G *Graph) FindPath(src, dest rune) ([]rune, error) {
	if G == nil {
		return nil, ErrGraphNil
	}
	var vertex *Vertix
	var exists bool
	if _, exists = G.adjList[src]; !exists {
		return nil, ErrVertexNotFound
	} else if vertex, exists = G.adjList[dest]; !exists {
		return nil, ErrVertexNotFound
	}
	parentVertices, err := G.Bfs(dest)
	if err != nil {
		return nil, err
	}
	path := make([]rune, 0, vertex.outDegree)
	path = append(path, src)
	parent := parentVertices[src]
	for parent != 0 {
		path = append(path, parent)
		parent = parentVertices[parent]
	}
	return path, nil
}

// Bfs is the breath_first_search algorithm. It returns the found
// parent vertices of the caller graph and an error if there's any.
func (G *Graph) Bfs(startVertex rune) (map[rune]rune, error) {
	if G == nil {
		return nil, ErrGraphNil
	}
	var vertex *Vertix
	var exists bool
	if vertex, exists = G.adjList[startVertex]; !exists {
		return nil, ErrVertexNotFound
	}

	// initialized with the startVertex's outdegree
	queue := make([]rune, 0, vertex.outDegree)
	// initialized with totalVertices
	parentVertices := make(map[rune]rune, G.totalVertices)
	visitedVertices := make(map[rune]bool, G.totalVertices)
	queue = append(queue, startVertex)
	visitedVertices[startVertex] = true

	for len(queue) != 0 {
		currentVertex := queue[0]
		queue = queue[1:]

		for e := G.adjList[currentVertex].edges.Front(); e != nil; e = e.Next() {
			visitingVertex := e.Value.(*Edge).vertixName
			// this vertex is not visited before.
			if visitedVertices[visitingVertex] != true {
				queue = append(queue, visitingVertex)          // append to queue
				visitedVertices[visitingVertex] = true         // mark it as visited
				parentVertices[visitingVertex] = currentVertex // mark is for parent vertex.
			}
		}
	}

	return parentVertices, nil
}
