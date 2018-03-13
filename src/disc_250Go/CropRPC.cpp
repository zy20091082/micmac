
#include "MainWindow.h"
#include "NewProject.h"
#include "CropRPC.h"
#include "Console.h"
//#include "XML_GEN/ParamChantierPhotogram.h"
//#include "general/MessageHandler.h"
//#include "StdAfx.h"


CropRPC::CropRPC(QList <QString> list,QList <QString> listCheckedItems, QString path) : QWidget()
{

    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    setWindowModality(Qt::ApplicationModal); //IMPORTANT, permet que ta fenêtre reste active

    sendCons="";
    aPath = path;
    setWindowTitle("CropRPC");
    path_s = path.toStdString();
    boxLayoutV = new QVBoxLayout;
    QLabel *labelImages = new QLabel(this);
    labelImages->setText("Pattern of orientation files to be cropped accordingly (in cXml_CamGenPolBundle format)");
    labelImages->setStyleSheet("font-weight: bold");

    oriFileCrop = new QLabel(this);
    oriFileCrop->setText("Orientation file of the image defining the crop extent (in cXml_CamGenPolBundle format):");
    oriFileCrop->setStyleSheet("font-weight: bold");


    QLabel *directoryOutput = new QLabel(this);
    directoryOutput->setText("Directory of output orientation files:");
    directoryOutput->setStyleSheet("font-weight: bold");


    patternTxt = new QTextEdit();
    patternTxt->setFixedHeight(25);
    oriFileCropTxt = new QTextEdit();
    oriFileCropTxt->setFixedHeight(25);
    directoryOutputTxt = new QTextEdit();
    directoryOutputTxt->setFixedHeight(25);

    boxLayoutV->addWidget(labelImages);

    QHBoxLayout *boxlayouth1 = new QHBoxLayout;
    QPushButton *buttonOri1 = new QPushButton();
    buttonOri1->setText("...");
    buttonOri1->setFixedWidth(30);
    buttonOri1->setFixedHeight(30);
    QObject::connect(buttonOri1, SIGNAL(clicked()), this, SLOT(oriSearch1()));
    boxlayouth1->addWidget(patternTxt);
    boxlayouth1->addWidget(buttonOri1);
    boxLayoutV->addLayout(boxlayouth1);
    boxLayoutV->addWidget(oriFileCrop);

    QHBoxLayout *boxlayouth = new QHBoxLayout;
    QPushButton *buttonOri = new QPushButton();
    QObject::connect(buttonOri, SIGNAL(clicked()), this, SLOT(oriSearch()));

    buttonOri->setText("...");
    buttonOri->setFixedWidth(30);
    buttonOri->setFixedHeight(30);
    QObject::connect(buttonOri, SIGNAL(clicked()), this, SLOT(rpcFile()));

    boxlayouth->addWidget(oriFileCropTxt);
    boxlayouth->addWidget(buttonOri);

    boxLayoutV->addLayout(boxlayouth);

    boxLayoutV->addWidget(directoryOutput);
    boxLayoutV->addWidget(directoryOutputTxt);




    QPushButton *ok = new QPushButton();
    ok->setText("Ok");
    ok->setFixedWidth(70);
    ok->setFixedHeight(40);
    boxLayoutV->addWidget(ok);
    QObject::connect(ok, SIGNAL(clicked()), this, SLOT(mm3d()));


    this->setLayout(boxLayoutV);

}


