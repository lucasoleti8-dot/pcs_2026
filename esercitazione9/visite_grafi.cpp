#include <iostream>
#include "coda_pila.h"
#include "undirected_graph.h"
#include "algoritmi_visita.h"


int main(void) {
	//TEST CLASSI FIFO E LIFO
	fifo<int> q; 
	q.put(10);
	int x = q.get();
	if (q.empty()) {
		std::cout << "coda vuota" << std::endl;
	}
	
	lifo<int> l; 
	l.put(10); 
	int y = l.get();
	if (l.empty()) {
		std::cout << "pila vuota" << std::endl;
	}
	//TEST BFS, DFS
	undirected_graph<int> G;
	G.add_edge(1,2);
	G.add_edge(1,3);
	G.add_edge(1,4);
	G.add_edge(1,6);
	G.add_edge(2,4);
	G.add_edge(2,5);
	G.add_edge(2,7);
	G.add_edge(3,6);
	G.add_edge(4,6);
	G.add_edge(4,7);
	G.add_edge(5,7);
	G.add_edge(6,7);
	G.add_edge(6,8);
	G.add_edge(7,9);
	G.add_edge(8,9);
	
	
	fifo<int> coda;
	auto bfsG = graph_visit(G,1,coda);
	lifo<int> pila; 
	auto dfsG = graph_visit(G,1,pila);
	
	std::cout << "Archi bfsG: "; 
	std::vector<undirected_edge<int>> edges_bfsG = bfsG.all_edges();
	for (size_t i = 0; i < edges_bfsG.size(); i++) {
		std::cout << edges_bfsG[i] << " "; 
	}
	std::cout << "\n";
	
	std::cout << "Archi dfsG: "; 
	std::vector<undirected_edge<int>> edges_dfsG = dfsG.all_edges();
	for (size_t i = 0; i < edges_dfsG.size(); i++) {
		std::cout << edges_dfsG[i] << " "; 
	}
	std::cout << "\n";
	
	auto recursive_dfsG = recursive_dfs(G,1);
	
	std::cout << "Archi recursive_dfsG: "; 
	std::vector<undirected_edge<int>> edges_recursive_dfsG = recursive_dfsG.all_edges();
	for (size_t i = 0; i < edges_recursive_dfsG.size(); i++) {
		std::cout << edges_recursive_dfsG[i] << " "; 
	}
	std::cout << "\n";
	
	auto DijkstraG = Dijkstra(G,1);
	//OSS: grafo senza pesi: dovrei ottenere stesso albero della visita bfs
	
	std::cout << "Archi DijkstraG: "; 
	std::vector<undirected_edge<int>> edges_Dijkstra = DijkstraG.all_edges();
	for (size_t i = 0; i < edges_Dijkstra.size(); i++) {
		std::cout << edges_Dijkstra[i] << " "; 
	}
	std::cout << "\n";
	
	
	
	return 0;
}