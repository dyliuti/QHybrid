**“纸上得来终觉浅，绝知此事要躬行。”  —— 陆游**

**"Practice，practice，practice and summary make perfect" —— dyliuti**

------



<br>

**简介：**

Qt与Cpp交互测试与总结。

<br>

**各文件夹说明文档总结汇总：**

## 1.ContextProperty

**一：Cpp类可暴露给QML的要求：**

要将Cpp中的一个类导入到qml中的前提与使用信号与槽的前提条件一样，都是为了引入元对象系统，这样方法和属性才可以通过字符串的形式来调用：

1.从QObject或QObject的派生类继承

2.使用Q_OBJECT宏

**二：setContextProperty与setContextObject：**

QML是需要QML引擎（即QQmlEngine）来解释执行的，所以QML中的全局变量本质是QML执行上下文QQmlContext的属性。定义QML全局变量也就是把我们的目标设置为QML执行上下文的属性。  setContextObject暴露类中的所有属性给QML，setContextProperty暴露对象作为QML执行上下文的属性。

**三：QML与Cpp属性相互绑定-QML中冒号与等号左边是属性时隐含的操作：**

1.“Qml的属性：Cpp中的属性”。执行该条语句后，等同于QML中生成了一个槽，关联Cpp中属性changed信号，一旦Cpp发送“属性名changed”信号，QML的属性得到更新。

2.在QML中使用“Cpp的属性=QML中的属性”。执行该条语句后，会通过元对象系统调用Cpp中的“set属性名”函数。

**四：如果QML上下文中某个全局变量构造很慢，可以通过QML中的`Loader`来很方便异步构造，从而加速程序启动**  

## 2.MetaTypeTransfer



## 3.RestAPI



## 4.RegisterType_OtherTypeTransfer



## 5.Model



## 6.CustomVisualType



## 7.DigQMLFromCpp