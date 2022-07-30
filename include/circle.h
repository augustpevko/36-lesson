#pragma once
#include <QWidget>
#include <QPixmap>
#include <QPaintEvent>

class Circle: public QWidget {
    Q_OBJECT
public:
    Circle() = default;
    Circle(QWidget* parent);
    void paintEvent(QPaintEvent* e) override;
    QSize minimumSizeHint() const override;
public slots:
    void setGreen();
    void setYellow();
    void setRed();
private:
    QPixmap mCurrentColorPixmap;
    QPixmap mGreenCircle;
    QPixmap mYellowCircle;
    QPixmap mRedCircle;
};
