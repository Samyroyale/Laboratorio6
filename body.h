#ifndef BODY_H
#define BODY_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <math.h>
#include <QtDebug>
#include <QLabel>

class Body : public QObject, public QGraphicsItem {
    Q_OBJECT

public: // Variables
    QLabel *label;

private: // Variables
    double x, y;
    double m;
    int r;
    double V0x, V0y;
    double Ax, Ay;

    int id;
    QString name;
    QString color;

    int w, h, ymax, xmin;

    double T;
    double G;

    float scale;

public: // Methods
    explicit Body(QObject *parent = nullptr, int id_ = 0, QString name_ = "", QString color_ = "", double x_ = 0, double y_= 0, double m_= 0, int r_= 0, double V0x_= 0, double V0y_= 0);
    ~Body();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    bool is_empty();

    void calculate_Ax(QList<Body *> bods);
    void calculate_Ay(QList<Body *> bods);

    void update(int w, int h);

    double getX() const;
    double getY() const;

    int new_x(float x_, int w);
    int new_y(float y_, int h);

    float getLabelX() const;
    float getLabelY() const;

    double getM() const;
    int getR() const;

    QString getName() const;
    float getScale() const;
    int getId() const;

private: // Methods

};

#endif // BODY_H
