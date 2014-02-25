HarrixQtLibraryForQWebView
==========================

Версия 1.14

Библиотека для отображения различных данных в [QWebView](http://qt-project.org/doc/qt-5.0/qtwebkit/qwebview.html), включая графики.

[https://github.com/Harrix/HarrixQtLibraryForQWebView](https://github.com/Harrix/HarrixQtLibraryForQWebView)

Библиотека распространяется по лицензии [Apache License, Version 2.0](https://github.com/Harrix/HarrixQtLibraryForQWebView/blob/master/LICENSE.txt).

Установка
---------

Подробно о установке с подробным примером можно прочитать тут [http://blog.harrix.org/?p=1196](http://blog.harrix.org/?p=1196).

Функции для получения HTML кода для вывода в QWebView
-----------------------------------------------------

- Функция обнуляет переменную HTML. Требуется когда нужно перезапустить показ информации в QWebView.

        void HQt_BeginHtml(QString Path);  

- Функция добавляет код html к существующему и сохраняет его в temp.html.

        void HQt_AddHtml(QString Html);  

- Функция выводит число VMHL_X в строку.

        template <class T> QString THQt_NumberToText (T VMHL_X);  

- Функция возвращает строку с выводом некоторой строки с HTML кодами. Для добавление в html файл.

        QString HQt_ShowText (QString TitleX);

- Функция возвращает строку с выводом некоторой строки с HTML кодами без всякого излишеств. Для добавление в html файл.

        QString HQt_ShowSimpleText (QString String);  

- Функция возвращает строку с выводом некоторой строки в виде заголовка. Для добавление в html файл.

        QString HQt_ShowH1 (QString String);  

- Функция возвращает строку с выводом горизонтальной линии. Для добавление в html файл.

        QString HQt_ShowHr ();  

- Функция возвращает строку с выводом некоторого предупреждения. Для добавление в html файл.

        QString HQt_ShowAlert (QString String);  

- Функция возвращает строку с выводом некоторого числа VMHL_X с HTML кодами.

        template <class T> QString THQt_ShowNumber (T VMHL_X, QString TitleX, QString NameX);
		template <class T> QString THQt_ShowNumber (T VMHL_X, QString NameX);
		template <class T> QString THQt_ShowNumber (T VMHL_X);  

- Функция возвращает строку с выводом некоторый вектора VMHL_Vector с HTML кодами.

        template <class T> QString THQt_ShowVector (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);
		template <class T> QString THQt_ShowVector (T *VMHL_Vector, int VMHL_N, QString NameVector);
		template <class T> QString THQt_ShowVector (T *VMHL_Vector, int VMHL_N);
		QString THQt_ShowVector (QStringList VMHL_Vector, QString TitleVector, QString NameVector); 
		QString THQt_ShowVector (QStringList VMHL_Vector, QString NameVector);
		QString THQt_ShowVector (QStringList VMHL_Vector);  	

- Функция возвращает строку с выводом некоторый вектора VMHL_Vector в транспонированном виде с HTML кодами.

        template <class T> QString THQt_ShowVectorT (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);
		template <class T> QString THQt_ShowVectorT (T *VMHL_Vector, int VMHL_N, QString NameVector);
		template <class T> QString THQt_ShowVectorT (T *VMHL_Vector, int VMHL_N);

- Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами.

        template <class T> QString THQt_ShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix);
		template <class T> QString THQt_ShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString NameMatrix);
		template <class T> QString THQt_ShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M);
		QString THQt_ShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString TitleMatrix, QString NameMatrix);
		QString THQt_ShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString NameMatrix);
		QString THQt_ShowMatrix (QStringList *VMHL_Matrix, int VMHL_N);

- Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в HTML файл.

        template <class T> QString THQt_ShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);  

- Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в HTML файл. Отличается от основной функцией отсутствием параметра NameLine(название первого графика (для легенды)).

        template <class T> QString THQt_ShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine); 
		template <class T> QString THQt_ShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine);
		template <class T> QString THQt_ShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N);  

- Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в HTML файл.

        template <class T> QString THQt_ShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
        template <class T> QString THQt_ShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
        template <class T> QString THQt_ShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2); 
        template <class T> QString THQt_ShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N);		   

- Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.

        template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
		template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
		template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2);
		template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2);

- Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Первый столбец - это значения вектора X, одинакового для всех графиков. Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.

        template <class T> QString THQt_ShowChartsOfLineFromMatrix (T VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
		template <class T> QString THQt_ShowChartsOfLineFromMatrix (T VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
		template <class T> QString THQt_ShowChartsOfLineFromMatrix (T VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine);
		template <class T> QString THQt_ShowChartsOfLineFromMatrix (T VMHL_MatrixXY,int VMHL_N,int VMHL_M); 

- Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл. Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие значения Y. То есть графики друг от друга независимы. Количество графиков равно половине столбцов в матрице.

        template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
		template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
		template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine);
		template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M);         

- Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий. Для добавление в html файл.

        template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
		template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
		template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2); 
		template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2);

- Функция возвращает строку с HTML кодом отрисовки линии по функции Function. Для добавление в html файл.

        QString HQt_DrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
		QString HQt_DrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
		QString HQt_DrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine);
		QString HQt_DrawLine (double Left, double Right, double h, double (*Function)(double));		

Скриншоты примеров вывода информации
------------------------------------

![alt text](https://raw.github.com/Harrix/HarrixQtLibraryForQWebView/master/imagesforgithub/graph.png "Вывод графика")

![alt text](https://raw.github.com/Harrix/HarrixQtLibraryForQWebView/master/imagesforgithub/matrix.png "Вывод матриц")

![alt text](https://raw.github.com/Harrix/HarrixQtLibraryForQWebView/master/imagesforgithub/vectors.png "Вывод векторов")
		
Использованные технологии
-------------------------

- [Qt](http://qt-project.org/), [JSXGraph](https://github.com/jsxgraph/jsxgraph), [Html](http://ru.wikipedia.org/wiki/HTML), [AJAX](http://ru.wikipedia.org/wiki/AJAX), [jQuery](http://jquery.com/).
- [HarrixQtLibrary](https://github.com/Harrix/HarrixQtLibrary).

История проекта
---------------

Подробный список изменений в файле [CHANGELOG.md](https://github.com/Harrix/HarrixQtLibraryForQWebView/blob/master/CHANGELOG.md).

Контакты
--------

Автор: Сергиенко Антон Борисович.

С автором можно связаться по адресу [sergienkoanton@mail.ru](mailto:sergienkoanton@mail.ru) или  [http://vk.com/harrix](http://vk.com/harrix).

Сайт автора, где публикуются последние новости: [http://blog.harrix.org](http://blog.harrix.org), а проекты располагаются по адресу: [http://harrix.org](http://harrix.org).