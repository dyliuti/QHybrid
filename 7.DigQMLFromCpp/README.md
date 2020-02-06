**“纸上得来终觉浅，绝知此事要躬行。”  —— 陆游**

**"Practice，practice，practice and summary make perfect" —— dyliuti**

------



<br>

**简介：**

在Cpp中获取QML中的对象、属性，调用QML中的方法，连接QML中的信号等。  

<br>

**总结：**

**一.Cpp中修改QML属性的两种方式及其区别：**

1.使用QQuickItem的setProperty，不会断开绑定。

2.使用QQmlProperty::write，会断开绑定。

**二.Cpp获取QML根对象的方式：**

1.使用QQmlApplicationEngine加载QML文档，再使用rootObjects()返回根对象们（返回前可用rootObjects().isEmpty()先判断下是否为空）。

2.使用QQmlComponent将qml文件作为一个组件，再使用create()得到该组件对象，即根对象。

<br>

**文件说明：**

1.LoadingQMLFilesConsoleCpp：使用QQmlComponent将qml文件作为一个组件加载，使用create()创建这个组件的一个实例 。进而在Cpp中获取QML中的对象及其属性，属性可通过QObject的property()方法获得。

2.ParsingCustomCppTypes： 与1.*相同方法，获取到QML中的对象后，进而在Cpp中获取QML中的list属性（在Cpp中定义）。使用QQmlListProperty<Player> players并qmlRegisterType<Player>与<FootBallTeam>，使其可以在QML中定义。QML定义时会调用Cpp中READ players中声明定义的回调函数。

3.QQuickViewLoadQML：使用QQuickView显示Qt Quick界面。QQuickView是QQuickWindow的一个方便的子类，当给定主源文件的URL时，它将自动加载并显示QML场景。之前都是使用QQmlComponent实例化对象，并将它们放在手动设置的QQuickWindow中。

4.QqmlApplicationEngine：使用QQmlApplicationEngine继承于QQmlEngine。该类结合了QQmlEngine和QQmlComponent来提供一个方便的方式来加载一个QML文件。QQuickItem的setProperty不会断开绑定，但QQmlProperty::write()方法会。

5.InvokeQMLMethod：在Cpp中通过QMetaObject::invokeMethod调用QML类中的方法。

6.QMLSignalCppSlot：在Cpp中的槽连接QML中的信号。  



