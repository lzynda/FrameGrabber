#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QtCore>
#include <iostream>
#include <Windows.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnChooseFile->setVisible(false);
    ui->SliderFrames->setVisible(false);
    ui->frameFPS->setVisible(false);
    ui->lblRec->setVisible(false);
    ui->btnPreview->setVisible(false);
    ui->frameFrames->setVisible(false);
    capture.open(0);

    if(capture.isOpened() == false ){
        return;
    }

    tmrTimer = new QTimer(this);
    connect(tmrTimer, SIGNAL(timeout()),this, SLOT(VidUpdateGUI()));
    tmrTimer->start(1000/ui->spnbFPS->value());

    keyS = new QShortcut(this);
    keyS->setKey(Qt::Key_S);
    connect(keyS, SIGNAL(activated()),this,SLOT(slotShortcutS()));

    keyE = new QShortcut(this);
    keyE->setKey(Qt::Key_E);
    connect(keyE, SIGNAL(activated()),this,SLOT(slotShortcutE()));

    keyRight = new QShortcut(this);
    keyRight->setKey(Qt::Key_Right);
    connect(keyRight, SIGNAL(activated()),this,SLOT(slotShortcutRight()));

    keyLeft = new QShortcut(this);
    keyLeft->setKey(Qt::Key_Left);
    connect(keyLeft, SIGNAL(activated()),this,SLOT(slotShortcutLeft()));

    keyCtrlRight = new QShortcut(this);
    keyCtrlRight->setKey(Qt::CTRL + Qt::Key_Right);
    connect(keyCtrlRight, SIGNAL(activated()),this,SLOT(slotShortcutCtrlRight()));

    keyCtrlLeft = new QShortcut(this);
    keyCtrlLeft->setKey(Qt::CTRL + Qt::Key_Left);
    connect(keyCtrlLeft, SIGNAL(activated()),this,SLOT(slotShortcutCtrlLeft()));

    keyShiftRight = new QShortcut(this);
    keyShiftRight->setKey(Qt::SHIFT + Qt::Key_Right);
    connect(keyShiftRight, SIGNAL(activated()),this,SLOT(slotShortcutShiftRight()));

    keyShiftLeft = new QShortcut(this);
    keyShiftLeft->setKey(Qt::SHIFT + Qt::Key_Left);
    connect(keyShiftLeft, SIGNAL(activated()),this,SLOT(slotShortcutShiftLeft()));

    keyAltLeft = new QShortcut(this);
    keyAltLeft->setKey(Qt::ALT + Qt::Key_Left);
    connect(keyAltLeft, SIGNAL(activated()),this,SLOT(slotShortcutAltLeft()));

    keyPDown = new QShortcut(this);
    keyPDown->setKey(Qt::Key_PageDown);
    connect(keyPDown, SIGNAL(activated()),this,SLOT(slotShortcutPDown()));

    keyPUp = new QShortcut(this);
    keyPUp->setKey(Qt::Key_PageUp);
    connect(keyPUp, SIGNAL(activated()),this,SLOT(slotShortcutPUp()));

    keyCtrlShiftRight = new QShortcut(this);
    keyCtrlShiftRight->setKey(Qt::CTRL + Qt::SHIFT + Qt::Key_Right);
    connect(keyCtrlShiftRight, SIGNAL(activated()),this,SLOT(slotShortcutCtrlShiftRight()));

    keyCtrlShiftLeft = new QShortcut(this);
    keyCtrlShiftLeft->setKey(Qt::CTRL + Qt::SHIFT + Qt::Key_Left);
    connect(keyCtrlShiftLeft, SIGNAL(activated()),this,SLOT(slotShortcutCtrlShiftLeft()));


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::VidUpdateGUI(){

    if(ui->tabWidget->currentIndex() == 0){
    if(ui->comboBoxSource->currentIndex() == 0){

        capture.read(matOriginal);

        if(matOriginal.empty() == true) return;

        if(isRecordCam == true){
            ui->lblRec->setVisible(true);
            if(  ui->doubleSpinBStart->value() * 1000 < (((clock() - start) /(double) CLOCKS_PER_SEC)*1000)){

                if(framesToRecod>0){
                    RecordToFiles("cam/jpg/frame");
                    framesToRecod--;
                    framesRecorded++;
                }
                else{
                    ui->lblRec->setVisible(false);
                    isRecordCam = false;
                    qInfo() << "czas trwania: " <<  ((clock() - start) /(double) CLOCKS_PER_SEC)*1000 << " "<< isRecordCam;
                 }
                 if (ui->doubleSpinBEnd->value() * 1000 < (((clock() - start) /(double) CLOCKS_PER_SEC)*1000)){
                     ui->lblRec->setVisible(false);
                     isRecordCam = false;
                 }
            }
        }

        if(isQuickRecordCam){

            video.write(matOriginal);
        }

        if(isRecordCamFPS){
            videoFPS.write(matOriginal);           
        }

        cv::cvtColor(matOriginal,matOriginal,CV_BGR2RGB);
        matOriginal.copyTo(frameToShow);
        cv::resize(frameToShow,frameToShow,cv::Size(520,390));
        QImage qimgOriginal((uchar*)frameToShow.data,frameToShow.cols,frameToShow.rows,frameToShow.step,QImage::Format_RGB888);

        ui->lblRecordVideo->setPixmap(QPixmap::fromImage(qimgOriginal));
    }


    if(ui->comboBoxSource->currentIndex() == 1){

        if(filename.toStdString() == ""){
            ui->lblRecordVideo->setText("WYBIERZ PLIK");
            ui->lblRecordVideo->setAlignment(Qt::AlignCenter);
        }
        else{

           ui->lblCurrentFrame->setText(QString::number(currentFrme));
           capture.set(cv::CAP_PROP_POS_FRAMES,currentFrme);
           capture.read(matOriginal);

           if(matOriginal.empty() == true) return;

           if(isRecordVid == true){

               ui->lblRec->setVisible(true);
               if(  ui->doubleSpinBStart->value() * 1000 < (((clock() - start) /(double) CLOCKS_PER_SEC)*1000)){

                   if(framesToRecod>0){
                       RecordToFiles("vid/jpg/frame");
                       framesToRecod--;
                       framesRecorded++;                       
                   }
                   else{
                       ui->lblRec->setVisible(false);
                       isRecordVid = false;
                       qInfo() << "czas trwania: " <<  ((clock() - start) /(double) CLOCKS_PER_SEC)*1000 << " "<< isRecordCam;
                    }
                    if (ui->doubleSpinBEnd->value() * 1000 < (((clock() - start) /(double) CLOCKS_PER_SEC)*1000)){
                        ui->lblRec->setVisible(false);
                        isRecordVid = false;
                    }
               }
           }

           if(isQuickRecordVid){
               RecordToFiles("vid/quickRecord/frame");
               framesRecorded++;
           }

           if(isPlay){
               if(currentFrme<framesCount-1){
                    currentFrme++;
                    ui->SliderFrames->setValue(currentFrme);
               }
               else{
                   isPlay=false;
                   displayStatus=0;
               }
           }

           if(isPlayBack){
               if(currentFrme>0){
                    currentFrme--;
                    ui->SliderFrames->setValue(currentFrme);
               }
               else{
                   isPlayBack=false;
                   displayStatus=0;
               }
           }


           if(isDisplay){

               matOriginal.copyTo(firstWindow);
               cv::resize(firstWindow,firstWindow,cv::Size(320,240));

               if(displayStatus == 1){   //odtwarzanie do przodu
                    cv::resize(lastFrame,lastFrame,cv::Size(320,240));
                    lastFrame.copyTo(secondWindow);
               }

               if(displayStatus == 2){   //odtwarzanie od tylu
                    cv::resize(firstFrame,firstFrame,cv::Size(320,240));
                    firstFrame.copyTo(secondWindow);
               }

               if(displayStatus == 0){
                    firstWindow.copyTo(secondWindow);
               }


               cv::Mat matDst(cv::Size(firstWindow.cols*2,firstWindow.rows),firstWindow.type(),cv::Scalar::all(0));
               cv::Mat matRoi = matDst(cv::Rect(0,0,firstWindow.cols,firstWindow.rows));
               firstWindow.copyTo(matRoi);
               matRoi = matDst(cv::Rect(firstWindow.cols,0,firstWindow.cols,firstWindow.rows));
               secondWindow.copyTo(matRoi);

               cv::imshow("Display",matDst);

           }

           cv::cvtColor(matOriginal,matOriginal,CV_BGR2RGB);
           matOriginal.copyTo(frameToShow);
           cv::resize(frameToShow,frameToShow,cv::Size(520,390));
           QImage qimgOriginal((uchar*)frameToShow.data,frameToShow.cols,frameToShow.rows,frameToShow.step,QImage::Format_RGB888);
           ui->lblRecordVideo->setPixmap(QPixmap::fromImage(qimgOriginal));
        }
    }
}
    if(ui->tabWidget->currentIndex() == 1){

        if(ui->comboBoxSourceLogo->currentIndex() == 0){

            if(filenamePicture.toStdString()==""){
                ui->lblLogoVideo->setText("WYBIERZ PLIK");
                ui->lblLogoVideo->setAlignment(Qt::AlignCenter);

            }
            else{
                picture.copyTo(frameLogo);
                rowsCount = picture.rows;
                colsCount = picture.cols;
                if(filenameLogo.toStdString()!=""){
                    logo.copyTo(frameLogo(cv::Rect(logoPosX,logoPosY,logo.cols,logo.rows)));
                }
                cv::cvtColor(frameLogo,frameLogo,CV_BGR2RGB);
                frameLogo.copyTo(frameToShow2);
                cv::resize(frameToShow2,frameToShow2,cv::Size(573,430));
                QImage qimgFrameLogo((uchar*)frameToShow2.data,frameToShow2.cols,frameToShow2.rows,frameToShow2.step,QImage::Format_RGB888);
                ui->lblLogoVideo->setPixmap(QPixmap::fromImage(qimgFrameLogo));
            }
        }

        if(ui->comboBoxSourceLogo->currentIndex() == 1){

            captureCamLogo.read(frameLogo);
            rowsCount = frameLogo.rows;
            colsCount = frameLogo.cols;
            if(filenameLogo.toStdString()!=""){

                logo.copyTo(frameLogo(cv::Rect(logoPosX,logoPosY,logo.cols,logo.rows)));
            }

            cv::cvtColor(frameLogo,frameLogo,CV_BGR2RGB);

            if(isRecordCamLogo){
                videoLogo.write(frameLogo);
            }

            frameLogo.copyTo(frameToShow2);
            cv::resize(frameToShow2,frameToShow2,cv::Size(573,430));
            QImage qimgFrameLogo((uchar*)frameToShow2.data,frameToShow2.cols,frameToShow2.rows,frameToShow2.step,QImage::Format_RGB888);
            ui->lblLogoVideo->setPixmap(QPixmap::fromImage(qimgFrameLogo));

        }

        if(ui->comboBoxSourceLogo->currentIndex() == 2){

            if(filenameVidLogo.toStdString()==""){
                ui->lblLogoVideo->setText("WYBIERZ PLIK");
                ui->lblLogoVideo->setAlignment(Qt::AlignCenter);
            }
            else{
                frameVid.copyTo(frameLogo);
                rowsCount = frameVid.rows;
                colsCount = frameVid.cols;

                if(filenameLogo.toStdString()!=""){
                    logo.copyTo(frameLogo(cv::Rect(logoPosX,logoPosY,logo.cols,logo.rows)));
                }

                cv::cvtColor(frameLogo,frameLogo,CV_BGR2RGB);
                frameLogo.copyTo(frameToShow2);
                cv::resize(frameToShow2,frameToShow2,cv::Size(573,430));
                QImage qimgFrameLogo((uchar*)frameToShow2.data,frameToShow2.cols,frameToShow2.rows,frameToShow2.step,QImage::Format_RGB888);
                ui->lblLogoVideo->setPixmap(QPixmap::fromImage(qimgFrameLogo));

            }
        }

    }
}


