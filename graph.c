#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAXV 100         // max number vertices

typedef struct edgenode {
  int y;
  int weight;
  struct edgenode *next;
} edgenode;

typedef struct {
  edgenode *edges[MAXV + 1];     // adjacency info
  int degree[MAXV + 1];          // outdegree of each vertex
  int nvertices;                 // num vertices in graph
  int nedges;                    // num edges in graph 
  int directed;                  // is graph directed?
} graph;

void initialize_graph(graph *g, bool directed) {
  int i;          // counter

  g->nvertices = 0;
  g->nedges = 0;
  g->directed = directed;

  for (i = 1; i <= MAXV; i++) {
    g->degree[i] = 0;
  }

  for (i = 1; i <= MAXV; i++) {
    g->edges[i] = NULL;
  }
}

void insert_edge(graph *g, int x, int y, bool directed) {
  edgenode *p; // temporary pointer

  p = malloc(sizeof(edgenode));

  p->weight = 0;
  p->y = y;
  p->next = g->edges[x];

  g->edges[x] = p; // insert at head of list

  g->degree[x]++;

  if(!directed) {
    insert_edge(g, y, x, true);
  } else {
    g->nedges++;
  }
}
    
void read_graph(graph *g, bool directed) {
  int i;    // counter
  int m;    // num edges
  int x, y; // vertices in edge (x, y)

  initialize_graph(g, directed);

  scanf("%d %d", &(g->nvertices), &m);

  for (i = 1; i <= m; i++) {
    scanf("%d %d", &x, &y);
    insert_edge(g, x, y, directed);
  }
}

