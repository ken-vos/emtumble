#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Board.hpp"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_step_clicked();
    void on_action_open_triggered();
    void on_button_play_clicked();

    void step_board();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer_simulation_delay;

    BoardGUI *board;

    void update_graphics();
    void load_board(std::string fname);
};

#endif // MAINWINDOW_H
