#include "phonograph.h"
#include "ui_phonograph.h"
#include <string>
#include <sstream>
#include <QGraphicsDropShadowEffect>
#include <QStyleFactory>

/*** Constructor & destructor ***/

Phonograph::Phonograph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Phonograph) {

    QStyleFactory styleFactory;
    this->setStyle(styleFactory.create("plastique"));

    // Setup the UI
    ui->setupUi(this);

    // Setup the flags
    this->isDialogShown = false;
    this->wasMinimized = false;

    /** Setup some CSS **/
    ui->mainframe->setStyleSheet( "QFrame#mainframe { border-image: url(:/images/background/theme/diskos-25-leivadia.jpg); }" );
    ui->playerFrame->setStyleSheet("QFrame#playerFrame { background-color: rgba(102, 102, 102, 200); }");

    // Add shadow effects to several GUI elements for better visualization
    QGraphicsDropShadowEffect *nowPLayingEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *categorizeByLabelEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *volumeLabelEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *startTimeLabelEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *endTimeLabelEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *nowComposerLabelEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *nowPerformerLabelEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *nowTitleLabelEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *lyricsSourceLabelEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *nowPerformerEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *nowTitleEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *nowComposerEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *libraryEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *savedPlaylistEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *playlistEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *descriptionLabelEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *descriptionEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *nowYearLabelEffect = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *nowYearEffect = new QGraphicsDropShadowEffect(this);

    nowPLayingEffect->setBlurRadius(1);
    nowPLayingEffect->setColor(QColor("#000000"));
    nowPLayingEffect->setOffset(1,1);

    categorizeByLabelEffect->setBlurRadius(1);
    categorizeByLabelEffect->setColor(QColor("#000000"));
    categorizeByLabelEffect->setOffset(1,1);

    volumeLabelEffect->setBlurRadius(1);
    volumeLabelEffect->setColor(QColor("#000000"));
    volumeLabelEffect->setOffset(1,1);

    startTimeLabelEffect->setBlurRadius(1);
    startTimeLabelEffect->setColor(QColor("#000000"));
    startTimeLabelEffect->setOffset(1,1);

    endTimeLabelEffect->setBlurRadius(1);
    endTimeLabelEffect->setColor(QColor("#000000"));
    endTimeLabelEffect->setOffset(1,1);

    nowComposerLabelEffect->setBlurRadius(1);
    nowComposerLabelEffect->setColor(QColor("#000000"));
    nowComposerLabelEffect->setOffset(1,1);

    nowPerformerLabelEffect->setBlurRadius(1);
    nowPerformerLabelEffect->setColor(QColor("#000000"));
    nowPerformerLabelEffect->setOffset(1,1);

    nowTitleLabelEffect->setBlurRadius(1);
    nowTitleLabelEffect->setColor(QColor("#000000"));
    nowTitleLabelEffect->setOffset(1,1);

    lyricsSourceLabelEffect->setBlurRadius(1);
    lyricsSourceLabelEffect->setColor(QColor("#000000"));
    lyricsSourceLabelEffect->setOffset(1,1);

    nowPerformerEffect->setBlurRadius(1);
    nowPerformerEffect->setColor(QColor("#000000"));
    nowPerformerEffect->setOffset(1,1);

    nowTitleEffect->setBlurRadius(1);
    nowTitleEffect->setColor(QColor("#000000"));
    nowTitleEffect->setOffset(1,1);

    nowComposerEffect->setBlurRadius(1);
    nowComposerEffect->setColor(QColor("#000000"));
    nowComposerEffect->setOffset(1,1);

    libraryEffect->setBlurRadius(1);
    libraryEffect->setColor(QColor("#000000"));
    libraryEffect->setOffset(1,1);

    savedPlaylistEffect->setBlurRadius(1);
    savedPlaylistEffect->setColor(QColor("#000000"));
    savedPlaylistEffect->setOffset(1,1);

    playlistEffect->setBlurRadius(1);
    playlistEffect->setColor(QColor("#000000"));
    playlistEffect->setOffset(1,1);

    descriptionLabelEffect->setBlurRadius(1);
    descriptionLabelEffect->setColor(QColor("#000000"));
    descriptionLabelEffect->setOffset(1,1);

    descriptionEffect->setBlurRadius(1);
    descriptionEffect->setColor(QColor("#000000"));
    descriptionEffect->setOffset(1,1);

    nowYearLabelEffect->setBlurRadius(1);
    nowYearLabelEffect->setColor(QColor("#000000"));
    nowYearLabelEffect->setOffset(1,1);

    nowYearEffect->setBlurRadius(1);
    nowYearEffect->setColor(QColor("#000000"));
    nowYearEffect->setOffset(1,1);

    this->ui->playingNowLabel->setGraphicsEffect(nowPLayingEffect);
    this->ui->categorizeByLabel->setGraphicsEffect(categorizeByLabelEffect);
    this->ui->volume_label->setGraphicsEffect(volumeLabelEffect);
    this->ui->startTimeLabel->setGraphicsEffect(startTimeLabelEffect);
    this->ui->endTimeLabel->setGraphicsEffect(endTimeLabelEffect);
    this->ui->nowComposerLabel->setGraphicsEffect(nowComposerLabelEffect);
    this->ui->nowTitleLabel->setGraphicsEffect(nowTitleLabelEffect);
    this->ui->nowPerformerLabel->setGraphicsEffect(nowPerformerLabelEffect);
    this->ui->lyricsSourceLabel->setGraphicsEffect(lyricsSourceLabelEffect);
    this->ui->nowTitle->setGraphicsEffect(nowTitleEffect);
    this->ui->nowPerformer->setGraphicsEffect(nowPerformerEffect);
    this->ui->nowComposer->setGraphicsEffect(nowComposerEffect);
    this->ui->library->setGraphicsEffect(libraryEffect);
    this->ui->savePlaylist->setGraphicsEffect(savedPlaylistEffect);
    this->ui->playlist->setGraphicsEffect(playlistEffect);
    this->ui->descriptionLabel->setGraphicsEffect(descriptionLabelEffect);
    this->ui->descriptionField->setGraphicsEffect(descriptionEffect);
    this->ui->nowYearLabel->setGraphicsEffect(nowYearLabelEffect);
    this->ui->nowYear->setGraphicsEffect(nowYearEffect);

    this->ui->descriptionField->setWordWrap(true);
    this->ui->descriptionScrollArea->setFrameShape(QFrame::NoFrame);

    this->ui->libraryTabWidget->setStyleSheet("QTabWidget,QTabWidget::pane,QTabBar { background-color: rgb(117, 117, 117, 200); border: 0px; }");
    this->ui->tabWidget->setStyleSheet("QTabWidget,QTabWidget::pane,QTabBar { background-color: rgb(117, 117, 117, 200); border: 0px; }");

    /** --------------------- **/

    // Setup system tray
    this->createTrayIcon();
    this->spawnTrayMenu();

    // Setup player and playlist
    this->playlist = new QMediaPlaylist;
    this->player = new QMediaPlayer(this, QMediaPlayer::StreamPlayback);
    this->player->setPlaylist( this->playlist );
    this->player->setVolume( this->ui->volume->value() );

    // Useful signals
    connect(this->player, SIGNAL(currentMediaChanged(QMediaContent)), this, SLOT(setPlayingSongLabel(QMediaContent)));
    connect(this->player, SIGNAL(positionChanged(qint64)), this, SLOT(setPlaybackTimer(qint64)));
    connect(this->ui->seeker, SIGNAL(sliderMoved(int)), this, SLOT(setMediaPosition(int)));
    connect(this->player, SIGNAL(durationChanged(qint64)), this, SLOT(setMediaTime(qint64)));

    // Create context menus
    this->createContextMenus();

    // Enable drag and drop for QListWidget and QTreeWidget
    /** TO-DO: Difficulties in implementing the drag & drop functionality **/
    this->ui->library->setDragEnabled(true);
    this->ui->library->setDragDropMode(QAbstractItemView::DragOnly);
    this->ui->savedPlaylists->setDragEnabled(true);
    this->ui->savedPlaylists->setDragDropMode(QAbstractItemView::DragOnly);
    this->ui->playlist->setDragDropMode(QAbstractItemView::DragDrop);
    this->ui->playlist->setAcceptDrops(true);
    this->ui->playlist->setDefaultDropAction(Qt::CopyAction);

}

