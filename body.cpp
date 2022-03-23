#include "body.h"

Body::Body(QObject *parent, int id_, QString name_, QString color_, double x_, double y_, double m_, int r_, double V0x_, double V0y_) : QObject(parent) {
    id = id_;
    name = name_;
    color = color_;
    x = x_;
    y = y_;
    m = m_;
    r = r_;
    V0x = V0x_;
    V0y = V0y_;
    Ax = 0;
    Ay = 0;

    xmin = -6000;
    ymax = 6000;

    scale = 0.05;

    label = new QLabel;
    label->setText(name);

    T = 5;
    //G = 6.67384e-11;
    G = 1;
}
Body::~Body() {
    delete label;
}

QRectF Body::boundingRect() const {
        return QRectF(-1*scale*r, -1*scale*r, 2*scale*r, 2*scale*r);
}
void Body::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    if(color == "Yellow")
        painter->setBrush(Qt::yellow);
    else if(color == "Blue")
        painter->setBrush(Qt::blue);
    else if(color == "Red")
        painter->setBrush(Qt::red);
    else if(color == "Magenta")
        painter->setBrush(Qt::magenta);
    else if(color == "Green")
        painter->setBrush(Qt::green);
    else if(color == "Black")
        painter->setBrush(Qt::black);

    painter->drawEllipse(boundingRect());
}

bool Body::is_empty() {
    if(r == 0 || m == 0.0)
        return true;
    else
        return false;
}

void Body::calculate_Ax(QList<Body *> bods) {
    double aux = 0;
    double dis;

    Ax= 0;

    for(int k = 0; k<bods.size(); k++){

        if(bods.at(k)->getName() != name){


            dis = sqrt(pow((bods.at(k)->getX() - x), 2)+pow((bods.at(k)->getY() - y),2));

            aux += (G*(bods.at(k)->getM()*(bods.at(k)->getX() - x))/(pow(dis, 3)));
        }
    }
    Ax = aux;
}
void Body::calculate_Ay(QList<Body *> bods) {
    double aux = 0;
    double dis;

    Ay = 0;

    for(int k = 0; k<bods.size(); k++){

        if(bods.at(k)->getId() != id){

            dis = sqrt(pow((bods.at(k)->getX() - x), 2)+pow((bods.at(k)->getY() - y),2));

            aux += (G*(bods.at(k)->getM()*(bods.at(k)->getY() - y)) / (pow(dis, 3)));
        }
    }
    Ay = aux;
}

void Body::update(int w, int h){
    V0x = V0x + (Ax*T);
    V0y = V0y + (Ay*T);
    x = x + (V0x*T);
    y = y + (V0y*T);

    setX(new_x(x, w));
    setY(new_y(y, h));
}

double Body::getX() const{
    return x;
}
double Body::getY() const{
    return y;
}

int Body::new_x(float x_, int w) {
    return int(((1-(x_/-6000))*(w))/2);
}
int Body::new_y(float y_, int h) {
    return int(((1-(y_/8000))*(h))/2);
}

float Body::getLabelX() const {
    return (x) + 25;
}
float Body::getLabelY() const {
    return (y - (r *3));
}

double Body::getM() const{
    return m;
}
int Body::getR() const {
    return r;
}

QString Body::getName() const {
    return name;
}
float Body::getScale() const {
    return scale;
}
int Body::getId() const{
    return  id;
}
