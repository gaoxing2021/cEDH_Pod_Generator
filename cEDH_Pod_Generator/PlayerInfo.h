#pragma once
#include <QString>
#include <QList>
#include "PlayerManager.h"
class PlayerInfo
{
	friend class PlayerManager;
public:
	double getWinRate();

private:
	PlayerInfo(const QString& PlayerName);
	~PlayerInfo();

protected:

	QString name;
	int win;
	int draw;
	int lose;



	bool operator>(const PlayerInfo& other);
	bool operator<(const PlayerInfo& other);
};

