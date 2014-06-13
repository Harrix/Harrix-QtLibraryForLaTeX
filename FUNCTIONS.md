Список функций библиотеки HarrixQtLibraryForLaTeX
=================================================

Главные загрузочные функции
----------------

- Возвращает начало для полноценного Latex файла для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate

```cpp
QString HQt_LatexBegin();
```

- Возвращает начало для полноценного Latex файла в виде статьи для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate.

```cpp
QString HQt_LatexBeginArticle();
```

- Возвращает начало для полноценного Latex файла в виде статьи для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate с использованием графиков через пакет pgfplots.

```cpp
QString HQt_LatexBeginArticleWithPgfplots();
```

- Возвращает начало для полноценного Latex файла для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate с использованием графиков через пакет pgfplots.

```cpp
QString HQt_LatexBeginWithPgfplots();
```

- Возвращает концовку для полноценного Latex файла для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate

```cpp
QString HQt_LatexEnd();
```

Графики
----------------

- Функция возвращает строку с Latex кодом отрисовки линии по функции Function.

```cpp
QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine);
QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double));
```

- Функция возвращает строку с Latex кодом отрисовки 3D поверхности по функции Function.

```cpp
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, double Opacity, double AngleHorizontal, double AngleVertical, bool ColorBar, bool ForNormalSize);
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar, bool ForNormalSize);
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar);
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type);
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label);
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double));
QString THQt_LatexDraw3DPlot (double Left, double Right, int N, double (*Function)(double, double));
```

- Функция возвращает строку с выводом некоторого 3D графика в виде поверхности.

```cpp
template <class T> QString THQt_LatexShow3DPlot (T *VMHL_VectorX, T *VMHL_VectorY, T **VMHL_VectorZ,  int VMHL_N,  int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, double Opacity, double AngleHorizontal, double AngleVertical, bool ColorBar, bool ForNormalSize);
template <class T> QString THQt_LatexShow3DPlot (T *VMHL_VectorX, T *VMHL_VectorY, T **VMHL_VectorZ,  int VMHL_N,  int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar, bool ForNormalSize);
template <class T> QString THQt_LatexShow3DPlot (T *VMHL_VectorX, T *VMHL_VectorY, T **VMHL_VectorZ,  int VMHL_N,  int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar);
template <class T> QString THQt_LatexShow3DPlot (T *VMHL_VectorX, T *VMHL_VectorY, T **VMHL_VectorZ,  int VMHL_N,  int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type);
template <class T> QString THQt_LatexShow3DPlot (T *VMHL_VectorX, T *VMHL_VectorY, T **VMHL_VectorZ,  int VMHL_N,  int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label);
template <class T> QString THQt_LatexShow3DPlot (T *VMHL_VectorX, T *VMHL_VectorY, T **VMHL_VectorZ,  int VMHL_N,  int VMHL_M);
```

- Функция возвращает строку с выводом некоторого 3D графика в виде множества точек.

```cpp
template <class T> QString THQt_LatexShow3DPlotPoints (T *VMHL_VectorX, T *VMHL_VectorY, T *VMHL_VectorZ,  int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, bool ForNormalSize);
template <class T> QString THQt_LatexShow3DPlotPoints (T *VMHL_VectorX, T *VMHL_VectorY, T *VMHL_VectorZ,  int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, bool ForNormalSize);
template <class T> QString THQt_LatexShow3DPlotPoints (T *VMHL_VectorX, T *VMHL_VectorY, T *VMHL_VectorZ,  int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label);
template <class T> QString THQt_LatexShow3DPlotPoints (T *VMHL_VectorX, T *VMHL_VectorY, T *VMHL_VectorZ,  int VMHL_N);
```

- Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.

```cpp
template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize, bool MinZero);
template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize);
template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label);
template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N);
template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize, bool MinZero);
template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize);
template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label);
```

- Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами.

```cpp
template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine, bool ForNormalSize);
template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints);
template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label);
template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N);
```

- Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.

```cpp
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle, bool SolidStyle, bool CircleStyle);
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize);
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label);
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M);
```

- Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами. Нечетные столбцы --- это значения координат X графиков. Следующие за ними четные столбцы --- соответствующие значения Y. То есть графики друг от друга независимы.

```cpp
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
```

- Функция возвращает строку с выводом некоторых двух графиков по точкам с Latex кодами.

```cpp
template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle);
template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize);
template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label);
template <class T> QString THQt_LatexShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N);
```

- Функция возвращает строку с выводом некоторых двух независимых графиков по точкам с Latex кодами.

```cpp
template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2);
```

- Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с Latex кодами. Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий.

```cpp
template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2, QString Label);
template <class T> QString THQt_LatexShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2);
```

Обработка текста
----------------

- Функция расставляет принудительные переносы в стиле Latex.

