#include <QApplication>
#include <QSplashScreen>
#include <QIcon>
#include <game.h>

Game *jugar;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/Imagenes/Icono4.ico"));
    QCoreApplication::setApplicationName("Pacman");
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/Imagenes/Inicio.png"));
    splash->show();

    jugar = new Game();

    QTimer::singleShot(3000,splash,SLOT(close()));
    QTimer::singleShot(3100,jugar,SLOT(show()));

    return a.exec();
}
