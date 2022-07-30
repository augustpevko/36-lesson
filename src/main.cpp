#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QSlider>
#include "circle.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto window = std::make_shared<QWidget>();
    auto slider = std::make_shared<QSlider>(Qt::Horizontal, window.get());
    slider->setMaximum(100);
    slider->setMinimum(0);

    auto circle = std::make_shared<Circle>(window.get());

    auto layout = std::make_shared<QVBoxLayout>(window.get());
    layout->addWidget(circle.get());
    layout->addWidget(slider.get());
    
    QObject::connect(slider.get(), &QSlider::valueChanged, [slider, circle](int newValue) {
        if (newValue < 33)
            circle->setGreen();
        else if (newValue > 32 && newValue < 66) 
            circle->setYellow();
        else 
            circle->setRed();
    });

    window->setFixedSize(200, 250);
    window->move(1000, 500);
    window->show();
    return QApplication::exec();
}