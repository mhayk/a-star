#include "astar.h"

vector<City>	Cities;
vector<City>	Frontier;

// Capturo as cidades vizinha a cidade informada.
bool GetChildCity (Neighbor Parent, City *ChildCity)
{
    vector<City>::iterator	CityNumber;

    for( CityNumber = Cities.begin(); CityNumber < Cities.end(); CityNumber++ )
    {
        *ChildCity = *CityNumber;
        if( ChildCity->Name == Parent.Name )
            return true;
    }
    return false;
}

/*
    Método que cria objetos com seus respectivos
    vizinhos e distância Euclidiana e por fim inseri
    em um container de cidades(Cities).
*/

void MakeMap()
{
    City	TempCity;

    //Dados da cidade Arad
    TempCity.Name="Arad";
    TempCity.StraightLineDistance=366;
    TempCity.Neighbors.clear();

    TempCity.AddNeighbor("Zerind",75);
    TempCity.AddNeighbor("Sibiu", 140);
    TempCity.AddNeighbor("Timisoara",118);
    Cities.push_back(TempCity);

    //Dados da cidade Bucharest
    TempCity.Name="Bucharest";
    TempCity.StraightLineDistance=0;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Giurgiu",90);
    TempCity.AddNeighbor("Urziceni",85);
    TempCity.AddNeighbor("Fagaras",211);
    TempCity.AddNeighbor("Pitesti",101);
    Cities.push_back(TempCity);


    //Dados da cidade Craiova
    TempCity.Name="Craiova";
    TempCity.StraightLineDistance=160;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Pitesti",138);
    TempCity.AddNeighbor("Rimnicu Vilcea",146);
    TempCity.AddNeighbor("Drobeta",120);
    Cities.push_back(TempCity);

    //Dados da cidade Drobeta
    TempCity.Name="Drobeta";
    TempCity.StraightLineDistance=242;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Craiova",120);
    TempCity.AddNeighbor("Mehadia",75);
    Cities.push_back(TempCity);

    //Dados da cidade Eforie
    TempCity.Name="Eforie";
    TempCity.StraightLineDistance=161;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Hirsova",86);
    Cities.push_back(TempCity);

    //Dados da cidade Fagaras
    TempCity.Name="Fagaras";
    TempCity.StraightLineDistance=176;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Bucharest",211);
    TempCity.AddNeighbor("Sibiu",99);
    Cities.push_back(TempCity);

    //Dados da cidade Giurgiu
    TempCity.Name="Giurgiu";
    TempCity.StraightLineDistance=77;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Bucharest",90);
    Cities.push_back(TempCity);

    //Dados da cidade Hirsova
    TempCity.Name="Hirsova";
    TempCity.StraightLineDistance=151;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Eforie",86);
    TempCity.AddNeighbor("Uriceni",98);
    Cities.push_back(TempCity);

    //Dados da cidade Iasi
    TempCity.Name="Iasi";
    TempCity.StraightLineDistance=226;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Vaslui",92);
    TempCity.AddNeighbor("Neamt",87);
    Cities.push_back(TempCity);

    //Dados da cidade Lugoj
    TempCity.Name="Lugoj";
    TempCity.StraightLineDistance=244;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Mehadia",70);
    TempCity.AddNeighbor("Timisoara",111);
    Cities.push_back(TempCity);

    //Dados da cidade Mehadia
    TempCity.Name="Mehadia";
    TempCity.StraightLineDistance=241;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Drobeta",75);
    TempCity.AddNeighbor("Lugoj",70);
    Cities.push_back(TempCity);

    //Dados da cidade Neamt
    TempCity.Name="Neamt";
    TempCity.StraightLineDistance=234;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Iasi",87);
    Cities.push_back(TempCity);

    //Dados da cidade Oradea
    TempCity.Name="Oradea";
    TempCity.StraightLineDistance=380;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Zerind",71);
    TempCity.AddNeighbor("Sibiu",151);
    Cities.push_back(TempCity);

    //Dados da cidade Pitesti
    TempCity.Name="Pitesti";
    TempCity.StraightLineDistance=100; //verificar
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Bucharest",101);
    TempCity.AddNeighbor("Rimnicu Vilcea",97);
    TempCity.AddNeighbor("Craiova",138);
    Cities.push_back(TempCity);

    //Dados da cidade Rimnicu Vilcea
    TempCity.Name="Rimnicu Vilcea";
    TempCity.StraightLineDistance=193;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Pitesti",97);
    TempCity.AddNeighbor("Sibiu",80);
    TempCity.AddNeighbor("Craiova",146);
    Cities.push_back(TempCity);

    //Dados da cidade Sibiu
    TempCity.Name="Sibiu";
    TempCity.StraightLineDistance=253;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Rimnicu Vilcea",80);
    TempCity.AddNeighbor("Fagaras",99);
    TempCity.AddNeighbor("Oradea",151);
    TempCity.AddNeighbor("Arad",140);
    Cities.push_back(TempCity);

    //Dados da cidade Timsoara
    TempCity.Name="Timisoara";
    TempCity.StraightLineDistance=329;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Lugoj",111);
    TempCity.AddNeighbor("Arad",118);
    Cities.push_back(TempCity);

    //Dados da cidade Urziceni
    TempCity.Name="Urziceni";
    TempCity.StraightLineDistance=80;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Hirsova",98);
    TempCity.AddNeighbor("Bucharest",85);
    TempCity.AddNeighbor("Vaslui",142);
    Cities.push_back(TempCity);

    //Dados da cidade Vaslui
    TempCity.Name="Vaslui";
    TempCity.StraightLineDistance=199;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Iasi",92);
    TempCity.AddNeighbor("Urziceni",142);
    Cities.push_back(TempCity);

    //Dados da cidade Zerind
    TempCity.Name="Zerind";
    TempCity.StraightLineDistance=374;
    TempCity.Neighbors.clear();
    TempCity.AddNeighbor("Oradea",71);
    TempCity.AddNeighbor("Arad",75);
    Cities.push_back(TempCity);
}

