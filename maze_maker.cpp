#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "room.h"

int getAdjacentRoom(int roomNumber, int size);
int mazeRow(int roomNumber, int size);
int mazeColumn(int roomNumber, int size); 
void openDoors(Room *room1, Room *room2, int size);

int main(){
	int size;

	std::cout << "Input the desired side length for the maze";
	std::cout << " (-1 for random): ";
	std::cin >> size; 	

	while(size <= 3 && size != -1){
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Invalid size. Size must be a positive integer";
		std::cout << " greater than 3: ";
		std::cin >> size;
	}
	if(size == -1){
		srand(time(NULL));
		size = rand() % 20 + 4;
		std::cout << "Size randomly selected to be " << size << "\n";
	} 

	// create 2D array to be our maze	
	Room** maze = new Room*[size];
	for(int i = 0; i < size; i++){
		maze[i] = new Room[size];
	}
	
	// nested for loops to label each room starting from 0
	//std::cout << "\nRooms by number:\n";	
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			maze[i][j].setRoomNumber((i * size) + j);
	//		std::cout << maze[i][j].getRoomNumber() << "\t"; 
		}
	//	std::cout << "\n";
	}
	/*
	for(int i = 0; i < size * size; i++){
	        std::cout << "Room " << i << ":\tmaze[" << mazeRow(i, size);
		std::cout << "][" << mazeColumn(i, size) << "]\n";
	}
	*/

	std::cout << "Generating a pair of adjacent rooms: (";
	int roomCount = size * size;
	int room = rand() % roomCount;
	int adjacentRoom = getAdjacentRoom(room, size);
	std::cout << room << ", " << adjacentRoom << ")\n";

        int row1 = mazeRow(room, size);
        int col1 = mazeColumn(room, size);
        int row2 = mazeRow(adjacentRoom, size);
        int col2 = mazeColumn(adjacentRoom, size);

	std::cout << "(maze[" << row1 << "][" << col1;
	std::cout << "], maze["	<< row2 << "][" << col2 << "])";

	openDoors(&maze[row1][col1], &maze[row2][col2], size);

	if(maze[row1][col1].getNorth() == 1 || maze[row1][col1].getSouth() == 1)
	{
		std::cout << "\nNorth/South door opened\n";
	}
	if(maze[row1][col1].getEast() == 1 || maze[row1][col1].getWest() == 1){
		std::cout << "\nEast/West door opened\n";
	}
	// Open the north door of Room 0 and the South door of the last room
	maze[0][0].setNorth(1);
	maze[size - 1][size - 1].setSouth(1);
	
	/*Print out the current maze, which at this point would look
	* like a chess board
	*/
	std::cout << "\nCurrent Maze:\n";

	for(int i = 0; i < size; i++){
		if(maze[0][i].getNorth() == 0){
			std::cout << "+---";
		} else {
			std::cout << "+   ";
		}
	}
	std::cout << "+\n";
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(maze[i][j].getWest() == 0){
				std::cout << "|   ";	
			} else {
				std::cout << "    ";
			}
		}
		std::cout << "|\n";
		for(int j = 0; j < size; j++){
			if(maze[i][j].getSouth() == 0){
				std::cout << "+---";
			} else {
				std::cout << "+   ";
			}
		}
		std::cout << "+\n";
	}
	
	for(int i = 0; i < size; i++){
		delete[] maze[i];
	}
	delete[] maze;
	
	return 0;
}

int getAdjacentRoom(int roomNumber, int size){
	int adj, maxNumber, delta, addSub;
	bool valid = 0;
	maxNumber = (size * size) - 1;
	srand(time(NULL));

	while(valid == 0){
		valid = 1;
		delta = rand() % 2;
		addSub = rand() % 2;
		if (delta == 0){
			delta = size;
		}
		if(addSub == 1){
			adj = roomNumber + delta;
		} else {
			adj = roomNumber - delta;
		}
		// 4 special cases where it would not be adjacent
		if((adj - roomNumber == 1) && (adj % size == 0)){
			valid = 0;
		}
		if((roomNumber - adj == 1) && (roomNumber % size == 0)){
			valid = 0;
		}
		if((adj < 0) || (adj > maxNumber)){
			valid = 0;
		}
	}	
	return adj;
}

int mazeRow(int roomNumber, int size){
	return roomNumber / size;
}

int mazeColumn(int roomNumber, int size){
	return roomNumber % size;
}

void openDoors(Room *room1, Room *room2, int size){
	if(room1->getRoomNumber() - room2->getRoomNumber() == 1){
		room1->setWest(1);
		room2->setEast(1);
	}
	if(room2->getRoomNumber() - room1->getRoomNumber() == 1){
       		room2->setWest(1);
                room1->setEast(1);
        }
	if(room1->getRoomNumber() - room2->getRoomNumber() == size){
       		room1->setNorth(1);
                room2->setSouth(1);
        }
	if(room2->getRoomNumber() - room1->getRoomNumber() == size){
		room2->setNorth(1);
                room1->setSouth(1);
        }
}
