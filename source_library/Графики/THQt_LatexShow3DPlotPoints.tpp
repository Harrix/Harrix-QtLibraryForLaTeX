template <class T> QString THQt_LatexShow3DPlotPoints (T *VMHL_VectorX, T *VMHL_VectorY, T *VMHL_VectorZ,  int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде множества точек.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY - указатель на вектор координат Y точек;
     VMHL_VectorZ - указатель на вектор координат Z точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика;
     ColorMap - какой раскраски будет график. Возможны значения: mathcad, matlab, hot или тот, что вы хотите использовать. Рекомендуется mathcad.
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата
    int i;

    if (ForNormalSize)
        VMHL_Result+="% Вывод графика\n";
    else
        VMHL_Result+="% Вывод подграфика\n";

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
    if (ForNormalSize) VMHL_Result+="\\begin{figure} [H]\n";
    if (ForNormalSize) VMHL_Result+="\\centering\n";
    VMHL_Result+="{\n";
    if (ForNormalSize) VMHL_Result+="\\begin{tikzpicture}\n"; else VMHL_Result+="\\begin{tikzpicture}[scale=0.9, baseline]\n";
    VMHL_Result+="\\begin{axis} [\n";
    VMHL_Result+="xlabel={"+NameVectorXnew+"},\n";
    VMHL_Result+="ylabel={"+NameVectorYnew+"},\n";
    VMHL_Result+="zlabel={"+NameVectorZnew+"},\n";
    if (ForNormalSize)
    {
        VMHL_Result+="height=12cm,\n";
        VMHL_Result+="width=12cm,\n";
    }
    else
    {
        VMHL_Result+="height=5.8cm,\n";
        VMHL_Result+="width=5.8cm,\n";
    }
    VMHL_Result+="z buffer=sort,\n";
    VMHL_Result+="colormap name="+ColorMap+",\n";
    if (!ForNormalSize) VMHL_Result+="label style={font=\\tiny},\n";
    if (ForNormalSize)  VMHL_Result+="label style={font=\\small},\n";
    if (!ForNormalSize) VMHL_Result+="tick label style={font=\\tiny},\n";
    VMHL_Result+="]\n\n";

    //соберем в массивы данные точек
    QString SData;
    for (i=0;i<VMHL_N;i++)
        SData+=" (" + QString::number(VMHL_VectorX[i]) + ", " + QString::number(VMHL_VectorY[i])+", " + QString::number(VMHL_VectorZ[i]) + ") \n";

    QString MarkSize;
    if (!ForNormalSize) MarkSize=",mark size=1pt";

    //Добавим график
    VMHL_Result+="\\addplot3[only marks,scatter"+MarkSize+"] coordinates {\n"+SData+"\n};\n";

    VMHL_Result+="\\end{axis}\n";
    VMHL_Result+="\\end{tikzpicture}\n";

    VMHL_Result+="}\n";

    if (!TitleChart.isEmpty())
    {
        if (!Label.isEmpty())
            VMHL_Result+="\\caption{"+TitleChart+"}\\label{"+Label+"}\n";
        else
            VMHL_Result+="\\caption{"+TitleChart+"}\n";
    }
    else
    {
        if (!Label.isEmpty())
            VMHL_Result+="\\caption{График}\\label{"+Label+"}\n\n";
        else
            VMHL_Result+="\\caption{График}\n\n";
    }
    if (ForNormalSize) VMHL_Result+="\\end{figure}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShow3DPlotPoints (T *VMHL_VectorX, T *VMHL_VectorY, T *VMHL_VectorZ,  int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде множества точек.
    В отличии от основной функции отсутствует параметр ColorMap.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY - указатель на вектор координат Y точек;
     VMHL_VectorZ - указатель на вектор координат Z точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    VMHL_Result = THQt_LatexShow3DPlotPoints (VMHL_VectorX, VMHL_VectorY, VMHL_VectorZ,  VMHL_N, TitleChart, NameVectorX, NameVectorY, NameVectorZ, Label, "mathcad", ForNormalSize);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShow3DPlotPoints (T *VMHL_VectorX, T *VMHL_VectorY, T *VMHL_VectorZ,  int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде множества точек.
    В отличии от основной функции отсутствует параметры ColorMap и ForNormalSize.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY - указатель на вектор координат Y точек;
     VMHL_VectorZ - указатель на вектор координат Z точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    VMHL_Result = THQt_LatexShow3DPlotPoints (VMHL_VectorX, VMHL_VectorY, VMHL_VectorZ,  VMHL_N, TitleChart, NameVectorX, NameVectorY, NameVectorZ, Label, "mathcad", true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShow3DPlotPoints (T *VMHL_VectorX, T *VMHL_VectorY, T *VMHL_VectorZ,  int VMHL_N)
{
    /*
    Функция возвращает строку с выводом некоторого 3D графика в виде множества точек.
    В отличии от основной функции отсутствует все дополнительные параметры.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY - указатель на вектор координат Y точек;
     VMHL_VectorZ - указатель на вектор координат Z точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    VMHL_Result = THQt_LatexShow3DPlotPoints (VMHL_VectorX, VMHL_VectorY, VMHL_VectorZ,  VMHL_N, "График", "x", "y", "z", "Plot3D"+HQt_RandomString(8), "mathcad", true);

    return VMHL_Result;
}