void MainWindow::RecordToFiles(std::string folderFilename){

    pngPath = "C:/Users/Dell/Desktop/opencvFiles/";
    pngPath.append(folderFilename);
    pngPath.append(std::to_string(framesRecorded));
    pngPath.append(".jpg");
    cv::imwrite(pngPath,matOriginal);


}

void MainWindow::on_spnbFPS_valueChanged(int arg1){
    tmrTimer->start(1000/arg1);
}


void MainWindow::ChangeVidFPS(){
    int fps1 = ui->spnbFPS->value();

    cv::VideoWriter video2("C:/Users/Dell/Desktop/opencvFiles/vid/fps/videoFPSchanged.avi", CV_FOURCC('M','J','P','G'), fps1, matOriginal.size());

    if(filename.toStdString()!=""){
        captureVid.open(filename.toStdString());
        while(true){
            if(!captureVid.read(frame)) break;
            video2.write(frame);
        }
    }
}

void MainWindow::RecordVidWithLogo(){

    if(filenameVidLogo.toStdString()!="" && filenameLogo.toStdString()!=""){

        captureVid.open(filenameVidLogo.toStdString());
        captureVid.read(frame);
        int fps = captureVid.get(CV_CAP_PROP_FPS);
        cv::VideoWriter videoLogo("C:/Users/Dell/Desktop/opencvFiles/logoOutput/videoWithLogo.avi", CV_FOURCC('M','J','P','G'), fps, frame.size());

        while(true){
            if(!captureVid.read(frame)) break;
            logo.copyTo(frame(cv::Rect(logoPosX,logoPosY,logo.cols,logo.rows)));
            videoLogo.write(frame);
        }
    }
}

