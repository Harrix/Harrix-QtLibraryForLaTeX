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