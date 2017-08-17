#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "room.h"

int main(){
	int size;

	std::cout << "Input the desired side length for the maze (-1 for random): ";
	std::cin >> size; 	

	while(size <= 3 && size != -1){
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Invalid size. Size must be a positive integer greater than 3: ";
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
//	std::cout << "\nRooms by number:\n";	
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			maze[i][j].setRoomNumber((i * size) + j);
//			std::cout << maze[i][j].getRoomNumber() << "\t"; 
		}
//		std::cout << "\n\n";
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
