#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QMainWindow>
#include <QTextStream>
#include <QFileDialog>
#include <fstream>
#include <QTimer>

#include "body.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public: // Variables

private: // Variables
    Ui::MainWindow *ui;

    QGraphicsScene *scene;

    QTimer *timer;

    QList <Body *> bodies;

    double T;

    QFile file;
    QTextStream txt_stream;
    QString file_name;
    bool save;

public: // Methods
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void remove_empty_bodies();

    void update_T();

private: // Methods
    void get_export_values();
    void update_boxes();

private slots: //slots
    void simulation();

    void on_start_button_clicked();
    void on_pause_button_clicked();
    void on_resume_button_clicked();
    void on_stop_button_clicked();
    void on_help_button_clicked();
    void on_Export_button_clicked();
    void on_Import_button_clicked();
};
#endif // MAINWINDOW_H
