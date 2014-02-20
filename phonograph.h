#ifndef PHONOGRAPH_H
#define PHONOGRAPH_H

#include <cmath>
#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QFile>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include "system/musicdatabase.h"
#include "system/qsongitem.h"
#include "system/qplaylistitem.h"

namespace Ui {
class Phonograph;
}

class Phonograph : public QMainWindow
{
    Q_OBJECT

public:
    explicit Phonograph(QWidget *parent = 0);
    ~Phonograph();

    bool updateLibrary();
    void addItemToPlaylist(Song song);
    void addItemToLibrary(QTreeWidgetItem *topLevel, Song song);
    void updatePlaylist();

private slots:

    void setPlaybackTimer(qint64 position);

    void setMediaTime(qint64 duration);

    void setMediaPosition(int position);

    void on_library_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_stop_clicked();

    void on_volume_valueChanged(int value);

    void on_mute_toggled(bool checked);

    void on_play_clicked(bool checked);

    void on_playlist_itemDoubleClicked(QListWidgetItem *item);

    void on_skip_backward_clicked();

    void on_skip_forward_clicked();

private:
    // UI variable
    Ui::Phonograph *ui;

    // Music library variable
    MusicDatabase *library;

    // Media player stuff
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
};

#endif // PHONOGRAPH_H