void Phonograph::showEvent(QShowEvent *event) {

    // Check flag to avoid execution during restoring from system tray or from minimized
    if (!this->wasMinimized) {

        QMainWindow::showEvent(event);
        QTimer::singleShot(0, this, SLOT(afterShowEvent()));
        this->wasMinimized = true;

    }
}

void Phonograph::afterShowEvent() {

    // Update library
    this->updateLibrary();

    // Load application settings
    this->loadSettings();

    // Load the user's playlists
    this->loadPlaylists();

}

Phonograph::~Phonograph() {

    // Save settings when going out
    this->saveSettings();

    delete library;
    delete player;
    delete playlist;
    delete ui;
}

/*****************/
/*** Functions ***/
/*****************/

/**
 * @brief loadSettings
 * Loads all settings saved with QSettings
 */
void Phonograph::loadSettings() {

    // Initialize a QSettings object
    QSettings settings("RebetikoSealabs", "Phonograph");

    // Player settings
    this->ui->volume->setValue( settings.value( "player/volume" , 50 ).toInt() );
    this->ui->mute->setChecked( settings.value( "player/mute" , false ).toBool() );

    // Application settings
    //this->ui->categorizeBySelect->setCurrentIndex( settings.value( "appl/categorizeby" , 0).toInt() );

    // Set language
    this->currentLanguage = settings.value( "appl/language" , "en" ).toString();

    if (this->currentLanguage == "en") {

        this->ui->actionEnglish->setChecked( true );
        on_actionEnglish_triggered( true );

    } else if (this->currentLanguage == "gr") {

        this->ui->actionGreek->setChecked( true );
        on_actionGreek_triggered( true );

    } else if (this->currentLanguage == "dk") {

        this->ui->actionDansk->setChecked( true );
        on_actionDansk_triggered( true );

    }

}

/**
 * @brief saveSettings
 * Saves all the application's settings using QSettings
 */
void Phonograph::saveSettings() {

    // Initialize a QSettings object
    QSettings settings("RebetikoSealabs", "Phonograph");

    // Clear settings first
    settings.clear();

    // General settings
    settings.setValue( "appl/language" , this->currentLanguage );
    settings.setValue( "appl/categorizeby" , this->ui->categorizeBySelect->currentIndex() );

    // Player settings
    settings.setValue( "player/volume" , this->ui->volume->value() );
    settings.setValue( "player/mute" , this->ui->mute->isChecked() );

    // Explicitly sync
    settings.sync();

}

/**
 * @brief Phonograph::switchLanguage
 * @param lang
 * Switches language on the entire application
 */
void Phonograph::switchLanguage() {

    // Get the app directory
    QString appDir = QApplication::applicationDirPath();

    // Setup translator
    QTranslator phonographTranslator;
    if (phonographTranslator.load(appDir + QString("/languages/phonograph_%1.qm").arg(this->currentLanguage))) {
        qApp->installTranslator(&phonographTranslator);
         this->ui->retranslateUi(this);
    }

}

