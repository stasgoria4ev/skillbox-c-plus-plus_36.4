#include <QPaintEvent>
#include <QApplication>
#include <QSlider>
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QVBoxLayout>

class Circle : public QWidget {
    //Q_OBJECT
public:
    Circle() = default;
    explicit Circle(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    [[nodiscard]] QSize minimumSizeHint() const override;
public slots:
    void setGreen();
    void setYellow();
    void setRed();
private:
    QPixmap mCurrentColorCirclePixmap;
    QPixmap mGreenCirclePixmap;
    QPixmap mYellowCirclePixmap;
    QPixmap mRedCirclePixmap;
};

Circle::Circle(QWidget *parent) {
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mGreenCirclePixmap = QPixmap("C:/Users/stas/Pictures/circle_green.png");
    mYellowCirclePixmap = QPixmap("C:/Users/stas/Pictures/circle_yellow.png");
    mRedCirclePixmap = QPixmap("C:/Users/stas/Pictures/circle_red.png");
    mCurrentColorCirclePixmap = mGreenCirclePixmap;
    setGeometry(mCurrentColorCirclePixmap.rect());
}

void Circle::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentColorCirclePixmap);
}

QSize Circle::minimumSizeHint() const {
    return {100,100};
}

void Circle::setGreen() {
    mCurrentColorCirclePixmap = mGreenCirclePixmap;
    update();
}
void Circle::setYellow() {
    mCurrentColorCirclePixmap = mYellowCirclePixmap;
    update();
}
void Circle::setRed() {
    mCurrentColorCirclePixmap = mRedCirclePixmap;
    update();
}

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget(nullptr);//родитель
    Circle circle(window);//наш круг в родительском окне
    circle.setFixedSize(200,200);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setMaximum(0);
    slider->setMaximum(100);

    QVBoxLayout *layout = new QVBoxLayout(window);
    layout->addWidget(&circle);
    layout->addWidget(slider);

    QObject::connect(slider, &QSlider::valueChanged, [&circle] (int newValue)
    {
        if (newValue >= 0 && newValue <= 32)
            circle.setGreen();
        else if (newValue >= 33 && newValue <= 66)
            circle.setYellow();
        else
            circle.setRed();
    });

    window->show();

    QApplication::exec();
}
