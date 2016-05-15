#ifndef A_STAR_H_
#define A_STAR_H_

#include <string>
#include <iostream>
#include <vector>

#include "city.h"

using namespace std;

bool	GetChildCity(Neighbor, City*);

void	MakeMap();

City	FindShortestPath(int *LowestPathDistance);

bool 	AStarSearch(string StartName, string GoalName);

#endif
