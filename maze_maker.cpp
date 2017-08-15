#include <iostream>

int main(int argc, char *argv[]){
	int size;
	
	std::cout << "Input the desired side length for the maze: ";
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
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			std::cout << "+---";	
		}
		std::cout << "+\n";
		for(int j = 0; j < size; j++){
			std::cout << "|   ";
		}
		std::cout << "|\n";
	}
	for(int i = 0; i < size; i++){
		std::cout << "+---";
	}
	std::cout << "+\n";	
	return 0;
}
