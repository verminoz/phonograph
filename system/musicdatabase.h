#ifndef MUSICDATABASE_H
#define MUSICDATABASE_H

#include <QDebug>

#include <QVariant>
#include <QUrl>
#include <QList>
#include <QHash>
#include "song.h"
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "databasecache.h"

class MusicDatabase {
private:
    QSqlDatabase database;
    DatabaseCache *cache;

    // Database login info
    QString host;
    int port;
    QString username;
    QString password;
    QString dbname;

    // Error stack
    QList<QString> errors;

    QString normalizeUrl(QString url);


public:
    /* Constructors & Destructors */
    MusicDatabase();
    MusicDatabase(QString host, int port, QString username, QString password, QString dbname);
    ~MusicDatabase();

    /* Getters and setters */
    // Getters
    QString getHost();
    int getPort();
    QString getUsername();
    QString getDBName();
    // Setters
    void setHost(QString host);
    void setPort(int port);
    void setUsername(QString username);
    void setPassword(QString password);
    void setDBName(QString dbname);

    /* Error stack */
    QList<QString> getErrors();
    QString getLastError();

    /* API functions */
    bool connect();
    bool update();
    void disconnect();
    bool isConnected();
    int getRecordCount();
    QString getFilename(int id);
    QHash<int, QString> getFilename(QList<int> ids);

    QList<Song> songs;
};

#endif // MUSICDATABASE_H
