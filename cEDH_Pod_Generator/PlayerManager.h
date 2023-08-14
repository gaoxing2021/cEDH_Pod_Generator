#pragma once

#include <QObject>
#include <QMap>
#include <QString>

class PlayerInfo;
class PlayerManager : public QObject
{
	Q_OBJECT

public:
	
	static PlayerManager* getInstance();

	PlayerInfo* createNewPlayer(const QString& name);

	bool removePlayer(const QString& name);


	PlayerInfo* getPlayedInfo(const QString& name);
	QList<PlayerInfo*> getPlayedPlayerList(const QString& name);

	double enemyWinRate(const QString& name);

private:
	PlayerManager(QObject *parent = nullptr);
	~PlayerManager();

private:
	static PlayerManager* pManager;

	QMap<QString, PlayerInfo*> playerMap;

	QMap<QString, QList<PlayerInfo*>> battledPlayerMap;

signals:
	void newPlayerCreated(PlayerInfo* pPlayerInfo);
	void playerRemoved(const QString& name);
};
