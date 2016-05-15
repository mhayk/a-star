#ifndef CITY_H_
#define CITY_H_

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Structure contendo informações mínimas da cidades vizinhas;
struct	Neighbor
{
	string	Name;
	int	Distance;
};


//Nó contendo informações necessário para o algorítmo A*(A Estrela).

class	City
{
public:

	vector<Neighbor>::iterator	NeighborNumber;
	vector<Neighbor>		Neighbors;

	string				Name;
	string				AccumulatedPath;
	int				AccumulatedDistance;
	int				StraightLineDistance;

	City();
	City(string, int);

	void	AddNeighbor	(string, int);
};

#endif
