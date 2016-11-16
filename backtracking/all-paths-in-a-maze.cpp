#include "bits/stdc++.h"
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define repeat(x) while(x--)
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { cout<<(a[i])<<' ';}
using namespace std;
pair<int,int> source;
pair<int,int> destination;
vector<string> solutions;
int x_ubound=0, y_ubound=0; //upperbound of x and y on board
char **a;
void printMatrix() //to print the current matrix
{
	for (int i = 0; i < x_ubound; ++i)
	{
		for (int j = 0; j < y_ubound; ++j)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
}
bool isOutOfBounds(pair<int,int> coordinates)
{
	if(coordinates.first<0 || coordinates.first >= x_ubound || coordinates.second <0 || coordinates.second >= y_ubound)
		return true;
	return false;
}
bool isObstacle(pair<int,int> coordinates)
{
	if(isOutOfBounds(coordinates))
		return true;
	if(a[coordinates.first][coordinates.second] == 'O')
		return true;
	return false;
}

bool explore(pair<int,int> coordinates, string movesSoFar, char move, set<pair<int,int> > visited = set<pair<int,int> >()) 
//start-coordinates, moveshistory, which move was made to get here, list of coordinates already visited in this exploration
{
	if( visited.count(coordinates) != 0) //cycled back to an already visited coordinate recursively
	{
		return false;
	}
	else
		visited.insert(coordinates); // insert coordinates to visited list for this exploration
	if(coordinates.first == destination.first && coordinates.second == destination.second) //at destination
	{
		movesSoFar+=move;
		solutions.push_back(movesSoFar);
		return true;
	}
	else //not at destination. so explore all directions
	{
		int mod_x=coordinates.first, mod_y=coordinates.second; //to be modified, x,y values
		set<char> setOfMoves; 
		setOfMoves.insert('U'); setOfMoves.insert('D'); setOfMoves.insert('L'); setOfMoves.insert('R'); //set of available moves
		if(move!= '-') //remove the direction you came from to avoid going back and both between the same two coordinates
		{
			char src;
			(move=='D')?src='U':(move=='U')?src='D':(move=='L')?src='R':(move=='R')?src='L':0;
			setOfMoves.erase(src); //remove source direction
		}
		for(std::set<char>::iterator it=setOfMoves.begin(); it!=setOfMoves.end(); ++it) //iterate through movelist
		{
			if(*it == 'U')
				if(!isObstacle(make_pair(mod_x-1, mod_y)) )
					if(!explore(make_pair(mod_x-1, mod_y),movesSoFar+move,'U',visited)) //explore up direction
						continue;
			if(*it == 'D')
				if(!isObstacle(make_pair(mod_x+1, mod_y)) )
					if(!explore(make_pair(mod_x+1, mod_y),movesSoFar+move,'D',visited)) //explore down direction
						continue;
			if(*it == 'L')
				if(!isObstacle(make_pair(mod_x, mod_y-1)) )
					if(!explore(make_pair(mod_x, mod_y-1),movesSoFar+move,'L',visited)) //explore left direction
						continue;
			if(*it == 'R')
				if(!isObstacle(make_pair(mod_x, mod_y+1)) )
					if(!explore(make_pair(mod_x, mod_y+1),movesSoFar+move,'R',visited)) //explore right direction
						continue;
		}
		if(coordinates.first==source.first && coordinates.second==source.second && !solutions.empty()) 
		//the recursion stack is back at the first function call and we have atleast one solution
		{
			cout<<"paths from "<<source.first<<","<<source.second<<" to "<<destination.first<<","<<destination.second<<" are\n";
			for (std::vector<string>::iterator v=solutions.begin(); v!=solutions.end(); ++v)
				cout<<*v<<endl;
			return true;
		}
		else if(solutions.empty())
		{
			cout<<"no viable paths\n";
			return true;
		}

	}
	return false; // not destination, all paths from coordinates are exhausted. so failure.
}
void setSource(pair<int,int> coordinates)
{
	a[coordinates.first][coordinates.second]='S'; //mark it in the maze
	source.first=coordinates.first; source.second=coordinates.second;
	return;
}
void setDestination(pair<int,int> coordinates)
{
	a[coordinates.first][coordinates.second]='X'; //mark it in the maze
	destination.first=coordinates.first; destination.second=coordinates.second;
	return;
}
void defineObstacles(int x,int y)
{
	a[x][y]='O';
}
int main()
{
	cout<<"enter size of maze A x B\n";
	cin>>x_ubound>>y_ubound;
	//x_ubound=5; y_ubound=8;
	a = new char*[x_ubound];
	for (int i = 0; i < x_ubound; ++i)
		a[i]= new char[y_ubound];
	for (int i = 0; i < x_ubound; ++i)
		for (int j = 0; j < y_ubound; ++j)
			a[i][j]='-'; //initially set all positions to be vacant
	/*for (int i = 1; i < x_ubound-1; ++i) //set a few obstables
		for (int j = 1; j < y_ubound-1; ++j)
			a[i][j]='O';
	a[1][2]='-';a[2][2]='-';a[2][3]='-';a[3][3]='-'; a[1][5]='-';a[2][5]='-';a[3][5]='-'; a[3][4]='-';// few more obstacles*/
	int x,y;
	cout<<"Enter the 0-based source coordinates\n";
	cin>>x>>y;
	setSource(make_pair(x,y)); //define source
	cout<<"Enter the 0-based destination coordinates\n";
	cin>>x>>y;
	setDestination(make_pair(x,y)); //define destination
	cout<<"Enter number of obstacles\n";
	int numberOfObstacles;
	cin>>numberOfObstacles;
	while(numberOfObstacles--)
	{
		cout<<"Enter 0-based coordinates of obstacle "<<endl;
		cin>>x>>y;
		defineObstacles(x,y);
	}
	printMatrix(); cout<<"\n";
	explore(source,"",'-');
	return 0;
}