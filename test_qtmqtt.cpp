#include <QCoreApplication>
#include <QtMqtt/QMqttClient>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;
int globalVariable = 0;

void _publish(QMqttClient &client)
{
    auto now = steady_clock::now();
    client.publish(QMqttTopicName("test_echo"), std::to_string(duration_cast<nanoseconds>(now.time_since_epoch()).count()).c_str(), 0);
    qDebug() << "time" << now.time_since_epoch().count() << ",topic published" << globalVariable;
    globalVariable++;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QMqttClient client;
    client.setHostname("127.0.0.1"); // 设置MQTT服务器的主机名
    client.setPort(1883);            // 设置MQTT服务器的端口

    QObject::connect(&client, &QMqttClient::connected, [&client]()
                     {
                           
                             qDebug() << "Connected to MQTT server";
                             // 订阅主题
                             auto subscription = client.subscribe(QMqttTopicFilter("test_echo"), 0); // 订阅"test_echo"主题,qos=0
                             if (!subscription)
                             {
                                 qDebug() << "Failed to subscribe to topic";
                                 return;
                             }
                             QObject::connect(subscription, &QMqttSubscription::stateChanged, [&client](QMqttSubscription::SubscriptionState state)
                                              { qDebug() << "Subscription state:" << state;
                                              if (state==QMqttSubscription::SubscriptionState::Subscribed){
                                                  _publish(client);
                                              } });
                             QObject::connect(subscription, &QMqttSubscription::messageReceived, [&client](const QMqttMessage &message)
                                              {
                                 auto now = steady_clock::now();
                                 qDebug() << "time" << now.time_since_epoch().count() << ",topic received ";
                                 double delay = double(duration_cast<nanoseconds>(now.time_since_epoch()).count() - std::stoll(message.payload().toStdString())) / 1000000.0;
                                 qDebug() << "time elapsed" << delay << " ms \n";
                                //  std::this_thread::sleep_for(1000ms);
                                 _publish(client); }); });

    client.connectToHost(); // 连接到MQTT服务器

    return app.exec();
}