void Phonograph::createContextMenus() {

    // Create actions
    QAction* libraryAction1 = new QAction(tr("Delete playlist"), ui->savedPlaylists);
    QAction* libraryAction2 = new QAction(tr("Add to playlist..."), this->ui->library);
    QAction* libraryAction3 = new QAction(tr("Add to current playlist"), this->ui->library);
    QAction* libraryAction4 = new QAction(tr("Remove from playlist"), this->ui->library);
    QAction* libraryAction5 = new QAction(tr("Add to playlist..."), this->ui->playlist);
    QAction* libraryAction6 = new QAction(tr("View playlist"), this->ui->playlist);

     // Connect the signals
    QSignalMapper* mapper = new QSignalMapper(this);
    connect(libraryAction2, SIGNAL(triggered()), mapper, SLOT(map()));
    connect(libraryAction5, SIGNAL(triggered()), mapper, SLOT(map()));
    mapper->setMapping(libraryAction2, "library");
    mapper->setMapping(libraryAction5, "current");
    connect(mapper, SIGNAL(mapped(QString)), this, SLOT(addToExistingPlaylist(const QString&)));
    connect(libraryAction1, SIGNAL(triggered()), this, SLOT(deletePlaylist()));
    connect(libraryAction3, SIGNAL(triggered()), this, SLOT(addToCurrPlaylist()));
    connect(libraryAction4, SIGNAL(triggered()), this, SLOT(on_removePlaylistItem_clicked()));
    connect(libraryAction6, SIGNAL(triggered()), this, SLOT(editPlaylist()));

    // Add the actions
    this->ui->savedPlaylists->addAction(libraryAction6);
    this->ui->savedPlaylists->addAction(libraryAction1);
    this->ui->library->addAction(libraryAction2);
    this->ui->library->addAction(libraryAction3);
    this->ui->playlist->addAction(libraryAction4);
    this->ui->playlist->addAction(libraryAction5);

    // Configure the list widget to display actions as popup menus
    this->ui->savedPlaylists->setContextMenuPolicy(Qt::ActionsContextMenu);
    this->ui->library->setContextMenuPolicy(Qt::ActionsContextMenu);
    this->ui->playlist->setContextMenuPolicy(Qt::ActionsContextMenu);

}

/*** System tray stuffz **/

/**
 * @brief Phonograph::createTrayIcon
 * Initialize tray icon in window constructor
 */
void Phonograph::createTrayIcon() {

    // Initiliaze and set icon
    this->trayIcon = new QSystemTrayIcon();
    this->trayIcon->setIcon( QIcon(":/images/background/theme/oud01.ico") );
    this->trayIcon->setToolTip( "Phonograph" );

    // Show tray icon always
    this->trayIcon->show();

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

}

/**
 * @brief Phonograph::iconActivated
 * @param reason
 * When the tray icon is clicked
 */
void Phonograph::iconActivated(QSystemTrayIcon::ActivationReason reason) {

    // Get action list
    QList< QAction * > actions = this->trayIcon->contextMenu()->actions();

    switch (reason) {
        case QSystemTrayIcon::Trigger:
        case QSystemTrayIcon::DoubleClick:
            this->restoreWindow();
            break;
        case QSystemTrayIcon::MiddleClick:
             //this->showMessage();
            break;

        case QSystemTrayIcon::Context:

            if (actions.count() > 0) {
                // Modify the play/pause action
                actions[1]->setText( (this->player->state() == QMediaPlayer::PlayingState) ? "Pause" : "Play" );
                actions[1]->setIcon( (this->player->state() == QMediaPlayer::PlayingState) ? QIcon(":/multimedia/player/icons/media-playback-pause-8.png") : QIcon(":/multimedia/player/icons/media-playback-start-8.png") );

                // Modify the stop
                actions[2]->setDisabled( !(this->player->state() == QMediaPlayer::PlayingState) );

                // Modify restore
                actions[4]->setDisabled( !this->wasMinimized );
            }
            break;
       default:
            break;
    }
}

/**
 * @brief restoreWindow
 * Restores the window when it's minimized to tray
 */
void Phonograph::restoreWindow() {

    // Show window / hide tray icon
    this->show();
    //this->trayIcon->hide();
    //this->wasMinimized = false;

}

void Phonograph::showMessage() {

    trayIcon->showMessage("Phonograph", "Rebetiko", QSystemTrayIcon::Information, 3000);

}

/**
 * @brief Phonograph::spawnTrayMenu
 * Build menu for tray icon
 */
void Phonograph::spawnTrayMenu() {

    // Create actions
    QAction *previous = new QAction("Previous", this->trayIcon);
    previous->setIcon( QIcon(":/multimedia/player/icons/media-skip-backward-8.png") );

    QAction *play_pause = new QAction( "Play" , this->trayIcon);
    play_pause->setIcon( QIcon(":/multimedia/player/icons/media-playback-start-8.png") );

    QAction *stop = new QAction("Stop", this->trayIcon);
    stop->setIcon( QIcon(":/multimedia/player/icons/media-playback-stop-8.png") );

    QAction *next = new QAction("Next", this->trayIcon);
    next->setIcon( QIcon(":/multimedia/player/icons/media-skip-forward-8.png") );

    QAction *restore = new QAction("Restore", trayIcon);

    QAction *quit = new QAction("Quit", this->trayIcon);
    quit->setIcon( QIcon(":/phonograph/menu/icons/menu/application-exit-2.png") );

    // Connect the signals
    connect(previous, SIGNAL(triggered()), this, SLOT(on_skip_backward_clicked()));
    connect(play_pause, SIGNAL(triggered(bool)), this, SLOT(on_play_clicked(bool)));
    connect(stop, SIGNAL(triggered()), this, SLOT(on_stop_clicked()));
    connect(next, SIGNAL(triggered()), this, SLOT(on_skip_forward_clicked()));
    connect(restore, SIGNAL(triggered()), this, SLOT(restoreWindow()));
    connect(quit, SIGNAL(triggered()), this, SLOT(on_actionQuit_triggered()));

    // Create the menu
    QMenu *trayMenu = new QMenu();
    trayMenu->addAction( previous );
    trayMenu->addAction( play_pause );
    trayMenu->addAction( stop );
    trayMenu->addAction( next );
    trayMenu->addSeparator();
    trayMenu->addAction( restore );
    trayMenu->addAction( quit );

    // Set the menu
    this->trayIcon->setContextMenu( trayMenu );

}

/**
 * @brief Phonograph::closeEvent
 * @param event
 * Override close event (user presses X on top right)
 */