void MainWindow::SavePictureWithLogo(){
    if(filenamePicture.toStdString()!="" && filenameLogo.toStdString()!=""){
        cv::cvtColor(frameLogo,frameLogo,CV_BGR2RGB);
        cv::imwrite("C:/Users/Dell/Desktop/opencvFiles/logoOutput/pictureWithLogo.png", frameLogo);
    }
}


void MainWindow::on_comboBoxSource_currentIndexChanged(int index){

    if(index == 0){
        ui->btnChooseFile->setVisible(false);
        ui->SliderFrames->setVisible(false);
        ui->btnPreview->setVisible(false);
        ui->frameFrames->setVisible(false);
        capture.open(0);

    }
    if(index == 1){
        ui->btnChooseFile->setVisible(true);
        ui->SliderFrames->setVisible(true);
        ui->btnPreview->setVisible(true);
        ui->frameFrames->setVisible(true);
        capture.open(filename.toStdString());
    }
}


void MainWindow::on_comboBoxFunction_currentIndexChanged(int index)
{
    if(index == 0){
        ui->frame->setVisible(true);
        ui->frameFPS->setVisible(false);
    }

    if(index == 1){
        ui->frame->setVisible(false);
        ui->frameFPS->setVisible(true);
    }

}

void MainWindow::on_btnChooseFile_clicked(){

         filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C:/Users/Dell/Desktop/opencvFiles",
                "Video Files (*.avi *.mpg *.mp4)"
                );
         capture.open(filename.toStdString());
         framesCount = capture.get(cv::CAP_PROP_FRAME_COUNT);
         currentFrme = 0;
         ui->SliderFrames->setMaximum(framesCount-1);
         ui->lblFramesCount->setText(QString::number(framesCount));
         capture.set(cv::CAP_PROP_POS_FRAMES,framesCount-1);
         capture.read(lastFrame);
         capture.set(cv::CAP_PROP_POS_FRAMES,1);
         capture.read(firstFrame);

}

