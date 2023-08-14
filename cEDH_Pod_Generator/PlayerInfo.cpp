#include "PlayerInfo.h"



double PlayerInfo::getWinRate()
{
	double trueScore = (win * 3 + draw * 1) / (win + draw + lose);
	if (trueScore<0.1)
	{
		return 0.1;
	}

	return trueScore;
}

PlayerInfo::PlayerInfo(const QString& PlayerName)
{
}


PlayerInfo::~PlayerInfo()
{
}

bool PlayerInfo::operator>(const PlayerInfo & other)
{
	int thisPlayerScor = win * 3 + draw * 1;
	int otherPlayerScor = other.win * 3 + other.draw * 1;

	if (thisPlayerScor == otherPlayerScor)
	{
		auto thisEnemyPlayerRate = PlayerManager::getInstance()->enemyWinRate(name);
		auto otherEnemyPlayerRate = PlayerManager::getInstance()->enemyWinRate(other.name);
		return thisEnemyPlayerRate > otherEnemyPlayerRate;
	}
	return thisPlayerScor > otherPlayerScor;
}

bool PlayerInfo::operator<(const PlayerInfo & other)
{
	int thisPlayerScor = win * 3 + draw * 1;
	int otherPlayerScor = other.win * 3 + other.draw * 1;

	if (thisPlayerScor == otherPlayerScor)
	{
		auto thisEnemyPlayerRate = PlayerManager::getInstance()->enemyWinRate(name);
		auto otherEnemyPlayerRate = PlayerManager::getInstance()->enemyWinRate(other.name);
		return thisEnemyPlayerRate < otherEnemyPlayerRate;
	}
	return thisPlayerScor < otherPlayerScor;
}
