#include "AppWrapper.h"

AppWrapper::AppWrapper(QObject *parent) : QObject(parent),
    mNetManger(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{

}

bool AppWrapper::initialize()
{
    // QQmlApplicationEngine engine;
    mEngine.rootContext()->setContextProperty("Wrapper", this);
    resetModel(); // 初始化时直接设置model，而不是请求后初始化，避免listView那报model未初始化

    mEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (mEngine.rootObjects().isEmpty()){
        return false;
    }
    else{
        return true;
    }
}

void AppWrapper::resetModel()
{
    mEngine.rootContext()->setContextProperty("myModel", QVariant::fromValue(mJokes));
}

void AppWrapper::fetchPost(int number)
{
    // 初始化API数据
    const QUrl API_ENDPOINT("http://api.icndb.com/jokes/random/" + QString::number(number));
    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);
    // request.setHeader(QNetworkRequest::UserAgentHeader, QVariant("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.88 Safari/537.36"));
    // 赋值获取网络报文
    mNetReply = mNetManger->get(request);
    connect(mNetReply, &QIODevice::readyRead, this, &AppWrapper::dataReadyRead);
    connect(mNetReply, &QNetworkReply::finished, this, &AppWrapper::dataReadFinished);
}

void AppWrapper::removeLast()
{
    if(!mJokes.isEmpty()){
        mJokes.removeLast();
        resetModel();   // 很关键，重新更新myModel中的数据，不然点remove按钮没效果
    }
}

QStringList AppWrapper::jokes() const
{
    return mJokes;
}

void AppWrapper::dataReadyRead()
{
    mDataBuffer->append(mNetReply->readAll());
}

void AppWrapper::dataReadFinished()
{
    // 解析Json
    if(mNetReply->error()){
        qDebug() << "there some error: " << mNetReply->errorString();
    }
    else{
        // 转换数据为Json document
        QJsonDocument doc = QJsonDocument::fromJson(*mDataBuffer);
        // 获取value array
        QJsonObject data = doc.object();

        QJsonArray array = data["value"].toArray();
        for(int i=0; i<array.size(); i++){
            QJsonObject obj = array.at(i).toObject();
            QString joke = obj["joke"].toString();

            mJokes.append(joke);
            qDebug() << joke;
        }

        if(array.size() != 0){
            resetModel();
        }

        mDataBuffer->clear();
    }
}