void MainWindow::on_btnRecord_clicked()
{

    if(ui->comboBoxSource->currentIndex() == 0){
        if(ui->comboBoxFunction->currentIndex() == 0){
            framesToRecod = ui->spinBFrames->value();
            framesRecorded = 0;
            start = clock();
            isRecordCam = true;

        }

        if(ui->comboBoxFunction->currentIndex() == 1){
            framesRecorded = 0;
            int fps = ui->spnbFPS->value();

            if(isRecordCamFPS){
                isRecordCamFPS = false;
                ui ->btnRecord->setText("NAGRYWAJ");
                ui->lblRec->setVisible(false);
            }
            else{
                videoFPS.open("C:/Users/Dell/Desktop/opencvFiles/cam/fps/camfps.avi", CV_FOURCC('M','J','P','G'), fps, matOriginal.size());
                isRecordCamFPS = true;
                ui ->btnRecord->setText("STOP");
                ui->lblRec->setVisible(true);
            }
        }
    }

    if(ui->comboBoxSource->currentIndex() == 1){
        if(ui->comboBoxFunction->currentIndex() == 0){
            framesToRecod = ui->spinBFrames->value();
            framesRecorded = 0;          
            start = clock();
            isRecordVid = true;
        }

        if(ui->comboBoxFunction->currentIndex() == 1){
            ChangeVidFPS();
        }
    }
}


