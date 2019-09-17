#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Graph {
	int V;
	vector<int> *adj;

	public: Graph(int v) {
		this->V = v;
		this->adj = new vector<int>[v];
	}
	
	public: void addEdge(int u, int v){
		this->adj[u].push_back(v);
	}
	
	public: void eSquared(){
		for (int v = 1; v < this->V; ++v){
			set<int> *s = new set<int>;
			cout << v << ":";
			for (int i = this->adj[v].size() - 1; i >= 0; --i){
				int x = this->adj[v][i];
				for (int j = this->adj[x].size() - 1; j >= 0; --j){
					int y = this->adj[x][j];
					if (y != v)
						s->insert(y);
				}
			}
			for (set<int>::iterator it = s->begin(); it != s->end(); ++it){
				cout << " " << *it;
			}
			cout << endl;
		}
	}
};

int main() {
	Graph *G = new Graph(7);
	
	G->addEdge(1, 3);
	G->addEdge(3, 4);
	G->addEdge(4, 6);
	G->addEdge(6, 5);
	G->addEdge(5, 4);
	G->addEdge(4, 5);
	G->addEdge(3, 2);
	G->addEdge(3, 5);
	G->addEdge(1, 5);
	
	G->eSquared();

	return 0;
}
