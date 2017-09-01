<<<<<<< HEAD
#ifndef ROOM_H
#define ROOM_H

class Room
{
	private:
	int roomNumber;
	bool north;
	bool south;
	bool east;
	bool west;
	bool visited;

	public:
	Room();
	void setRoomNumber(int x);
	void setNorth(bool x);
	void setSouth(bool x);  
	void setEast(bool x);
	void setWest(bool x);
	void setVisited(bool x);
	int getRoomNumber();
	bool getNorth();
	bool getSouth();  
	bool getEast();
	bool getWest();
	bool getVisited();
};
#endif
=======
//declaration of the Room class
#ifndef ROOM_H
#define ROOM_H

class Room
{
	private:
	int roomNumber;
	bool north;
	bool south;
	bool east;
	bool west;
	bool visited;

	public:
	Room();
	void setRoomNumber(int x);
	void setNorth(bool x);
	void setSouth(bool x);  
	void setEast(bool x);
	void setWest(bool x);
	void setVisited(bool x);
	int getRoomNumber();
	bool getNorth();
	bool getSouth();  
	bool getEast();
	bool getWest();
	bool getVisited();
};
#endif
>>>>>>> 4c7355df64267f45f786f786887dd2f5d6b53718
