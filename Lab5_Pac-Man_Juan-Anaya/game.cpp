#include "game.h"

Game::Game()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(457, 505);

    scene = new QGraphicsScene();
    Pacman = new Personaje();;
    cPacman = new Personaje();
    tPacman = new QTimer();

    scene->setSceneRect(0,0, 455, 503);
    setScene(scene);
    scene->addPixmap(QPixmap(":/Imagenes/Nivel1.png"));

    nivel1.leerMuros("Mapa.txt");
    nivel1.leerComida("Monedas.txt");
    for(int i=0; i<nivel1.sizeComida(); ++i)
        scene->addItem(nivel1.atComida(i));

    direccion = "";
    fdireccion = "";

    scene->addItem(Pacman->getCuerpo());

    tPacman->start(8);
    connect(tPacman, &QTimer::timeout, this, &Game::moverPersonaje);
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up || event->key() == Qt::Key_W){
        fdireccion = "Arriba";
    }
    else if(event->key() == Qt::Key_Down || event->key() == Qt::Key_S){
        fdireccion = "Abajo";
    }
    else if(event->key() == Qt::Key_Right || event->key() == Qt::Key_D){
        fdireccion = "Derecha";
    }
    else if(event->key() == Qt::Key_Left || event->key() == Qt::Key_A){
        fdireccion = "Izquierda";
    }
}

bool Game::colisionaconunitem()
{
    cPacman->setPosX(Pacman->getPosX());
    cPacman->setPosY(Pacman->getPosY());
    cPacman->setX_Y(mover(fdireccion));
    for(int i=0; i<nivel1.sizeMuros(); ++i){
        if(cPacman->getCorteza()->collidesWithItem(nivel1.atMuros(i)))
            return true;
    }
    return false;
}

void Game::moverPersonaje()
{
    Pacman->setX_Y(mover(direccion));
    for(int i=0; i<nivel1.sizeComida(); ++i){
        if(Pacman->getCentro()->collidesWithItem(nivel1.atComida(i))){
            scene->removeItem(nivel1.atComida(i));
            nivel1.removeMoneda(i);
        }
    }
    if(Pacman->getPosX()<-32)
        Pacman->setPosX(453);
    if(Pacman->getPosX()>453)
        Pacman->setPosX(-32);
    if(not colisionaconunitem()){
        direccion = fdireccion;
    }
    for(int i=0; i<nivel1.sizeMuros(); ++i){
        if(Pacman->getCorteza()->collidesWithItem(nivel1.atMuros(i))){
            Pacman->setX_Y(mover("-"+direccion));
            direccion = "";
        }
    }
}

QList<int> Game::mover(string d)
{
    if(d == "Arriba" || d == "-Abajo")
        return {0,-1};
    else if(d == "Abajo" || d == "-Arriba")
        return {0,1};
    else if(d == "Derecha" || d == "-Izquierda")
        return {1,0};
    else if(d == "Izquierda" || d == "-Derecha")
        return {-1,0};
    return {0,0};
}