void Phonograph::closeEvent (QCloseEvent *event) {

    // Ignore the default action
    event->ignore();

    // Show system tray icon
    //this->trayIcon->show();

    // Hide window
    this->hide();

    // Set flag
    //this->wasMinimized = true;

}

/* Functions that sets the current playing media's current playback time */
void Phonograph::setPlaybackTimer(qint64 position) {

    // Calculate times
    int seconds = ( position / 1000 ) % 60;
    int minutes = round( ((position - seconds) / 1000) / 60 );

    // Set the label
    this->ui->startTimeLabel->setText( QString().sprintf("%02d", minutes) + QString(":") + QString().sprintf("%02d", seconds) );

    // Kata vasi den yparxei logos na mi setaristei ki auto edw. Kalytera to signal na einai syndedemeno me mia synartisi
    // Set new slider position, since we set it to tenths of seconds we can just apply directly
    if (!this->ui->seeker->isSliderDown()) {
        this->ui->seeker->setSliderPosition( round(position / 100) );
    }

}

/* Functions that sets the current playing media's total playback time */
void Phonograph::setMediaTime(qint64 duration) {

    // Calculate times
    int seconds = ( duration / 1000 ) % 60;
    int minutes = round( ((duration - seconds) / 1000) / 60 );

    // Set the label
    this->ui->endTimeLabel->setText( QString().sprintf("%02d", minutes) + QString(":") + QString().sprintf("%02d", seconds) );

    // Change the seeker range to achieve smoother scrolling. Set to tenths of seconds.
    this->ui->seeker->setRange(0, round(duration / 100) - 1);

}

/* Function used as slot for enabling media seeking with QSlider */
void Phonograph::setMediaPosition(int position) {

    if (this->player->isSeekable()){
        this->player->setPosition(100 * position);
    }

}

/* Slot that receives a signal when the media changes, so that several ui elements are updated */
void Phonograph::setPlayingSongLabel(QMediaContent content) {

    if (content.isNull() == false) {

        QPlaylistItem *currItem = (QPlaylistItem*)this->ui->playlist->item( this->playlist->currentIndex() );
        this->ui->playingNowLabel->setText(currItem->song.composer + " - " + currItem->song.title);
        this->ui->playingNowLabel->setAlignment(Qt::AlignCenter);
        QFont font("MS Shell Dlg 2", 12, QFont::Bold);
        this->ui->playingNowLabel->setFont(font);

        // Set current row in playlist
        this->ui->playlist->setCurrentRow( this->playlist->currentIndex() );

        // Fetch wiki article on composer or performer if composer is unknown or empty or nothing if both are empty
        if (currItem->song.composer.length() > 0 && currItem->song.composer.compare("Unknown") != 0) {

            this->fetchWikiArticle( currItem->song.composer );

        } else if (currItem->song.performer1.length() > 0) {

            this->fetchWikiArticle( currItem->song.performer1 );

        }

        // Set the Playing now tab stuffz
        this->ui->descriptionField->setText(currItem->song.description);
        this->ui->descriptionField->setStyleSheet("font: 11pt; color: white");
        this->ui->nowTitle->setText(currItem->song.title);
        this->ui->nowTitle->setStyleSheet("font: 16pt; color: white");
        this->ui->nowComposer->setText(currItem->song.composer);
        this->ui->nowComposer->setStyleSheet("font: 16pt; color: white");
        this->ui->nowPerformer->setText(currItem->song.performer1);
        this->ui->nowPerformer->setStyleSheet("font: 16pt; color: white");
        this->ui->nowYear->setText(currItem->song.year);
        this->ui->nowYear->setStyleSheet("font: 16pt; color: white");


    } else { //the playlist has finished

        this->ui->play->setChecked(false);

    }
}

/**
 * Update function
*/
bool Phonograph::updateLibrary() {
    // Show status message
    showStatus( tr("Syncing database...") );

    this->ui->library->clear();
    QString host("rebetiko.sealabs.net");
    int port = 33306;
    QString dbname("rebetikosongs");

    // Get username and password from file
    QFile credentialsFile("credentials.txt");
    credentialsFile.open(QFile::ReadOnly); // Open file
    QTextStream fileStream(&credentialsFile); // Set stream
    QString line = fileStream.readAll().trimmed(); // Get the data trimmed
    QString username = line.split(",")[0];
    QString password = line.split(",")[1];
    //QString username( "" );
    //QString password( "" );

    // Create a music database object
    this->library = new MusicDatabase(host, port, username, password, dbname);

    // Try to update
    if (this->library->update()) {
        qDebug() << "Found " << this->library->songs.length() << " songs";

        this->categorizeBySelect(this->ui->categorizeBySelect->currentIndex());

    } else {
        qDebug() << this->library->getLastError();
    }

    hideStatus();
    return true;
}

void Phonograph::addItemToLibrary(QTreeWidgetItem *topLevel, Song song, int categorizeBy) {

    // Create the new item
    QSongItem *newSong = new QSongItem();
    newSong->setText(0, song.title + " (" + song.year + ")");
    newSong->setIcon(0, QIcon(":/phonograph/general/icons/songbird.png"));
    newSong->song = song;


    QString categorizeByTerm;
    if (categorizeBy == 0) {
        categorizeByTerm = song.composer;
    } else {
        categorizeByTerm = song.performer1;
    }

    // Look if the same artist is there
    int j, found = -1;
    for (j = 0; j < topLevel->childCount(); j++) {
        if ( topLevel->child(j)->text(0) == categorizeByTerm) {
            found = j;
            break;
        }
    }

    QTreeWidgetItem *newArtist;
    if (found == -1) {

        // If artist not found there, add it
        newArtist = new QTreeWidgetItem();
        newArtist->setText(0, categorizeByTerm);
        topLevel->addChild( newArtist );

        // Add icon to it
        newArtist->setIcon(0, QIcon(":/phonograph/general/icons/view-media-artist.png"));

        // Finally add the song to it
        newArtist->addChild( newSong );

    } else {

        newArtist = topLevel->child(j);

    }

    // Finally add the song to it
    newArtist->addChild( newSong );

}

