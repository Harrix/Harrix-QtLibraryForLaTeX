template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize, bool MinZero)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    Входные параметры:
     VMHL_Vector - указатель на вектор значений точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VMHL_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается;
     MinZero - гистограмму начинать с нуля (true) или с минимального значения среди VMHL_Vector (false).
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата
    int i;

    //посчитаем границы изменения параметров

    T MinY=VMHL_Vector[0];
    for (i=1;i<VMHL_N;i++)
        if (VMHL_Vector[i]<MinY)
            MinY=VMHL_Vector[i];

    T MaxY=VMHL_Vector[0];
    for (i=1;i<VMHL_N;i++)
        if (VMHL_Vector[i]>MaxY)
            MaxY=VMHL_Vector[i];

    T LengthY=MaxY-MinY;

    if (ForNormalSize)
        VMHL_Result+="% Вывод графика\n";
    else
        VMHL_Result+="% Вывод подграфика\n";


    //Обработаем текст подписи к осям.
    QString NameVectorYnew=NameVectorY, subStr;

    subStr=",";
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    subStr=".";
    if (NameVectorYnew.contains(subStr))
        NameVectorYnew="$"+NameVectorYnew.replace(NameVectorYnew.indexOf(subStr), (subStr).size(), "$,");

    if ((!NameVectorYnew.contains(","))&&(!NameVectorYnew.contains(".")))
        if (!HQt_CheckRus(NameVectorYnew))
            NameVectorYnew="$"+NameVectorYnew+"$";

    NameVectorYnew=NameVectorYnew.replace(";","");

    NameVectorYnew=NameVectorYnew.replace("&","\\");

    QString *NameVectorXnew=new QString[VMHL_N];
    for (i=0;i<VMHL_N;i++)
    {
        NameVectorXnew[i]=NameVectorX[i];

        subStr=",";
        if (NameVectorXnew[i].contains(subStr))
            NameVectorXnew[i]="$"+NameVectorXnew[i].replace(NameVectorXnew[i].indexOf(subStr), (subStr).size(), "$,");

        subStr=".";
        if (NameVectorXnew[i].contains(subStr))
            NameVectorXnew[i]="$"+NameVectorXnew[i].replace(NameVectorXnew[i].indexOf(subStr), (subStr).size(), "$,");

        if ((!NameVectorXnew[i].contains(","))&&(!NameVectorXnew[i].contains(".")))
            if (!HQt_CheckRus(NameVectorXnew[i]))
                NameVectorXnew[i]="$"+NameVectorXnew[i]+"$";

        NameVectorXnew[i]=NameVectorXnew[i].replace(";","");
        NameVectorXnew[i]=NameVectorXnew[i].replace("&","\\");
    }

    //рисуем область графика и оси
    if (ForNormalSize) VMHL_Result+="\\begin{figure} [H]\n";
    if (ForNormalSize) VMHL_Result+="\\centering\n";
    VMHL_Result+="{\n";
    VMHL_Result+="\\pgfplotsset{x axis line style={-},}\n";
    if (ForNormalSize) VMHL_Result+="\\begin{tikzpicture}\n"; else VMHL_Result+="\\begin{tikzpicture}[scale=0.9, baseline]\n";
    VMHL_Result+="\\begin{axis} [\n";
    VMHL_Result+="ybar,\n";
    VMHL_Result+="xmajorgrids=false,\n";
    VMHL_Result+="xminorgrids=false,\n";
    VMHL_Result+="ylabel={"+NameVectorYnew+"},\n";

    double MinD=10;
    if (!ForNormalSize) MinD=5;

    if ((MinY>=0)&&(MaxY>=0)&&(MinY!=MaxY))
    {

        VMHL_Result+="ymax="+QString::number(MaxY+LengthY/15.)+",\n";
        if (MinZero)
            VMHL_Result+="ymin=0,\n";
        else
            VMHL_Result+="ymin="+QString::number(MinY-LengthY/MinD)+",\n";
    }

    if ((MinY<0)&&(MaxY>=0))
    {

        VMHL_Result+="ymin="+QString::number(MinY-LengthY/MinD)+",\n";
        VMHL_Result+="ymax="+QString::number(MaxY+LengthY/15.)+",\n";
    }

    if ((MinY<0)&&(MaxY<0)&&(MinY!=MaxY))
    {

        VMHL_Result+="ymin="+QString::number(MinY-LengthY/MinD)+",\n";
        if (MinZero)
            VMHL_Result+="ymax=0,\n";
        else
            VMHL_Result+="ymax="+QString::number(MaxY+LengthY/15.)+",\n";
    }

    if ((MinY==MaxY)&&(MinY>=0))
    {
        if (MinZero)
        {
            VMHL_Result+="ymax="+QString::number(MaxY+(fabs(MinY)/MinD))+",\n";
            VMHL_Result+="ymin=0,\n";
        }
        else
        {
            VMHL_Result+="ymax="+QString::number(MaxY+(fabs(MinY)/MinD)/MinD)+",\n";
            VMHL_Result+="ymin="+QString::number(MinY-fabs(MinY)/MinD)+",\n";
        }
    }

    if ((MinY==MaxY)&&(MinY<0))
    {

        if (MinZero)
        {
            VMHL_Result+="ymax=0,\n";
            VMHL_Result+="ymin="+QString::number(MinY-(fabs(MinY)/MinD))+",\n";
        }
        else
        {
            VMHL_Result+="ymax="+QString::number(MaxY+fabs(MinY)/MinD)+",\n";
            VMHL_Result+="ymin="+QString::number(MinY-(fabs(MinY)/MinD)/MinD)+",\n";
        }
    }


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

    VMHL_Result+="xticklabels={";
    for (i=0;i<VMHL_N-1;i++) VMHL_Result+=NameVectorXnew[i]+", ";
    VMHL_Result+=NameVectorXnew[VMHL_N-1]+"},\n";

    VMHL_Result+="xtick=data,\n";
    VMHL_Result+="minor x tick num=0,\n";
    VMHL_Result+="nodes near coords,\n";
    VMHL_Result+="nodes near coords align={vertical},\n";

    if (ForNormalSize)
    {
        if (VMHL_N>10)
            VMHL_Result+="every node near coord/.style={color=black,font=\\tiny},\n";
        else
            VMHL_Result+="every node near coord/.style={color=black},\n";
    }
    else
        VMHL_Result+="every node near coord/.style={color=black,font=\\tiny},\n";

    QString BarWidth;
    QString TextWidth;
    QString XLimits;
    if (ForNormalSize)
    {
        BarWidth="bar width=2.0cm,\n";
        TextWidth="x tick label style={font=\\small,text width=1.7cm,align=center},\n";
        XLimits="enlarge x limits=.15,\n";

        if (VMHL_N==1)
        {
            BarWidth="bar width=3.0cm,\n";
            TextWidth="x tick label style={font=\\small,text width=15cm,align=center},\n";
        }

        if (VMHL_N==2)
        {
            BarWidth="bar width=3.0cm,\n";
            TextWidth="x tick label style={font=\\small,text width=7cm,align=center},\n";
            XLimits="enlarge x limits=.4,\n";
        }

        if (VMHL_N==3)
        {
            BarWidth="bar width=2.5cm,\n";
            TextWidth="x tick label style={font=\\small,text width=4cm,align=center},\n";
        }

        if (VMHL_N==4)
        {
            BarWidth="bar width=2cm,\n";
            TextWidth="x tick label style={font=\\small,text width=1.9cm,align=center},\n";
        }

        if (VMHL_N==6)
        {
            BarWidth="bar width=2cm,\n";
            TextWidth="x tick label style={font=\\small,text width=1.7cm,align=center},\n";
        }

        if (VMHL_N==7)
        {
            BarWidth="bar width=1.8cm,\n";
            TextWidth="x tick label style={font=\\small,text width=1.5cm,align=center},\n";
        }

        if (VMHL_N==8)
        {
            BarWidth="bar width=1.5cm,\n";
            TextWidth="x tick label style={font=\\tiny,text width=1.4cm,align=center},\n";
        }

        if (VMHL_N==9)
        {
            BarWidth="bar width=1.2cm,\n";
            TextWidth="x tick label style={font=\\tiny,rotate=45,anchor=east},\n";
        }

        if (VMHL_N==10)
        {
            BarWidth="bar width=1.0cm,\n";
            TextWidth="x tick label style={font=\\tiny,rotate=45,anchor=east},\n";
        }

        if (VMHL_N==11)
        {
            BarWidth="bar width=0.8cm,\n";
        }

        if (VMHL_N>=11)
        {
            TextWidth="x tick label style={font=\\tiny,rotate=45,anchor=east},\n";
            XLimits="enlarge x limits=.05,\n";
        }

        if (VMHL_N==12)
        {
            BarWidth="bar width=0.75cm,\n";
        }

        if (VMHL_N==13)
        {
            BarWidth="bar width=0.65cm,\n";
        }

        if (VMHL_N>=14)
        {
            BarWidth="";
        }


    }
    else
    {
        BarWidth="bar width=0.8cm,\n";
        TextWidth="x tick label style={font=\\tiny,rotate=45,anchor=east},\n";
        XLimits="enlarge x limits=.15,\n";

        if (VMHL_N==1)
        {
            BarWidth="bar width=1.0cm,\n";
            TextWidth="x tick label style={font=\\tiny,text width=8cm,align=center},\n";
        }

        if (VMHL_N==2)
        {
            BarWidth="bar width=1.0cm,\n";
            TextWidth="x tick label style={font=\\small,text width=4cm,align=center},\n";
            XLimits="enlarge x limits=.4,\n";
        }

        if (VMHL_N==8)
        {
            BarWidth="bar width=0.6cm,\n";
        }

        if (VMHL_N>=9)
        {
            BarWidth="";
        }

        if (VMHL_N>=11)
        {
            XLimits="enlarge x limits=.05,\n";
        }
    }
    VMHL_Result+=BarWidth;
    VMHL_Result+=TextWidth;
    VMHL_Result+=XLimits;


    VMHL_Result+="]\n\n";


    //соберем в массивы данные точек
    QString SData;
    for (i=0;i<VMHL_N;i++)
        SData+=" ("+QString::number(i)+", "+QString::number(VMHL_Vector[i])+") \n";

    //добавим график
    VMHL_Result+="\\addplot[color=plotmain,fill] coordinates {\n";
    VMHL_Result+=SData;
    VMHL_Result+="};\n";

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

    delete [] NameVectorXnew;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается отсутствием параметра MinZero.
    Входные параметры:
     VMHL_Vector - указатель на вектор значений точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VMHL_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    VMHL_Result = THQt_LatexShowBar (VMHL_Vector, VMHL_N, TitleChart, NameVectorX, NameVectorY, Label, ForNormalSize, false);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается отсутствием параметра MinZero и ForNormalSize.
    Входные параметры:
     VMHL_Vector - указатель на вектор значений точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VMHL_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    VMHL_Result = THQt_LatexShowBar (VMHL_Vector, VMHL_N, TitleChart, NameVectorX, NameVectorY, Label, true, false);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается отсутствием параметра MinZero и ForNormalSize и всех текстовых параметров.
    Входные параметры:
     VMHL_Vector - указатель на вектор значений точек;
     VMHL_N - количество точек.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    QString *NameVectorX = new QString[VMHL_N];
    for (int i=0;i<VMHL_N;i++) NameVectorX[i] = "№ " + QString::number(i+1);

    VMHL_Result = THQt_LatexShowBar (VMHL_Vector, VMHL_N, "График", NameVectorX, "y",  "Chart"+HQt_RandomString(8), true, false);

    delete [] NameVectorX;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize, bool MinZero)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается тем, что список наименований хранится в QStringList, а не массиве.
    Входные параметры:
     VMHL_Vector - указатель на вектор значений точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VMHL_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается;
     MinZero - гистограмму начинать с нуля (true) или с минимального значения среди VMHL_Vector (false).
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    QString *NameVectorXArray = new QString [VMHL_N];
    for (int i=0;i<VMHL_N;i++) NameVectorXArray[i]=NameVectorX.at(i);

    VMHL_Result = THQt_LatexShowBar (VMHL_Vector, VMHL_N, TitleChart, NameVectorXArray, NameVectorY, Label, ForNormalSize, MinZero);

    delete [] NameVectorXArray;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается тем, что список наименований хранится в QStringList, а не массиве. Еще нет переменой MinZero.
    Входные параметры:
     VMHL_Vector - указатель на вектор значений точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VMHL_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    QString *NameVectorXArray = new QString [VMHL_N];
    for (int i=0;i<VMHL_N;i++) NameVectorXArray[i]=NameVectorX.at(i);

    VMHL_Result = THQt_LatexShowBar (VMHL_Vector, VMHL_N, TitleChart, NameVectorXArray, NameVectorY, Label, ForNormalSize, true);

    delete [] NameVectorXArray;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VMHL_Vector, int VMHL_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается тем, что список наименований хранится в QStringList, а не массиве. Еще нет переменых MinZero и ForNormalSize.
    Входные параметры:
     VMHL_Vector - указатель на вектор значений точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VMHL_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    QString *NameVectorXArray = new QString [VMHL_N];
    for (int i=0;i<VMHL_N;i++) NameVectorXArray[i]=NameVectorX.at(i);

    VMHL_Result = THQt_LatexShowBar (VMHL_Vector, VMHL_N, TitleChart, NameVectorXArray, NameVectorY, Label, true, true);

    delete [] NameVectorXArray;

    return VMHL_Result;
}