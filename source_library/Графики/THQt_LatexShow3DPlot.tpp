template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, double Opacity, double AngleHorizontal, double AngleVertical, bool ColorBar, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде поверхности.
    Входные параметры:
     VHQt_VectorX - указатель на вектор значений координат X сетки точек. Количество элементов VHQt_N;
     VHQt_VectorY - указатель на вектор значений координат Y сетки точек. Количество элементов VHQt_M;
     VHQt_VectorZ - указатель на матрицу значений координат Z точек. Количество элементов VHQt_NxVHQt_M;
     VHQt_N - количество значений в сетке по оси Ox;
     VHQt_M - количество значений в сетке по оси Oy;
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
     Opacity - прозначность графика. Может изменяться от 0 до 1;
     AngleHorizontal - угол поворота графика по горизонтали в градусах от -180 до 180. Рекомендуется 25;
     AngleVertical - угол поворота графика по вертикали в градусах от -180 до 180. Рекомендуется 30;
     ColorBar - рисоватm с графиком колонку с градациями цветов или нет;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата
    int i,j;

    if (ForNormalSize)
        VHQt_Result+="% Вывод графика\n";
    else
        VHQt_Result+="% Вывод подграфика\n";

    //Обработаем текст подписи к осям.
    QString NameVectorXnew=NameVectorX,NameVectorYnew=NameVectorY, NameVectorZnew=NameVectorZ, subStr;

    subStr=",";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorZnew.contains(subStr))
        NameVectorZnew="$"+NameVectorZnew.replace(NameVectorZnew.indexOf(subStr), (subStr).size(), "$,");

    subStr=".";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorZnew.contains(subStr))
        NameVectorZnew="$"+NameVectorZnew.replace(NameVectorZnew.indexOf(subStr), (subStr).size(), "$,");

    if ((!NameVectorXnew.contains(","))&&(!NameVectorXnew.contains(".")))
        if (!HQt_CheckRus(NameVectorXnew))
            NameVectorXnew="$"+NameVectorXnew+"$";

    if ((!NameVectorYnew.contains(","))&&(!NameVectorYnew.contains(".")))
        if (!HQt_CheckRus(NameVectorYnew))
            NameVectorYnew="$"+NameVectorYnew+"$";

    if ((!NameVectorZnew.contains(","))&&(!NameVectorZnew.contains(".")))
        if (!HQt_CheckRus(NameVectorZnew))
            NameVectorZnew="$"+NameVectorZnew+"$";

    NameVectorXnew=NameVectorXnew.replace(";","");
    NameVectorYnew=NameVectorYnew.replace(";","");
    NameVectorZnew=NameVectorZnew.replace(";","");

    NameVectorXnew=NameVectorXnew.replace("&","\\");
    NameVectorYnew=NameVectorYnew.replace("&","\\");
    NameVectorZnew=NameVectorZnew.replace("&","\\");

    //рисуем область графика и оси
    if (ForNormalSize) VHQt_Result+="\\begin{figure} [H]\n";
    if (ForNormalSize) VHQt_Result+="\\centering\n";
    VHQt_Result+="{\n";
    if (ForNormalSize) VHQt_Result+="\\begin{tikzpicture}\n"; else VHQt_Result+="\\begin{tikzpicture}[scale=0.9, baseline]\n";
    VHQt_Result+="\\begin{axis} [\n";
    VHQt_Result+="xlabel={"+NameVectorXnew+"},\n";
    VHQt_Result+="ylabel={"+NameVectorYnew+"},\n";
    VHQt_Result+="zlabel={"+NameVectorZnew+"},\n";
    if (ForNormalSize)
    {
        VHQt_Result+="height=12cm,\n";
        VHQt_Result+="width=12cm,\n";
    }
    else
    {
        VHQt_Result+="height=5.8cm,\n";
        VHQt_Result+="width=5.8cm,\n";
    }
    VHQt_Result+="z buffer=sort,\n";
    VHQt_Result+="colormap name="+ColorMap+",\n";
    if (!ForNormalSize) VHQt_Result+="label style={font=\\tiny},\n";
    if (ForNormalSize)  VHQt_Result+="label style={font=\\small},\n";
    if (!ForNormalSize) VHQt_Result+="tick label style={font=\\tiny},\n";
    if (ColorBar) VHQt_Result+="colorbar,\n";
    if (ColorBar) VHQt_Result+="colorbar style={axis lines=box},\n";
    if (Type==Plot3D_TopView) VHQt_Result+="view={0}{90},\n";
    if (Type==Plot3D_TopView) VHQt_Result+="grid=none,\n";
    if (Type!=Plot3D_TopView) VHQt_Result+="view/h="+QString::number(AngleHorizontal)+",\n";
    if (Type!=Plot3D_TopView) VHQt_Result+="view/h="+QString::number(AngleVertical)+",\n";
    VHQt_Result+="]\n\n";

    //соберем в массивы данные точек
    QString SData;
    for (i=0;i<VHQt_N;i++)
        for (j=0;j<VHQt_M;j++)
        SData+=" (" + QString::number(VHQt_VectorX[i]) + ", " + QString::number(VHQt_VectorY[j])+", " + QString::number(VHQt_VectorZ[i][j]) + ") \n";

    QString MarkSize;
    if (!ForNormalSize) MarkSize=",mark size=1pt";

    if (Type==Plot3D_Points)
    {
    //Добавим график
    VHQt_Result+="\\addplot3[only marks,scatter"+MarkSize+", opacity="+QString::number(Opacity)+"] coordinates {\n"+SData+"\n};\n";
    }

    if (Type==Plot3D_Surface)
    {
    //поверхность с непрерывной заливкой
    VHQt_Result+="\\addplot3[surf,shader=interp,mesh/cols="+QString::number(VHQt_M)+", opacity="+QString::number(Opacity)+"] coordinates {\n"+SData+"\n};\n";
    }

    if (Type==Plot3D_SurfaceGrid)
    {
    //поверхность с сеточной заливкой
    VHQt_Result+="\\addplot3[surf,shader=faceted,mesh/cols="+QString::number(VHQt_M)+", opacity="+QString::number(Opacity)+"] coordinates {\n"+SData+"\n};\n";
    }

    if (Type==Plot3D_TopView)
    {
    //вид сверху
    VHQt_Result+="\\addplot3[surf,shader=interp,mesh/cols="+QString::number(VHQt_M)+", opacity="+QString::number(Opacity)+"] coordinates {\n"+SData+"\n};\n";
    }

    VHQt_Result+="\\end{axis}\n";
    VHQt_Result+="\\end{tikzpicture}\n";

    VHQt_Result+="}\n";

    if (!TitleChart.isEmpty())
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{"+TitleChart+"}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{"+TitleChart+"}\n";
    }
    else
    {
        if (!Label.isEmpty())
            VHQt_Result+="\\caption{График}\\label{"+Label+"}\n\n";
        else
            VHQt_Result+="\\caption{График}\n\n";
    }
    if (ForNormalSize) VHQt_Result+="\\end{figure}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде поверхности.
    По сравнению с основным сайтом отсутствуют параметры Opacity, AngleHorizontal, AngleVertical.
    Входные параметры:
     VHQt_VectorX - указатель на вектор значений координат X сетки точек. Количество элементов VHQt_N;
     VHQt_VectorY - указатель на вектор значений координат Y сетки точек. Количество элементов VHQt_M;
     VHQt_VectorZ - указатель на матрицу значений координат Z точек. Количество элементов VHQt_NxVHQt_M;
     VHQt_N - количество значений в сетке по оси Ox;
     VHQt_M - количество значений в сетке по оси Oy;
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
     ColorBar - рисоватm с графиком колонку с градациями цветов или нет;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;
    if (Type==Plot3D_TopView)
    {
       AngleHorizontalNew=0;
       AngleVerticalNew=0;
    }

    VHQt_Result = THQt_LatexShow3DPlot (VHQt_VectorX, VHQt_VectorY, VHQt_VectorZ,  VHQt_N, VHQt_M, TitleChart, NameVectorX, NameVectorY, NameVectorZ, Label, ColorMap, Type, 1.0, AngleHorizontalNew, AngleVerticalNew, ColorBar,  ForNormalSize);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде поверхности.
    По сравнению с основным сайтом отсутствуют параметры Opacity, AngleHorizontal, AngleVertical и ForNormalSize.
    Входные параметры:
     VHQt_VectorX - указатель на вектор значений координат X сетки точек. Количество элементов VHQt_N;
     VHQt_VectorY - указатель на вектор значений координат Y сетки точек. Количество элементов VHQt_M;
     VHQt_VectorZ - указатель на матрицу значений координат Z точек. Количество элементов VHQt_NxVHQt_M;
     VHQt_N - количество значений в сетке по оси Ox;
     VHQt_M - количество значений в сетке по оси Oy;
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
    QString VHQt_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;
    if (Type==Plot3D_TopView)
    {
       AngleHorizontalNew=0;
       AngleVerticalNew=0;
    }

    VHQt_Result = THQt_LatexShow3DPlot (VHQt_VectorX, VHQt_VectorY, VHQt_VectorZ,  VHQt_N, VHQt_M, TitleChart, NameVectorX, NameVectorY, NameVectorZ, Label, ColorMap, Type, 1.0, AngleHorizontalNew, AngleVerticalNew, ColorBar,  true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде поверхности.
    По сравнению с основным сайтом отсутствуют параметры Opacity, AngleHorizontal, AngleVertical и ForNormalSize, ColorBar.
    Входные параметры:
     VHQt_VectorX - указатель на вектор значений координат X сетки точек. Количество элементов VHQt_N;
     VHQt_VectorY - указатель на вектор значений координат Y сетки точек. Количество элементов VHQt_M;
     VHQt_VectorZ - указатель на матрицу значений координат Z точек. Количество элементов VHQt_NxVHQt_M;
     VHQt_N - количество значений в сетке по оси Ox;
     VHQt_M - количество значений в сетке по оси Oy;
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
    QString VHQt_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;
    if (Type==Plot3D_TopView)
    {
       AngleHorizontalNew=0;
       AngleVerticalNew=0;
    }

    VHQt_Result = THQt_LatexShow3DPlot (VHQt_VectorX, VHQt_VectorY, VHQt_VectorZ,  VHQt_N, VHQt_M, TitleChart, NameVectorX, NameVectorY, NameVectorZ, Label, ColorMap, Type, 1.0, AngleHorizontalNew, AngleVerticalNew, true,  true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде поверхности.
    По сравнению с основным сайтом отсутствуют параметры Opacity, AngleHorizontal, AngleVertical и ForNormalSize, ColorBar, ColorMap, Type.
    Входные параметры:
     VHQt_VectorX - указатель на вектор значений координат X сетки точек. Количество элементов VHQt_N;
     VHQt_VectorY - указатель на вектор значений координат Y сетки точек. Количество элементов VHQt_M;
     VHQt_VectorZ - указатель на матрицу значений координат Z точек. Количество элементов VHQt_NxVHQt_M;
     VHQt_N - количество значений в сетке по оси Ox;
     VHQt_M - количество значений в сетке по оси Oy;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;

    VHQt_Result = THQt_LatexShow3DPlot (VHQt_VectorX, VHQt_VectorY, VHQt_VectorZ,  VHQt_N, VHQt_M, TitleChart, NameVectorX, NameVectorY, NameVectorZ, Label, "mathcad", Plot3D_Surface, 1.0, AngleHorizontalNew, AngleVerticalNew, true,  true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShow3DPlot (T *VHQt_VectorX, T *VHQt_VectorY, T **VHQt_VectorZ,  int VHQt_N,  int VHQt_M)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде поверхности.
    По сравнению с основным сайтом отсутствуют все дополнительные параметры.
    Входные параметры:
     VHQt_VectorX - указатель на вектор значений координат X сетки точек. Количество элементов VHQt_N;
     VHQt_VectorY - указатель на вектор значений координат Y сетки точек. Количество элементов VHQt_M;
     VHQt_VectorZ - указатель на матрицу значений координат Z точек. Количество элементов VHQt_NxVHQt_M;
     VHQt_N - количество значений в сетке по оси Ox;
     VHQt_M - количество значений в сетке по оси Oy.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;

    VHQt_Result = THQt_LatexShow3DPlot (VHQt_VectorX, VHQt_VectorY, VHQt_VectorZ,  VHQt_N, VHQt_M, "График", "x", "y", "z", "Plot3D"+HQt_RandomString(8), "mathcad", Plot3D_Surface, 1.0, AngleHorizontalNew, AngleVerticalNew, true,  true);

    return VHQt_Result;
}