/**
 * @brief Phonograph::addItemToPlaylist
 * @param song
 * Adds a new song to the playlist
 */
void Phonograph::addItemToPlaylist(Song song, int pos) {

    // Create the item object
    QPlaylistItem *newItem = new QPlaylistItem();
    newItem->setText( song.composer + QString(" - ") + song.performer1 + QString(" - ") + song.title );
    newItem->setIcon( QIcon(":/phonograph/general/icons/songbird.png") );
    newItem->song = song;

    // ...put the item on the GUI playlist...
    this->ui->playlist->addItem( newItem );
    // ...and to the media playlist
    QString url = this->library->getFilename( song.id );

    // Update song with filename
    newItem->song.filename = url;
    if (pos > 0) {

        this->playlist->insertMedia( pos, QUrl(url));

    } else {

        this->playlist->addMedia( QUrl(url) );

    }
}

/**
 * @brief Phonograph::addItemsToPlaylist
 * @param songs
 * Adds many songs at onceto the playlist
 */
void Phonograph::addItemsToPlaylist(QList<Song> songs, int pos) {

    // Get all the songs IDs
    QList<int> ids;
    for (int i = 0; i < songs.count(); i++) {
        ids.push_back( songs[i].id );
    }

    // Fetch the filenames into a lookup table
    QHash<int, QString> filenames = this->library->getFilename( ids );

    //if (filenames.size() == songs.size()) {

        QList< QMediaContent > itemList;
        for (int i = 0; i < songs.size(); i++) {

            // Set the real filename
            songs[i].filename = filenames.value( songs[i].id );

            // Create the item object
            QPlaylistItem *newItem = new QPlaylistItem();
            newItem->setText( songs[i].composer + QString(" - ") + songs[i].performer1 + QString(" - ") + songs[i].title );
            newItem->setIcon( QIcon(":/phonograph/general/icons/songbird.png") );
            newItem->song = songs[i];

            // ...put the item on the GUI playlist...
            this->ui->playlist->addItem( newItem );
            // ...and to the media playlist
            if (pos > 0) {

                itemList.push_back( QUrl( filenames.value( songs[i].id ) ) );

            } else {

                this->playlist->addMedia( QUrl( filenames.value( songs[i].id ) ) );

            }
        }

        if (pos > 0) {

            this->playlist->insertMedia( pos, itemList );

        }
    //}
}

/**
 * @brief Phonograph::updatePlaylist
 * This function updates the QMediaPlaylist object with the list's contents
 * Syncronize media playlist to UI playlist
 */
void Phonograph::updatePlaylist() {

    // Loop through UI playlist
    for (int i = 0; i < this->ui->playlist->count(); i++) {

        // Get the item by dynamic casting
        QPlaylistItem *item = dynamic_cast<QPlaylistItem *>(this->ui->playlist->item(i));
        if (item) {

            // Check the current item on the UI playlist against the media playlist
            if ( item->song.filename == this->playlist->media(i).canonicalUrl().toString() ) {

                // If it is the same then skip
                continue;

            } else {

                // If it is not the same then look if it exists somewhere else on the playlist
                int exists = -1;
                for (int j = 0; j < this->playlist->mediaCount(); j++) {

                    if (this->playlist->media(j).canonicalUrl() == QUrl(item->song.filename)) {
                        exists = j;
                        break;
                    }

                }

                // If it was found remove
                if (exists > 0) {

                    this->playlist->removeMedia(exists);

                }

                // And insert in the right place
                this->playlist->insertMedia( i, QUrl(item->song.filename) );

           }
        }
    }
}

/**
 * @brief Phonograph::loadPlaylists
 * List all of the users playlists on disk
 */
void Phonograph::loadPlaylists() {

    QDir directory( QCoreApplication::applicationDirPath() + QString("/playlists"));
    QStringList files = directory.entryList( QStringList("*.spl") );
    this->ui->savedPlaylists->clear();

    for (int i = 0; i < files.count(); i++) {

        QListWidgetItem *newItem = new QListWidgetItem();
        newItem->setText( files[i].left( files[i].indexOf(".") ) );
        newItem->setIcon( QIcon(":/phonograph/general/icons/folder-multimedia.png") );        
        this->ui->savedPlaylists->addItem( newItem );

    }
}

/**
 * @brief Phonograph::loadPlaylist
 * @param name
 * Load the user playlist named "name" from disk
 */
void Phonograph::loadPlaylist(QString name) {

    QThread::sleep(3);

    // Create a playlist object
    this->selectedPlaylist.setName( name );

    // Load the playlist
    this->selectedPlaylist.load();
    QList<Song> contents = this->selectedPlaylist.getPlaylist();

    // Stop player in case it's playing the current playlist and clear the latter
    this->on_stop_clicked();
    this->ui->playlist->clear();
    this->playlist->clear();

    // Add the songs
    this->addItemsToPlaylist( contents );

}

/**
 * @brief Phonograph::savePlaylist
 * @param name
 * Save playlist to disk
 */
void Phonograph::savePlaylist(QString name) {

    // Get song list from playlist items located on the list widget
    QList<Song> contents;

    for (int i = 0; i < this->ui->playlist->count(); i++) {
        QPlaylistItem *item = dynamic_cast<QPlaylistItem *>(this->ui->playlist->item(i));
        if (item) {
            contents.push_back( item->song );
        }
    }

    // Set the name and contents to the playlist object and save
    this->selectedPlaylist.setName( name );
    this->selectedPlaylist.setPlayist( contents );
    this->selectedPlaylist.save();
    this->loadPlaylists();

}

/**
 * @brief Phonograph::fetchWikiArticle
 * @param composer
 * Fetch wiki article for composer from rebetiko sealabs
 */
