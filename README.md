**“纸上得来终觉浅，绝知此事要躬行。”  —— 陆游**

**"Practice，practice，practice and summary make perfect" —— dyliuti**

------



<br>

**简介：**

Qt Quick与Cpp交互测试与总结。

<br>

**各文件夹说明文档总结汇总：**

## 1.ContextProperty

**一：Cpp类可暴露给QML的要求：**

要将Cpp中的一个类导入到qml中的前提与使用信号与槽的前提条件一样，都是为了引入元对象系统，这样方法和属性才可以通过字符串的形式来调用：

1.从QObject或QObject的派生类继承

2.使用Q_OBJECT宏

**二：setContextProperty与setContextObject介绍及注意点：**

QML是需要QML引擎（即QQmlEngine）来解释执行的，所以QML中的全局变量本质是QML执行上下文QQmlContext的属性。定义QML全局变量也就是把我们的目标设置为QML执行上下文的属性。  setContextObject暴露类中的所有属性给QML，setContextProperty暴露对象作为QML执行上下文的属性。

setContextProperty有两个重载函数，一个用于继承自QObject 的类，另一个更松点，能转换为QVariatn的类即可，即需要在元对象系统中注册过该类型（如QList属性用这种注册方法）。setContextObject只有前者。

此外，由于QML中求值的所有表达式都是在特定上下文中求值的，因此如果上下文被修改，那么该上下文中的所有绑定都将被重新求值。因此，应该在应用程序初始化之外小心使用上下文属性，因为这可能会导致应用程序性能下降。  

**三：QML与Cpp属性相互绑定-QML中冒号与等号左边是属性时隐含的操作：**

1.“QML的属性：Cpp中的属性”。执行该条语句后，等同于QML中生成了一个槽，关联Cpp中属性changed信号，一旦Cpp发送“属性名changed”信号，QML的属性得到更新。

2.在QML中使用“Cpp的属性=QML中的属性”。执行该条语句后，会通过元对象系统调用Cpp中的“set属性名”函数。

**四：如果QML上下文中某个全局变量构造很慢，可以通过QML中的`Loader`来很方便异步构造，从而加速程序启动**

## 2.MetaTypeTransfer

无

## 3.RestAPI

无

## 4.RegisterType_OtherTypeTransfer

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

## 5.Model

**一.关于modelData：**

没有指定角色的模型，将通过modelData角色提供数据。另外，只有一个角色的模型时也提供了modelData角色来供访问。如模型是QStringList，有个只读的modelData属性，可通过它访问model中的字符。

加上前缀限定1.便于阅读，知道从哪里来；2.模型属性名与委托属性名冲突时时，使用限定的模型名称访问角色。

如将Cpp的model暴露给QML。属性引用方式多样，如Cpp的names属性可以用下面任意一个：

text :  names

text :  modelData.names

text :  model.names

text :  model.modelData.names

model前缀为ListView的属性。若names是QML中ListElement中的属性，则不能用modelData前缀相关的进行访问。

**二.model/view效率最高的方式：**

使用继承于QAbstractItemModel的model，这样可以做到改动最小，就更新view。

## 6.CustomVisualType

**一：QML中绘制可视化图像的几种方式：**

1.继承于QQuickItem，然后重新实现了虚函数paint()。

2.实现QML中Canvas的onPaint()。

## 7.DigQMLFromCpp

**一.Cpp中修改QML属性的两种方式及其区别：**

1.使用QQuickItem的setProperty，不会断开绑定。

2.使用QQmlProperty::write，会断开绑定。

**二.Cpp获取QML根对象的方式：**

1.使用QQmlApplicationEngine加载QML文档，再使用rootObjects()返回根对象们（返回前可用rootObjects().isEmpty()先判断下是否为空）。

2.使用QQmlComponent将qml文件作为一个组件，再使用create()得到该组件对象，即根对象。