```cpp
QString HQt_ForcedWordWrap(QString S);
```

- Функция возвращает строку с выводом зеленого текста.

```cpp
QString HQt_LatexGreenText (QString String);
```

- Функция возвращает строку с выводом красного текста.

```cpp
QString HQt_LatexRedText (QString String);
```

- Функция переводит текст в текст, который можно добавить в Latex код. В-первую очередь, это экранирование некоторых элементов.

```cpp
QString HQt_TextToTextForLatex (QString Text);
```

- Функция выводит число VMHL_X в строку Latex, причем число выделено жирным.

```cpp
template <class T> QString THQt_LatexNumberToText (T VMHL_X);
```

Показ математических выражений
----------------

- Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами.

```cpp
template <class T> QString THQt_LatexShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix);
template <class T> QString THQt_LatexShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString NameMatrix);
template <class T> QString THQt_LatexShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M);
```

- Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами.

```cpp
QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString TitleMatrix, QString NameMatrix);
QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString NameMatrix);
QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N);
```

- Функция возвращает строку с выводом некоторого вектора VMHL_Vector с Latex кодами.

```cpp
template <class T> QString THQt_LatexShowVector (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);
template <class T> QString THQt_LatexShowVector (T *VMHL_Vector, int VMHL_N, QString NameVector);
template <class T> QString THQt_LatexShowVector (T *VMHL_Vector, int VMHL_N);
```

- Функция возвращает строку с выводом некоторого вектора VMH_Vector с Latex кодами.

```cpp
QString THQt_LatexShowVector (QStringList VMHL_Vector, QString TitleVector, QString NameVector);
QString THQt_LatexShowVector (QStringList VMHL_Vector, QString NameVector);
QString THQt_LatexShowVector (QStringList VMHL_Vector);
```

- Функция возвращает строку с выводом некоторого вектора VMHL_Vector в транспонированном виде с Latex кодами.

```cpp
template <class T> QString THQt_LatexShowVectorT (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);
template <class T> QString THQt_LatexShowVectorT (T *VMHL_Vector, int VMHL_N, QString NameVector);
template <class T> QString THQt_LatexShowVectorT (T *VMHL_Vector, int VMHL_N);
```

Составные изображения
----------------

- Функция возвращает строку с выводом начала рисунка, состоящего из нескольких рисунков или графиков.

```cpp
QString HQt_LatexBeginCompositionFigure ();
```

- Функция возвращает строку с Latex кодом при добавлении дополнительного рисунка или графика в рисунок, состоящего из нескольких рисунков.

```cpp
QString HQt_LatexBeginFigureInCompositionFigure ();
```

- Функция возвращает строку с выводом окончания рисунка, состоящего из нескольких рисунков или графиков.

```cpp
QString HQt_LatexEndCompositionFigure (QString TitleFigure, QString Label);
QString HQt_LatexEndCompositionFigure (QString TitleFigure);
QString HQt_LatexEndCompositionFigure ();
```

- Функция возвращает строку с Latex кодом после добавлении дополнительного рисунка или графика в рисунок, состоящего из нескольких рисунков.

```cpp
QString HQt_LatexEndFigureInCompositionFigure ();
```

Таблицы
----------------

- Функция возвращает строку с выводом таблицы.

```cpp
QString HQt_LatexShowTable (QStringList Col1, QStringList Col2, QString NameCol1, QString NameCol2, double WidthCol1, QString Title);
QString HQt_LatexShowTable (QStringList Col1, QStringList Col2, QStringList Col3, QString NameCol1, QString NameCol2, QString NameCol3, double WidthCol1, double WidthCol2, QString Title);
```

Текст
----------------

- Функция возвращает строку с выводом некоторого предупреждения.

```cpp
QString HQt_LatexShowAlert (QString String);
```

- Функция возвращает строку с выводом горизонтальной линии.

```cpp
QString HQt_LatexShowHr ();
```

- Функция возвращает строку с выводом некоторой строки в виде заголовка.

```cpp
QString HQt_LatexShowSection (QString String);
```

- Функция возвращает строку с выводом некоторой строки с Latex кодами без всякого излишества.

```cpp
QString HQt_LatexShowSimpleText (QString String);
```

- Функция возвращает строку с выводом некоторой строки в виде подзаголовка.

```cpp
QString HQt_LatexShowSubsection (QString String);
```

- Функция возвращает строку с выводом некоторой строки с Latex кодами.

```cpp
QString HQt_LatexShowText (QString TitleX);
```

- Функция возвращает строку с выводом некоторого числа VMHL_X с Latex кодами.

```cpp
template <class T> QString THQt_LatexShowNumber (T VMHL_X, QString TitleX, QString NameX);
template <class T> QString THQt_LatexShowNumber (T VMHL_X, QString NameX);
template <class T> QString THQt_LatexShowNumber (T VMHL_X);
```