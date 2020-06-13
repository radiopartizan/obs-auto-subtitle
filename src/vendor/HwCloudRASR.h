//
// Created by Yibai Zhang on 2020/6/10.
//

#ifndef OBS_AUTO_SUBTITLE_HW_RASR_H
#define OBS_AUTO_SUBTITLE_HW_RASR_H
#include <QObject>
#include <QString>
#include <QWebSocket>
#include <memory>

#include "ASRBase.h"

#define HWCLOUD_SIS_ENDPOINT "sis-ext.cn-north-4.myhuaweicloud.com"
#define HWCLOUD_SIS_RASR_URI "/v1/%1/rasr/continue-stream"

class HwCloudRASR : public ASRBase {
    Q_OBJECT
public:
    HwCloudRASR(const QString &project_id, const QString &token, QObject *parent = nullptr);
    QString getProjectId();
    QString getToken();

    ~HwCloudRASR();

signals:
    void textMessageReceived(const QString message);
    void haveResult(QString message, int type);

private slots:
    void onStart();
    void onStop();
    void onConnected();
    void onDisconnected();
    void onTextMessageReceived(const QString message);
    void onSendAudioMessage(const void *, unsigned long);
    void onResult(QString message, int type);
    void onError(QAbstractSocket::SocketError error);
private:
    QString project_id;
    QString token;
    QWebSocket ws;
    bool running;

};

#endif //OBS_AUTO_SUBTITLE_HW_RASR_H