void MainWindow::slotShortcutS(){
    if (ui->tabWidget->currentIndex() == 0){
        framesRecorded = 0;
        ui->lblRec->setVisible(true);
        if (ui->comboBoxSource->currentIndex() == 0){
            video.open("C:/Users/Dell/Desktop/opencvFiles/cam/quickRecord/quicRec.avi", CV_FOURCC('M','J','P','G'), 25, matOriginal.size());
            isQuickRecordCam = true;
        }
        if (ui->comboBoxSource->currentIndex() == 1){
            isQuickRecordVid = true;
        }
    }
}

void MainWindow::slotShortcutE(){
    if (ui->tabWidget->currentIndex() == 0){
        framesRecorded=0;
        ui->lblRec->setVisible(false);
        if (ui->comboBoxSource->currentIndex() == 0){
            isQuickRecordCam = false;
        }
        if (ui->comboBoxSource->currentIndex() == 1){
            isQuickRecordVid = false;
        }
    }
}

void MainWindow::slotShortcutRight(){
    if (ui->tabWidget->currentIndex() == 0){
        if(currentFrme<framesCount){
            currentFrme++;
            ui->SliderFrames->setValue(currentFrme);
            displayStatus = 0;
        }
    }

    if (ui->tabWidget->currentIndex() == 1){
        if(logoPosX < colsCount-2)
            logoPosX++;
    }
}

void MainWindow::slotShortcutLeft(){
    if (ui->tabWidget->currentIndex() == 0){
       if(currentFrme>0){
            currentFrme--;
            ui->SliderFrames->setValue(currentFrme);
            displayStatus = 0;
       }
    }
    if (ui->tabWidget->currentIndex() == 1){
        if(logoPosX>0)
            logoPosX--;
    }

}

void MainWindow::slotShortcutCtrlRight(){
    if (ui->tabWidget->currentIndex() == 0){
        currentFrme = framesCount;
        ui->SliderFrames->setValue(currentFrme);
        displayStatus = 0;
    }

}

void MainWindow::slotShortcutCtrlLeft(){
    if (ui->tabWidget->currentIndex() == 0){
        currentFrme = 0;
        ui->SliderFrames->setValue(currentFrme);
        displayStatus = 0;
    }
}

void MainWindow::slotShortcutShiftRight(){
    if (ui->tabWidget->currentIndex() == 0){
        if(currentFrme+15<framesCount-1){
            currentFrme+=15;
            ui->SliderFrames->setValue(currentFrme);
            displayStatus = 0;
        }
    }
}

void MainWindow::slotShortcutShiftLeft(){
    if (ui->tabWidget->currentIndex() == 0){
        if(currentFrme-15>=0){
            currentFrme-=15;
            ui->SliderFrames->setValue(currentFrme);
            displayStatus = 0;
        }
    }
}

void MainWindow::slotShortcutAltLeft(){
    if (ui->tabWidget->currentIndex() == 0){
        if(currentFrme-50>=0){
            currentFrme-=50;
            ui->SliderFrames->setValue(currentFrme);
            displayStatus = 0;
        }
    }
}
void MainWindow::slotShortcutPDown(){
    if (ui->tabWidget->currentIndex() == 0){
        if(currentFrme+50<framesCount-1){
            currentFrme+=50;
            ui->SliderFrames->setValue(currentFrme);
            displayStatus = 0;
        }
    }

    if (ui->tabWidget->currentIndex() == 1){
        if(logoPosY<rowsCount-2)
            logoPosY++;
    }
}

void MainWindow::slotShortcutPUp(){
    if (ui->tabWidget->currentIndex() == 1){
        if(logoPosY>0)
            logoPosY--;
    }
}

void MainWindow::slotShortcutCtrlShiftRight(){
    if (ui->tabWidget->currentIndex() == 0){        
        displayStatus = 1;
        isPlay = true;
    }
}
void MainWindow::slotShortcutCtrlShiftLeft(){
    if (ui->tabWidget->currentIndex() == 0){        
        displayStatus = 2;
        isPlayBack = true;        
    }
}

