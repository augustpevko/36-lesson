#include "circle.h"
#include <QPainter>

Circle::Circle(QWidget* parent) {
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mGreenCircle = QPixmap("green.png");
    mYellowCircle = QPixmap("yellow.png");
    mRedCircle = QPixmap("red.png");
    mCurrentColorPixmap = mGreenCircle;
    setGeometry(mCurrentColorPixmap.rect());
}

void Circle::paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    painter.drawPixmap(e->rect(), mCurrentColorPixmap);
}

QSize Circle::minimumSizeHint() const {
    return QSize(100, 100);
}

void Circle::setGreen() {
    mCurrentColorPixmap = mGreenCircle;
    update();
}

void Circle::setYellow() {
    mCurrentColorPixmap = mYellowCircle;
    update();
}

void Circle::setRed() {
    mCurrentColorPixmap = mRedCircle;
    update();
}