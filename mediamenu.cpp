#include "mediamenu.h"

//реализация параметров меню
MediaMenu::MediaMenu(QWidget* pwgt):QMenu(pwgt)
{
    //выделить память и применить дизайн
    menuStyleCSS = new QFile(":/menuStyle.css");
    menuStyleCSS->open(QFile::ReadOnly);
    this->setStyleSheet(QString(menuStyleCSS->readAll()));


    //создание в меню открытия
    mOpen = this->addAction(QObject::tr("&Open"));
    mOpen->setObjectName("Open");
    //разделитель
    this->addSeparator();
    playAction = this->addAction(QObject::tr("&Play"));
    stopAction = this->addAction(QObject::tr("&Stop"));
    pauseAction = this->addAction(QObject::tr("&Pause"));
    this->addSeparator();
    nextAction = this->addAction(QObject::tr("&Next"));
    previousAction = this->addAction(QObject::tr("Pre&vious"));
    this->addSeparator();
    //опции
    optionMenu = new QMenu(QObject::tr("Option&s"), this);
    this->addMenu(optionMenu);  //добавим выплывающие опции
    this->addSeparator();
    aboutAction = this->addAction(QObject::tr("About GMedia"));    //меню About
    this->addSeparator();
    //выход
    exitAction = this->addAction(QObject::tr("&Exit"), qApp, SLOT(quit()), Qt::CTRL + Qt::Key_E);

    //заполняем меню Options
    langMenu = new QMenu(QObject::tr("Language"), optionMenu);    //настройки языка
    optionMenu->addMenu(langMenu);  //добавить подменю Language в подменю Options

    designMenu = new QMenu(QObject::tr("Design"), optionMenu);    //настройка дизайна
    optionMenu->addMenu(designMenu);    //добавить подменю Design в подменю Options

    //заполняем языковое меню
    engAction = langMenu->addAction(QObject::tr("English"));
    rusAction = langMenu->addAction(QObject::tr("Russian"));
    deAction = langMenu->addAction(QObject::tr("Dutch"));
    frAction = langMenu->addAction(QObject::tr("French"));

    //заполняем меню дизайна
    defaultAction = designMenu->addAction(QObject::tr("Default"));
    magicAction = designMenu->addAction(("Fusion style"));
    mnitiAction = designMenu->addAction(("Windows style"));

    //создание  имен для меню
    rusAction->setObjectName("Rus");
    engAction->setObjectName("Eng");
    deAction->setObjectName("De");
    frAction->setObjectName("Fr");

    //имена для дизайна
    magicAction->setObjectName("Magic");
    defaultAction->setObjectName("Default");
    mnitiAction->setObjectName("Windows");
}

//чистка памяти
MediaMenu::~MediaMenu()
{
    delete menuStyleCSS;
}

//перевести интерфейс меню
void MediaMenu::retranslateMenu()
{
    //обновляем опции плеера
    mOpen->setText(tr("&Open"));
    playAction->setText(tr("&Play"));
    stopAction->setText(tr("&Stop"));
    pauseAction->setText(tr("&Pause"));
    nextAction->setText(tr("Next"));
    previousAction->setText(tr("Previous"));
    aboutAction->setText(tr("About GMedia"));
    //обновляем подменю Options
    optionMenu->setTitle(tr("Option&s"));
    exitAction->setText(tr("&Exit"));
    //обновляем подменю Design
    designMenu->setTitle(tr("Design"));
    //обновляем подменю Language
    langMenu->setTitle(tr("Language"));
    //обновить список языков
    engAction->setText(tr("English"));
    rusAction->setText(tr("Russian"));
    deAction->setText(tr("Dutch"));
    frAction->setText(tr("French"));
    //обновить список стилей
    defaultAction->setText(tr("Default"));
}

//открытие меню
void MediaMenu::contextMenuEvent(QContextMenuEvent *me)
{
    this->exec(me->globalPos());    //открывать меню там, где находится указатель мыши
}

//дизайн в стиле Виндовс
void MediaMenu::designWindowsMenu()
{
    //фактически чистим CSS
    menuStyleCSS->setFileName("");
    menuStyleCSS->open(QFile::ReadOnly);
    this->setStyleSheet(QString(menuStyleCSS->readAll()));
}

//дизайн в стиле Fusion
void MediaMenu::designFusionMenu()
{
    //фактически чистим CSS
    menuStyleCSS->setFileName("");
    menuStyleCSS->open(QFile::ReadOnly);
    this->setStyleSheet(QString(menuStyleCSS->readAll()));
}

//дизайн по умолчанию
void MediaMenu::designDefaultMenu()
{
    //выделить память и применить дизайн
    menuStyleCSS->setFileName(":/menuStyle.css");
    menuStyleCSS->open(QFile::ReadOnly);
    this->setStyleSheet(QString(menuStyleCSS->readAll()));
}

//получить указатель на меню Pause
QAction *MediaMenu::getPauseAction() const
{
    return pauseAction;
}

//получить указатель на меню Play
QAction *MediaMenu::getPlayAction() const
{
    return playAction;
}

//получить указатель на меню Stop
QAction *MediaMenu::getStopAction() const
{
    return stopAction;
}

//получить указатель на rusAction
QAction *MediaMenu::getRusAction() const
{
    return rusAction;
}

QAction *MediaMenu::getEngAction() const
{
    return engAction;
}

QMenu *MediaMenu::getLangMenu() const
{
    return langMenu;
}

QAction *MediaMenu::getAboutAction() const
{
    return aboutAction;
}
QAction *MediaMenu::getNextAction() const
{
    return nextAction;
}
QAction *MediaMenu::getPreviousAction() const
{
    return previousAction;
}




