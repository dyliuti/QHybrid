**“纸上得来终觉浅，绝知此事要躬行。”  —— 陆游**

**"Practice，practice，practice and summary make perfect" —— dyliuti**

------



<br>

**简介：**

Cpp作为后台处理一些网络请求、Json解析、复杂运算，QML设计UI将结果显示。  

**总结：**

**一.qmlRegisterType相关的几种形式：**

1..qmlRegisterType< Type>("URI", 1, 0, "别名")

应用场景：可在qml初始化，有别名。 别名{name:...}。

2.qmlRegisterUncreatableType< Type>("URI", 1, 0, "别名", "提示：不能在qml创建")

应用场景：经常用于Enums或者附加属性attached properties(具有附加属性的附加类型) 纯虚类也是可以的

一.类型有名字和类型；二.不能在qml中用别名实例化Type；三.当你在qml中实例化该类型时，错误消息显示。

3.qmlRegisterType< Type>()

应用场景：一.不能在qml中实例化Type；二.Type不需要被别名引用 。

**二.qmlRegisterType相关的注册与setContextProperty相关注册方法的区别：**

使用qmlRegisterType等函数注册后，需要使用注册的类时需要引入库函数。而setContextProperty等注册后的类或属性是全局变量，在任意qml文件中都可以直接用。

<br>

**文件说明：**

1.CustomTypeCounter： 使用qmlRegisterType在qml中注册Cpp类，并调用其注册到元对象中的属性和方法。  Q_ENUM可将枚举类型注册到元对象系统。

2.EnumRegister：使用qmlRegisterUncreatableType在qml中注册Cpp中的enum类型，并使用。使用该方法注册后的类，不能在QML中初始化该类。以及一种更加轻量化的enum注册方法，使用Q_GADGET宏。Q_GADGET宏是Q_OBJECT宏的较轻版本，适用于那些不从QObject继承但仍然希望使用QMetaObject提供的一些反射功能的类。就像Q_OBJECT宏一样，它必须出现在类定义的私有部分中。 

3.EnumCounter：还是1.*的代码，不用Enum而用布尔变量作为计数增加还是减少的条件判断。注册多个Cpp类可以用同一个URI。  

4.ObjectListAndProperties：程序逻辑就是一个FootballTeam中有很多个Player，此时的FootballTeam与Player都要在QML中初始化，所以用qmlRegisterType来注册这两个类，且这两个类中在qml中要用到的属性需要在Cpp中用Q_PROPERTY声明。  

**注意**：FootballTeam中的players属性，它在Cpp中声明的类型是QQmlListProperty<Player>，意味着对QML中的players列表进行数据项添加，QML会调用Cpp给的回调函数

QQmlListProperty::AppendFunction（必须得实现）

QQmlListProperty::CountFunction

QQmlListProperty::AtFunction

如果进行项删除，QML会调用回调函数QQmlListProperty::ClearFunction)

**备注**：Q_PROPERTY(QQmlListProperty<Player> players READ players);无需setter，因为QQmlListProperty就没重载=运算符！  

5.InheritedTypes：程序逻辑同4.*，不过此时Player是个纯虚函数类，不能直接创建。从Player中继承、实现虚函数，实现具体的运动位置选手，如Defender、Striker。

Striker、Defender等继承于Player，需要在QML中实例化，所以用qmlRegisterType。但其父类Player不可实例化，需要qmlRegisterUncreatableType进行显示说明，若忽略这一步的话，在QML中实例化Defender会在Debug中显示实例化Player的警告消息等。  

6.GroupedProperties：在纯虚函数类Player中多了PlayDetails* details属性，PlayDetails类包含多个属性。PlayDetails属于定制的类型，需要向qml中注册下该类型，使QML engine知道Player有这么个属性，然后才可以在QML中使用其作为属性。又因为该类型声明是在纯虚函数Player类中的，Player不能在QML中实例化，PlayDetails自然也不能，所以用qmlRegisterType< PlayDetails>()。其只是用作QML中的属性，不需要类的别名。

7.AttachedProperties：TimerAttached作为Timer的附加属性，为定制类需要向QML注册该类型。

8.PropertyValueSource： QQmlPropertyValueSource类是属性值的接口。这里相当于将QML中Rectangle的radius属性配了RandomNumber接口。setTarget(const QQmlProperty &prop)将radius属性引用到Cpp，然后在Cpp中定时改变其值，达到动画的效果。



