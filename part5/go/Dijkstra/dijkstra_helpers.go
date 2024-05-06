package main

import (
	"container/heap"
	"math"
)

func (G *Graph) Dijkstra(src rune) (*ShortestDistance, error) {
	if G == nil {
		return nil, ErrGraphNil
	}

	pq := make(PriorityQueue, G.totalVertices, G.totalVertices)
	sd := &ShortestDistance{Src: src, Distances: make(map[rune]*DistanceNode, G.totalVertices)}
	i := 0
	for vertexName := range G.adjList {
		// initialize the structs and distances to infinity.
		sd.Distances[vertexName] = &DistanceNode{Distance: math.Inf(0)}
		// storing data for the changable priority queue.
		pq[i] = &PQItem{
			value:    vertexName,
			priority: sd.Distances[vertexName].Distance,
			index:    i,
		}
		i++
	}
	// initialize the changeable priority queue.
	cpq := &ChangeablePriorityQueue{}
	cpq.Init(pq)

	// initialize the source.
	sd.Distances[src].Distance = 0
	sd.Distances[src].ParentVertex = src
	cpq.DecreaseKey(src, 0) // update the priority of the src

	// while Q is not empty, delete item(u, d(s, u)) from Q that is minimum.
	for cpq.Len() > 0 {
		item := cpq.DeleteMin().(*PQItem)
		value := item.value.(rune)
		for e := G.adjList[value].edges.Front(); e != nil; e = e.Next() {
			edge := e.Value.(*Edge)
			G.tryToRelax(sd, value, edge)
			cpq.DecreaseKey(edge.vertixName, float64(edge.weight))
			// queue.Update(item.(*QueueItem), edge.vertixName, float64(edge.weight))
		}
	}
	return sd, nil
}

type element any

type ChangeablePriorityQueue struct {
	pqMap map[element]*PQItem // maps the vertex rune to Queue item.
	pq    PriorityQueue
}

// Init initialize the given pq and sets it to the Pq field of the ChangeablePriorityQueue.
func (cpq *ChangeablePriorityQueue) Init(pq PriorityQueue) {
	cpq.pqMap = make(map[element]*PQItem, pq.Len())
	// maps the vertex rune to the priority queue.
	for _, item := range pq {
		cpq.pqMap[item.value.(element)] = item
	}
	heap.Init(&cpq.pq)
	cpq.pq = pq
}

// Len returns the number of items in the queue.
func (cpq *ChangeablePriorityQueue) Len() int {
	return cpq.pq.Len()
}

// DecreaseKey update the key(priority) of this queue to the given priority.
func (cpq *ChangeablePriorityQueue) DecreaseKey(vertexName rune, priority float64) {
	item := cpq.pqMap[vertexName]
	item.priority = priority
	heap.Fix(&cpq.pq, item.index)
}

// DeleteMin removes the least priority item and returns it.
func (cpq *ChangeablePriorityQueue) DeleteMin() any {
	return heap.Pop(&cpq.pq)
}

// An PQItem is something we manage in a priority queue.
type PQItem struct {
	value    any     // The value of the item; arbitrary.
	priority float64 // The priority of the item in the queue.
	// The index is needed by update and is maintained by the heap.Interface methods.
	index int // The index of the item in the heap.
}

// A PriorityQueue implements heap.Interface and holds Items.
type PriorityQueue []*PQItem

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	// We want Pop to give us the highest, not lowest, priority so we use greater than here.
	return pq[i].priority < pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x any) {
	n := len(*pq)
	item := x.(*PQItem)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil  // avoid memory leak
	item.index = -1 // for safety
	*pq = old[0 : n-1]
	return item
}