void Phonograph::fetchWikiArticle(QString composer) {
    //QString lang = this->ui->wikipedia_select_lang->currentText();
    //QString request_url = QString("http://") + lang + QString(".wikipedia.org/wiki/") + composer.replace( QString(" "), QString("_") );
    QString request_url = QString("http://rebetiko.sealabs.net/wiki/mediawiki/index.php/") + composer.replace( QString(" "), QString("_") );

    this->ui->wiki_view->setUrl( request_url );
}

/**
 * @brief Phonograph::fetchLyrics
 * @param title
 * Send a request to rebetiko sealabs to fetch the lyrics for the song if they are uploaded
 */
void Phonograph::fetchLyrics(QString title) {
    // Set the URL
    QString request_url = QString("http://rebetiko.sealabs.net/wiki/mediawiki/index.php/") + title.replace( QString(" "), QString("_") );

    // Initialize a network manager and connect the signal
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(parseLyrics(QNetworkReply*)));

    // Make GET request
    manager->get( QNetworkRequest( QUrl(request_url) ) );
}

/**
 * @brief Phonograph::parseLyrics
 * @param reply
 * Parse the reply to the lyrics request
 */
void Phonograph::parseLyrics(QNetworkReply* reply) {

    // Get the contents
    QString htmlContents( reply->readAll() );

    // Parse to get the bodyContent element
    QWebPage page;
    page.mainFrame()->setHtml( htmlContents );
    QWebElement parse = page.mainFrame()->documentElement();
    QWebElement result = parse.findFirst("div[id=bodyContent]");

    if (result.isNull()) {
        return;
    }

    // Strip HTML
    QString lyrics = result.toInnerXml();

    lyrics = lyrics.mid( lyrics.indexOf("</h2>") + 5 , lyrics.indexOf("<div") - lyrics.indexOf("</h2>") - 5 );
    lyrics = lyrics.replace( QRegExp("<<?.>") , "" ).replace( QRegExp("</<?.>") , "" ).replace( QRegExp("<!--.*-->") , "" ).replace( QRegExp("<.*>") , "" );

    // Print the lyrics
    this->ui->lyrics_display->setText( lyrics );
}

void Phonograph::executeStatus() {

}

/**
 * @brief Phonograph::showStatus
 * @param msg
 * Shows a splash-like dialog with a status message (msg) blocking the application
 */
void Phonograph::showStatus(QString msg) {
/*
    progress = new QProgressDialog(msg, "", 0, 2, this);
    progress->setMinimum( 0 );

    progress->setAutoClose( true );
    progress->setWindowModality(Qt::WindowModal);
    progress->setValue( 1 );
    */

    if (this->isDialogShown == true) {
        hideStatus();
        delete this->statusDialog;
    }

    // Create the dialog and set its settings
    this->statusDialog = new QDialog( this );
    this->statusDialog->setWindowOpacity( 0.72 );
    this->statusDialog->setWindowFlags( Qt::SplashScreen );
    this->statusDialog->setWindowModality( Qt::WindowModal );
    this->statusDialog->setFixedSize(220, 80);
    this->statusDialog->setEnabled( false );

    // Fix a layout for it
    this->statusDialog->setLayout( new QVBoxLayout() );

    // Add the label with the status message
    QLabel *label = new QLabel( this->statusDialog );
    label->setAlignment( Qt::AlignCenter );
    label->setFont( QFont("MS Shell Dlg 2", 15, QFont::Bold, true) );
    label->setText( msg );
    this->statusDialog->layout()->addWidget( label );

    // Show the dialog
    this->statusDialog->show();
    QCoreApplication::processEvents();

    // Set flag
    this->isDialogShown = true;

}

/**
 * @brief Phonograph::hideStatus
 * Hides the status message if it is shown
 */
void Phonograph::hideStatus() {
    /*
    progress->setValue( 2 );
    progress->close();
    */

    // Close window and unset flag
    this->statusDialog->hide();
    this->isDialogShown = false;

}

/**
 * @brief Phonograph::addSelectedItemsToCurrPlaylist
 * Adds selected items from library (songs or artists) to current playing list
 */
void Phonograph::addSelectedItemsToCurrPlaylist()
{
    // Get the selected items
    QList<QTreeWidgetItem *> selectedSongs = this->ui->library->selectedItems();

    // Loop through them and extract Song objects
    QList< Song > allSongs;
    for (int i = 0; i < selectedSongs.count(); i++) {

        // Cast to QSongItem to get Song object
        QSongItem *item = dynamic_cast<QSongItem *>(selectedSongs[i]);
        if (item) {

            // Put it in list
            allSongs.push_back( item->song );

        } else {

            for (int j = 0; j < selectedSongs[i]->childCount(); j++) {

                QSongItem *childItem = dynamic_cast<QSongItem *>(selectedSongs[i]->child(j));
                if (childItem) {

                    // Put it in list
                    allSongs.push_back( childItem->song );

                }
            }
        }
    }

    // If there where songs then call addItemsToPlaylist to add them
    if (allSongs.size() > 0) {
        this->addItemsToPlaylist( allSongs );
    }
}

// Method that categorizes the library according to the user's selection (Composer/Performer)
void Phonograph::categorizeBySelect(int index) {

    // Disable left sidebar since it shouldn't be touchable while updating
    // but also to give the user the knowledge that it is updating
    this->ui->sidebarleft->setEnabled( false );
    showStatus( tr("Sorting...") );

    // Clear library first
    this->ui->library->clear();

    // Add top level item
    QTreeWidgetItem *topLevel = new QTreeWidgetItem( this->ui->library );
    if (index == 0) {
        topLevel->setText(0, "Composers"); // 0 --> Categorize by composers
    } else {
        topLevel->setText(0, "Singers"); // 1 --> Categorize by singers
    }
    topLevel->setIcon(0, QIcon(":/phonograph/general/icons/folder-sound.png"));

    // Loop through the songs
    for (int i = 0; i < this->library->songs.length(); i++) {

        this->addItemToLibrary( topLevel , this->library->songs[i] , index );

    }

    // Sort and expand
    this->ui->library->sortItems(0, Qt::AscendingOrder);
    this->ui->library->expandItem( topLevel );

    // Re-enable the left sidebar
    this->ui->sidebarleft->setEnabled( true );
    hideStatus();

}

