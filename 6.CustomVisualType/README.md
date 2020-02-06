**“纸上得来终觉浅，绝知此事要躬行。”  —— 陆游**

**"Practice，practice，practice and summary make perfect" —— dyliuti**

------



<br>

**简介：**

Qt Quick中所有可见的Item都是继承于QQuickItem的，虽然QQuickItem自身没可视外观，但它定义了所有可视项目中常见的属性，比如x和y位置、宽度和高度、锚(anchor)和键处理支持，如setWidth和setHeight分别可设置这个Item的宽高。可以子类化QQuickItem来提供您自己的自定义可视项，它继承了这些特性。

QQuickPaintedItem类提供了一种在QML场景图中使用QPainter API的方法。

QQuickPaintedItem使QPainter API与QML场景图一起使用成为可能。它在场景图中设置一个纹理矩形，并使用QPainter在纹理上进行绘制。呈现目标可以是QImage，也可以是使用OpenGL时的QOpenGLFramebufferObject。当渲染目标是QImage时，QPainter首先渲染到图像中，然后将内容上传到纹理中。当使用QOpenGLFramebufferObject时，QPainter直接在纹理上绘图。调用update()来触发重绘。

<br>

**一：QML中绘制可视化图像的几种方式：**

1.继承于QQuickItem，然后重新实现了虚函数paint()。

2.实现QML中Canvas的onPaint()。

<br>

**文件说明：**

1.PaintOnImage：LearnQtLogo类就是继承于QQuickItem，然后重新实现了虚函数paint()。可以使用QPainter中的任意绘图函数。将LearnQtLogo类通过qmlRegisterType注册到QML中，在QML中创建该对象，以及结合元对象系统的属性来进行Cpp与QML交互。  

2.BarChart：还是继承于QQuickItem，不过这次纯用画笔和画刷绘柱状图与文字。  

3.BarChartListProperties：QQmlListProperty <Stair> stairs作为属性（实现了追加元素回调函数），可以在QML中使用staires作为属性，而qmlRegisterType<StairChart >和<Stair>则可以在QML中创建这两个类。QML中创建类后进入Cpp中的Paint事件进行绘制。这里遍历了m_stairs，使用Stair的属性从而绘制出不同的柱状图。分离出了UI元素，使其在QML中创建。  

4.QMLCanvas：在QML中使用Canvas (通过getContext(‘2d’得到)的onPaint中绘制。  

