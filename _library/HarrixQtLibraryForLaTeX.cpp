//HarrixQtLibraryForLaTeX
//Версия 1.29
//Библиотека для отображения различных данных в LaTeX файлах.
//https://github.com/Harrix/HarrixQtLibraryForLaTeX
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include "HarrixQtLibraryForLaTeX.h"

//*****************************************************************
//Главные загрузочные функции
//*****************************************************************
QString HQt_LatexBegin()
{
    /*
     Возвращает начало для полноценного Latex файла для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate.
     */
    QString VMHL_Result;
    VMHL_Result+="\\documentclass[a4paper,12pt]{report}\n\n";
    VMHL_Result+="\\input{packages} %Подключаем модуль пакетов\n";
    VMHL_Result+="\\input{styles} %Подключаем модуль стилей\n\n";
    VMHL_Result+="\\begin{document}\n\n";
    VMHL_Result+="\\input{names} %Подключаем модуль переименования некоторых команд\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexBeginArticle()
{
    /*
     Возвращает начало для полноценного Latex файла в виде статьи для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate.
     */
    QString VMHL_Result;
    VMHL_Result+="\\documentclass[a4paper,12pt]{article}\n\n";
    VMHL_Result+="\\input{packages} %Подключаем модуль пакетов\n";
    VMHL_Result+="\\input{styles} %Подключаем модуль стилей\n\n";
    VMHL_Result+="\\begin{document}\n\n";
    VMHL_Result+="\\input{names} %Подключаем модуль переименования некоторых команд\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexBeginArticleWithPgfplots()
{
    /*
     Возвращает начало для полноценного Latex файла в виде статьи для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate
     с использованием графиков через пакет pgfplots.
     */
    QString VMHL_Result;
    VMHL_Result+="\\documentclass[a4paper,12pt]{article}\n\n";
    VMHL_Result+="\\input{packages} %Подключаем модуль пакетов\n";
    VMHL_Result+="\\input{styles} %Подключаем модуль стилей\n\n";
    VMHL_Result+="\\usepgfplotslibrary{external}\n";
    VMHL_Result+="\\tikzexternalize[prefix=TikzPictures/]\n\n";
    VMHL_Result+="\\begin{document}\n\n";
    VMHL_Result+="\\input{names} %Подключаем модуль переименования некоторых команд\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexBeginWithPgfplots()
{
    /*
     Возвращает начало для полноценного Latex файла для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate
     с использованием графиков через пакет pgfplots.
     */
    QString VMHL_Result;
    VMHL_Result+="\\documentclass[a4paper,12pt]{report}\n\n";
    VMHL_Result+="\\input{packages} %Подключаем модуль пакетов\n";
    VMHL_Result+="\\input{styles} %Подключаем модуль стилей\n\n";
    VMHL_Result+="\\usepgfplotslibrary{external}\n";
    VMHL_Result+="\\tikzexternalize[prefix=TikzPictures/]\n\n";
    VMHL_Result+="\\begin{document}\n\n";
    VMHL_Result+="\\input{names} %Подключаем модуль переименования некоторых команд\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexEnd()
{
    /*
     Возвращает концовку для полноценного Latex файла для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate.
     */
    return "\n\n\\end{document}";
}
//---------------------------------------------------------------------------


//*****************************************************************
//Графики
//*****************************************************************
QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine)
{
    /*
    Функция возвращает строку с Latex кодом отрисовки линии по функции Function.
    Входные параметры:
     Left - левая граница области;
     Right - правая граница области;
     h - шаг, с которым надо рисовать график;
     Function - указатель на вычисляемую функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - название первого графика (для легенды);
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю.
    Возвращаемое значение:
     Строка с Latex кодом.
    */
    QString VMHL_Result;

    int N=(Right-Left)/h;
    double *dataX=new double [N];
    double *dataY=new double [N];

    double x=Left;
    for (int i=0;i<N;i++)
    {
        dataX[i]=x;
        dataY[i]=Function(x);

        x+=h;
    }

    VMHL_Result += THQt_LatexShowChartOfLine (dataX, dataY, N, TitleChart, NameVectorX, NameVectorY, NameLine, "Chart"+HQt_RandomString(8), ShowLine, ShowPoints, ShowArea, ShowSpecPoints, RedLine, true);

    delete []dataX;
    delete []dataY;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine)
{
    /*
    Функция возвращает строку с Latex кодом отрисовки линии по функции Function. Для добавление в Latex файл.
    Отличается от основной функцией отсутствием параметра NameLine(название графика (для легенды)).
    Входные параметры:
     Left - левая граница области;
     Right - правая граница области;
     h - шаг, с которым надо рисовать график;
     Function - указатель на вычисляемую функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю.
    Возвращаемое значение:
     Строка с Latex кодом.
    */
    QString VMHL_Result;

    VMHL_Result += HQt_LatexDrawLine (Left, Right, h, Function, TitleChart, NameVectorX, NameVectorY, "", ShowLine, ShowPoints, ShowArea, ShowSpecPoints, RedLine);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine)
{
    /*
    Функция возвращает строку с Latex кодом отрисовки линии по функции Function. Для добавление в Latex файл.
    Отличается от основной функцией отсутствием булевских параметров в конце - все по умолчанию делается.
    Входные параметры:
     Left - левая граница области;
     Right - правая граница области;
     h - шаг, с которым надо рисовать график;
     Function - указатель на вычисляемую функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
	 NameLine - название линии на графике.
    Возвращаемое значение:
     Строка с Latex кодом.
    */
    QString VMHL_Result;

    VMHL_Result += HQt_LatexDrawLine (Left, Right, h, Function, TitleChart, NameVectorX, NameVectorY, NameLine, true, false, false, true, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double))
{
    /*
    Функция возвращает строку с Latex кодом отрисовки линии по функции Function. Для добавление в Latex файл.
    Отличается от основной функцией отсутствием булевских параметров в конце и названий осей и графиков - для быстрого отображения графика без лишних телодвижений.
    Входные параметры:
     Left - левая граница области;
     Right - правая граница области;
     h - шаг, с которым надо рисовать график;
     Function - указатель на вычисляемую функцию;
    Возвращаемое значение:
     Строка с Latex кодом.
    */
    QString VMHL_Result;

    VMHL_Result += HQt_LatexDrawLine (Left, Right, h, Function, "", "x", "y", true, false, false, true, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, double Opacity, double AngleHorizontal, double AngleVertical, bool ColorBar, bool ForNormalSize)
{
    /*
    Функция возвращает строку с Latex кодом отрисовки 3D поверхности по функции Function.
    Входные параметры:
     Left_X - левая граница по оси Ox;
     Right_X - правая граница по оси Ox;
     Left_Y - левая граница по оси Oy;
     Right_Y - правая граница по оси Oy;
     N - сколько нужно построить точек по каждой оси. В итоге получим N*N точек;
     Function - ссылка на отрисовываемую двумерную функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика;
     ColorMap - какой раскраски будет график. Возможны значения: mathcad, matlab, hot или тот, что вы хотите использовать. Рекомендуется mathcad;
     Type - тип графика. Возможные значения:
        Plot3D_Points - в виде точек,
        Plot3D_Surface - в виде поверхности с непрерывной заливкой,
        Plot3D_SurfaceGrid - в виде поверхности с сеточной заливкой,
        Plot3D_TopView - вид сверху;
     Opacity - прозрачность графика. Может изменяться от 0 до 1;
     AngleHorizontal - угол поворота графика по горизонтали в градусах от -180 до 180. Рекомендуется 25;
     AngleVertical - угол поворота графика по вертикали в градусах от -180 до 180. Рекомендуется 30;
     ColorBar - рисовать с графиком колонку с градациями цветов или нет;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    double *x=new double [N];
    double *y=new double [N];
    double **z;
    z=new double*[N];
    for (int i=0;i<N;i++) z[i]=new double[N];

    for (int i=0;i<N;i++)
        x[i]=Left_X + i*(Right_X-Left_X)/double(N-1);
    for (int j=0;j<N;j++)
        y[j]=Left_Y + j*(Right_Y-Left_Y)/double(N-1);

    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
        {
            z[i][j]=Function(x[i],y[j]);
        }

    VMHL_Result = THQt_LatexShow3DPlot (x, y, z,  N,  N, TitleChart,  NameVectorX, NameVectorY, NameVectorZ, Label, ColorMap, Type, Opacity, AngleHorizontal, AngleVertical, ColorBar,  ForNormalSize);

    delete [] x;
    delete [] y;
    for (int i=0;i<N;i++) delete [] z[i];
    delete [] z;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar, bool ForNormalSize)
{
    /*
    Функция возвращает строку с Latex кодом отрисовки 3D поверхности по функции Function.
    По сравнению с основным сайтом отсутствуют параметры Opacity, AngleHorizontal, AngleVertical.
    Входные параметры:
     Left_X - левая граница по оси Ox;
     Right_X - правая граница по оси Ox;
     Left_Y - левая граница по оси Oy;
     Right_Y - правая граница по оси Oy;
     N - сколько нужно построить точек по каждой оси. В итоге получим N*N точек;
     Function - ссылка на отрисовываемую двумерную функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика;
     ColorMap - какой раскраски будет график. Возможны значения: mathcad, matlab, hot или тот, что вы хотите использовать. Рекомендуется mathcad;
     Type - тип графика. Возможные значения:
        Plot3D_Points - в виде точек,
        Plot3D_Surface - в виде поверхности с непрерывной заливкой,
        Plot3D_SurfaceGrid - в виде поверхности с сеточной заливкой,
        Plot3D_TopView - вид сверху;
     ColorBar - рисовать с графиком колонку с градациями цветов или нет;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;
    if (Type==Plot3D_TopView)
    {
       AngleHorizontalNew=0;
       AngleVerticalNew=0;
    }

    VMHL_Result = THQt_LatexDraw3DPlot (Left_X, Right_X, Left_Y, Right_Y, N, Function,  TitleChart, NameVectorX,  NameVectorY, NameVectorZ, Label, ColorMap, Type, 1.0, AngleHorizontalNew, AngleVerticalNew, ColorBar, ForNormalSize);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar)
{
    /*
    Функция возвращает строку с Latex кодом отрисовки 3D поверхности по функции Function.
    По сравнению с основным сайтом отсутствуют параметры Opacity, AngleHorizontal, AngleVertical и ForNormalSize.
    Входные параметры:
     Left_X - левая граница по оси Ox;
     Right_X - правая граница по оси Ox;
     Left_Y - левая граница по оси Oy;
     Right_Y - правая граница по оси Oy;
     N - сколько нужно построить точек по каждой оси. В итоге получим N*N точек;
     Function - ссылка на отрисовываемую двумерную функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика;
     ColorMap - какой раскраски будет график. Возможны значения: mathcad, matlab, hot или тот, что вы хотите использовать. Рекомендуется mathcad;
     Type - тип графика. Возможные значения:
        Plot3D_Points - в виде точек,
        Plot3D_Surface - в виде поверхности с непрерывной заливкой,
        Plot3D_SurfaceGrid - в виде поверхности с сеточной заливкой,
        Plot3D_TopView - вид сверху;
     ColorBar - рисовать с графиком колонку с градациями цветов или нет.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;
    if (Type==Plot3D_TopView)
    {
       AngleHorizontalNew=0;
       AngleVerticalNew=0;
    }

    VMHL_Result = THQt_LatexDraw3DPlot (Left_X, Right_X, Left_Y, Right_Y, N, Function,  TitleChart, NameVectorX,  NameVectorY, NameVectorZ, Label, ColorMap, Type, 1.0, AngleHorizontalNew, AngleVerticalNew, ColorBar, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type)
{
    /*
    Функция возвращает строку с Latex кодом отрисовки 3D поверхности по функции Function.
    По сравнению с основным сайтом отсутствуют параметры Opacity, AngleHorizontal, AngleVertical, ForNormalSize и ColorBar.
    Входные параметры:
     Left_X - левая граница по оси Ox;
     Right_X - правая граница по оси Ox;
     Left_Y - левая граница по оси Oy;
     Right_Y - правая граница по оси Oy;
     N - сколько нужно построить точек по каждой оси. В итоге получим N*N точек;
     Function - ссылка на отрисовываемую двумерную функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика;
     ColorMap - какой раскраски будет график. Возможны значения: mathcad, matlab, hot или тот, что вы хотите использовать. Рекомендуется mathcad;
     Type - тип графика. Возможные значения:
        Plot3D_Points - в виде точек,
        Plot3D_Surface - в виде поверхности с непрерывной заливкой,
        Plot3D_SurfaceGrid - в виде поверхности с сеточной заливкой,
        Plot3D_TopView - вид сверху.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;
    if (Type==Plot3D_TopView)
    {
       AngleHorizontalNew=0;
       AngleVerticalNew=0;
    }

    VMHL_Result = THQt_LatexDraw3DPlot (Left_X, Right_X, Left_Y, Right_Y, N, Function,  TitleChart, NameVectorX,  NameVectorY, NameVectorZ, Label, ColorMap, Type, 1.0, AngleHorizontalNew, AngleVerticalNew, true, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label)
{
    /*
    Функция возвращает строку с Latex кодом отрисовки 3D поверхности по функции Function.
    По сравнению с основным сайтом отсутствуют параметры Opacity, AngleHorizontal, AngleVertical и ForNormalSize, ColorBar, ColorMap, Type.
    Входные параметры:
     Left_X - левая граница по оси Ox;
     Right_X - правая граница по оси Ox;
     Left_Y - левая граница по оси Oy;
     Right_Y - правая граница по оси Oy;
     N - сколько нужно построить точек по каждой оси. В итоге получим N*N точек;
     Function - ссылка на отрисовываемую двумерную функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;

    VMHL_Result = THQt_LatexDraw3DPlot (Left_X, Right_X, Left_Y, Right_Y, N, Function,  TitleChart, NameVectorX,  NameVectorY, NameVectorZ, Label, "mathcad", Plot3D_Surface, 1.0, AngleHorizontalNew, AngleVerticalNew, true, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double))
{
    /*
    Функция возвращает строку с Latex кодом отрисовки 3D поверхности по функции Function.
    По сравнению с основным сайтом отсутствуют все дополнительные параметры.
    Входные параметры:
     Left_X - левая граница по оси Ox;
     Right_X - правая граница по оси Ox;
     Left_Y - левая граница по оси Oy;
     Right_Y - правая граница по оси Oy;
     N - сколько нужно построить точек по каждой оси. В итоге получим N*N точек;
     Function - ссылка на отрисовываемую двумерную функцию.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;

    VMHL_Result = THQt_LatexDraw3DPlot (Left_X, Right_X, Left_Y, Right_Y, N, Function,  "График", "x", "y", "z", "Plot3D"+HQt_RandomString(8), "mathcad", Plot3D_Surface, 1.0, AngleHorizontalNew, AngleVerticalNew, true, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString THQt_LatexDraw3DPlot (double Left, double Right, int N, double (*Function)(double, double))
{
    /*
    Функция возвращает строку с Latex кодом отрисовки 3D поверхности по функции Function.
    По сравнению с основным сайтом отсутствуют все дополнительные параметры и для всех осей одинаковые границы изменения.
    Входные параметры:
     Left - левая граница по осям;
     Right - правая граница по осям;
     N - сколько нужно построить точек по каждой оси. В итоге получим N*N точек;
     Function - ссылка на отрисовываемую двумерную функцию.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;

    VMHL_Result = THQt_LatexDraw3DPlot (Left, Right, Left, Right, N, Function,  "График", "x", "y", "z", "Plot3D"+HQt_RandomString(8), "mathcad", Plot3D_Surface, 1.0, AngleHorizontalNew, AngleVerticalNew, true, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Обработка текста
//*****************************************************************
QString HQt_ForcedWordWrap(QString S)
{
    /*
    Функция расставляет принудительные переносы в стиле Latex.
    Входные параметры:
     S - разбиваемая строка.
    Возвращаемое значение:
     Срока с расставленными принудительно переносами.
    Примечание:
     Перевод слов производится по алгоритму П. Хpистова в модификации Дымченко и Ваpсанофьева.
    */
    QStringList List;

    List = HQt_CutToWordsWithWordWrap(S);

    QString VMHL_Result = List.join("\\-");

    VMHL_Result = VMHL_Result.replace("\\-\\\\-_", "\\_");

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexGreenText (QString String)
{
    /*
    Функция возвращает строку с выводом зеленого текста.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с зеленым текстом.
    */
    QString VMHL_Result;

    VMHL_Result="\\textcolor{darkgreen}{\\textbf{"+String+"}}";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexRedText (QString String)
{
    /*
    Функция возвращает строку с выводом красного текста.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с красным текстом.
    */
    QString VMHL_Result;

    VMHL_Result="\\textcolor{red}{\\textbf{"+String+"}}";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_TextToTextForLatex (QString Text)
{
    /*
    Функция переводит текст в текст, который можно добавить в Latex код.
    В-первую очередь, это экранирование некоторых элементов.
    Входные параметры:
     TitleX - непосредственно выводимая строка.
    Возвращаемое значение:
     Измененный текст, который можно добавлять в LaTeX.
    */

    Text = Text.replace("_", "\\_").replace("#", "\\#");

    return Text;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Показ математических выражений
//*****************************************************************
QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк.
    Каждый QStringList - это одна строка.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     TitleMatrix - заголовок выводимой матрицы;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n"+TitleMatrix+":\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+="\\overline{"+NameMatrix+"} = ";

    QString C;
    for (int j=0;j<VMHL_Matrix[0].count();j++) C+="c";
    VMHL_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VMHL_N;i++)
    {
        QString H;

        for (int j=0;j<VMHL_Matrix[i].count();j++)
        {
            if (j!=VMHL_Matrix[i].count()-1) H=" & "; else H="";
            VMHL_Result+="\\text{"+VMHL_Matrix[i].at(j)+"}"+H;
        }

        if (i!=VMHL_N-1) H="\\\\"; else H="";
        VMHL_Result+=H;
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк.
    Каждый QStringList - это одна строка.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+="\\overline{"+NameMatrix+"} = ";

    QString C;
    for (int j=0;j<VMHL_Matrix[0].count();j++) C+="c";
    VMHL_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VMHL_N;i++)
    {
        QString H;

        for (int j=0;j<VMHL_Matrix[i].count();j++)
        {
            if (j!=VMHL_Matrix[i].count()-1) H=" & "; else H="";
            VMHL_Result+="\\text{"+VMHL_Matrix[i].at(j)+"}"+H;
        }

        if (i!=VMHL_N-1) H="\\\\"; else H="";
        VMHL_Result+=H;
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк.
    Каждый QStringList - это одна строка.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+="\\overline{x} = ";

    QString C;
    for (int j=0;j<VMHL_Matrix[0].count();j++) C+="c";
    VMHL_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VMHL_N;i++)
    {
        QString H;

        for (int j=0;j<VMHL_Matrix[i].count();j++)
        {
            if (j!=VMHL_Matrix[i].count()-1) H=" & "; else H="";
            VMHL_Result+="\\text{"+VMHL_Matrix[i].at(j)+"}"+H;
        }

        if (i!=VMHL_N-1) H="\\\\"; else H="";
        VMHL_Result+=H;
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString THQt_LatexShowVector (QStringList VMHL_Vector, QString TitleVector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VMHL_Vector с Latex кодами.
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n"+TitleVector+":\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+="\\overline{"+NameVector+"} = ";

    VMHL_Result+="\\left( \\begin{array}{c} ";

    for (int i=0;i<VMHL_Vector.count();i++)
    {
        VMHL_Result+="\\text{"+(VMHL_Vector.at(i))+"}\\\\";
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString THQt_LatexShowVector (QStringList VMHL_Vector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VMHL_Vector с Latex кодами.
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+="\\overline{"+NameVector+"} = ";

    VMHL_Result+="\\left( \\begin{array}{c} ";

    for (int i=0;i<VMHL_Vector.count();i++)
    {
        VMHL_Result+="\\text{"+(VMHL_Vector.at(i))+"}\\\\";
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString THQt_LatexShowVector (QStringList VMHL_Vector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VMHL_Vector с Latex кодами.
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+="\\overline{x} = ";

    VMHL_Result+="\\left( \\begin{array}{c} ";

    for (int i=0;i<VMHL_Vector.count();i++)
    {
        VMHL_Result+="\\text{"+(VMHL_Vector.at(i))+"}\\\\";
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Составные изображения
//*****************************************************************
QString HQt_LatexBeginCompositionFigure ()
{
    /*
    Функция возвращает строку с выводом начала рисунка, состоящего из нескольких рисунков или графиков.
    Входные параметры:
     Отсутствует.
    Возвращаемое значение:
     Строка с Latex кодами.
    Пример использования:
    Latex += HQt_LatexBeginCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot1",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot2",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexEndCompositionFigure ("Два графика", "TwoFig");
    */
    QString VMHL_Result;

    VMHL_Result="\n\\begin{figure}[H]\n\\centering\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexBeginFigureInCompositionFigure ()
{
    /*
    Функция возвращает строку с Latex кодом при добавлении дополнительного рисунка или графика в рисунок, состоящего из нескольких рисунков.
    Входные параметры:
     Отсутствует.
    Возвращаемое значение:
     Строка с Latex кодами.
    Пример использования:
    Latex += HQt_LatexBeginCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot1",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot2",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexEndCompositionFigure ("Два графика", "TwoFig");
    */
    QString VMHL_Result;

    VMHL_Result="\\begin{subfigure}[t]{0.48\\textwidth}\n\\centering\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexEndCompositionFigure (QString TitleFigure, QString Label)
{
    /*
    Функция возвращает строку с выводом окончания рисунка, состоящего из нескольких рисунков или графиков.
    Входные параметры:
     TitleFigure - заголовок рисунка;
     Label - label для рисунка.
    Возвращаемое значение:
     Строка с Latex кодами.
    Пример использования:
    Latex += HQt_LatexBeginCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot1",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot2",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexEndCompositionFigure ("Два графика", "TwoFig");
    */
    QString VMHL_Result;

    VMHL_Result="\n\\caption{"+TitleFigure+"}\\label{"+Label+"}\\end{figure}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString HQt_LatexEndCompositionFigure (QString TitleFigure)
{
    /*
    Функция возвращает строку с выводом окончания рисунка, состоящего из нескольких рисунков или графиков.
    Входные параметры:
     TitleFigure - заголовок рисунка.
    Возвращаемое значение:
     Строка с Latex кодами.
    Пример использования:
    Latex += HQt_LatexBeginCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot1",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot2",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexEndCompositionFigure ("Два графика", "TwoFig");
    */
    QString Label="CompositionFigure"+HQt_RandomString(5);

    QString VMHL_Result;

    VMHL_Result=HQt_LatexEndCompositionFigure (TitleFigure, Label);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString HQt_LatexEndCompositionFigure ()
{
    /*
    Функция возвращает строку с выводом окончания рисунка, состоящего из нескольких рисунков или графиков.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Строка с Latex кодами.
    Пример использования:
    Latex += HQt_LatexBeginCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot1",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot2",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexEndCompositionFigure ("Два графика", "TwoFig");
    */
    QString Label="CompositionFigure"+HQt_RandomString(5);

    QString TitleFigure="Система";

    QString VMHL_Result;

    VMHL_Result=HQt_LatexEndCompositionFigure (TitleFigure, Label);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexEndFigureInCompositionFigure ()
{
    /*
    Функция возвращает строку с Latex кодом после добавлении дополнительного рисунка или графика в рисунок, состоящего из нескольких рисунков.
    Входные параметры:
     Отсутствует.
    Возвращаемое значение:
     Строка с Latex кодами.
    Пример использования:
    Latex += HQt_LatexBeginCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot1",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot2",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexEndCompositionFigure ("Два графика", "TwoFig");
    */
    QString VMHL_Result;

    VMHL_Result="\n\\end{subfigure}\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Таблицы
//*****************************************************************
QString HQt_LatexShowTable (QStringList Col1, QStringList Col2, QString NameCol1, QString NameCol2, double WidthCol1, QString Title)
{
    /*
    Функция возвращает строку с выводом таблицы с двумя столбцами.
    Входные параметры:
     Col1 - список строк первого столбца;
     Col2 - список строк второго столбца;
     NameCol1- заголовок первого столбца;
     NameCol2- заголовок второго столбца;
     WidthCol1 - ширина первого столбца в процентах, например 50%;
     Title - заголовок таблицы.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой таблицы.
    */
    QString VMHL_Result;

    VMHL_Result+="\\begin{center}\n";
    VMHL_Result+="{\n\\renewcommand{\\arraystretch}{1.5}\n";

    double width1 = (WidthCol1/100.);
    double width2 = (1.-WidthCol1/100.);

    VMHL_Result+="\\footnotesize\\begin{longtable}[H]{|m{\\dimexpr"+QString::number(width1)+"\\linewidth-2\\tabcolsep}|m{\\dimexpr"+QString::number(width2)+"\\linewidth-2\\tabcolsep}|}\n";
    VMHL_Result+="\\caption{"+Title+"}\n";

    VMHL_Result+="\\tabularnewline\\hline\n";
    VMHL_Result+="\\centering \\textbf{"+NameCol1+"} & \\centering \\textbf{"+NameCol2+"} \\centering \\tabularnewline \\hline \\endhead\n";
    VMHL_Result+="\\multicolumn{2}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
    VMHL_Result+="\\endlastfoot\n";

    for (int i=0;i<Col1.count();i++)
    {
        VMHL_Result+="\\footnotesize "+Col1.at(i)+" & \\footnotesize "+Col2.at(i)+" \\tabularnewline \\hline\n";
    }

    VMHL_Result+="\\end{longtable}\n";
    VMHL_Result+="}\n";
    VMHL_Result+="\\end{center}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString HQt_LatexShowTable (QStringList Col1, QStringList Col2, QStringList Col3, QString NameCol1, QString NameCol2, QString NameCol3, double WidthCol1, double WidthCol2, QString Title)
{
    /*
    Функция возвращает строку с выводом таблицы с тремя столбцами.
    Входные параметры:
     Col1 - список строк первого столбца;
     Col2 - список строк второго столбца;
     Col3 - список строк второго столбца;
     NameCol1- заголовок первого столбца;
     NameCol2- заголовок второго столбца;
     NameCol3- заголовок второго столбца;
     WidthCol1 - ширина первого столбца в процентах, например 50%;
     WidthCol2 - ширина первого столбца в процентах, например 50%;
     Title - заголовок таблицы;
    Возвращаемое значение:
     Строка с Latex кодами с выводимой таблицы.
    */
    QString VMHL_Result;

    VMHL_Result+="\\begin{center}\n";
    VMHL_Result+="{\n\\renewcommand{\\arraystretch}{1.5}\n";

    double width1 = (WidthCol1/100.);
    double width2 = (WidthCol2/100.);
    double width3 = (1.-WidthCol1/100.-WidthCol2/100.);

    VMHL_Result+="\\footnotesize\\begin{longtable}[H]{|m{\\dimexpr"+QString::number(width1)+"\\linewidth-2\\tabcolsep}|m{\\dimexpr"+QString::number(width2)+"\\linewidth-2\\tabcolsep}|m{\\dimexpr"+QString::number(width3)+"\\linewidth-2\\tabcolsep}|}\n";
    VMHL_Result+="\\caption{"+Title+"}\n";

    VMHL_Result+="\\tabularnewline\\hline\n";
    VMHL_Result+="\\centering \\textbf{"+NameCol1+"} & \\centering \\textbf{"+NameCol2+"} & \\centering \\textbf{"+NameCol3+"} \\centering \\tabularnewline \\hline \\endhead\n";
    VMHL_Result+="\\multicolumn{3}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
    VMHL_Result+="\\endlastfoot\n";

    for (int i=0;i<Col1.count();i++)
    {
        VMHL_Result+="\\footnotesize "+Col1.at(i)+" & \\footnotesize "+Col2.at(i)+" & \\footnotesize "+Col3.at(i)+" \\tabularnewline \\hline\n";
    }

    VMHL_Result+="\\end{longtable}\n";
    VMHL_Result+="}\n";
    VMHL_Result+="\\end{center}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Текст
//*****************************************************************
QString HQt_LatexShowAlert (QString String)
{
    /*
    Функция возвращает строку с выводом некоторого предупреждения.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым предупреждением.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\textcolor{red}{\\textbf{"+String+"}}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexShowHr ()
{
    /*
    Функция возвращает строку с выводом горизонтальной линии.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Строка с Latex кодами с тэгом горизонтальной линии.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\hrulefill\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexShowSection (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки в виде заголовка.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\section{"+String+"}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexShowSimpleText (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки с Latex кодами без всякого излишества.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n"+String+"\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexShowSubsection (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки в виде подзаголовка.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\subsection{"+String+"}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexShowText (QString TitleX)
{
    /*
    Функция возвращает строку с выводом некоторой строки с Latex кодами.
    Входные параметры:
     TitleX - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой (в виде абзаца).
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\textbf{"+TitleX+".}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------