void MainWindow::on_SliderFrames_valueChanged(int value)
{
    currentFrme = value;
    //displayStatus = 0;
}

void MainWindow::on_comboBoxSourceLogo_currentIndexChanged(int index)
{
    if(index == 0){
        captureLogo.open(filenameLogo.toStdString());
        ui->btnVideoLogo->setVisible(true);
        ui->btnSaveLogo->setText("ZAPISZ");
        logoPosX = 0;
        logoPosY = 0;
    }

    if(index == 1){
        captureCamLogo.open(0);
        ui->btnVideoLogo->setVisible(false);
        ui->btnSaveLogo->setText("SART");
        logoPosX = 0;
        logoPosY = 0;
    }

    if(index == 2){
        captureVidLogo.open(filenameVidLogo.toStdString());
        ui->btnVideoLogo->setVisible(true);
        ui->btnSaveLogo->setText("ZAPISZ");
        logoPosX = 0;
        logoPosY = 0;
    }

}

void MainWindow::on_btnLogo_clicked()
{
    filenameLogo = QFileDialog::getOpenFileName(
           this,
           tr("Open File"),
           "C:/Users/Dell/Desktop/opencvFiles",
           "Image Files (*.bmp)"
           );
    captureLogo.open(filenameLogo.toStdString());
    captureLogo.read(logo);
}

void MainWindow::on_btnVideoLogo_clicked()
{
    logoPosX = 0;
    logoPosY = 0;

    if (ui->comboBoxSourceLogo->currentIndex() == 0){

        filenamePicture = QFileDialog::getOpenFileName(
           this,
           tr("Open File"),
           "C:/Users/Dell/Desktop/opencvFiles",
           "Video Files (*.png *.jpg)"
           );
        capturePicture.open(filenamePicture.toStdString());
        capturePicture.read(picture);
    }

    if (ui->comboBoxSourceLogo->currentIndex() == 2){

         filenameVidLogo = QFileDialog::getOpenFileName(
           this,
           tr("Open File"),
           "C:/Users/Dell/Desktop/opencvFiles",
           "Video Files (*.avi *.mpg *.mp4)"
           );
         captureVidLogo.open(filenameVidLogo.toStdString());
         captureVidLogo.read(frameVid);
    }
}

void MainWindow::on_btnPreview_clicked()
{
    if(filename.toStdString()!=""){
        if(isDisplay){
            isDisplay = false;
            cv::destroyAllWindows();
            ui->btnPreview->setText("Dodatkowy podgląd");
        }
        else{
            isDisplay = true;
            ui->btnPreview->setText("Zamknij podgląd");
        }
    }
}

void MainWindow::on_btnSaveLogo_clicked()
{
    if(ui->comboBoxSourceLogo->currentIndex() == 0){
            SavePictureWithLogo();
    }

    if(ui->comboBoxSourceLogo->currentIndex() == 1){

        if(isRecordCamLogo){
            isRecordCamLogo = false;
            ui->btnSaveLogo->setText("SART");
        }
        else{
            videoLogo.open("C:/Users/Dell/Desktop/opencvFiles/logoOutput/camWithLogo.avi", CV_FOURCC('M','J','P','G'), 30, frameLogo.size());
            isRecordCamLogo = true;
            ui->btnSaveLogo->setText("STOP");
        }

    }

    if(ui->comboBoxSourceLogo->currentIndex() == 2){
        RecordVidWithLogo();
    }

}

void MainWindow::on_btnImgToVid_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "C:/Users/Dell/Desktop/opencvFiles",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    dir.append("/frame%d.jpg");
    cv::Mat toRecord;

    cv::VideoCapture cap(dir.toStdString());
    cap.read(toRecord);

    cv::VideoWriter out_cap("C:/Users/Dell/Desktop/opencvFiles/jpgToVid/frames.avi", CV_FOURCC('M', 'J', 'P', 'G'),15, toRecord.size());

    while(1){
        cap.read(toRecord);
        if(toRecord.empty()) break;
        out_cap.write(toRecord);
    }

    cap.release();
}
