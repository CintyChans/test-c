#include <QtWidgets>

int main(int argc,char * argv[])
{
    QApplication a(argc,argv);
 
    QWidget * widget=new QWidget(0,Qt::Dialog|Qt::FramelessWindowHint);
 
    widget->setWindowTitle(QObject::tr("我是widget"));
 
    QLabel * label=new QLabel(0,Qt::SplashScreen|Qt::WindowStaysOnTopHint);
    label->setWindowTitle(QObject::tr("我是label"));
 
    label->setText(QObject::tr("label:我是窗口"));
 
    label->resize(260,20);
  
    QLabel * label2=new QLabel(widget);
    label2->setText(QObject::tr("label2:我不是独立的窗口，只是widget的子部件"));
    label2->resize(260,20);
  
    label->show();
    widget->show();

    delete label;
    delete widget;
    return a.exec();
}
