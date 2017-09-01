<<<<<<< HEAD
#include "room.h"

Room::Room()
{
	roomNumber = 0;
	north = 0;
	south = 0;
	east = 0;
	west = 0;
	visited = 0;
}

void Room::setRoomNumber(int x)
{
	roomNumber = x;
}

void Room::setNorth(bool x)
{
	north = x;
}

void Room::setSouth(bool x)
{
	south = x;
}

void Room::setEast(bool x)
{
	east = x;
}

void Room::setWest(bool x)
{
	west = x;
}

void Room::setVisited(bool x)
{
	visited = x;
}

int Room::getRoomNumber()
{
	return roomNumber;
}

bool Room::getNorth()
{
	return north;
}

bool Room::getSouth()
{
	return south;
}

bool Room::getEast()
{
	return east;
}

bool Room::getWest()
{
	return west;
}

bool Room::getVisited()
{
	return visited;
}
=======
//implementation of the room class
#include "room.h"

Room::Room()
{
	roomNumber = 0;
	north = 0;
	south = 0;
	east = 0;
	west = 0;
	visited = 0;
}

void Room::setRoomNumber(int x)
{
	roomNumber = x;
}

void Room::setNorth(bool x)
{
	north = x;
}

void Room::setSouth(bool x)
{
	south = x;
}

void Room::setEast(bool x)
{
	east = x;
}

void Room::setWest(bool x)
{
	west = x;
}

void Room::setVisited(bool x)
{
	visited = x;
}

int Room::getRoomNumber()
{
	return roomNumber;
}

bool Room::getNorth()
{
	return north;
}

bool Room::getSouth()
{
	return south;
}

bool Room::getEast()
{
	return east;
}

bool Room::getWest()
{
	return west;
}

bool Room::getVisited()
{
	return visited;
}
>>>>>>> 4c7355df64267f45f786f786887dd2f5d6b53718
