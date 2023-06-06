#include "mainwindow1.h"
#include "ui_mainwindow1.h"

MainWindow1::MainWindow1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow1)
{




    ui->setupUi(this);

    escena=new QGraphicsScene(0,0,400,300);
    ui->graphicsView->setScene(escena);

    puntuacion = 0;
    moverIx1=false;
    moverDx1=false;
    moverUy1=false;
    moverDy1=false;

    ui->graphicsView->setBackgroundBrush(QBrush(Qt::black));

    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
    connect(this,SIGNAL(aviso(int)),this,SLOT(aumentarPuntos()));

    timer->start(33);

    bordeI=new QGraphicsRectItem(0,0,20,280);
    escena->addItem(bordeI);
    bordeI->setBrush(Qt::lightGray);

    bordeD=new QGraphicsRectItem(380,0,20,300);
    escena->addItem(bordeD);
    bordeD->setBrush(Qt::lightGray);

    bordeD=new QGraphicsRectItem(300,80,20,180);
    escena->addItem(bordeD);
    bordeD->setBrush(Qt::lightGray);

    bordeS=new QGraphicsRectItem(0,0,380,20);
    escena->addItem(bordeS);
    bordeS->setBrush(Qt::lightGray);

    bordeIn=new QGraphicsRectItem(0,280,380,20);
    escena->addItem(bordeIn);
    bordeIn->setBrush(Qt::lightGray);

    borde1=new QGraphicsRectItem(40,0,20,140);
    escena->addItem(borde1);
    borde1->setBrush(Qt::lightGray);

    borde1=new QGraphicsRectItem(340,0,20,140);
    escena->addItem(borde1);
    borde1->setBrush(Qt::lightGray);

    borde2=new QGraphicsRectItem(40,160,20,120);
    escena->addItem(borde2);
    borde2->setBrush(Qt::lightGray);

    borde2=new QGraphicsRectItem(340,160,20,120);
    escena->addItem(borde2);
    borde2->setBrush(Qt::lightGray);

    borde3=new QGraphicsRectItem(60,160,140,20);
    escena->addItem(borde3);
    borde3->setBrush(Qt::lightGray);

    borde3=new QGraphicsRectItem(200,160,80,20);
    escena->addItem(borde3);
    borde3->setBrush(Qt::lightGray);

    borde4=new QGraphicsRectItem(80,40,20,120);
    escena->addItem(borde4);
    borde4->setBrush(Qt::lightGray);

    borde4=new QGraphicsRectItem(80,160,20,80);
    escena->addItem(borde4);
    borde4->setBrush(Qt::lightGray);

    borde4=new QGraphicsRectItem(80,260,20,20);
    escena->addItem(borde4);
    borde4->setBrush(Qt::lightGray);

    borde4=new QGraphicsRectItem(120,80,20,60);
    escena->addItem(borde4);
    borde4->setBrush(Qt::lightGray);

    borde4=new QGraphicsRectItem(260,80,20,60);
    escena->addItem(borde4);
    borde4->setBrush(Qt::lightGray);

    borde4=new QGraphicsRectItem(120,240,200,20);
    escena->addItem(borde4);
    borde4->setBrush(Qt::lightGray);

    borde4=new QGraphicsRectItem(120,200,200,20);
    escena->addItem(borde4);
    borde4->setBrush(Qt::lightGray);

    borde5=new QGraphicsRectItem(100,40,120,20);
    escena->addItem(borde5);
    borde5->setBrush(Qt::lightGray);

    borde5=new QGraphicsRectItem(120,80,220,20);
    escena->addItem(borde5);
    borde5->setBrush(Qt::lightGray);

    borde5=new QGraphicsRectItem(160,120,100,20);
    escena->addItem(borde5);
    borde5->setBrush(Qt::lightGray);

    borde5=new QGraphicsRectItem(220,40,100,20);
    escena->addItem(borde5);
    borde5->setBrush(Qt::lightGray);


    pac=new jugador();
    escena->addItem(pac);
    //pac->setBrush(Qt::yellow);
    pac->setPos(30,30);



    l1=new QGraphicsLineItem(0,0,400,0);
    l2=new QGraphicsLineItem(0,0,0,300);
    l3=new QGraphicsLineItem(400,0,400,300);
    l4=new QGraphicsLineItem(0,300,400,300);
    escena->addItem(l1);
    escena->addItem(l2);
    escena->addItem(l3);
    escena->addItem(l4);


    bola0 = new miesfera();
    escena->addItem(bola0);
    bola0->setPos(35,35);

    bola1 = new gatorade();
    escena->addItem(bola1);
    bola1->setPos(262,122);

    bola9 = new botiquin();
    escena->addItem(bola9);
    bola9->setPos(302,122);
    bola00 = new miesfera();
    escena->addItem(bola00);
    bola00->setPos(302,122);

    bola10 = new corazon();
    escena->addItem(bola10);
    bola10->setPos(302,242);
    bola000 = new miesfera();
    escena->addItem(bola000);
    bola000->setPos(295,242);

    bola5 = new corazon();
    escena->addItem(bola5);
    bola5->setPos(82,42);
    bola0000 = new miesfera();
    escena->addItem(bola0000);
    bola0000->setPos(82,42);

    bola6 = new botiquin();
    escena->addItem(bola6);
    bola6->setPos(342,122);
    bola00000 = new miesfera();
    escena->addItem(bola00000);
    bola00000->setPos(342,122);

    bola8 = new chaleco();
    escena->addItem(bola8);
    bola8->setPos(340,80);

    bola3 = new chaleco();
    escena->addItem(bola3);
    bola3->setPos(81,200);

    bola4 = new gatorade();
    escena->addItem(bola4);
    bola4->setPos(40,280);

    bola15 = new miesfera();
    escena->addItem(bola15);
    bola15->setPos(370,270);

    enemigo1 = new Enemigo1();
    escena->addItem(enemigo1);
    enemigo1->setPos(40,160);

    enemigo2 = new Enemigo2();
    escena->addItem(enemigo2);
    enemigo2->setPos(160,140);

    enemigo22 = new Enemigo2();
    escena->addItem(enemigo22);
    enemigo22->setPos(120,222);

    enemigo3 = new Enemigo3();
    escena->addItem(enemigo3);
    enemigo3->setPos(380,150);

}

