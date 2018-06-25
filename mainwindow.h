#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include "opencv2/videoio/videoio.hpp"
#include <ctime>
#include <QShortcut>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    cv::VideoCapture capture;
    cv::VideoCapture captureVid;
    cv::VideoCapture captureCamLogo;
    cv::VideoCapture captureVidLogo;
    cv::VideoCapture capturePicture;
    cv::VideoCapture captureLogo;
    cv::VideoWriter video;
    cv::VideoWriter videoFPS;
    cv::VideoWriter videoLogo;
    cv::Mat matOriginal;
    cv::Mat frame;
    cv::Mat logo;
    cv::Mat picture;
    cv::Mat frameVid;
    cv::Mat frameLogo;
    cv::Mat frameToShow;
    cv::Mat frameToShow2;
    cv::Mat firstWindow;
    cv::Mat secondWindow;
    cv::Mat firstFrame;
    cv::Mat lastFrame;

    QImage qimgOriginal;
    QImage qimgFrame;
    QImage qimgPicture;
    QImage qimgFrameLogo;

    QString filename;
    QString filenameLogo;
    QString filenameVidLogo;
    QString filenamePicture;
    QTimer* tmrTimer;
    QTimer* tmrTimerToSave;
    std::string pngPath;
    int framesToRecod;
    int framesRecorded;
    int recordDuration;
    int logoPosX=0;
    int logoPosY=0;
    int colsCount;
    int rowsCount;
    int displayStatus=0;
    bool isRecordVid = false;
    bool isRecordCam = false;
    bool isRecordCamFPS = false;
    bool isRecordCamLogo = false;
    bool isQuickRecordVid = false;
    bool isQuickRecordCam = false;
    bool isPlay = false;
    bool isPlayBack = false;
    bool isDisplay = false;
    clock_t start;

    int currentFrme = 0;
    int framesCount;

    QShortcut *keyS;
    QShortcut *keyE;
    QShortcut *keyRight;
    QShortcut *keyLeft;
    QShortcut *keyCtrlRight;
    QShortcut *keyCtrlLeft;
    QShortcut *keyShiftRight;
    QShortcut *keyShiftLeft;
    QShortcut *keyAltLeft;
    QShortcut *keyPDown;
    QShortcut *keyPUp;
    QShortcut *keyCtrlShiftRight;
    QShortcut *keyCtrlShiftLeft;

public slots:
   void VidUpdateGUI();


private slots:
  //  void on_btnPauseOrResume_clicked();
    void RecordToFiles(std::string);
    void RecordVidWithLogo();
    void SavePictureWithLogo();
    void ChangeVidFPS();
    void on_spnbFPS_valueChanged(int arg1);
    void on_comboBoxSource_currentIndexChanged(int index);
    void on_btnChooseFile_clicked();
    void on_comboBoxFunction_currentIndexChanged(int index);
    void on_btnRecord_clicked();

    void slotShortcutS();
    void slotShortcutE();
    void slotShortcutRight();
    void slotShortcutLeft();
    void slotShortcutCtrlRight();
    void slotShortcutCtrlLeft();
    void slotShortcutShiftRight();
    void slotShortcutShiftLeft();
    void slotShortcutAltLeft();
    void slotShortcutPDown();
    void slotShortcutPUp();
    void slotShortcutCtrlShiftRight();
    void slotShortcutCtrlShiftLeft();
    void on_SliderFrames_valueChanged(int value);
    void on_comboBoxSourceLogo_currentIndexChanged(int index);
    void on_btnLogo_clicked();
    void on_btnVideoLogo_clicked();
    void on_btnPreview_clicked();
    void on_btnSaveLogo_clicked();

    void on_btnImgToVid_clicked();
};



#endif // MAINWINDOW_H
