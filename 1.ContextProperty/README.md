**“纸上得来终觉浅，绝知此事要躬行。”  —— 陆游**

**"Practice，practice，practice and summary make perfect" —— dyliuti**

------



<br>

**简介：**

QML中使用Cpp属性、成员函数、信号的方法。Cpp中调用QML中JavaScript函数的方法。

<br>

**总结：**

**一：Cpp类可暴露给QML的要求：**

要将Cpp中的一个类导入到qml中的前提与使用信号与槽的前提条件一样，都是为了引入元对象系统，这样方法和属性才可以通过字符串的形式来调用：

1.从QObject或QObject的派生类继承

2.使用Q_OBJECT宏

**二：setContextProperty与setContextObject介绍及注意点：**

QML是需要QML引擎（即QQmlEngine）来解释执行的，所以QML中的全局变量本质是QML执行上下文QQmlContext的属性。定义QML全局变量也就是把我们的目标设置为QML执行上下文的属性。  setContextObject暴露类中的所有属性给QML，setContextProperty暴露对象作为QML执行上下文的属性。

setContextProperty有两个重载函数，一个用于继承自QObject 的类，另一个更松点，能转换为QVariatn的类即可，即需要在元对象系统中注册过该类型（如QList属性用这种注册方法）。setContextObject只有前者。

此外，由于QML中求值的所有表达式都是在特定上下文中求值的，因此如果上下文被修改，那么该上下文中的所有绑定都将被重新求值。因此，应该在应用程序初始化之外小心使用上下文属性，因为这可能会导致应用程序性能下降。  

**三：QML与Cpp属性相互绑定-QML中冒号与等号左边是属性时隐含的操作：**

1.“Qml的属性：Cpp中的属性”。执行该条语句后，等同于QML中生成了一个槽，关联Cpp中属性changed信号，一旦Cpp发送“属性名changed”信号，QML的属性得到更新。

2.在QML中使用“Cpp的属性=QML中的属性”。执行该条语句后，会通过元对象系统调用Cpp中的“set属性名”函数。

**四：如果QML上下文中某个全局变量构造很慢，可以通过QML中的`Loader`来很方便异步构造，从而加速程序启动**  



<br>

**文件说明：**

1.QmlCallCppMethod：QQmlApplicationEngine是QQmlEngine的继承类，提供了加载单个QML文件的便捷方法。setContextProperty(const QString &*name*, QObject **value*)可将Cpp中的QObject的继承类的实例暴露给QML，QML可通过name进行调用。

Cpp中的成员函数被元对象系统QMetaObject::invokeMethod()调用需要在函数前加上Q_INVOKABLE宏，将此函数注册为QMetaObject::InvokeMetaMethod。QMetaObject::invokeMethod为信号与槽而生，槽函数前不需要加这个宏。

究其原因的话，可以看下moc文件qt_meta_stringdata_*中的函数只有1.构造函数；2.信号函数；3.槽函数。最主要的还是函数指针qt_static_metacall中c == QMetaObject::InvokeMetaMethod条件中的switch的case项只有信号和槽。

而成员函数前加上Q_INVOKABLE宏，moc生成文件后，会在qt_meta_stringdata_*中加上该函数方法，也会在qt_static_metacall的InvokeMetaMethod加上该方法的调用。

**备注：**只有信号、槽以及被标记成Q_INVOKABLE的方法才能够被原对象系统调用，当然也可以跨线程调用。

2.QmlConnectCppSignalDemo：Qml中可通过Connections来设置Cpp的信号与Qml中的槽进行连接。target：信号发射对象，为Cpp对象在QML中的别名。

QML中的槽命名规则：将发射对象中的信号函数名前加上on，再安装驼峰命名。

流程：Qml的UI中调用Cpp元对象方法（复杂逻辑、运算处理），然后方法中然后触发信号，回到QML的UI中进行显示等。

3.QPropertyDemo：属性绑定的两种方向：

一.“Qml的属性：Cpp中的属性”。执行该条语句后，等同于QML中生成了一个槽，关联Cpp中属性changed信号，一旦Cpp发送“属性名changed”信号，QML的属性得到更新。

二.在QML中使用“Cpp的属性=QML中的属性”。执行该条语句后，会通过元对象系统调用Cpp中的“set属性名”函数。

Q_PROPERTY将属性注册到元对象系统。可以在moc生成文件qt_static_metacall中看到 属性名Changed的信号。并且set属性名和读属性名的函数也写进了qt_meta_stringdata_*，表明已经注册到了元对象系统。相应的qt_static_metacall中多了_c == QMetaObject::ReadProperty和_c == QMetaObject::WriteProperty等else if判断分支。

**备注：**Q_PROPERTY中的“set属性名”函数一定要emit 属性名Changed信号，QML中关联该Cpp属性的属性不会更新。而且若是双向绑定时，set函数在emit前一定要判断两个值是否相同，相同就退出函数，不进行相同判断就发送信号将会无限循环。

**备注：**功能实现来看，跟WPF中的Binding属性好像啊，如：Text = {Binding 属性}，但WPF中的get和set更加简洁。。。

4.ContextObjectDemo：QQmlContext::setContextObject(QObject *object*)可一次性得将Cpp中的定义的实例object中的所有属性注册到QML中，当做全局变量使用。

**备注：**setContextObject与setContextProperty注册后都是全局变量，任意qml文件都可以直接调用。区别在于，后者是用了别名，在QML中调用需要“别名.属性”，而前者类中的属性可在QML中直接调用。

5.CallJSFromCppDemo：Cpp中调用QML中的JavaScript函数需要使用元对象函数QMetaObject::invokeMethod。

