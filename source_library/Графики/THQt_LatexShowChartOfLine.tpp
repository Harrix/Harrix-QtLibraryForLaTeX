template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY - указатель на вектор координат Y точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - название первого графика (для легенды);
     Label - label для графика
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата
    int i,j;

    //посчитаем границы изменения параметров
    T MinX=VMHL_VectorX[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorX[i]<MinX)
            MinX=VMHL_VectorX[i];

    T MinY=VMHL_VectorY[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorY[i]<MinY)
            MinY=VMHL_VectorY[i];

    T MaxX=VMHL_VectorX[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorX[i]>MaxX)
            MaxX=VMHL_VectorX[i];

    T MaxY=VMHL_VectorY[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorY[i]>MaxY)
            MaxY=VMHL_VectorY[i];

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/15.;
    T LeftYBoundingBox=MinY-LengthY/15.;
    T RightXBoundingBox=MaxX+LengthX/15.;
    T RightYBoundingBox=MaxY+LengthY/15.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;VMHL_Result+="\n";}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;VMHL_Result+="\n";}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    if (ForNormalSize)
        VMHL_Result+="% Вывод графика\n";
    else
        VMHL_Result+="% Вывод подграфика\n";

    //Если график маленький, то дополнительные настройки:
    if (!ForNormalSize)
    {
        VMHL_Result+="{\\pgfplotsset{every axis legend/.append style={at={(0.5,-0.25)},anchor=north,legend cell align=left},}\n";
    }

    //Обработаем текст подписи к осям.
    QString NameVectorXnew=NameVectorX,NameVectorYnew=NameVectorY, subStr;

    subStr=",";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    subStr=".";
    if (NameVectorXnew.contains(subStr))
        NameVectorXnew="$"+NameVectorXnew.replace(NameVectorXnew.indexOf(subStr), (subStr).size(), "$,");
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    if ((!NameVectorXnew.contains(","))&&(!NameVectorXnew.contains(".")))
        if (!HQt_CheckRus(NameVectorXnew))
            NameVectorXnew="$"+NameVectorXnew+"$";

    if ((!NameVectorYnew.contains(","))&&(!NameVectorYnew.contains(".")))
        if (!HQt_CheckRus(NameVectorYnew))
            NameVectorYnew="$"+NameVectorYnew+"$";

    NameVectorXnew=NameVectorXnew.replace(";","");
    NameVectorYnew=NameVectorYnew.replace(";","");

    NameVectorXnew=NameVectorXnew.replace("&","\\");
    NameVectorYnew=NameVectorYnew.replace("&","\\");

    //рисуем область графика и оси
    if (ForNormalSize) VMHL_Result+="\\begin{figure} [H]\n";
    if (ForNormalSize) VMHL_Result+="\\centering\n";
    if (ForNormalSize) VMHL_Result+="\\begin{tikzpicture}\n"; else VMHL_Result+="\\begin{tikzpicture}[scale=0.9, baseline]\n";
    VMHL_Result+="\\begin{axis} [\n";
    VMHL_Result+="xlabel={"+NameVectorXnew+"},\n";
    VMHL_Result+="ylabel={"+NameVectorYnew+"},\n";
    //if (ForNormalSize)
    VMHL_Result+="xmax="+SRightXBoundingBox+",\n";
    //if (ForNormalSize)
    VMHL_Result+="ymax="+SRightYBoundingBox+",\n";
    if (ForNormalSize)
    {
        VMHL_Result+="height=10cm,\n";
        VMHL_Result+="width=17cm,\n";
    }
    else
    {
        VMHL_Result+="height=5.8cm,\n";
        VMHL_Result+="width=8.5cm,\n";
    }
    VMHL_Result+="]\n\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T *Temp_VMHL_VectorX=new T[VMHL_N];
    T *Temp_VMHL_VectorY=new T[VMHL_N];
    for (i=0;i<VMHL_N;i++) Temp_VMHL_VectorX[i]=VMHL_VectorX[i];
    for (i=0;i<VMHL_N;i++) Temp_VMHL_VectorY[i]=VMHL_VectorY[i];

    //отсортируем массивы
    for(i=VMHL_N-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VMHL_VectorX[j]>Temp_VMHL_VectorX[j+1])
            {
                T x;
                x=Temp_VMHL_VectorX[j+1];
                Temp_VMHL_VectorX[j+1]=Temp_VMHL_VectorX[j];
                Temp_VMHL_VectorX[j]=x;

                x=Temp_VMHL_VectorY[j+1];
                Temp_VMHL_VectorY[j+1]=Temp_VMHL_VectorY[j];
                Temp_VMHL_VectorY[j]=x;
            }

    //соберем в массивы данные точек
    QString SData;
    for (i=0;i<VMHL_N;i++)
        SData+=" ("+QString::number(Temp_VMHL_VectorX[i])+", "+QString::number(Temp_VMHL_VectorY[i])+") \n";

    if ((ShowArea)&&((ShowPoints)||(ShowLine)))
    {
        //нарисуем закрашенную область
        VMHL_Result+="\\addplot[color=plotmain, draw=none,fill, fill opacity = 0.5,forget plot] coordinates {\n";
        VMHL_Result+=" ("+QString::number(MinX)+", "+QString::number(MinY)+") \n";
        VMHL_Result+=SData;
        VMHL_Result+=" ("+QString::number(MaxX)+", "+QString::number(MinY)+") \n";
        VMHL_Result+="};\n\n";
    }

    if ((ShowArea)&&(!ShowPoints)&&(!ShowLine))
    {
        //нарисуем закрашенную область
        VMHL_Result+="\\addplot[color=plotmain, draw=none,fill, fill opacity = 0.5] coordinates {\n";
        VMHL_Result+=" ("+QString::number(MinX)+", "+QString::number(MinY)+") \n";
        VMHL_Result+=SData;
        VMHL_Result+=" ("+QString::number(MaxX)+", "+QString::number(MinY)+") \n";
        VMHL_Result+="};\n";
        VMHL_Result+="\\addlegendentry{"+NameLine+"};\n\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        QString MarkSize;
        if (VMHL_N>100) MarkSize=",mark size=1.5pt";

        //Нарисуем график
        if (RedLine==false)
            VMHL_Result+="\\addplot[color=plotmain, mark=*,mark options={plotmain,opacity = 1, fill=white,thick}"+MarkSize+",very thick] coordinates {\n";
        else
            VMHL_Result+="\\addplot[color=red, mark=*,mark options={red,opacity = 1, fill=white,very thin}"+MarkSize+",very thin] coordinates {\n";
        VMHL_Result+=SData;
        VMHL_Result+="};\n";
        VMHL_Result+="\\addlegendentry{"+NameLine+"};\n\n";
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        QString MarkSize;
        if (VMHL_N>100) MarkSize=",mark size=1.5pt";

        //Нарисуем график
        if (RedLine==false)
            VMHL_Result+="\\addplot[color=plotmain, mark=*,mark options={plotmain,opacity = 1, fill=white,thick}"+MarkSize+",only marks] coordinates {\n";
        else
            VMHL_Result+="\\addplot[color=red, mark=*,mark options={red,opacity = 1, fill=white,very thin}"+MarkSize+",only marks] coordinates {\n";
        VMHL_Result+=SData;
        VMHL_Result+="};\n";
        VMHL_Result+="\\addlegendentry{"+NameLine+"};\n\n";
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        if (RedLine==false)
            VMHL_Result+="\\addplot[color=plotmain, no markers,very thick] coordinates {\n";
        else
            VMHL_Result+="\\addplot[color=red, no markers,very thin] coordinates {\n";
        VMHL_Result+=SData;
        VMHL_Result+="};\n";
        VMHL_Result+="\\addlegendentry{"+NameLine+"};\n\n";
    }

    if (ShowSpecPoints)
    {
        //Определим что писать в виде min_x и др.
        QString LabelX="Ox",LabelY="Oy";
        if (NameVectorX.length()<100) LabelX=NameVectorX;else LabelX="Ox";
        if (NameVectorY.length()<100) LabelY=NameVectorY;else LabelY="Oy";

        if (LabelX.contains(",")) LabelX=LabelX.mid(0,LabelX.indexOf(","));
        if (LabelY.contains(",")) LabelY=LabelY.mid(0,LabelY.indexOf(","));

        if (LabelX.contains(".")) LabelX=LabelX.mid(0,LabelX.indexOf("."));
        if (LabelY.contains(".")) LabelY=LabelY.mid(0,LabelY.indexOf("."));

        if (HQt_CheckRus(LabelX)) LabelX="Ox";
        if (HQt_CheckRus(LabelY)) LabelY="Oy";

        LabelX=LabelX.replace(";","");
        LabelY=LabelY.replace(";","");

        LabelX=LabelX.replace("&","\\");
        LabelY=LabelY.replace("&","\\");

        //Теперь проставим точки
        //Нулевая точка
        VMHL_Result+="\\addplot [\n";
        VMHL_Result+="black,\n";
        VMHL_Result+="mark = *,\n";
        VMHL_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VMHL_Result+="nodes near coords={$\\min_{"+LabelX+"}="+QString::number(MinX)+"; \\min_{"+LabelY+"}="+QString::number(MinY)+" $},\n";
        VMHL_Result+="every node near coord/.style={black, anchor=south west,font=\\tiny},\n";
        VMHL_Result+="fill=white,\n";
        VMHL_Result+="forget plot\n";
        VMHL_Result+="]\n";
        VMHL_Result+="coordinates {("+QString::number(MinX)+","+QString::number(MinY)+")};\n";

        //Максимальная по Y
        VMHL_Result+="\\addplot [\n";
        VMHL_Result+="black,\n";
        VMHL_Result+="mark = *,\n";
        VMHL_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VMHL_Result+="nodes near coords={$\\max_{"+LabelY+"} = "+QString::number(MaxY)+" $},\n";
        VMHL_Result+="every node near coord/.style={black, anchor=south west,font=\\tiny},\n";
        VMHL_Result+="fill=white,\n";
        VMHL_Result+="forget plot\n";
        VMHL_Result+="] \n";
        VMHL_Result+="coordinates {("+QString::number(MinX)+","+QString::number(MaxY)+")};\n";

        //Максимальная по X
        VMHL_Result+="\\addplot [\n";
        VMHL_Result+="black,\n";
        VMHL_Result+="mark = *,\n";
        VMHL_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VMHL_Result+="nodes near coords={$\\max_{"+LabelX+"} = "+QString::number(MaxX)+" $},\n";
        VMHL_Result+="every node near coord/.style={black, anchor=north west,font=\\tiny, rotate=90},\n";
        VMHL_Result+="fill=white,\n";
        VMHL_Result+="forget plot\n";
        VMHL_Result+="] \n";
        VMHL_Result+="coordinates {("+QString::number(MaxX)+","+QString::number(MinY)+")};\n";
    }

    VMHL_Result+="\\end{axis}\n";
    VMHL_Result+="\\end{tikzpicture}\n";

    if (!ForNormalSize)
    {
        VMHL_Result+="}\n";
    }

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
            VMHL_Result+="\\caption{График}\\label{"+Label+"}\n";
        else
            VMHL_Result+="\\caption{График}\n";
    }
    if (ForNormalSize) VMHL_Result+="\\end{figure}\n";

    delete [] Temp_VMHL_VectorX;
    delete [] Temp_VMHL_VectorY;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами.
    По сравнению с основной функцией тут отсутствует параметр ForNormalSize.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY - указатель на вектор координат Y точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - название первого графика (для легенды);
     Label - label для графика
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    VMHL_Result = THQt_LatexShowChartOfLine (VMHL_VectorX, VMHL_VectorY, VMHL_N, TitleChart, NameVectorX, NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, RedLine, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами.
    По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY - указатель на вектор координат Y точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - название первого графика (для легенды);
     Label - label для графика
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    VMHL_Result = THQt_LatexShowChartOfLine (VMHL_VectorX, VMHL_VectorY, VMHL_N, TitleChart, NameVectorX, NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, false, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, QString Label)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами.
    По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine и все остальные булевские переменные.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY - указатель на вектор координат Y точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - название первого графика (для легенды);
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    VMHL_Result = THQt_LatexShowChartOfLine (VMHL_VectorX, VMHL_VectorY, VMHL_N, TitleChart, NameVectorX, NameVectorY, NameLine, Label, true, true, true, true, false, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с Latex кодами.
    По сравнению с основной функцией тут отсутствует параметр ForNormalSize и RedLine и все остальные булевские переменные, а также все переменные названий.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY - указатель на вектор координат Y точек;
     VMHL_N - количество точек.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    VMHL_Result = THQt_LatexShowChartOfLine (VMHL_VectorX, VMHL_VectorY, VMHL_N, "", "x", "y", "Линия", "Chart"+HQt_RandomString(8), true, true, true, true, false, true);

    return VMHL_Result;
}