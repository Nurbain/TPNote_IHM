#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLCDNumber>
#include <QDebug>
#include <QPixmap>


void MainWindow::reset()
{
    etatreset=true;
    nbreset=2;

    vanneDroite->Fermeture();
    vanneGauche->Fermeture();
    porteDroite-> DebutFermeture();
    porteGauche->DebutFermeture();


    light_init();
    boat_init();
}


void MainWindow::DebutOuvertureG(){
    qDebug("Debut ouverture vanne Gauche");
}

void MainWindow::DebutOuvertureD(){
    qDebug("Debut ouverture vanne Droite");
}



void MainWindow::VanneDroiteOuverte(){
    qDebug("Vanne droite ouverte");
    FeuVert(ui->VertV2 , ui->RougeV2);
    porteDroite->DebutOuverture();
}

void MainWindow::VanneGaucheOuverte(){
    FeuVert(ui->VertV1 , ui->RougeV1);
    qDebug("Vanne gauche ouverte");
    _eau->Monter();
    porteGauche->DebutOuverture();
}

void MainWindow::AvancementPorteDroite(double valeur){
    char s[64];
    snprintf(s,64,"avancement porte droite : %f /1",valeur);
    PorteOF(ui->Porte2 , valeur , IdPorte::Droite);
    qDebug(s);
}

void MainWindow::AvancementPorteGauche(double valeur){
    char s[64];
    snprintf(s,64,"avancement porte gauche : %f /1",valeur);
    PorteOF(ui->Porte1 , valeur , IdPorte::Gauche);
    qDebug(s);
}

void MainWindow::PorteDouverte(){
    qDebug("Porte droite ouverte");
    //Affichage feu
    FeuVert(ui->VertD,ui->RougeD);
    FeuVert(ui->VertP2 , ui->RougeP2);


    //Affichage bateau mid
    ui->BateauMilieu->setVisible(!sens);
    ui->Bateau2->setVisible(sens);

    ui->PorteDroite->setVisible(false);
}

void MainWindow::PorteGouverte(){
    qDebug("Porte gauche ouverte");
    //Affichage feu
    FeuVert(ui->VertG,ui->RougeG);
    FeuVert(ui->VertP1 , ui->RougeP1);

    //Affichage bateau mid
    ui->BateauMilieu->setVisible(sens);
    ui->Bateau1->setVisible(!sens);

    ui->PorteGauche->setVisible(false);
}

void MainWindow::PorteGfermer(){
    CHECK_RESET
    qDebug("Porte gauche fermer");
    FeuRouge(ui->VertG,ui->RougeG);
    FeuRouge(ui->VertP1 , ui->RougeP1);

    ui->PorteGauche->setVisible(true);
    porteDroite->DebutOuverture();
}

void MainWindow::PorteDfermer(){
    CHECK_RESET
    qDebug("Porte droit fermer");
    FeuRouge(ui->VertD,ui->RougeD);
    FeuRouge(ui->VertP2 , ui->RougeP2);

    ui->PorteDroite->setVisible(true);
    porteGauche->DebutOuverture();
}