// Equivalente a fila de prioridade a partir da distância inicial até o objetivo.

City FindShortestPath(int *LowestPathDistance)
{
    vector<City>::iterator	FrontierNumber;
    vector<City>::iterator	LowestNodeNumber;

    City	CurrentCity;

    FrontierNumber = Frontier.begin();
    CurrentCity = *FrontierNumber;

    /*
     f(n) = g(n) + h(n)
        f(n) = distância total estimada do caminho através de n até o objetivo. -> LowestPathDistance.
        g(n) = distância percorrida até o momento para alcançar n.              -> CurrentCity.AccumulatedDistance.
        h(n) = distância estimada de n até o objetivo.                          -> CurrentCity.StraightLineDistance.

    */
    *LowestPathDistance = CurrentCity.AccumulatedDistance + CurrentCity.StraightLineDistance;
    LowestNodeNumber = FrontierNumber;
    FrontierNumber++;

    while( FrontierNumber < Frontier.end() )
    {
        CurrentCity = *FrontierNumber;
        if( *LowestPathDistance > CurrentCity.AccumulatedDistance + CurrentCity.StraightLineDistance )
        {
            *LowestPathDistance = CurrentCity.AccumulatedDistance + CurrentCity.StraightLineDistance;
            LowestNodeNumber = FrontierNumber;
        }
        FrontierNumber++;
    }

    CurrentCity = *LowestNodeNumber;
    //cout << "Vou por: \e[1m" << CurrentCity.Name << "\e[0m" << endl;

    //Remove a cidade já visitada!
    Frontier.erase(LowestNodeNumber);

    return CurrentCity;
}

bool AStarSearch(string StartName, string GoalName)
{
    vector<City>::iterator	CityNumber;

    City		CurrentCity;
    City		StartCity;
    City		ChildCity;

    Neighbor	CurrentNeighbor;

    bool		StartCityFound=false;
    bool		GoalFound=false;

    int		MinPossibleDistance = 0;
    int		GoalDistance = 0;

    string		GoalPath;

    if( StartName == "" || GoalName == "" ) return false;


    //Pesquisa a Cidade de Partida no meu container de cidades.
    for( CityNumber = Cities.begin(); CityNumber < Cities.end(); CityNumber++)
    {
        CurrentCity = *CityNumber;
        if( CurrentCity.Name == StartName )
        {
            StartCity = CurrentCity;
            StartCityFound = true;
            StartCity.AccumulatedPath = StartName;
        }
    }

    if( StartCityFound == false ) return false;

    //Se encontrei insiro no meu container "Frontier".
    Frontier.push_back( StartCity );

    cout << endl << "Gravando Processo Exploratório:\n" << "Localização Inicial: [" <<
            StartName << "]\t Localização Final: [" << GoalName << "]" << endl << endl;

    /*
      Enquanto houver cidade vizinhas há visitar e ( distância até o destino maior que a menor distância já
      encontrada ou se o destino foi encontrado )
      */
    while( !Frontier.empty() && ( GoalDistance > MinPossibleDistance || GoalFound == false))
    {
        // Aplica a heurítica da distância euclediana ....
        CurrentCity = FindShortestPath(&MinPossibleDistance);

        if( GoalDistance > MinPossibleDistance || GoalFound == false)
        {
            // Visita os vizinhos adjacentes...
            for( CurrentCity.NeighborNumber = CurrentCity.Neighbors.begin();
                 CurrentCity.NeighborNumber < CurrentCity.Neighbors.end();
                 CurrentCity.NeighborNumber++ )
            {
                CurrentNeighbor = *CurrentCity.NeighborNumber;
                if( GetChildCity(CurrentNeighbor, &ChildCity) == false )
                {
                    cout << "Cidade filha não encontrada - Terminando...\n";
                    return false;
                }
                // concatena a string de caminho percorrido para facilitar a explicação.
                ChildCity.AccumulatedPath = CurrentCity.AccumulatedPath +
                        " -> " + ChildCity.Name;
                // acumula a distância percorrida.
                ChildCity.AccumulatedDistance = CurrentCity.AccumulatedDistance +
                        CurrentNeighbor.Distance;

                cout << "Caminho corrente expandido: " << ChildCity.AccumulatedPath
                     << " | Distância: [\e[1m" << ChildCity.AccumulatedDistance << "\e[0m]"
                     << " (" << ChildCity.AccumulatedDistance+ChildCity.StraightLineDistance << " = "
                     << ChildCity.AccumulatedDistance << "+" << ChildCity.StraightLineDistance << ")" << endl;

                // condição que verifica se a cidade destino foi encontrada!
                if( ChildCity.Name == GoalName )
                {
                    GoalDistance = ChildCity.AccumulatedDistance;
                    GoalPath = ChildCity.AccumulatedPath;

                    cout << "Caminho até o destino: " << GoalPath << " | Distância: "
                         << GoalDistance << endl;

                    GoalFound = true;
                }
                // Lista de Abertos .... Sibiu .. Timisoara ... Zerind ...
                Frontier.push_back(ChildCity);
            }
        }
    }

    cout << "\nMelhor caminho até o destino:\n";
    cout << "\e[1m" << GoalPath << "\e[0m | Distância: [\e[1m" << GoalDistance << "\e[0m]" << endl;
    cout << "Avaliação concluída.\n";
    return true;
}
