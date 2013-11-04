HarrixQtLibraryForLaTeX
=======================

Версия 1.4.

Библиотека для отображения различных данных в LaTeX файлах.

https://github.com/Harrix/HarrixQtLibraryForLaTeX

Библиотека распространяется по лицензии [Apache License, Version 2.0](../master/LICENSE.txt).

Функции для получения LaTeX кода 
--------------------------------

- Возвращает начало для полноценного Latex файла.

        QString HQt_LatexBegin();

- Возвращает концовку для полноценного Latex файла.

        QString HQt_LatexEnd();

- Функция возвращает строку с выводом некоторой строки с Latex кодами. Для добавление в Latex файл.

        QString HQt_LatexShowText (QString TitleX);

- Функция возвращает строку с выводом некоторой строки с Latex кодами без всякого излишевства. Для добавление в Latex файл.

        QString HQt_LatexShowSimpleText (QString String);

- Функция возвращает строку с выводом горизонтальной линии. Для добавление в Latex файл.

        QString HQt_LatexShowHr ();

- Функция возвращает строку с выводом некоторой строки в виде заголовка. Для добавление в Latex файл.

        QString HQt_LatexShowSection (QString String);

- Функция возвращает строку с выводом некоторой строки в виде подзаголовка. Для добавление в Latex файл.

        QString HQt_LatexShowSubsection (QString String);

- Функция возвращает строку с выводом некоторого предупреждения. Для добавление в Latex файл.

        QString HQt_LatexShowAlert (QString String);

- Функция возвращает строку с выводом некоторого числа VMHL_X с Latex кодами. Для добавление в Latex файл.

        template <class T> QString THQt_LatexShowNumber (T VMHL_X, QString TitleX, QString NameX);

- Функция возвращает строку с выводом некоторого числа VMHL_X с Latex кодами. Для добавление в Latex файл.

        template <class T> QString THQt_LatexShowNumber (T VMHL_X, QString NameX);

- Функция возвращает строку с выводом некоторого числа VMHL_X с Latex кодами. Для добавление в Latex файл.

        template <class T> QString THQt_LatexShowNumber (T VMHL_X);
		
- Функция выводит число VMHL_X в строку Latex, причем число выделено жирным.

        template <class T> QString THQt_LatexNumberToText (T VMHL_X);		
		
- Функция возвращает строку с выводом некоторого вектора VMHL_Vector с Latex кодами. Для добавление в Latex файл.

        template <class T> QString THQt_LatexShowVector (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);
		
- Функция возвращает строку с выводом некоторого вектора VMHL_Vector с Latex кодами. Для добавление в Latex файл.

        template <class T> QString THQt_LatexShowVector (T *VMHL_Vector, int VMHL_N, QString NameVector);

- Функция возвращает строку с выводом некоторого вектора VMHL_Vector с Latex кодами. Для добавление в Latex файл.

        template <class T> QString THQt_LatexShowVector (T *VMHL_Vector, int VMHL_N);

- Функция возвращает строку с выводом некоторого вектора VMHL_Vector в траснпонированном виде с Latex кодами. Для добавление в Latex файл.

        template <class T> QString THQt_LatexShowVectorT (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);

- Функция возвращает строку с выводом некоторого вектора VMHL_Vector в траснпонированном виде с Latex кодами. Для добавление в Latex файл.

        template <class T> QString THQt_LatexShowVectorT (T *VMHL_Vector, int VMHL_N, QString NameVector);

- Функция возвращает строку с выводом некоторого вектора VMHL_Vector в траснпонированном виде с Latex кодами. Для добавление в Latex файл.

        template <class T> QString THQt_LatexShowVectorT (T *VMHL_Vector, int VMHL_N);
		
- Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами. Для добавление в Latex файл.

        template <class T> QString THQt_LatexShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix);

- Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами. Для добавление в Latex файл.

        template <class T> QString THQt_LatexShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString NameMatrix);

- Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами. Для добавление в Latex файл.

        template <class T> QString THQt_LatexShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M);
		
- Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами. Для добавление в Latex файл.

        template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine, bool ForNormalSize);

- Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами. Для добавление в Latex файл. По сравнению с основной функцией тут отсутствует параметр ForNormalSize.

        template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);

- Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами. Для добавление в Latex файл. По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine.

        template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints);

- Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами. По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine и все остальные булевские переменные.

        template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label);

- Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами. Для добавление в Latex файл. По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine и все остальные булевские переменные, а также все переменные названий.

        template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N);


Скриншоты применения функций
----------------------------

![alt text](../master/images/example.png "Пример использования функций")

Пример использования функция вывода в Latex файл
-----------------------------------------------

Скопируйте файлы из списка в папку с исходниками вашего проекта.
- [HarrixQtLibraryForLaTeX.cpp](../master/HarrixQtLibraryForLaTeX.cpp)
- [HarrixQtLibraryForLaTeX.h](../master/HarrixQtLibraryForLaTeX.h)
- [HarrixQtLibrary.cpp](../master/HarrixQtLibrary.cpp)
- [HarrixQtLibrary.h](../master/HarrixQtLibrary.h)
- [HarrixMathLibrary.cpp](../master/HarrixQtLibrary.cpp)
- [HarrixMathLibrary.h](../master/HarrixQtLibrary.h)
- [HarrixMathLibrary.cpp](../master/HarrixQtLibrary.cpp)
- [HarrixMathLibrary.h](../master/HarrixQtLibrary.h)
- [mtrand.cpp](../master/mtrand.cpp)
- [mtrand.h](../master/mtrand.cpp)

А файлы из списка в папку, где у вас должен быть Latex документ.
- [styles.tex](../master/styles.tex)
- [packages.tex](../master/packages.tex)
- [names.tex](../master/names.tex)

Добавьте  соответствующие инклуды:

```cpp
#include "HarrixQtLibrary.h"
#include "HarrixQtLibraryForLaTeX.h"
#include "HarrixMathLibrary.h"
```

Объявите, например, в mainwindow.h глобальные переменные:

```cpp
QString DS;//разделитель между папками: слэш или иное в данной ОС
QString Path;//путь к папке с программой
QString LaTeX;//сюда кладется выводимый текст
```

Вам нужно вызвать данные 4 строчки, например, в конструкторе ``MainWindow::MainWindow(QWidget *parent)``:

```cpp
DS=QDir::separator();//какой разделитель используется в пути между папками
Path=QGuiApplication::applicationDirPath()+DS;//путь к папке, где находится приложение
```
	
Теперь в любом месте, где хотите добавить текст html и его отобразить, пишите:

```cpp
    QString Latex;

    Latex+=HQt_LatexBegin();

    ////////////////////////////////////////////////////////

    Latex+=HQt_LatexShowSection("Рассказ");

    Latex+=HQt_LatexShowSubsection("Nen");

    Latex+=HQt_LatexShowText("Вот так я нашел истину");

    Latex+=HQt_LatexShowSimpleText("И это была логика.");

    Latex+=HQt_LatexShowHr ();

    Latex+=HQt_LatexShowAlert ("Внимание!! Нельзя купить или продать!");

    double y=5.987;
    Latex+=THQt_LatexShowNumber (y, "Положение крабовой палочки ", "y");

    Latex+=THQt_LatexShowNumber (y,"y");

    Latex+=THQt_LatexShowNumber (y);

    ////////////////////////////////////////////////////////

    Latex+=HQt_LatexEnd();
    HQt_SaveFile(Latex, Path+"Example.tex");
```
	
И теперь у нас есть Latex **Example.tex**, в котором у нас находится наш текст.


История проекта
---------------

Подробный список изменений в файле [CHANGELOG.md](../master/CHANGELOG.md).

Контакты
--------

Автор: Сергиенко Антон Борисович.

С автором можно связаться по адресу sergienkoanton@mail.ru или  http://vk.com/harrix.

Сайт автора, где публикуются последние новости: http://blog.harrix.org, а проекты располагаются по адресу: http://harrix.org.