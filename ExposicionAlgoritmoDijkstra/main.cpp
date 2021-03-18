#include<iostream>
#include<climits>     
using namespace std;

/*Función utilizada para devolver el vértice con 
menor distancia*/
int minimumDist(int distancia[], bool visitados[])
{
	int min = INT_MAX, index;

	for (int i = 0; i < 6; i++)
	{
		if (visitados[i] == false && distancia[i] <= min)
		{
			min = distancia[i];
			index = i;
		}
	}
	return index;
}

void Dijkstra(int graph[6][6], int origen)
{
	int distancia[6];                        
	bool visitados[6];

	/*Los nodos se inicializan con distancia infinita en un principio
	Y se registran como no visitados*/
	for (int i = 0; i < 6; i++)
	{
		distancia[i] = INT_MAX;
		visitados[i] = false;
	}

	//Distancia del vertice origen se inicializa en 0
	distancia[origen] = 0;             

	for (int i = 0; i < 6; i++)
	{
		int m = minimumDist(distancia, visitados);
		visitados[m] = true;
		for (int i = 0; i < 6; i++)
		{
			//Actualiza la distancia mínima para el nodo especial
			if (!visitados[i] && graph[m][i] && distancia[m] != INT_MAX && distancia[m] + graph[m][i] < distancia[i])
				distancia[i] = distancia[m] + graph[m][i];
		}
	}
	cout << "Vertice\t\tDistancia desde el origen" << endl;
	for (int i = 0; i < 6; i++)
	{ 
		char str = 65 + i; 
		cout << str << "\t\t\t" << distancia[i] << endl;
	}
}

int main()
{
	int graph[6][6] = {
		{0, 10, 20, 0, 0, 0},
		{10, 0, 0, 50, 10, 0},
		{20, 0, 0, 20, 33, 0},
		{0, 50, 20, 0, 20, 2},
		{0, 10, 33, 20, 0, 1},
		{0, 0, 0, 2, 1, 0} };
	Dijkstra(graph, 2);
	return 0;
}
