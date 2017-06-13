#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{
public:
	Player(int, QString, int);

	int id;
	QString name;
	int val;
};

#endif // PLAYER_H