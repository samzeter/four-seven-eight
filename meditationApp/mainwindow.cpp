#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , in_sound("/Users/samz/dev/meditationApp/meditationApp/in.wav")
    , hold_sound("/Users/samz/dev/meditationApp/meditationApp/hold.wav")
    , out_sound("/Users/samz/dev/meditationApp/meditationApp/out.wav")
{
    ui->setupUi(this);
    timer_1s = new QTimer(this);
    QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(UpdateTime())); // connect method takes care of signal
    timer_1s->start(1000); // 1 second interval
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::reset_progressBar()
{
    ui->progressBar_in->setValue(0);
    ui->progressBar_hold->setValue(0);
    ui->progressBar_out->setValue(0);
}


void MainWindow::update_progressBar()
{
    if (state == 0) {
        ui->progressBar_in->setValue(gui_seconds+1);
    }
    else if (state == 1) {
        ui->progressBar_hold->setValue(gui_seconds+1);
    }
    else if (state == 2) {
        ui->progressBar_out->setValue(gui_seconds+1);
    }
}


void MainWindow::timer_logic()
{
    if (seconds % 19 == 0 && seconds != 0) {
        seconds = 0;
        num_of_reps--;
        if (num_of_reps == 3) {
            switch( QMessageBox::question(
                        this,
                        tr("Timer finished"),
                        tr("Exit?"),
                        QMessageBox::Yes |
                        QMessageBox::No ,

                        QMessageBox::No ) )
            {
            case QMessageBox::Yes:
                exit(0);
                break;
            case QMessageBox::No:
                countdown_seconds = 3;
                num_of_reps = 4;
                seconds = 0;
                state = 4;
                reset_progressBar();
                return;
            }
        }
        ui->lbl_num_of_repetitions->setText(QString::number(num_of_reps));
        reset_progressBar();
    }
    if (seconds == 0 || seconds == 19) {
        state = 0;
        gui_seconds = 0;
        in_sound.play();
    }
    else if (seconds == 4) {
        state = 1;
        gui_seconds = 0;
        hold_sound.play();
    }
    else if (seconds == 11) {
        state = 2;
        gui_seconds = 0;        
        out_sound.play();
    }
}


void MainWindow::UpdateTime()
{
    while (countdown_seconds != -1) {
        ui->lbl_count_down->setText(QString::number(countdown_seconds));
        countdown_seconds--;
        return;
    }
    timer_logic();
    if (state == 4) {
        return;
    }
    update_progressBar();
    gui_seconds++;
    seconds++;
}
