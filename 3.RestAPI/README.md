**“纸上得来终觉浅，绝知此事要躬行。”  —— 陆游**

**"Practice，practice，practice and summary make perfect" —— dyliuti**

------



<br>

**简介：**

Cpp作为后台处理一些网络请求、Json解析、复杂运算，QML设计UI将结果显示。  

<br>

**文件说明：**

1.RestAPIClientDemo：QML搭建UI(ListModel\View)，ListView以QStringList为model。QML调用Cpp类进行Cpp进行网络请求、Json数据解析。QStringList的数据改动或增删后，需通过mEngine.rootContext()->setContextProperty重新加载一次model来更新QML中的属性值，从而更改界面中的内容。    

2.RestAPIClientDemo2：也是采用Model\View结构，并将数据源与Model分离，此时数据源变动后只需更新需要变动的部分，不需要重新加载整个Model。这种思路可参考5.5与5.6。    