MainWindow1::~MainWindow1()
{
    delete escena;
    delete ui;
}

void MainWindow1::animar(){



    if(moverIx1 && pac->x()>30){
        if (pac->x()>24 && pac->x()<71 && pac->y()>145 && pac->y()<155){
            pac->setPos(pac->x()-2,pac->y());
        }
        if (pac->x()>110 && pac->x()<294 && pac->y()>145 && pac->y()<155){
            pac->setPos(pac->x()-2,pac->y());
        }
        if (pac->x()>70 && pac->x()<335 && pac->y()>25 && pac->y()<35){
            pac->setPos(pac->x()-2,pac->y());
        }
        if (pac->x()>110 && pac->x()<335 && pac->y()>65 && pac->y()<75){
            pac->setPos(pac->x()-2,pac->y());
        }
        if (pac->x()>150 && pac->x()<252 && pac->y()>105 && pac->y()<115){
            pac->setPos(pac->x()-2,pac->y());
        }
        if (pac->x()>110 && pac->x()<294 && pac->y()>185 && pac->y()<195){
            pac->setPos(pac->x()-2,pac->y());
        }
        if (pac->x()>110 && pac->x()<294 && pac->y()>225 && pac->y()<235){
            pac->setPos(pac->x()-2,pac->y());
        }
        if (pac->x()>70 && pac->x()<114 && pac->y()>247 && pac->y()<252){
            pac->setPos(pac->x()-2,pac->y());
        }
        if (pac->x()>110 && pac->x()<335 && pac->y()>265 && pac->y()<275){
            pac->setPos(pac->x()-2,pac->y());
        }
        if (pac->x()>330 && pac->x()<375 && pac->y()>147 && pac->y()<152){
            pac->setPos(pac->x()-2,pac->y());
        }
    }

    if(moverDx1 && pac->x()<370){
        if (pac->x()>24 && pac->x()<70 && pac->y()>145 && pac->y()<155){
            pac->setPos(pac->x()+2,pac->y());
        }
        if (pac->x()>109 && pac->x()<290 && pac->y()>145 && pac->y()<155){
            pac->setPos(pac->x()+2,pac->y());
        }
        if (pac->x()>65 && pac->x()<330 && pac->y()>25 && pac->y()<35){
            pac->setPos(pac->x()+2,pac->y());
        }
        if (pac->x()>100 && pac->x()<330 && pac->y()>65 && pac->y()<75){
            pac->setPos(pac->x()+2,pac->y());
        }
        if (pac->x()>145 && pac->x()<250 && pac->y()>105 && pac->y()<115){
            pac->setPos(pac->x()+2,pac->y());
        }
        if (pac->x()>105 && pac->x()<290 && pac->y()>185 && pac->y()<195){
            pac->setPos(pac->x()+2,pac->y());
        }
        if (pac->x()>105 && pac->x()<290 && pac->y()>225 && pac->y()<235){
            pac->setPos(pac->x()+2,pac->y());
        }
        if (pac->x()>65 && pac->x()<110 && pac->y()>247 && pac->y()<252){
            pac->setPos(pac->x()+2,pac->y());
        }
        if (pac->x()>100 && pac->x()<330 && pac->y()>265 && pac->y()<275){
            pac->setPos(pac->x()+2,pac->y());
        }
        if (pac->x()>324 && pac->x()<370 && pac->y()>145 && pac->y()<155){
            pac->setPos(pac->x()+2,pac->y());
        }
    }

    if(moverUy1 && pac->y()>30 ){
        if (pac->x()>25 && pac->x()<35){
            pac->setPos(pac->x(),pac->y()-2);
        }
        if (pac->x()>60 && pac->x()<80 && pac->y()>29 &&pac->y()<155){
            pac->setPos(pac->x(),pac->y()-2);
        }
        if (pac->x()>60 && pac->x()<80 && pac->y()>190 &&pac->y()<275){
            pac->setPos(pac->x(),pac->y()-2);
        }
        if (pac->x()>325 && pac->x()<335 && pac->y()>30 && pac->y()<75){
            pac->setPos(pac->x(),pac->y()-2);
        }
        if (pac->x()>325 && pac->x()<335 && pac->y()>110 && pac->y()<278){
            pac->setPos(pac->x(),pac->y()-2);
        }
        if (pac->x()>105 && pac->x()<115 && pac->y()>70 && pac->y()<155){
            pac->setPos(pac->x(),pac->y()-2);
        }
        if (pac->x()>147 && pac->x()<152 && pac->y()>110 && pac->y()<155){
            pac->setPos(pac->x(),pac->y()-2);
        }
        if (pac->x()>285 && pac->x()<295 && pac->y()>110 && pac->y()<195){
            pac->setPos(pac->x(),pac->y()-2);
        }
        if (pac->x()>105 && pac->x()<115 && pac->y()>190 && pac->y()<275){
            pac->setPos(pac->x(),pac->y()-2);
        }
        if (pac->x()>368 && pac->x()<375){
            pac->setPos(pac->x(),pac->y()-2);
        }
    }

    if(moverDy1 && pac->y()<270){
        if (pac->x()>25 && pac->x()<35){
            pac->setPos(pac->x(),pac->y()+2);
        }
        if (pac->x()>60 && pac->x()<80 && pac->y()>29 &&pac->y()<149){
            pac->setPos(pac->x(),pac->y()+2);
        }
        if (pac->x()>60 && pac->x()<80 && pac->y()>189 &&pac->y()<275){
            pac->setPos(pac->x(),pac->y()+2);
        }
        if (pac->x()>325 && pac->x()<335 && pac->y()>25 && pac->y()<70){
            pac->setPos(pac->x(),pac->y()+2);
        }
        if (pac->x()>325 && pac->x()<335 && pac->y()>105 && pac->y()<270){
            pac->setPos(pac->x(),pac->y()+2);
        }
        if (pac->x()>105 && pac->x()<115 && pac->y()>64 && pac->y()<150){
            pac->setPos(pac->x(),pac->y()+2);
        }
        if (pac->x()>147 && pac->x()<152 && pac->y()>105 && pac->y()<150){
            pac->setPos(pac->x(),pac->y()+2);
        }
        if (pac->x()>285 && pac->x()<295 && pac->y()>105 && pac->y()<190){
            pac->setPos(pac->x(),pac->y()+2);
        }
        if (pac->x()>105 && pac->x()<115 && pac->y()>185 && pac->y()<277){
            pac->setPos(pac->x(),pac->y()+2);
        }
        if (pac->x()>368 && pac->x()<375){
            pac->setPos(pac->x(),pac->y()+2);
        }
    }




    if(pac->collidesWithItem(bola0)){
        if(bola0->isVisible()){
            bola0->hide();
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola00)){
        if(bola00->isVisible()){
            bola00->hide();
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola000)){
        if(bola000->isVisible()){
            bola000->hide();
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola0000)){
        if(bola0000->isVisible()){
            bola0000->hide();
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola00000)){
        if(bola00000->isVisible()){
            bola00000->hide();
            emit aviso(9);
            //delete bola;
        }
    }

    if(pac->collidesWithItem(bola1)){
        if(bola1->isVisible()){
            bola1->hide();
            ATK = ATK + 50;
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola3)){
        if(bola3->isVisible()){
            bola3->hide();
            emit aviso(9);
            chalecos = chalecos + 1;
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola4)){
        if(bola4->isVisible()){
            bola4->hide();
            ATK = ATK + 50;
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola5)){
        if(bola5->isVisible()){
            bola5->hide();
            emit aviso(9);
            vidaMAX = vidaMAX + 100;
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola6)){
        if(bola6->isVisible()){
            bola6->hide();
            vidaMOM = vidaMAX;
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola8)){
        if(bola8->isVisible()){
            bola8->hide();
            emit aviso(9);
            chalecos = chalecos + 1;
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola9)){
        if(bola9->isVisible()){
            bola9->hide();
            emit aviso(9);
            vidaMOM = vidaMAX;
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola10)){
        if(bola10->isVisible()){
            bola10->hide();
            emit aviso(9);
            vidaMAX = vidaMAX + 100;
            //delete bola;
        }
    }

    if(pac->collidesWithItem(enemigo1)){

        if(enemigo1->isVisible()){
            enemigo1->hide();
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(enemigo2)){

        if(enemigo2->isVisible()){
            enemigo2->hide();
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(enemigo22)){

        if(enemigo22->isVisible()){
            enemigo22->hide();
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(enemigo3)){
        if(enemigo3->isVisible()){
            enemigo3->hide();
            emit aviso(9);
            //delete bola;
        }
    }
    if(pac->collidesWithItem(bola15)){
        QApplication::quit();
        //Z.show();
        if(bola15->isVisible()){
            bola15->hide();
            emit aviso(9);
            chalecos = chalecos + 1;
            //delete bola;
        }
    }
}

void MainWindow1::keyPressEvent(QKeyEvent *ev){

    if(ev->key()==Qt::Key_A)
    {
        moverIx1=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverDx1=true;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverUy1=true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverDy1=true;
    }
}

void MainWindow1::keyReleaseEvent(QKeyEvent *ev){

    if(ev->key()==Qt::Key_A)
    {
        moverIx1=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverDx1=false;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverUy1=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverDy1=false;
    }
}

void MainWindow1::aumentarPuntos(){
    puntuacion += 10;
    ui->lcdNumber->display(ATK);
    ui->lcdNumber_2->display(vidaMOM);
    ui->lcdNumber_3->display(vidaMAX);
    std::cout<<puntuacion<<std::endl;
}










