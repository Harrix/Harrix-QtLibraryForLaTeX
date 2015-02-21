template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize, bool MinZero)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    Входные параметры:
     VHQt_Vector - указатель на вектор значений точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VHQt_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается;
     MinZero - гистограмму начинать с нуля (true) или с минимального значения среди VHQt_Vector (false).
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата
    int i;

    //посчитаем границы изменения параметров

    T MinY=VHQt_Vector[0];
    for (i=1;i<VHQt_N;i++)
        if (VHQt_Vector[i]<MinY)
            MinY=VHQt_Vector[i];

    T MaxY=VHQt_Vector[0];
    for (i=1;i<VHQt_N;i++)
        if (VHQt_Vector[i]>MaxY)
            MaxY=VHQt_Vector[i];

    T LengthY=MaxY-MinY;

    if (ForNormalSize)
        VHQt_Result+="% Вывод графика\n";
    else
        VHQt_Result+="% Вывод подграфика\n";


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

    QString *NameVectorXnew=new QString[VHQt_N];
    for (i=0;i<VHQt_N;i++)
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
    if (ForNormalSize) VHQt_Result+="\\begin{figure} [H]\n";
    if (ForNormalSize) VHQt_Result+="\\centering\n";
    VHQt_Result+="{\n";
    VHQt_Result+="\\pgfplotsset{x axis line style={-},}\n";
    if (ForNormalSize) VHQt_Result+="\\begin{tikzpicture}\n"; else VHQt_Result+="\\begin{tikzpicture}[scale=0.9, baseline]\n";
    VHQt_Result+="\\begin{axis} [\n";
    VHQt_Result+="ybar,\n";
    VHQt_Result+="xmajorgrids=false,\n";
    VHQt_Result+="xminorgrids=false,\n";
    VHQt_Result+="ylabel={"+NameVectorYnew+"},\n";

    double MinD=10;
    if (!ForNormalSize) MinD=5;

    if ((MinY>=0)&&(MaxY>=0)&&(MinY!=MaxY))
    {

        VHQt_Result+="ymax="+QString::number(MaxY+LengthY/15.)+",\n";
        if (MinZero)
            VHQt_Result+="ymin=0,\n";
        else
            VHQt_Result+="ymin="+QString::number(MinY-LengthY/MinD)+",\n";
    }

    if ((MinY<0)&&(MaxY>=0))
    {

        VHQt_Result+="ymin="+QString::number(MinY-LengthY/MinD)+",\n";
        VHQt_Result+="ymax="+QString::number(MaxY+LengthY/15.)+",\n";
    }

    if ((MinY<0)&&(MaxY<0)&&(MinY!=MaxY))
    {

        VHQt_Result+="ymin="+QString::number(MinY-LengthY/MinD)+",\n";
        if (MinZero)
            VHQt_Result+="ymax=0,\n";
        else
            VHQt_Result+="ymax="+QString::number(MaxY+LengthY/15.)+",\n";
    }

    if ((MinY==MaxY)&&(MinY>=0))
    {
        if (MinZero)
        {
            VHQt_Result+="ymax="+QString::number(MaxY+(fabs(MinY)/MinD))+",\n";
            VHQt_Result+="ymin=0,\n";
        }
        else
        {
            VHQt_Result+="ymax="+QString::number(MaxY+(fabs(MinY)/MinD)/MinD)+",\n";
            VHQt_Result+="ymin="+QString::number(MinY-fabs(MinY)/MinD)+",\n";
        }
    }

    if ((MinY==MaxY)&&(MinY<0))
    {

        if (MinZero)
        {
            VHQt_Result+="ymax=0,\n";
            VHQt_Result+="ymin="+QString::number(MinY-(fabs(MinY)/MinD))+",\n";
        }
        else
        {
            VHQt_Result+="ymax="+QString::number(MaxY+fabs(MinY)/MinD)+",\n";
            VHQt_Result+="ymin="+QString::number(MinY-(fabs(MinY)/MinD)/MinD)+",\n";
        }
    }


    if (ForNormalSize)
    {
        VHQt_Result+="height=10cm,\n";
        VHQt_Result+="width=17cm,\n";
    }
    else
    {
        VHQt_Result+="height=5.8cm,\n";
        VHQt_Result+="width=8.5cm,\n";
    }

    VHQt_Result+="xticklabels={";
    for (i=0;i<VHQt_N-1;i++) VHQt_Result+=NameVectorXnew[i]+", ";
    VHQt_Result+=NameVectorXnew[VHQt_N-1]+"},\n";

    VHQt_Result+="xtick=data,\n";
    VHQt_Result+="minor x tick num=0,\n";
    VHQt_Result+="nodes near coords,\n";
    VHQt_Result+="nodes near coords align={vertical},\n";

    if (ForNormalSize)
    {
        if (VHQt_N>10)
            VHQt_Result+="every node near coord/.style={color=black,font=\\tiny},\n";
        else
            VHQt_Result+="every node near coord/.style={color=black},\n";
    }
    else
        VHQt_Result+="every node near coord/.style={color=black,font=\\tiny},\n";

    QString BarWidth;
    QString TextWidth;
    QString XLimits;
    if (ForNormalSize)
    {
        BarWidth="bar width=2.0cm,\n";
        TextWidth="x tick label style={font=\\small,text width=1.7cm,align=center},\n";
        XLimits="enlarge x limits=.15,\n";

        if (VHQt_N==1)
        {
            BarWidth="bar width=3.0cm,\n";
            TextWidth="x tick label style={font=\\small,text width=15cm,align=center},\n";
        }

        if (VHQt_N==2)
        {
            BarWidth="bar width=3.0cm,\n";
            TextWidth="x tick label style={font=\\small,text width=7cm,align=center},\n";
            XLimits="enlarge x limits=.4,\n";
        }

        if (VHQt_N==3)
        {
            BarWidth="bar width=2.5cm,\n";
            TextWidth="x tick label style={font=\\small,text width=4cm,align=center},\n";
        }

        if (VHQt_N==4)
        {
            BarWidth="bar width=2cm,\n";
            TextWidth="x tick label style={font=\\small,text width=1.9cm,align=center},\n";
        }

        if (VHQt_N==6)
        {
            BarWidth="bar width=2cm,\n";
            TextWidth="x tick label style={font=\\small,text width=1.7cm,align=center},\n";
        }

        if (VHQt_N==7)
        {
            BarWidth="bar width=1.8cm,\n";
            TextWidth="x tick label style={font=\\small,text width=1.5cm,align=center},\n";
        }

        if (VHQt_N==8)
        {
            BarWidth="bar width=1.5cm,\n";
            TextWidth="x tick label style={font=\\tiny,text width=1.4cm,align=center},\n";
        }

        if (VHQt_N==9)
        {
            BarWidth="bar width=1.2cm,\n";
            TextWidth="x tick label style={font=\\tiny,rotate=45,anchor=east},\n";
        }

        if (VHQt_N==10)
        {
            BarWidth="bar width=1.0cm,\n";
            TextWidth="x tick label style={font=\\tiny,rotate=45,anchor=east},\n";
        }

        if (VHQt_N==11)
        {
            BarWidth="bar width=0.8cm,\n";
        }

        if (VHQt_N>=11)
        {
            TextWidth="x tick label style={font=\\tiny,rotate=45,anchor=east},\n";
            XLimits="enlarge x limits=.05,\n";
        }

        if (VHQt_N==12)
        {
            BarWidth="bar width=0.75cm,\n";
        }

        if (VHQt_N==13)
        {
            BarWidth="bar width=0.65cm,\n";
        }

        if (VHQt_N>=14)
        {
            BarWidth="";
        }


    }
    else
    {
        BarWidth="bar width=0.8cm,\n";
        TextWidth="x tick label style={font=\\tiny,rotate=45,anchor=east},\n";
        XLimits="enlarge x limits=.15,\n";

        if (VHQt_N==1)
        {
            BarWidth="bar width=1.0cm,\n";
            TextWidth="x tick label style={font=\\tiny,text width=8cm,align=center},\n";
        }

        if (VHQt_N==2)
        {
            BarWidth="bar width=1.0cm,\n";
            TextWidth="x tick label style={font=\\small,text width=4cm,align=center},\n";
            XLimits="enlarge x limits=.4,\n";
        }

        if (VHQt_N==8)
        {
            BarWidth="bar width=0.6cm,\n";
        }

        if (VHQt_N>=9)
        {
            BarWidth="";
        }

        if (VHQt_N>=11)
        {
            XLimits="enlarge x limits=.05,\n";
        }
    }
    VHQt_Result+=BarWidth;
    VHQt_Result+=TextWidth;
    VHQt_Result+=XLimits;


    VHQt_Result+="]\n\n";


    //соберем в массивы данные точек
    QString SData;
    for (i=0;i<VHQt_N;i++)
        SData+=" ("+QString::number(i)+", "+QString::number(VHQt_Vector[i])+") \n";

    //добавим график
    VHQt_Result+="\\addplot[color=plotmain,fill] coordinates {\n";
    VHQt_Result+=SData;
    VHQt_Result+="};\n";

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

    delete [] NameVectorXnew;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается отсутствием параметра MinZero.
    Входные параметры:
     VHQt_Vector - указатель на вектор значений точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VHQt_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowBar (VHQt_Vector, VHQt_N, TitleChart, NameVectorX, NameVectorY, Label, ForNormalSize, false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QString *NameVectorX, QString NameVectorY, QString Label)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается отсутствием параметра MinZero и ForNormalSize.
    Входные параметры:
     VHQt_Vector - указатель на вектор значений точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VHQt_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowBar (VHQt_Vector, VHQt_N, TitleChart, NameVectorX, NameVectorY, Label, true, false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается отсутствием параметра MinZero и ForNormalSize и всех текстовых параметров.
    Входные параметры:
     VHQt_Vector - указатель на вектор значений точек;
     VHQt_N - количество точек.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    QString *NameVectorX = new QString[VHQt_N];
    for (int i=0;i<VHQt_N;i++) NameVectorX[i] = "№ " + QString::number(i+1);

    VHQt_Result = THQt_LatexShowBar (VHQt_Vector, VHQt_N, "График", NameVectorX, "y",  "Chart"+HQt_RandomString(8), true, false);

    delete [] NameVectorX;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize, bool MinZero)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается тем, что список наименований хранится в QStringList, а не массиве.
    Входные параметры:
     VHQt_Vector - указатель на вектор значений точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VHQt_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается;
     MinZero - гистограмму начинать с нуля (true) или с минимального значения среди VHQt_Vector (false).
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    QString *NameVectorXArray = new QString [VHQt_N];
    for (int i=0;i<VHQt_N;i++) NameVectorXArray[i]=NameVectorX.at(i);

    VHQt_Result = THQt_LatexShowBar (VHQt_Vector, VHQt_N, TitleChart, NameVectorXArray, NameVectorY, Label, ForNormalSize, MinZero);

    delete [] NameVectorXArray;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается тем, что список наименований хранится в QStringList, а не массиве. Еще нет переменой MinZero.
    Входные параметры:
     VHQt_Vector - указатель на вектор значений точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VHQt_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    QString *NameVectorXArray = new QString [VHQt_N];
    for (int i=0;i<VHQt_N;i++) NameVectorXArray[i]=NameVectorX.at(i);

    VHQt_Result = THQt_LatexShowBar (VHQt_Vector, VHQt_N, TitleChart, NameVectorXArray, NameVectorY, Label, ForNormalSize, true);

    delete [] NameVectorXArray;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowBar (T *VHQt_Vector, int VHQt_N, QString TitleChart, QStringList NameVectorX, QString NameVectorY, QString Label)
{
    /*
    Функция возвращает строку с выводом некоторого графика гистограммы с Latex кодами.
    От основной функции отличается тем, что список наименований хранится в QStringList, а не массиве. Еще нет переменых MinZero и ForNormalSize.
    Входные параметры:
     VHQt_Vector - указатель на вектор значений точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название значений точек. Будут подписаны под каждым столбиком на оси Ox. Количество элементов VHQt_N;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    QString *NameVectorXArray = new QString [VHQt_N];
    for (int i=0;i<VHQt_N;i++) NameVectorXArray[i]=NameVectorX.at(i);

    VHQt_Result = THQt_LatexShowBar (VHQt_Vector, VHQt_N, TitleChart, NameVectorXArray, NameVectorY, Label, true, true);

    delete [] NameVectorXArray;

    return VHQt_Result;
}