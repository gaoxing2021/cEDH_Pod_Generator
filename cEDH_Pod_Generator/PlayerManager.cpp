#include "PlayerManager.h"
#include "PlayerInfo.h"
#include "qmessagebox.h"

PlayerManager* PlayerManager::pManager = nullptr;

PlayerManager * PlayerManager::getInstance()
{
	if (pManager = nullptr)
	{
		pManager = new PlayerManager();
	}

	return pManager;
}

PlayerManager::PlayerManager(QObject *parent)
	: QObject(parent)
{
}

PlayerManager::~PlayerManager()
{
}

PlayerInfo * PlayerManager::createNewPlayer(const QString & name)
{
	if (name.isEmpty())
	{
		QMessageBox::warning(nullptr, QStringLiteral("警告"), QStringLiteral("玩家名称为空"));
		return nullptr;
	}
	if (playerMap.contains(name))
	{
		QMessageBox::warning(nullptr, QStringLiteral("警告"), QStringLiteral("玩家名称重复"));
		return nullptr;
	}
	auto player = new PlayerInfo(name);
	playerMap.insert(name, player);

	emit newPlayerCreated(player);
	return player;
}

bool PlayerManager::removePlayer(const QString & name)
{
	if (battledPlayerMap.contains(name)&& battledPlayerMap[name].count()>0)
	{
		QMessageBox::warning(nullptr, QStringLiteral("警告"), QStringLiteral("比赛已经开始不能删除用户"));
		return false;
	}

	if (playerMap.contains(name))
	{
		playerMap.remove(name);
		emit playerRemoved(name);

		return true;
	}

	return false;
}

PlayerInfo * PlayerManager::getPlayedInfo(const QString & name)
{
	if (playerMap.contains(name)) 
	{
		return playerMap[name];
	}
	return nullptr;
}

QList<PlayerInfo*> PlayerManager::getPlayedPlayerList(const QString & name)
{
	if (battledPlayerMap.contains(name))
	{
		return battledPlayerMap[name];
	}
	return QList<PlayerInfo*>();
}

double PlayerManager::enemyWinRate(const QString & name)
{
	auto battlePlayerList = getPlayedPlayerList(name);

	double fullEnemyWinRate = 0.0;
	for (auto palyerInfo:battlePlayerList)
	{
		fullEnemyWinRate += palyerInfo->getWinRate();
	}
	return fullEnemyWinRate / (battlePlayerList.count()*1.0);
}
