#include "qplaylistwidget.h"

void QPlaylistWidget::dragEnterEvent(QDragEnterEvent *event) {

  // Accept if there's Json
  if (event->mimeData()->hasFormat("application/json")) {

      event->acceptProposedAction();
      //QListWidget::dragEnterEvent( event );

  } else if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")) {

       event->acceptProposedAction();

  } else {

      event->ignore();

  }

}

void QPlaylistWidget::dragMoveEvent(QDragMoveEvent *event) {

    // Accept if there's Json
    if (event->mimeData()->hasFormat("application/json")) {

        //event->acceptProposedAction();
        event->accept();
        //QListWidget::dragMoveEvent( event );

    } else if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")) {

        event->acceptProposedAction();
        QListWidget::dragMoveEvent( event );

   } else {

        event->ignore();

    }

}

void QPlaylistWidget::dropEvent(QDropEvent * event) {

    // Get pointer to main window in order to call functions from that class
    Phonograph *mainWindow = (Phonograph *)this->getParentWindow();

    // First check if it is an internal move
    if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")) {

        // Show message
        mainWindow->showStatus( tr("Rearranging...") );

        // Set to move action and call parent class default action which will result to internal move according to settings
        event->setDropAction( Qt::MoveAction );
        QListWidget::dropEvent( event );

        // Call function to rearrange media playlist
        mainWindow->updatePlaylist();

        // Hide status
        mainWindow->hideStatus();

        return;

    }    

    // Get data
    QByteArray data = event->mimeData()->data("application/json");

    // Parse JSON
    QJsonDocument doc = QJsonDocument::fromJson( data );

    // Get the array of songs
    QJsonArray array = doc.array();


    if (array.count() > 0) {

        if (array[0].toObject().contains("playlist")) {

            // Show message
            mainWindow->showStatus( tr("Loading playlist...") );

            mainWindow->loadPlaylist(array[0].toObject().value( "playlist" ).toString());
        }

        else {


            // Show message
            mainWindow->showStatus( tr("Adding...") );

            QList< Song > listOfSongs;
            Song tmp;
            for (int i = 0; i < array.count(); i++) {

                // Convert Json object to Song object
                tmp.composer = array[i].toObject().value( "composer" ).toString();
                tmp.filename = array[i].toObject().value( "filename" ).toString();
                tmp.id = array[i].toObject().value( "id" ).toInt();
                tmp.performer1 = array[i].toObject().value( "performer1" ).toString();
                tmp.title = array[i].toObject().value( "title" ).toString();
                tmp.year = array[i].toObject().value( "year" ).toString();

                // Push in song list
                listOfSongs.push_back( tmp );

            }

            // Add songs to playlist
            mainWindow->addItemsToPlaylist( listOfSongs );

        }

    }

    // Hide status
    mainWindow->hideStatus();

}

bool QPlaylistWidget::dropMimeData ( int index, const QMimeData * data, Qt::DropAction action ) {
    qDebug() << "keftedakia: " << data->data("application/json");
    qDebug() << "index: " << index;

    return QListWidget::dropMimeData(index, data, action);
}

/**
 * @brief QPlaylistWidget::getParentWindow
 * @return The widget's parent window
 */
QWidget* QPlaylistWidget::getParentWindow() {

    // Loop until we reach the top level wiget
    QWidget *widget = this;
    while (widget->parentWidget()) {

        widget = widget->parentWidget();

    }

    return widget;

}
