#include "undirected_graph.h" //oss: serve specificare con " " quando includo file mio
#include <iostream> 

int main(void) {
	//TEST PER CLASSE UNDIRECTED_EDGE
	
	//verifico inizializzazione corretta + operatore <<
	undirected_edge<int> edge4_8(8,4); //collega nodo 4 al nodo 8 
	//(nodo A sarà 4: vale A <= B)
	std::cout << "coppia di nodi collegati: " << edge4_8 << "\n"; 
	
	//verifico operatore ==
	undirected_edge<int> edgebis4_8(4,8); 
	std::cout << (edge4_8 == edgebis4_8) << "\n"; 
	
	
	//verifico operatore <
	undirected_edge<int> edge4_7(4,7);
	undirected_edge<int> edge3_7(3,7);
	std::cout << (edge3_7 < edge4_7) << "\n"; 
	std::cout << (edge4_7 < edge4_8) << "\n"; 
	
	//TEST PER CLASSE UNDIRECTED_GRAPH
	undirected_graph<int> graph1; //inizializzo grafo1
	
	//creo struttura GRAFO1
	graph1.add_edge(7, 14); 
	graph1.add_edge(7, 12);
	graph1.add_edge(7, 15);
	graph1.add_edge(15, 12);
	graph1.add_edge(12, 11);
	graph1.add_edge(12, 2);
	
	std::cout << "Nodi grafo1: "; 
	std::vector<int> nodes = graph1.all_nodes();
	for (size_t i = 0; i < nodes.size(); i++) {
		std::cout << nodes[i] << " "; 
	}	
	std::cout << "\n";
	
	std::cout << "Archi grafo1: "; 
	std::vector<undirected_edge<int>> edges = graph1.all_edges();
	for (size_t i = 0; i < edges.size(); i++) {
		std::cout << edges[i] << " "; 
	}	
	std::cout << "\n";
	
	std::cout << "Vicini nodo 12: "; 
	std::set<int> neighbours_12 = graph1.neighbours(12);
	for (auto& itor : neighbours_12) {
		std::cout << itor << " "; 
	}	
	std::cout << "\n";
	
	std::cout << "Vicini nodo 8: "; //nodo non presente --> correttamente non stampa nulla
	std::set<int> neighbours_8 = graph1.neighbours(8);
	for (auto& itor : neighbours_8) {
		std::cout << itor << " "; 
	}	
	std::cout << "\n";
	
	std::cout << "Arco numero 3: " << graph1.edge_at(3) << "\n";
	std::cout << "Arco numero 8: " << graph1.edge_at(8) << "\n"; //posizione non presente
	// --> correttamente stampa primo arco	
	
	undirected_edge<int> edge7_14(14,7);
	std::cout << "Posizione arco (7,14): " << (graph1.edge_number(edge7_14)) << "\n";
	undirected_edge<int> edge2_14(14,2); //arco non presente --> correttamente stampa -1
	std::cout << "Posizione arco (2,14): " << (graph1.edge_number(edge2_14)) << "\n";
	
	undirected_graph<int> graph2; //inizializzo grafo2
	
	//creo struttura GRAFO2
	graph2.add_edge(12, 11);
	graph2.add_edge(12, 2);
	
	std::cout << "Nodi grafo2: "; 
	std::vector<int> nodes2 = graph2.all_nodes();
	for (size_t i = 0; i < nodes2.size(); i++) {
		std::cout << nodes2[i] << " "; 
	}	
	std::cout << "\n";
	
	std::cout << "Archi grafo2: "; 
	std::vector<undirected_edge<int>> edges2 = graph2.all_edges();
	for (size_t i = 0; i < edges2.size(); i++) {
		std::cout << edges2[i] << " "; 
	}	
	std::cout << "\n";
	
	//test operatore differenza GRAFO3 = GRAFO1 - GRAFO2
	undirected_graph<int> graph3 = graph1 - graph2; 
	
	std::cout << "Nodi grafo3: "; 
	std::vector<int> nodes3 = graph3.all_nodes();
	for (size_t i = 0; i < nodes3.size(); i++) {
		std::cout << nodes3[i] << " "; 
	}	
	std::cout << "\n";
	
	std::cout << "Archi grafo3: "; 
	std::vector<undirected_edge<int>> edges3 = graph3.all_edges();
	for (size_t i = 0; i < edges3.size(); i++) {
		std::cout << edges3[i] << " "; 
	}	
	std::cout << "\n";
	
	return 0; 
	
}