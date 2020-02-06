**“纸上得来终觉浅，绝知此事要躬行。”  —— 陆游**

**"Practice，practice，practice and summary make perfect" —— dyliuti**

------



<br>

**简介：**

测试model、view结构。如使用不同的model更新方式，分别使用Cpp的model与QML中的model于QML中的view关联等。

Z值的类型是real，因此可以将小数值设置为0.1。Z值越小越显示在底层。model/view相关的各组件显示层级如下：

|       属性       | 默认Z值 |
| :--------------: | :-----: |
|     delegate     |    1    |
|      footer      |    1    |
|      header      |    1    |
|    highlight     |    0    |
| section.delegate |    2    |

<br>

**总结：**

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

<br>

**文件说明：**

1.StringListModel： 将Cpp中的QStringList作为QML中ListView的model，Rectangle作为代理组件。

2.ObjectListModel：分别将Cpp中的QList和QML中的ListModel作为整体暴露给QML，使其作为ListView的model。需要注意，这里使用QList<QObject *>而不是QList<Person *>，因为自定义类型Person并没暴露给QML。此外，使用QML中的ListModel时，在ListView中不能使用含modelData的前缀。

3.EditableObjectListModel：将QList<QObject *>封装了一层，使其作为ObjectListWrapper的**成员变量**。需要注意的是ObjectListWrapper中的“set属性名”函数中的emit 信号都注释掉了，这意味着在QML中调用这些函数，与Cpp属性相绑定的QML属性将不会得到更新。这里采用重新加载Model来进行更新（不注释掉emit 信号就不需要这样）。这里的addPerson，必须重新加载Model来进行更新，无其他办法，后面会对这种进行优化。

4.EditableObjectListModelQproperty：高效得使用model/view构架，优化3.*，只改变需要改变的地方，而不需一变动就重新加载整个Model。使QList<QObject  *>作为ObjectListWrapper的**属性**，然后使其作为QML中ListView的model所绑定的对象model : Wrapper.mypersons。这样当addPerson时，只需要对model重新复制，而不是使用QML上下文重新加载model。Person中的属性改变，也是属性绑定的方法。

5.AbstractListModel：继续优化4.*，当addPerson时，需要对model重新拷贝，view需要重新渲染整个model的数据，这里通过使用QAbstractItemModel可以优化。因为QML使用ListView，可以使用QAbstractListModel（继承于QAbstractItemModel）更方便点。

将PersonModel继承于QAbstractListModel，QList<Person*> mPersons作为成员变量，注意下这里使用了Person而且Person是没注册到元对象系统的。因为向列表中添加元素时，是使用

```c++
QAbstractItemModel::beginInsertRows(const QModelIndex &parent, int first, int last)
```

是对注册到元对象系统了的QModelIndex进行操作。beginInsertRows函数中会发射rowsAboutToBeInserted。

QAbstractItemModel下面的这两个虚函数是可以被元对象系统调用的。其它的还有，可以在qabstractitemmodel.h中看到。

```c++
QVariant data(const QModelIndex &index, int role) const;
bool setData(const QModelIndex &index, const QVariant &value, int role);
```

QML中获取Cpp属性和“Cpp属性=值”时会调用下面这两个函数。如SpinBox中的model.age = value;和mSpinbox.value = model.age。这两个函数对数据的获取和修改起到了路由分发的作用，必须实现。

6.ExternalDataSource：解耦data source与model。 将5.*中的数据QList<Person *> mPersons以及与之相关的接口从PersonModel中分离出来形成DataSource类，将DataSource类作为PersonModel的一个属性。QML中直接对数据源mPersons进行操作，如addPerson()操作，但本质上还是需要QAbstractItemModel的同步函数，如beginInsertRows，所以在DataSource类进行插入删除操作时需要利用信号槽同步到QAbstractItemModel的beginInsertRows等。此外，QML中直接要用到DataSource，所以DataSource对象需要暴露给QML。

7.ModelListPropreties： 在QML中初始化Cpp中定义的Model和源数据。 



