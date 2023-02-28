#include<QApplication>
#include <QMainWindow>
int main(int argc,char* argv[])
{

    QApplication* qa=new QApplication(argc,argv);
    QMainWindow* qm=new QMainWindow();
    qm->show();
    return qa->exec();
}
