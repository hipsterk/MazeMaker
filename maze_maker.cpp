#include <iostream>
#include "room.h"

int main(){
	int size;

	std::cout << "Testing room class:\n";
	Room test;
	test.setRoomNumber(420);
	test.setNorth(true);
	test.setEast(true);
	test.setVisited(true); 
	std::cout << "roomNumber: " << test.getRoomNumber();
	std::cout << "\n     north: " << test.getNorth();
	std::cout << "\n     south: " << test.getSouth();
	std::cout << "\n      east: " << test.getEast();
	std::cout << "\n      west: " << test.getWest();
	std::cout << "\n   visited: " << test.getVisited();

	std::cout << "\n\nInput the desired side length for the maze: ";
	std::cin >> size; 	

	// create 2D array to be our maze	
	int** maze = new int*[size];
	for(int i = 0; i < size; i++){
		maze[i] = new int[size];
	}
	
	// nested for loops to label each room starting from 0
	std::cout << "Rooms by number:\n";	
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			maze[i][j] = (i * size) + j;
			std::cout << maze[i][j] << "\t"; 
		}
		std::cout << "\n\n";
	}
	
	/*Print out the current maze, which at this point would look
	* like a chess board
	*/
	std::cout << "Current Maze:\n";
//	std::cout << "+   ";
	for(int i = 0; i < size; i++){
		std::cout << "+---";
	}
	std::cout << "+\n";
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			std::cout << "|   ";	
		}
		std::cout << "|\n";
		for(int j = 0; j < size; j++){
//			if(i != size - 1 || j != size - 1){
				std::cout << "+---";
//			} else {
//				std::cout << "+   ";
//			}
		}
		std::cout << "+\n";
	}

	
	return 0;
}
