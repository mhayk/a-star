#include "city.h"


//Construtor para City

City::City()
{
	Name="";
	NeighborNumber=Neighbors.begin();
	AccumulatedPath="";
	AccumulatedDistance=0;
	StraightLineDistance=0;
}


//Construtor para inicializar via parâmetros o City

City::City(string name, int sld)
{
	Name=name;
	NeighborNumber=Neighbors.begin();
	AccumulatedPath=name;
	AccumulatedDistance=0;
	StraightLineDistance=sld;
}

//Adiciona a vizinhança - necessita do "nome do vizinho" e "distância euclidiana" até a cidade destino.

void	City::AddNeighbor(string name, int distance)
{
	Neighbor	TempNeighbor;

	TempNeighbor.Name		= name;
	TempNeighbor.Distance	= distance;
	Neighbors.push_back(TempNeighbor);
	NeighborNumber=Neighbors.begin();
}
