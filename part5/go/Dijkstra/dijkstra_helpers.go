package main

import (
	"container/heap"
	"math"
)

func (G *Graph) Dijkstra(src rune) (*ShortestDistance, error) {
	if G == nil {
		return nil, ErrGraphNil
	}
	queue := make(ChangablePriorityQueue, G.totalVertices, G.totalVertices)
	sd := &ShortestDistance{Src: src, Distances: make(map[rune]*DistanceNode, G.totalVertices)}
	i := 0
	for vertexName := range G.adjList {
		// initialize the structs and distances to infinity.
		sd.Distances[vertexName] = &DistanceNode{Distance: math.Inf(0)}
		// storing data for the changable priority queue.
		queue[i] = &QueueItem{
			value:    vertexName,
			priority: sd.Distances[vertexName].Distance,
			index:    i,
		}
		i++
	}
	heap.Init(&queue) // init the changable priority queue.

	// initialize the source.
	sd.Distances[src].Distance = 0
	sd.Distances[src].ParentVertex = src

	// while Q is not empty, delete item(u, d(s, u)) from Q that is minimum.
	for queue.Len() != 0 {
		item := queue.Pop()
		value := item.(*QueueItem).value.(rune)
		// for every edges.
		for e := G.adjList[value].edges.Front(); e != nil; e = e.Next() {
			edge := e.Value.(*Edge)
			G.tryToRelax(sd, value, edge)
			queue.Update(item.(*QueueItem), value, float64(edge.weight))
		}
	}
	return sd, nil
}

type QueueItem struct {
	value    any     // the value of the item; arbitrary.
	priority float64 // the priority of the item in the queue.
	// The index is needed by update and is maintained by the heap.Interface method.
	index int // the index of the item in the heap.
}

// A ChangablePriorityQueue implements heap.Interface and holds the QueueItems.
// This is to use with the Dijkstra algorithm.
//
// to intialize the ChangablePriorityQueue:
//
// pq := make(PriorityQueue, len(items))	// make the queue items and add them if neccessary.
//
// heap.Init(&pq)	// initialize the heap interface.
type ChangablePriorityQueue []*QueueItem

func (cpq ChangablePriorityQueue) Len() int { return len(cpq) }

func (cpq ChangablePriorityQueue) Less(i, j int) bool {
	// we want the lowest, use less than
	return cpq[i].priority < cpq[j].priority
}

func (cpq ChangablePriorityQueue) Swap(i, j int) {
	cpq[i], cpq[j] = cpq[j], cpq[i]
	cpq[i].index = i
	cpq[j].index = j
}

func (cpq *ChangablePriorityQueue) Push(x any) {
	n := len(*cpq)
	item := x.(*QueueItem)
	item.index = n
	*cpq = append(*cpq, item)
}

// Pop removes the least priority item and returns it.
//
// this implementation can be used as delete_min operation for Dijkstra algorithm.
func (cpq *ChangablePriorityQueue) Pop() any {
	old := *cpq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil  // avoid memory leak
	item.index = -1 // for safety
	*cpq = old[0 : n-1]
	return item
}

// Update modifies the priority and value of an QueueItem in the priority queue.
// Value's type must be the same as the type that is stored inside the value field of the QueueItem.
//
// this implementation can be used as decrease_key operation for Dijkstra algorithm.
// priority is the shortest distance from src vertex to the value vertex.
func (cpq *ChangablePriorityQueue) Update(item *QueueItem, value any, priority float64) {
	item.value = value
	item.priority = priority
	heap.Fix(cpq, item.index)
}
