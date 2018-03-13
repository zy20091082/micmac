
#include "MainWindow.h"
#include "NewProject.h"
#include "MM2DPosSism.h"



MM2DPosSism::MM2DPosSism(QList <QString> list,QList <QString> listCheckedItems, QString path) : QWidget()
{
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    setWindowModality(Qt::ApplicationModal); //IMPORTANT, permet que ta fenêtre reste active

    setWindowTitle("MM2DPosSism");
    path_s = path.toStdString();
    QVBoxLayout *boxLayoutV = new QVBoxLayout;

    QLabel *labelImages = new QLabel(this);
    labelImages->setText("Select 2 images :");
    labelImages->setStyleSheet("font-weight: bold");

    QLabel *xML = new QLabel(this);
    xML->setText("Options :");
    xML->setStyleSheet("font-weight: bold");

    QLabel *DirMECLabel = new QLabel(this);
    DirMECLabel->setText("DirMEC :");
    DirMECLabel->setStyleSheet("font-weight: bold");

    dirMec = new QTextEdit();
    dirMec->setFixedHeight(25);
boxLayoutV->addWidget(labelImages);


    for (int i = 0; i < list.count(); i++)
    {
        std::string mot = list[i].toStdString();
        if((mot.find(".JPG")<10000) ||
                (mot.find(".jpg")<10000) ||
                (mot.find(".JPEG")<10000) ||
                (mot.find(".jpeg")<10000) ||
                (mot.find(".png")<10000) ||
                (mot.find(".PNG")<10000) ||
                (mot.find(".bmp")<10000) ||
                (mot.find(".BMP")<10000) ||
                (mot.find(".TIF")<10000) ||
                (mot.find(".tif")<10000)){
            listImages.append(list[i]);
        }
    }


    for (int i = 0; i < listImages.count(); i++)
    {
        imagesCheckBox = new QCheckBox(listImages[i]);
        listeCasesImages.append(imagesCheckBox);
        boxLayoutV->addWidget(imagesCheckBox);
        imagesCheckBox->setChecked(false);
    }

    boxLayoutV->addWidget(xML);
    boxXml = new QCheckBox("Dequant=false");
    boxLayoutV->addWidget(boxXml);

    QHBoxLayout *boxLayouth = new QHBoxLayout;
    boxLayouth->addWidget(DirMECLabel);
    boxLayouth->addWidget(dirMec);
    boxLayoutV->addLayout(boxLayouth);

    QPushButton *ok = new QPushButton();
    ok->setText("Ok");
    ok->setFixedWidth(70);
    ok->setFixedHeight(40);
    boxLayoutV->addWidget(ok);
    QObject::connect(ok, SIGNAL(clicked()), this, SLOT(mm3d()));
    this->setLayout(boxLayoutV);
}





QString MM2DPosSism::msg1(){
    return sendCons;
}





void MM2DPosSism::mm3d(){

    int a = 0;
    images.erase();
    std::cout <<  "images = "  << std::endl;
    for( int i = 0; i< listeCasesImages.size(); i++){
        if(listeCasesImages.at(i)->isChecked())
        {a+=1;
            images.append(listImages.at(i).toStdString()+" ");
        }
    }


    if(a!=2){
        msgBox2.setWindowTitle("MM2DPosSism Error");

        msgBox2.setText("Please, Select 2 images \n ");
        msgBox2.setStandardButtons(QMessageBox::Ok);
        msgBox2.setDefaultButton(QMessageBox::Ok);
        if(msgBox2.exec() == QMessageBox::Ok){
       }

    }else{

        std::cout <<  images << std::endl;
        if(boxXml->isChecked())
        {    txt="Dequant=false";
        }


        if(dirMec->toPlainText()!=""){

            dirMecToStdStrg="DirMEC="+dirMec->toPlainText().toStdString();
        }

        cmd = "mm3d MM2DPosSism "+ images + dirMecToStdStrg + " @ExitOnBrkp";
        msgBox2.setWindowTitle("title");
        const QString cmd_str = QString::fromStdString(cmd);
        msgBox2.setText("Here is the commande you're about to launch : \n " + cmd_str);
        msgBox2.setStandardButtons(QMessageBox::Yes);
        msgBox2.addButton(QMessageBox::No);
        msgBox2.setDefaultButton(QMessageBox::No);
        if(msgBox2.exec() == QMessageBox::Yes){
            this->close();
                //       cons.show();
                p.setWorkingDirectory(path_s.c_str());
                p.waitForFinished(-1);
                qDebug() <<  get_current_dir_name();
                qDebug() <<  cmd.c_str() ;
                p.start(cmd.c_str());
                p.setReadChannel(QProcess::StandardOutput);
                connect(&p,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadStandardOutput()));
        //        p.waitForFinished(-1);
        //        p.kill();
          connect(&p, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(stopped()));  //Add this line will cause error at runtime
          msg();

        }
    }}





void MM2DPosSism::msg(){
         qDi.setWindowTitle("MM2DPosSism state");

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

void MM2DPosSism::readyReadStandardOutput(){
  Qtr->append(QString::fromStdString( p.readAllStandardOutput().data()));

}


void MM2DPosSism::stopped(){
    sendCons= Qtr->toPlainText();
    qDi.accept();
    this->close();


      }