/****************/
/**** Events ****/
/****************/

/**
 * @brief Phonograph::deletePlaylist
 * Slot function for deleting a playlist
 */
void Phonograph::deletePlaylist() {

    if (this->ui->savedPlaylists->count() > 0) {
        if (this->ui->savedPlaylists->selectedItems().count() > 0) {
            // Get the selected playlist
            QString playlist = this->ui->savedPlaylists->currentItem()->text();

            // Delete it
            QPlaylist::deletePlaylist( playlist );

            // Delete the item from the list
            delete this->ui->savedPlaylists->item( this->ui->savedPlaylists->currentRow() );
        }
    }
}

/**
 * @brief Phonograph::editPlaylist
 * Slot function for editing a playlist
 */
void Phonograph::editPlaylist() {

    if (this->ui->savedPlaylists->count() > 0) {
        if (this->ui->savedPlaylists->selectedItems().count() > 0) {
            PlaylistEditDialog *playlistEdit = new PlaylistEditDialog(this, this->ui->savedPlaylists->currentItem());
            playlistEdit->setFixedSize(520, 437);
            playlistEdit->show();
        }
    }
}

/**
 * @brief Phonograph::addToPlaylist
 * Slot function for adding songs to a playlist
 */
void Phonograph::addToExistingPlaylist(QString source) {

    PlaylistsDialog *playlists = new PlaylistsDialog(this, source, this->ui->library, (QListWidget*) this->ui->playlist);
    playlists->setFixedSize(300, 437);
    playlists->show();

}

/**
 * @brief Phonograph::addToCurrPlaylist
 * Slot function for adding songs to current playing list
 */
void Phonograph::addToCurrPlaylist() {

    addSelectedItemsToCurrPlaylist();

}

void Phonograph::on_library_itemDoubleClicked(QTreeWidgetItem *item) {

    QSongItem *itemClicked = dynamic_cast<QSongItem *>(item);

    if (itemClicked) {

        this->addItemToPlaylist( itemClicked->song );

    } else {

        QList< Song > allSongs;
        for (int i = 0; i < item->childCount(); i++) {

            itemClicked = dynamic_cast<QSongItem *>(item->child(i));
            if (itemClicked) {
                allSongs.push_back( itemClicked->song );
            }

        }

        if (allSongs.size() > 0) {
            this->addItemsToPlaylist( allSongs );
        }
    }
}

void Phonograph::on_stop_clicked() {

    if ( this->player->state() == QMediaPlayer::PlayingState || this->player->state() == QMediaPlayer::PausedState) {

        this->player->stop();
        this->ui->play->setChecked( false );

    }

}

void Phonograph::on_volume_valueChanged(int value) {

    this->player->setVolume( value );

}

void Phonograph::on_mute_toggled(bool checked) {

    this->player->setMuted( checked );

}

void Phonograph::on_play_clicked(bool checked) {

    // Check if button is checked or not
    if (checked) {

        if (this->player->state() == QMediaPlayer::PausedState) {
            this->player->play();

        }  else if (!this->playlist->isEmpty()) {
            int current = this->ui->playlist->currentRow();
            if (current > -1) {
                this->playlist->setCurrentIndex( current );
                this->player->play();
            }
        }

    } else {

        if (this->player->state() == QMediaPlayer::PlayingState) {
            this->player->pause();
        }
    }
}

void Phonograph::on_playlist_itemDoubleClicked() {

    this->showStatus( tr("Loading...") );

    if (!this->playlist->isEmpty()) {

        int current = this->ui->playlist->currentRow();
        this->playlist->setCurrentIndex( current );
        this->player->play();
        this->ui->play->setChecked(true);

    }

    this->hideStatus();

}

void Phonograph::on_skip_backward_clicked() {
/*
    this->playlist->addMedia( QUrl("http://echidna-band.com/manifest/mp3/Manifests_Of_Human_Existence/08-Pendulum.mp3") );
    this->playlist->addMedia( QUrl::fromLocalFile("/home/verminoz/Music/giaf-giouf.mp3") );

    this->playlist->setCurrentIndex(0);

    this->player->play();
    qDebug() << "State: " << player->state();
    qDebug() << "Media State: " << player->mediaStatus();
    qDebug() << "Error: " << player->error() << " " << player->errorString();
    qDebug() << "Error: " << playlist->error() << " " << playlist->errorString();
*/
   if(this->playlist->previousIndex() != -1) {

        this->playlist->previous();

    }

}

void Phonograph::on_skip_forward_clicked() {

    if(this->playlist->nextIndex() != -1) {
        if (this->ui->playlist->count() > this->playlist->nextIndex()) {
            this->playlist->next();
        }
    }
}

void Phonograph::on_clearPlaylist_clicked() {

    this->ui->playlist->clear();
    this->playlist->clear();

}

void Phonograph::on_addPlaylistItem_clicked() {

    if (this->ui->libraryTabWidget->currentIndex() == 0) {
        addSelectedItemsToCurrPlaylist();
    }
    else {
        if (this->ui->savedPlaylists->count() > 0) {
            if (this->ui->savedPlaylists->selectedItems().count() > 0) {
                on_savedPlaylists_itemDoubleClicked(this->ui->savedPlaylists->currentItem());
            }
        }
    }
}

void Phonograph::on_removePlaylistItem_clicked() {

    // Get selected items
    QList<QListWidgetItem *> selectedSongs = this->ui->playlist->selectedItems();

    if (!this->playlist->isEmpty()) {

        for (int i = 0; i < selectedSongs.count(); i++){
            QPlaylistItem *itemSelected = dynamic_cast<QPlaylistItem *>(selectedSongs[i]);

            for(int j = 0; j < this->ui->playlist->count(); j++) {

                QPlaylistItem *playlistItem = dynamic_cast<QPlaylistItem *>(this->ui->playlist->item(j));
                if (itemSelected->song.id == playlistItem->song.id) {
                    delete this->ui->playlist->item(j);                    
                    this->playlist->removeMedia(j);
                    updatePlaylist();
                }
            }
        }
    }
}

