#ifndef QPLAYLIST_H
#define QPLAYLIST_H

#include <QDebug>

#include <QCoreApplication>
#include <QDateTime>
#include <QFile>
#include "song.h"
#include <QDataStream>

class QPlaylist
{
    QString name;
    QDateTime created;
    QDateTime modified;

    QList<Song> playlist;

public:
    QPlaylist();
    QPlaylist(QString name);

    // Getters
    QString getName();
    QDateTime getCreated();
    QDateTime getModified();
    QList<Song> getPlaylist();

    // Setters
    void setName(QString name);
    void setPlayist(QList<Song> playlist);

    // I/O
    void load();
    void save();

    // Static functions
    static QString getOriginalPlaylistName();
    static void deletePlaylist(QString name);

    // Other
    void removeItem(QString item);
};

#endif // QPLAYLIST_H
