#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , in_sound(":/files/sounds/in.wav")
    , hold_sound(":/files/sounds/hold.wav")
    , out_sound(":/files/sounds/out.wav")
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
    if (state == IN) {
        ui->progressBar_in->setValue(gui_seconds+1);
    }
    else if (state == HOLD) {
        ui->progressBar_hold->setValue(gui_seconds+1);
    }
    else if (state == OUT) {
        ui->progressBar_out->setValue(gui_seconds+1);
    }
}


void MainWindow::timer_logic()
{
    if (seconds % 19 == 0 && seconds != 0) {
        seconds = 0;
        num_of_reps--;
        if (num_of_reps == 0) {
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
                state = COUNTDOWN;
                reset_progressBar();
                return;
            }
        }
        ui->lbl_num_of_repetitions->setText(QString::number(num_of_reps));
        reset_progressBar();
    }
    if (seconds == 0 || seconds == 19) {
        //in_sound.play();
        state = IN;
        gui_seconds = 0;
    }
    else if (seconds == 4) {
        state = HOLD;
        gui_seconds = 0;
        hold_sound.play();
    }
    else if (seconds == 11) {
        state = OUT;
        gui_seconds = 0;
        out_sound.play();
    }
}


void MainWindow::UpdateTime()
{
    while (state == COUNTDOWN) {
        ui->lbl_count_down->setText(QString::number(countdown_seconds));
        countdown_seconds--;
        if (countdown_seconds == -1) {
            state = IN;
        }
        return;
    }
    timer_logic();
    if (state == COUNTDOWN) {
        return;
    }
    update_progressBar();
    gui_seconds++;
    seconds++;
}