void Phonograph::on_shuffle_clicked(bool checked) {

    if (checked) {

        this->ui->toolButton->setChecked(false);
        this->playlist->setPlaybackMode(QMediaPlaylist::Random);

    } else {

        this->playlist->setPlaybackMode(QMediaPlaylist::Sequential);

    }
}

void Phonograph::on_toolButton_clicked(bool checked) {

    if (checked) {

        this->ui->shuffle->setChecked(false);
        this->playlist->setPlaybackMode(QMediaPlaylist::Loop);

    }
    else {

        this->playlist->setPlaybackMode(QMediaPlaylist::Sequential);

    }
}

void Phonograph::on_seek_forward_clicked() {

    int pos = this->ui->seeker->sliderPosition();
    setMediaPosition(pos + 100);

}

void Phonograph::on_seek_backward_clicked() {

    int pos = this->ui->seeker->sliderPosition();
    setMediaPosition(pos - 100);

}

// About dialog trigger
void Phonograph::on_actionAbout_Phonograph_triggered() {

    AboutDialog *about = new AboutDialog(this);

    // Set language, size and then show it
    about->currentLanguage = this->currentLanguage;
    about->switchLanguage();
    about->setFixedSize(778, 437);
    about->show();

}

void Phonograph::on_savePlaylist_clicked() {

    QString name = this->ui->playlistName->text();

    if (name.length() == 0) {
        QMessageBox msgbox;
        msgbox.setText( "Please enter a name for your playlist" );
        msgbox.exec();
        this->ui->playlistName->setFocus();
        return;
    }

    this->savePlaylist(name);
    this->ui->playlistName->setText("");
    this->ui->libraryTabWidget->setCurrentIndex(1);
}

void Phonograph::on_searchLibraryText_textChanged(const QString &arg1) {

    // Check on which tab we are to search the appropriate list
    if (this->ui->libraryTabWidget->currentIndex() == 0) {

        // Take top level item of library
        QTreeWidgetItem* topLevel = this->ui->library->topLevelItem(0);

        // Loop through all of its items
        for (int i = 0; i < topLevel->childCount(); i++) {

            // If we matched the composer then show the composer and all of the songs and continue to next composer
            if ( topLevel->child(i)->text(0).toLower().contains(arg1.toLower())) {
                topLevel->child(i)->setHidden( false );
                for (int j = 0; j < topLevel->child(i)->childCount(); j++) {
                    topLevel->child(i)->child(j)->setHidden( false );
                }
                continue;
            }

            // If we didn't match the composer's name let's check if we can match any of the songs
            bool isThereMatch = false;
            for (int j = 0; j < topLevel->child(i)->childCount(); j++) {

                 topLevel->child(i)->child(j)->setHidden( ! topLevel->child(i)->child(j)->text(0).toLower().contains(arg1.toLower()));
                 isThereMatch |= topLevel->child(i)->child(j)->text(0).toLower().contains(arg1.toLower());

            }

            // If there was a song matched then the composer should be visible, if not then not :P
            topLevel->child(i)->setHidden( !isThereMatch );
        }

    } else {

        for (int i = 0; i < this->ui->savedPlaylists->count(); i++) {

            QListWidgetItem *item = this->ui->savedPlaylists->item(i);
            item->setHidden( !item->text().toLower().contains(arg1.toLower()));

        }
    }
}

void Phonograph::on_searchPlaylistText_textChanged(const QString &arg1) {

    for (int i = 0; i < this->ui->playlist->count(); i++) {

        QListWidgetItem *item = this->ui->playlist->item(i);
        item->setHidden( !item->text().toLower().contains(arg1.toLower()));

    }

}

void Phonograph::on_searchLibraryClear_clicked() {

    this->ui->searchLibraryText->clear();

}

void Phonograph::on_searchPlaylistClear_clicked() {

    this->ui->searchPlaylistText->clear();

}

void Phonograph::on_savedPlaylists_itemDoubleClicked(QListWidgetItem *item) {

    showStatus( tr("Loading playlist...") );

    this->ui->playlistName->setText( item->text() );
    this->loadPlaylist( item->text() );

    hideStatus();

}

void Phonograph::on_categorizeBySelect_currentIndexChanged(int index) {

    this->categorizeBySelect(index);

}

void Phonograph::on_actionQuit_triggered() {

    // Quit the application
    QApplication::quit();

}

void Phonograph::on_actionEnglish_triggered(bool checked) {

    if (checked) {

        this->ui->actionGreek->setChecked( false );
        this->ui->actionDansk->setChecked( false );
        this->currentLanguage = "en";
        this->switchLanguage();

    }

}

void Phonograph::on_actionGreek_triggered(bool checked) {

    if (checked) {

        this->ui->actionEnglish->setChecked( false );
        this->ui->actionDansk->setChecked( false );
        this->currentLanguage = "gr";
        this->switchLanguage();

    }

}

void Phonograph::on_actionDansk_triggered(bool checked) {

    if (checked) {

        this->ui->actionGreek->setChecked( false );
        this->ui->actionEnglish->setChecked( false );
        this->currentLanguage = "dk";
        this->switchLanguage();

    }

}

void Phonograph::on_delete_playlist_clicked()
{
    deletePlaylist();
}

void Phonograph::on_new_playlist_clicked()
{
    PlaylistNameDialog *playlistName = new PlaylistNameDialog();
    connect(playlistName, SIGNAL(loadPlaylists()), this, SLOT(loadPlaylists()));
    playlistName->setFixedSize(320, 64);
    playlistName->show();
}

void Phonograph::on_libraryTabWidget_currentChanged(int index)
{
    if (index == 0) this->ui->removePlaylistItem->setEnabled(true);
    else this->ui->removePlaylistItem->setEnabled(false);
}

void Phonograph::on_edit_playlist_clicked()
{
    editPlaylist();
}
