#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer> // handling 1s time
#include <QTime> // display current system time
#include <QMessageBox>
#include <QtMultimedia/QSound>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void reset_progressBar();
    void timer_logic();
    
private slots:
    void UpdateTime();


private:
    Ui::MainWindow *ui;
    QTimer *timer_1s;
    int seconds{0};
    int gui_seconds{1};
    int countdown_seconds{3};
    int num_of_reps{4};
    int state{0};
    QSound in_sound;
    QSound hold_sound;
    QSound out_sound;
    void update_progressBar();
    bool finished = false;
    enum State{COUNTDOWN, IN, HOLD, OUT};
};
#endif // MAINWINDOW_H
