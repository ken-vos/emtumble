#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "GUI.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphics_view->setScene(scene);
    GUI::get_instance().draw(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_step_clicked()
{
    GUI::get_instance().step();
    GUI::get_instance().draw(scene);
}
