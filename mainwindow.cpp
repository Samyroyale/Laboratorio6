#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, ui->graphicsView->width() - 10, ui->graphicsView->height() - 10);
    scene->setBackgroundBrush((QPixmap(":/square_blue.png").scaledToWidth(25)));

    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();

    T = ui->speed_slider->value();

    save = false;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(simulation()));
}
MainWindow::~MainWindow() {
    delete timer;
    delete scene;
    delete ui;
}

void MainWindow::simulation(){

    if(save){
        for(int i = 0; i<bodies.size(); i++ )
            txt_stream << std::to_string(bodies.at(i)->getX()).c_str() << "\t" << std::to_string(bodies.at(i)->getY()).c_str() <<"\t";
        txt_stream << "\n";
    }

    for(int i=0; i<bodies.size(); i++ ){

        bodies.at(i)->calculate_Ax(bodies);
        bodies.at(i)->calculate_Ay(bodies);

        bodies.at(i)->update(ui->graphicsView->width(), ui->graphicsView->height());
        bodies.at(i)->label->setGeometry(bodies.at(i)->new_x(bodies.at(i)->getLabelX(), ui->graphicsView->width() - 10), bodies.at(i)->new_y(bodies.at(i)->getLabelY(), ui->graphicsView->height() - 10), bodies.at(i)->getName().length()*8, 10);
    }
}

void MainWindow::remove_empty_bodies() {
    QList <Body *> aux;

    for(int k = 0; k<bodies.size(); k++)
        if(!bodies.at(k)->is_empty())
            aux.push_back(bodies.at(k));

    bodies = aux;
}
void MainWindow::update_T() {
    T = ui->speed_slider->value();
}

void MainWindow::get_export_values() {
    txt_stream <<  std::to_string(ui->x_box_1->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->y_box_1->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->m_box_1->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->r_box_1->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->vx_box_1->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->vy_box_1->value()).c_str() << '\t';
    txt_stream << "\n";
    txt_stream <<  std::to_string(ui->x_box_2->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->y_box_2->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->m_box_2->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->r_box_2->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->vx_box_2->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->vy_box_2->value()).c_str() << '\t';
    txt_stream << "\n";
    txt_stream <<  std::to_string(ui->x_box_3->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->y_box_3->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->m_box_3->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->r_box_3->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->vx_box_3->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->vy_box_3->value()).c_str() << '\t';
    txt_stream << "\n";
    txt_stream <<  std::to_string(ui->x_box_4->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->y_box_4->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->m_box_4->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->r_box_4->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->vx_box_4->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->vy_box_4->value()).c_str() << '\t';
    txt_stream << "\n";
    txt_stream <<  std::to_string(ui->x_box_5->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->y_box_5->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->m_box_5->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->r_box_5->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->vx_box_5->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->vy_box_5->value()).c_str() << '\t';
    txt_stream << "\n";
    txt_stream <<  std::to_string(ui->x_box_6->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->y_box_6->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->m_box_6->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->r_box_6->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->vx_box_6->value()).c_str() << '\t';
    txt_stream <<  std::to_string(ui->vy_box_6->value()).c_str() << '\t';
    txt_stream << "\n";
}

void MainWindow::update_boxes() {
    ui->x_box_1->update();
    ui->y_box_1->update();
    ui->m_box_1->update();
    ui->r_box_1->update();
    ui->vx_box_1->update();
    ui->vy_box_1->update();

    ui->x_box_2->update();
    ui->y_box_2->update();
    ui->m_box_2->update();
    ui->r_box_2->update();
    ui->vx_box_2->update();
    ui->vy_box_2->update();

    ui->x_box_3->update();
    ui->y_box_3->update();
    ui->m_box_3->update();
    ui->r_box_3->update();
    ui->vx_box_3->update();
    ui->vy_box_3->update();

    ui->x_box_4->update();
    ui->y_box_4->update();
    ui->m_box_4->update();
    ui->r_box_4->update();
    ui->vx_box_4->update();
    ui->vy_box_4->update();

    ui->x_box_5->update();
    ui->y_box_5->update();
    ui->m_box_5->update();
    ui->r_box_5->update();
    ui->vx_box_5->update();
    ui->vy_box_5->update();

    ui->x_box_6->update();
    ui->y_box_6->update();
    ui->m_box_6->update();
    ui->r_box_6->update();
    ui->vx_box_6->update();
    ui->vy_box_6->update();
}

