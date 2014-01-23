HarrixQtLibraryForLaTeX
=======================

Версия 1.18

Библиотека для отображения различных данных в LaTeX файлах.

https://github.com/Harrix/HarrixQtLibraryForLaTeX

Библиотека распространяется по лицензии [Apache License, Version 2.0](../master/LICENSE.txt).

Функции для получения LaTeX кода 
--------------------------------

- Возвращает начало для полноценного Latex файла.

        QString HQt_LatexBegin();

- Возвращает концовку для полноценного Latex файла.

        QString HQt_LatexEnd();

- Функция возвращает строку с выводом некоторой строки с Latex кодами.

        QString HQt_LatexShowText (QString TitleX);

- Функция возвращает строку с выводом некоторой строки с Latex кодами без всякого излишевства.

        QString HQt_LatexShowSimpleText (QString String);

- Функция возвращает строку с выводом горизонтальной линии.

        QString HQt_LatexShowHr ();

- Функция возвращает строку с выводом некоторой строки в виде заголовка.

        QString HQt_LatexShowSection (QString String);

- Функция возвращает строку с выводом некоторой строки в виде подзаголовка.

        QString HQt_LatexShowSubsection (QString String);

- Функция возвращает строку с выводом некоторого предупреждения.

        QString HQt_LatexShowAlert (QString String);

- Функция возвращает строку с выводом некоторого числа VMHL_X с Latex кодами.

        template <class T> QString THQt_LatexShowNumber (T VMHL_X, QString TitleX, QString NameX);
        template <class T> QString THQt_LatexShowNumber (T VMHL_X, QString NameX);
        template <class T> QString THQt_LatexShowNumber (T VMHL_X);
		
- Функция выводит число VMHL_X в строку Latex, причем число выделено жирным.

        template <class T> QString THQt_LatexNumberToText (T VMHL_X);		
		
- Функция возвращает строку с выводом некоторого вектора VMHL_Vector с Latex кодами.

        template <class T> QString THQt_LatexShowVector (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);
        template <class T> QString THQt_LatexShowVector (T *VMHL_Vector, int VMHL_N, QString NameVector);
        template <class T> QString THQt_LatexShowVector (T *VMHL_Vector, int VMHL_N);
		QString THQt_LatexShowVector (QStringList VMHL_Vector, QString TitleVector, QString NameVector);
		QString THQt_LatexShowVector (QStringList VMHL_Vector, QString NameVector);
		QString THQt_LatexShowVector (QStringList VMHL_Vector);

- Функция возвращает строку с выводом некоторого вектора VMHL_Vector в транспонированном виде с Latex кодами.

        template <class T> QString THQt_LatexShowVectorT (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);
        template <class T> QString THQt_LatexShowVectorT (T *VMHL_Vector, int VMHL_N, QString NameVector);
        template <class T> QString THQt_LatexShowVectorT (T *VMHL_Vector, int VMHL_N);
		
- Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами.

        template <class T> QString THQt_LatexShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix);
        template <class T> QString THQt_LatexShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString NameMatrix);
        template <class T> QString THQt_LatexShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M);
		QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString TitleMatrix, QString NameMatrix);
		QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString NameMatrix);
		QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N);
		
- Функция возвращает строку с выводом начала рисунка, состоящего из нескольких рисунков или графиков.

        QString HQt_LatexBeginCompositionFigure ();

- Функция возвращает строку с выводом окончания рисунка, состоящего из нескольких рисунков или графиков.

        QString HQt_LatexEndCompositionFigure (QString TitleFigure, QString Label);
        QString HQt_LatexEndCompositionFigure (QString TitleFigure);
        QString HQt_LatexEndCompositionFigure ();

- Функция возвращает строку с Latex кодом при добавлении дополнительного рисунка или графика в рисунок, состоящего из нескольких рисунков.

        QString HQt_LatexBeginFigureInCompositionFigure ();

- Функция возвращает строку с Latex кодом после добавлении дополнительного рисунка или графика в рисунок, состоящего из нескольких рисунков.

        QString HQt_LatexEndFigureInCompositionFigure ();
		
- Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами.

        template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine, bool ForNormalSize);
        template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
        template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints);
        template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label);
        template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N);
		
- Функция возвращает строку с выводом некоторого двух графиков по точкам с Latex кодами.

        template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle);
		template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize);
		template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
		template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label);
		template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N);//Функция возвращает строку с выводом некоторого двух графиков по точкам с Latex кодами. У обоих графиков одинаковый массив значений X. По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine и все остальные булевские переменные, а также все переменные названий.

- Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с Latex кодами.

        template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle);
		template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize);
		template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
		template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label);
		template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2);//Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с Latex кодами. По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine и все остальные булевские переменные, а также все переменные названий.
		
- Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами. Первый столбец - это значения вектора X, одинакового для всех графиков. Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.

        template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle, bool SolidStyle, bool CircleStyle);
        template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize);
        template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
        template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label);
        template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M);
	
- Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами. Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие значения Y. То есть графики друг от друга независимы. Количество графиков равно половине столбцов в матрице.
	
        template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle, bool SolidStyle, bool CircleStyle);
        template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize);
        template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
        template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label);
        template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M);
        template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle, bool SolidStyle, bool CircleStyle);
        template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize);
        template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
        template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label);
        template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M);

- Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с Latex кодами. Для добавление в html файл. Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий. У обоих графиков разные массивы значений X и Y.

        template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle);
        template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize);
        template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
        template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label);
        template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2);

- Функция возвращает строку с Latex кодом отрисовки линии по функции Function.

        QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
        QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
        QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine);
        QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double));
		
- Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.

        template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize, bool MinZero);
        template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize);
        template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label);
        template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N);
		template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize, bool MinZero);
		template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize);
		template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label);

 - Функция возвращает строку с выводом некоторого 3D графика в виде множества точек.
 
        template <class T> QString THQt_LatexShow3DPlotPoints (T *VMHL_VectorX, T *VMHL_VectorY, T *VMHL_VectorZ,  int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, bool ForNormalSize);
        template <class T> QString THQt_LatexShow3DPlotPoints (T *VMHL_VectorX, T *VMHL_VectorY, T *VMHL_VectorZ,  int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, bool ForNormalSize);
        template <class T> QString THQt_LatexShow3DPlotPoints (T *VMHL_VectorX, T *VMHL_VectorY, T *VMHL_VectorZ,  int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label);
        template <class T> QString THQt_LatexShow3DPlotPoints (T *VMHL_VectorX, T *VMHL_VectorY, T *VMHL_VectorZ,  int VMHL_N);
		
 - Функция возвращает строку с выводом некоторого 3D графика в виде поверхности.
 
        template <class T> QString THQt_LatexShow3DPlot (T *VMHL_VectorX, T *VMHL_VectorY, T **VMHL_VectorZ,  int VMHL_N,  int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, double Opacity, double AngleHorizontal, double AngleVertical, bool ColorBar, bool ForNormalSize);
        template <class T> QString THQt_LatexShow3DPlot (T *VMHL_VectorX, T *VMHL_VectorY, T **VMHL_VectorZ,  int VMHL_N,  int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar, bool ForNormalSize);
        template <class T> QString THQt_LatexShow3DPlot (T *VMHL_VectorX, T *VMHL_VectorY, T **VMHL_VectorZ,  int VMHL_N,  int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar);
        template <class T> QString THQt_LatexShow3DPlot (T *VMHL_VectorX, T *VMHL_VectorY, T **VMHL_VectorZ,  int VMHL_N,  int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type);
        template <class T> QString THQt_LatexShow3DPlot (T *VMHL_VectorX, T *VMHL_VectorY, T **VMHL_VectorZ,  int VMHL_N,  int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label);
        template <class T> QString THQt_LatexShow3DPlot (T *VMHL_VectorX, T *VMHL_VectorY, T **VMHL_VectorZ,  int VMHL_N,  int VMHL_M);
		

Скриншоты применения функций
----------------------------

![alt text](../master/images/example.png "Пример использования функций")

![alt text](../master/images/example2.png "Пример использования функций")

![alt text](../master/images/example3.png "Пример использования функций")

![alt text](../master/images/example4.png "Пример использования функций")

![alt text](../master/images/example5.png "Пример использования функций")

![alt text](../master/images/example6.png "Пример использования функций")

![alt text](../master/images/example7.png "Пример использования функций")

![alt text](../master/images/example8.png "Пример использования функций")

![alt text](../master/images/example9.png "Пример использования функций")

Установка и использования функций вывода в Latex файл
-----------------------------------------------------

Скопируйте файлы из списка в папку с исходниками вашего проекта.
- [HarrixQtLibraryForLaTeX.cpp](../master/HarrixQtLibraryForLaTeX.cpp)
- [HarrixQtLibraryForLaTeX.h](../master/HarrixQtLibraryForLaTeX.h)
- [HarrixQtLibrary.cpp](../master/HarrixQtLibrary.cpp)
- [HarrixQtLibrary.h](../master/HarrixQtLibrary.h)
- [HarrixMathLibrary.cpp](../master/HarrixMathLibrary.cpp)
- [HarrixMathLibrary.h](../master/HarrixMathLibrary.h)
- [mtrand.cpp](../master/mtrand.cpp)
- [mtrand.h](../master/mtrand.cpp)

А файлы из списка ниже в папку, где у вас должен быть Latex документ.
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

    Latex+=HQt_LatexShowSubsection("Ten");

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

Сведения для редактирования файлов
----------------------------------

Для полноценной работы редактированию LaTeX документа вам потребуются программа для компиляции \*.tex документов в \*.pdf. Автор использует для этого связку [MiKTex](http://www.miktex.org/) и [TeXstudio](http://texstudio.sourceforge.net/). 

В варианте, который использует автор, в \*.tex файлах справок для отображения русских букв используется модуль pscyr. Об его установке можно прочитать (и скачать) в статье http://blog.harrix.org/?p=444.

Подробное описание установки и настройки связки MiKTeX + TeXstudio + pscyr можно прочитать в статье http://blog.harrix.org/?p=849.


История проекта
---------------

Подробный список изменений в файле [CHANGELOG.md](../master/CHANGELOG.md).

Контакты
--------

Автор: Сергиенко Антон Борисович.

С автором можно связаться по адресу sergienkoanton@mail.ru или  http://vk.com/harrix.

Сайт автора, где публикуются последние новости: http://blog.harrix.org, а проекты располагаются по адресу: http://harrix.org.