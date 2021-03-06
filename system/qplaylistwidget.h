#ifndef QPLAYLISTWIDGET_H
#define QPLAYLISTWIDGET_H

#include <QDebug>

#include <QListWidget>
#include <QDropEvent>
#include <QMimeData>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "song.h"
#include "../phonograph.h"

class QPlaylistWidget: public QListWidget
{
public:
    QPlaylistWidget(): QListWidget() {

        this->setAcceptDrops( true );
        this->setDragDropMode( QAbstractItemView::InternalMove );
        this->viewport()->setAcceptDrops( true );
        this->setDropIndicatorShown( true );
        this->setDragEnabled( true );

    }
    QPlaylistWidget(QWidget *parent = 0): QListWidget(parent) {}
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent * event);
    void dragMoveEvent(QDragMoveEvent *event);
    bool dropMimeData ( int index, const QMimeData * data, Qt::DropAction action );

private:
    QWidget* getParentWindow();
};

#endif // QPLAYLISTWIDGET_H