void MainWindow::on_start_button_clicked() {

    timer->stop();

    if(!ui->resume_button->isEnabled())
        ui->resume_button->setEnabled(true);
    if(!ui->pause_button->isEnabled())
        ui->pause_button->setEnabled(true);

    for(int k = 0; k<bodies.size(); k++){
        bodies.at(k)->label->deleteLater();
        scene->removeItem(bodies.at(k));
    }

    bodies.clear();

    bodies.push_back(new Body(nullptr, 1,ui->name_box_1->text(), ui->color_1->currentText(), ui->x_box_1->value(), ui->y_box_1->value(), ui->m_box_1->value(), ui->r_box_1->value(), ui->vx_box_1->value(), ui->vy_box_1->value()));
    bodies.push_back(new Body(nullptr, 2,ui->name_box_2->text(), ui->color_2->currentText(), ui->x_box_2->value(), ui->y_box_2->value(), ui->m_box_2->value(), ui->r_box_2->value(), ui->vx_box_2->value(), ui->vy_box_2->value()));
    bodies.push_back(new Body(nullptr, 3, ui->name_box_3->text(), ui->color_3->currentText(), ui->x_box_3->value(), ui->y_box_3->value(), ui->m_box_3->value(), ui->r_box_3->value(), ui->vx_box_3->value(), ui->vy_box_3->value()));
    bodies.push_back(new Body(nullptr, 4, ui->name_box_4->text(), ui->color_4->currentText(), ui->x_box_4->value(), ui->y_box_4->value(), ui->m_box_4->value(), ui->r_box_4->value(), ui->vx_box_4->value(), ui->vy_box_4->value()));
    bodies.push_back(new Body(nullptr, 5, ui->name_box_5->text(), ui->color_5->currentText(), ui->x_box_5->value(), ui->y_box_5->value(), ui->m_box_5->value(), ui->r_box_5->value(), ui->vx_box_5->value(), ui->vy_box_5->value()));
    bodies.push_back(new Body(nullptr, 6, ui->name_box_6->text(), ui->color_6->currentText(), ui->x_box_6->value(), ui->y_box_6->value(), ui->m_box_6->value(), ui->r_box_6->value(), ui->vx_box_6->value(), ui->vy_box_6->value()));

    remove_empty_bodies();

    for(int k = 0; k<bodies.size(); k++){
        bodies.at(k)->setPos(bodies.at(k)->new_x(bodies.at(k)->getX(),ui->graphicsView->width()), bodies.at(k)->new_y(bodies.at(k)->getY(),ui->graphicsView->height()));
        scene->addItem(bodies.at(k));

        scene->addWidget(bodies.at(k)->label);
        bodies.at(k)->label->setGeometry(-1*bodies.at(k)->getLabelX(), -1*bodies.at(k)->getLabelY(), bodies.at(k)->getName().length()*8, 15);
    }

    if(file.isOpen()){ //saving if it's opened
        file.flush();
        file.close();
        ui->save_label->setText("Saved succesfully");
    }
    else
        ui->save_label->setText("");

    if(ui->save_box->QAbstractButton::isChecked()){

        file_name = QFileDialog::getSaveFileName(this, "Save", "", "Text file (*.txt)");

        if(file_name.isEmpty()) //not sure why this is necessary but ok
            return;

        file.setFileName(file_name);

        file.open(QIODevice::WriteOnly | QIODevice::Text);

        if(!file.isOpen()){
            QMessageBox::critical(this, "Error", file.errorString());
            return;
        }

        txt_stream.setDevice(&file);

        save = true;
        update_T();
        timer->start(T);
    }
    else{
        save = false;
        update_T();
        timer->start(T);
    }
}
void MainWindow::on_pause_button_clicked() {
    timer->stop();
    ui->pause_button->setEnabled(false);
    if(!ui->resume_button->isEnabled())
        ui->resume_button->setEnabled(true);
}
void MainWindow::on_resume_button_clicked() {
    if(!ui->pause_button->isEnabled()){
        timer->start(T);
        ui->resume_button->setEnabled(false);
        if(!ui->pause_button->isEnabled())
            ui->pause_button->setEnabled(true);
    }

}
void MainWindow::on_stop_button_clicked() {
    timer->stop();
    ui->pause_button->setEnabled(false);
    ui->resume_button->setEnabled(false);

    if(file.isOpen()){
        file.flush();
        file.close();
        ui->save_label->setText("Saved succesfully");
    }
}
void MainWindow::on_help_button_clicked() {
    QString txt;
    txt = "To save a file click on the CheckBox and then hit \"Start Simulation\"; a window asking for a file name and path will appear. As soon as you hit the \"Save\" button the simulation will start. "
            "When you hit the \"Stop Simulation\" button or the \"Start Simulaton\" button the file will be closed and thus, saved.";

    QMessageBox::about(this, "Help", txt);
}
void MainWindow::on_Export_button_clicked() {

    file_name = QFileDialog::getSaveFileName(this, "Save", "", "Text file (*.txt)");

    if(file_name.isEmpty())
        return;

    file.setFileName(file_name);

    file.open(QIODevice::WriteOnly | QIODevice::Text);

    if(!file.isOpen()){
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    txt_stream.setDevice(&file);

    get_export_values();

    file.flush();
    file.close();

    ui->save_label->setText("Exported correctly");
}
void MainWindow::on_Import_button_clicked() {

    file_name = QFileDialog::getOpenFileName(this, "Open", "", "Text file (*.txt)");

    std::fstream file (file_name.toStdString(), std:: fstream::in | std::fstream::binary);

     if(file.is_open()){

         std::string temp;
         short counter = 1;

         while (counter <= 6){

             file >> temp;

             switch (counter) {
             case 1:{
                 ui->x_box_1->setValue(std::stoi(temp.c_str())); break;
             }
             case 2:{
                 ui->y_box_1->setValue(std::stoi(temp.c_str())); break;
             }
             case 3:{
                 ui->m_box_1->setValue(std::stod(temp.c_str())); break;
             }
             case 4:{
                 ui->r_box_1->setValue(std::stoi(temp.c_str())); break;
             }
             case 5:{
                 ui->vx_box_1->setValue(std::stod(temp.c_str())); break;
             }
             case 6:{
                 ui->vy_box_1->setValue(std::stod(temp.c_str())); break;
             }
             }
             counter++;
         }
         counter = 1;
         while (counter <= 6){

             file >> temp;

             switch (counter) {
             case 1:{
                 ui->x_box_2->setValue(std::stoi(temp.c_str())); break;
             }
             case 2:{
                 ui->y_box_2->setValue(std::stoi(temp.c_str())); break;
             }
             case 3:{
                 ui->m_box_2->setValue(std::stod(temp.c_str())); break;
             }
             case 4:{
                 ui->r_box_2->setValue(std::stoi(temp.c_str())); break;
             }
             case 5:{
                 ui->vx_box_2->setValue(std::stod(temp.c_str())); break;
             }
             case 6:{
                 ui->vy_box_2->setValue(std::stod(temp.c_str())); break;
             }
             }
             counter++;
         }
         counter = 1;
         while (counter <= 6){

             file >> temp;

             switch (counter) {
             case 1:{
                 ui->x_box_3->setValue(std::stoi(temp.c_str())); break;
             }
             case 2:{
                 ui->y_box_3->setValue(std::stoi(temp.c_str())); break;
             }
             case 3:{
                 ui->m_box_3->setValue(std::stod(temp.c_str())); break;
             }
             case 4:{
                 ui->r_box_3->setValue(std::stoi(temp.c_str())); break;
             }
             case 5:{
                 ui->vx_box_3->setValue(std::stod(temp.c_str())); break;
             }
             case 6:{
                 ui->vy_box_3->setValue(std::stod(temp.c_str())); break;
             }
             }
             counter++;
         }
         counter = 1;
         while (counter <= 6){

             file >> temp;

             switch (counter) {
             case 1:{
                 ui->x_box_4->setValue(std::stoi(temp.c_str())); break;
             }
             case 2:{
                 ui->y_box_4->setValue(std::stoi(temp.c_str())); break;
             }
             case 3:{
                 ui->m_box_4->setValue(std::stod(temp.c_str())); break;
             }
             case 4:{
                 ui->r_box_4->setValue(std::stoi(temp.c_str())); break;
             }
             case 5:{
                 ui->vx_box_4->setValue(std::stod(temp.c_str())); break;
             }
             case 6:{
                 ui->vy_box_4->setValue(std::stod(temp.c_str())); break;
             }
             }
             counter++;
         }
         counter = 1;
         while (counter <= 6){

             file >> temp;

             switch (counter) {
             case 1:{
                 ui->x_box_5->setValue(std::stoi(temp.c_str())); break;
             }
             case 2:{
                 ui->y_box_5->setValue(std::stoi(temp.c_str())); break;
             }
             case 3:{
                 ui->m_box_5->setValue(std::stod(temp.c_str())); break;
             }
             case 4:{
                 ui->r_box_5->setValue(std::stoi(temp.c_str())); break;
             }
             case 5:{
                 ui->vx_box_5->setValue(std::stod(temp.c_str())); break;
             }
             case 6:{
                 ui->vy_box_5->setValue(std::stod(temp.c_str())); break;
             }
             }
             counter++;
         }
         counter = 1;
         while (counter <= 6){

             file >> temp;

             switch (counter) {
             case 1:{
                 ui->x_box_6->setValue(std::stoi(temp.c_str())); break;
             }
             case 2:{
                 ui->y_box_6->setValue(std::stoi(temp.c_str())); break;
             }
             case 3:{
                 ui->m_box_6->setValue(std::stod(temp.c_str())); break;
             }
             case 4:{
                 ui->r_box_6->setValue(std::stoi(temp.c_str())); break;
             }
             case 5:{
                 ui->vx_box_6->setValue(std::stod(temp.c_str())); break;
             }
             case 6:{
                 ui->vy_box_6->setValue(std::stod(temp.c_str())); break;
             }
             }
             counter++;
         }

         file.close();

         update_boxes();

         ui->save_label->setText("Imported correctly");
     }
     else {
         ui->save_label->setText("Error importing");
     }
}