void CropRPC::mm3d(){

//    int a = 0;
//    images.erase();
//std::cout <<  "images = "  << std::endl;
//    for( int i = 0; i< listeCasesImages.size(); i++){
//        if(listeCasesImages.at(i)->isChecked())
//        {a+=1;
//            images.append(listImages.at(i).toStdString()+"|");
//        }
//    }
//    if(a<2){
//        msgBox2.setWindowTitle("Warning");
//        msgBox2.setText("Veuillez sélectionner au moins deux images à traiter \n ");
//        msgBox2.setStandardButtons(QMessageBox::Ok);
//        msgBox2.setDefaultButton(QMessageBox::Ok);
//        if(msgBox2.exec() == QMessageBox::Ok){
//            }
//    }else{





patternTxt_str = patternTxt->toPlainText().toStdString();
std::cout <<  "Size m = " + patternTxt_str << std::endl;



oriFileCropTxt_str = oriFileCropTxt->toPlainText().toStdString();
std::cout <<  "Size m = " + oriFileCropTxt_str << std::endl;

directoryOutputTxt_str = directoryOutputTxt->toPlainText().toStdString();
std::cout <<  "Size M = " + directoryOutputTxt_str << std::endl;




cmd = "mm3d SateLib CropRPC " +oriFileCropTxt_str+" "+patternTxt_str+" "+ directoryOutputTxt_str +" @ExitOnBrkp";

    msgBox2.setWindowTitle("mm3d command");

    const QString cmd_str = QString::fromStdString(cmd);
    msgBox2.setText("Here is the commande you are about to launch : \n " + cmd_str);
    msgBox2.setStandardButtons(QMessageBox::Yes);
    msgBox2.addButton(QMessageBox::No);
    msgBox2.setDefaultButton(QMessageBox::No);
    if(msgBox2.exec() == QMessageBox::Yes){
    this->close();
        p.setWorkingDirectory(path_s.c_str());
        p.waitForFinished(-1);
        qDebug() <<  get_current_dir_name();
        qDebug() <<  cmd.c_str() ;
        p.start(cmd.c_str());
        p.setReadChannel(QProcess::StandardOutput);
        connect(&p,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadStandardOutput()));
        connect(&p, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(stopped()));  //Add this line will cause error at runtime
        msg();



      }else{
        images.clear();}
    }



QString CropRPC::getTxt(){
    return sendCons;

}


void CropRPC::msg(){
         qDi.setWindowTitle("CropRPC state");
         QLabel *wait = new QLabel(this);
         wait->setText(" Wait until the end of the process, or click stop to cancel it ");
         wait->setStyleSheet("font-weight: bold");

        Qtr = new QTextEdit();
        Qtr->setFixedHeight(500);
        Qtr->setFixedWidth(700);

        QVBoxLayout *QV = new QVBoxLayout();
        QV->addWidget(wait);
        QV->addWidget(Qtr);

        QPushButton *stop = new QPushButton();
        stop->setText("STOP");
        stop->setFixedHeight(30);
        stop->setFixedWidth(60);

        QObject::connect(stop, SIGNAL(clicked()), this, SLOT(stopped()));
        QV->addWidget(stop);
        qDi.setLayout(QV);
        qDi.show();
      }




QString CropRPC::msg1(){
        return sendCons;
    }




void CropRPC::readyReadStandardOutput(){
      Qtr->append(QString::fromStdString( p.readAllStandardOutput().data()));
}


void CropRPC::stopped(){
    sendCons= Qtr->toPlainText();
    qDi.accept();
    this->close();


      }


void CropRPC::oriSearch(){
    fichier = QFileDialog::getOpenFileName(0, ("Select Output Folder"), QDir::currentPath());
    QString name = aPath+"/"+fichier.fileName();
    QMessageBox msgBox;
    msgBox.setWindowTitle("title");
    msgBox.setText("Do you confirm that the selected folder where your images have to be loaded is the following one? \n" + name);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
    oriFileCropTxt->setText(name);
        }else{
    }
}

void CropRPC::oriSearch1(){
    fichier = QFileDialog::getOpenFileName(0, ("Select Output Folder"), QDir::currentPath());
    QString name = aPath+"/"+fichier.fileName();
    QMessageBox msgBox;
    msgBox.setWindowTitle("title");
    msgBox.setText("Do you confirm that the selected folder where your images have to be loaded is the following one? \n" + name);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
    patternTxt->setText(name);
        }else{
    }
}


