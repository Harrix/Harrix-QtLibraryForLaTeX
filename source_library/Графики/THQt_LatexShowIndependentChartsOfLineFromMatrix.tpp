template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle, bool SolidStyle, bool CircleStyle)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
Входные параметры:
 VMHL_MatrixXY - указатель на матрицу значений X и Y графиков;
 VMHL_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VMHL_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
 NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VMHL_M/2;
 Label - label для графика;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную область под кривой;
 ShowSpecPoints - показывать ли специальные точки;
 ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается;
 GrayStyle - серый стиль графиков;
 SolidStyle - линии делать сплошными или разными по типу (точками, тире и др.);
 CircleStyle - точки все делать кругляшками или нет.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VMHL_Result;//переменная итогового результата
    int i,j,k;

    //цвета
    QString *Color=new QString [VMHL_M/2];
    for (j=0;j<VMHL_M/2;j++) Color[j]="97BBCD";

    QString *ColorArea=new QString [VMHL_M/2];
    for (j=0;j<VMHL_M/2;j++) ColorArea[j]="plot1";

    QString *TypeLine=new QString [VMHL_M/2];
    //for (j=0;j<VMHL_M/2;j++) TypeLine[j]="";

    QString *FaceOfLine=new QString [VMHL_M/2];
    for (j=0;j<VMHL_M/2;j++) FaceOfLine[j]="*";

    QString Opacity="0.5";

    QString Legend;
    if (VMHL_M/2>3) Legend="legend columns=2,\n";

    if (GrayStyle)
    {
        if (VMHL_M/2==2)//если два графика
        {
            Color[1]="CCCCCC";
        }
        if (VMHL_M/2==3)//если три графика и показаны закрашенные области
        {
            Color[0]="799BAC";
            Color[1]="97BBCD";
            Color[2]="CCCCCC";
        }
        if (VMHL_M/2==4)//если 4 графика и показаны закрашенные области
        {
            Color[0]="799BAC";
            Color[1]="83A6B7";
            Color[2]="97BBCD";
            Color[3]="CCCCCC";
        }
        if (VMHL_M/2==5)//если 5 графика и показаны закрашенные области
        {
            Color[0]="799BAC";
            Color[1]="83A6B7";
            Color[2]="97BBCD";
            Color[3]="ADC2CD";
            Color[4]="CCCCCC";
        }
        if (VMHL_M/2==6)//если 6 графика и показаны закрашенные области
        {
            Color[0]="799BAC";
            Color[1]="83A6B7";
            Color[2]="97BBCD";
            Color[3]="ADC2CD";
            Color[4]="BEC7CD";
            Color[5]="CCCCCC";
        }
        if (VMHL_M/2==7)//если 7 графика и показаны закрашенные области
        {
            Color[0]="6A8795";
            Color[1]="799BAC";
            Color[2]="83A6B7";
            Color[3]="97BBCD";
            Color[4]="ADC2CD";
            Color[5]="BEC7CD";
            Color[6]="CCCCCC";
        }
        if (VMHL_M/2==8)//если 8 графика и показаны закрашенные области
        {
            Color[0]="6A8795";
            Color[1]="799BAC";
            Color[2]="83A6B7";
            Color[3]="8EB1C3";
            Color[4]="97BBCD";
            Color[5]="ADC2CD";
            Color[6]="BEC7CD";
            Color[7]="CCCCCC";
        }
        if (VMHL_M/2==9)//если 9 графика и показаны закрашенные области
        {
            Color[0]="6a8795";
            Color[1]="799BAC";
            Color[2]="83A6B7";
            Color[3]="8EB1C3";
            Color[4]="97BBCD";
            Color[5]="ADC2CD";
            Color[6]="B6C5CD";
            Color[7]="BEC7CD";
            Color[8]="CCCCCC";
        }
        if (VMHL_M/2>9)//если больше 9 графика и показаны закрашенные области
        {
            double position;
            for (j=0;j<VMHL_M/2;j++)
            {
                position=j/double(VMHL_M/2);
                Color[j]=(THQt_ColorFromGradient(position,"#6A8795","#CCCCCC")).mid(1).toUpper();//"537c90";
            }

            Opacity="0.1";
        }

        for (j=0;j<VMHL_M/2;j++) ColorArea[j]="plot"+QString::number(j+1);
    }
    else
    {
        double position;
        for (j=0;j<VMHL_M/2;j++)
        {
            position=j/double(VMHL_M/2);
            Color[j]=(THQt_AlphaBlendingColorToColor(0.2,THQt_GiveRainbowColorRGB(position),"#000000")).mid(1).toUpper();//"537c90";
        }

        Opacity="0.3";

        for (j=0;j<VMHL_M/2;j++) ColorArea[j]="plotmain";

        if (VMHL_M/2==1)
        {
            Color[0]="97BBCD";
            ColorArea[0]="plotmain";

            Opacity="0.5";
        }

        if (VMHL_M/2==2)
        {
            Color[0]="97BBCD";
            ColorArea[0]="plotmain";

            Color[1]="FF0000";
            ColorArea[1]="plotsecond";

            Opacity="0.5";
        }

        if (VMHL_M/2==3)
        {
            Color[0]="97BBCD";
            Color[1]="4AC955";
            Color[2]="E06C65";
            for (j=0;j<VMHL_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VMHL_M/2==4)
        {
            Color[0]="97BBCD";
            Color[1]="4AC955";
            Color[2]="E7CC4C";
            Color[3]="E06C65";
            for (j=0;j<VMHL_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VMHL_M/2==5)
        {
            Color[0]="97BBCD";
            Color[1]="4AC955";
            Color[2]="E7CC4C";
            Color[3]="E06C65";
            Color[4]="9D50C8";
            for (j=0;j<VMHL_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VMHL_M/2==6)
        {
            Color[0]="97BBCD";
            Color[1]="4AC955";
            Color[2]="B5D24E";
            Color[3]="E7CC4C";
            Color[4]="E06C65";
            Color[5]="9D50C8";
            for (j=0;j<VMHL_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VMHL_M/2==7)
        {
            Color[0]="6250C9";
            Color[1]="97BBCD";
            Color[2]="4AC955";
            Color[3]="B5D24E";
            Color[4]="E7CC4C";
            Color[5]="E06C65";
            Color[6]="9D50C8";
            for (j=0;j<VMHL_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VMHL_M/2==8)
        {
            Color[0]="6250C9";
            Color[1]="97BBCD";
            Color[2]="4AC955";
            Color[3]="B5D24E";
            Color[4]="E7CC4C";
            Color[5]="E06C65";
            Color[6]="9D50C8";
            Color[7]="C64F8F";
            for (j=0;j<VMHL_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VMHL_M/2==9)
        {
            Color[0]="6250C9";
            Color[1]="97BBCD";
            Color[2]="4AC955";
            Color[3]="B5D24E";
            Color[4]="E7CC4C";
            Color[5]="E9AC4C";
            Color[6]="E06C65";
            Color[7]="9D50C8";
            Color[8]="C64F8F";
            for (j=0;j<VMHL_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
    }

    for (j=0;j<VMHL_M/2;j++)
    {
        if (j%6==1) TypeLine[j]=",dashed";
        if (j%6==2) TypeLine[j]=",dotted";
        if (j%6==3) TypeLine[j]=",dashdotted";
        if (j%6==4) TypeLine[j]=",dashdotdotted";
        if (j%6==5) TypeLine[j]=",loosely dotted";
    }

    for (j=0;j<VMHL_M/2;j++)
    {
        if (j%5==1) FaceOfLine[j]="square*";
        if (j%5==2) FaceOfLine[j]="triangle*";
        if (j%5==3) FaceOfLine[j]="diamond*";
        if (j%5==4) FaceOfLine[j]="triangle*, every mark/.append style={rotate=90}";
    }

    if (CircleStyle) for (j=0;j<VMHL_M/2;j++) FaceOfLine[j]="*";
    if (SolidStyle)  for (j=0;j<VMHL_M/2;j++) TypeLine[j]="";

    //Подсчитаем максимальное число N
    int VMHL_N_Max;
    VMHL_N_Max = VMHL_N_EveryCol[0];
    for (j=0;j<VMHL_M/2;j++)
        if (VMHL_N_EveryCol[j*2]>VMHL_N_Max)
            VMHL_N_Max=VMHL_N_EveryCol[j*2];

    //посчитаем гарницы изменения параметров
    T MinX=VMHL_MatrixXY[0][0];
    for (j=0;j<VMHL_M/2;j++)
        for (int i=0;i<VMHL_N_EveryCol[j*2];i++)
            if (VMHL_MatrixXY[i][j*2]<MinX)
                MinX=VMHL_MatrixXY[i][j*2];

    T MaxX=VMHL_MatrixXY[0][0];
    for (j=0;j<VMHL_M/2;j++)
        for (int i=0;i<VMHL_N_EveryCol[j*2];i++)
            if (VMHL_MatrixXY[i][j*2]>MaxX)
                MaxX=VMHL_MatrixXY[i][j*2];

    T MinY=VMHL_MatrixXY[0][1];
    for (j=0;j<VMHL_M/2;j++)
        for (int i=0;i<VMHL_N_EveryCol[j*2+1];i++)
            if (VMHL_MatrixXY[i][j*2+1]<MinY)
                MinY=VMHL_MatrixXY[i][j*2+1];

    T MaxY=VMHL_MatrixXY[0][1];
    for (j=0;j<VMHL_M/2;j++)
        for (int i=0;i<VMHL_N_EveryCol[j*2+1];i++)
            if (VMHL_MatrixXY[i][j*2+1]>MaxY)
                MaxY=VMHL_MatrixXY[i][j*2+1];

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/15.;
    T LeftYBoundingBox=MinY-LengthY/15.;
    T RightXBoundingBox=MaxX+LengthX/15.;
    T RightYBoundingBox=MaxY+LengthY/15.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    if (ForNormalSize)
        VMHL_Result+="% Вывод графика\n{\n";
    else
        VMHL_Result+="% Вывод подграфика\n{\n";

    //Если график маленький, то дополнительные настройки:
    if (!ForNormalSize)
    {
        VMHL_Result+="\\pgfplotsset{every axis legend/.append style={at={(0.5,-0.25)},anchor=north,legend cell align=left},}\n";
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
        QString HeightPlot="10cm";

        if (VMHL_M/2>10) HeightPlot="9cm";

        if (VMHL_M/2>19) HeightPlot="8cm";

        if (VMHL_M/2>25) HeightPlot="12cm";

        if (VMHL_M/2>35) HeightPlot="10cm";

        VMHL_Result+="height="+HeightPlot+",\n";
        VMHL_Result+="width=17cm,\n";
    }
    else
    {
        QString HeightPlot="5.8cm";

        if (VMHL_M/2>10) HeightPlot="4.8cm";

        if (VMHL_M/2>17) HeightPlot="6.8cm";


        VMHL_Result+="height="+HeightPlot+",\n";
        VMHL_Result+="width=8.5cm,\n";
    }
    VMHL_Result+=Legend;
    VMHL_Result+="]\n\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T **Temp_VMHL_MatrixXY;
    Temp_VMHL_MatrixXY=new double*[VMHL_N_Max];
    for (i=0;i<VMHL_N_Max;i++) Temp_VMHL_MatrixXY[i]=new double[VMHL_M];
    for (j=0;j<VMHL_M;j++)
        for (i=0;i<VMHL_N_EveryCol[j];i++)
            Temp_VMHL_MatrixXY[i][j]=VMHL_MatrixXY[i][j];

    //отсортируем массивы
    for (k=0;k<VMHL_M/2;k++)
    {
        for(i=VMHL_N_EveryCol[2*k]-1;i>0;i--)
            for(j=0;j<i;j++)
                if(Temp_VMHL_MatrixXY[j][2*k]>Temp_VMHL_MatrixXY[j+1][2*k])
                {
                    T x;
                    x=Temp_VMHL_MatrixXY[j+1][2*k];
                    Temp_VMHL_MatrixXY[j+1][2*k]=Temp_VMHL_MatrixXY[j][2*k];
                    Temp_VMHL_MatrixXY[j][2*k]=x;

                    x=Temp_VMHL_MatrixXY[j+1][2*k+1];
                    Temp_VMHL_MatrixXY[j+1][2*k+1]=Temp_VMHL_MatrixXY[j][2*k+1];
                    Temp_VMHL_MatrixXY[j][2*k+1]=x;
                }
    }

    QString *SData = new QString[VMHL_M/2];

    QString *Plot = new QString[VMHL_M/2];

    for (j=0;j<VMHL_M/2;j++)
    {
        for (i=0;i<VMHL_N_EveryCol[2*j]-1;i++)
            SData[j]+=" ("+QString::number(Temp_VMHL_MatrixXY[i][2*j])+", "+QString::number(Temp_VMHL_MatrixXY[i][2*j+1])+") \n";
        SData[j]+=" ("+QString::number(Temp_VMHL_MatrixXY[VMHL_N_EveryCol[2*j+1]-1][2*j])+", "+QString::number(Temp_VMHL_MatrixXY[VMHL_N_EveryCol[2*j+1]-1][2*j+1])+") \n";
    }

    QString MarkSize;
    if (VMHL_N_Max>100) MarkSize=",mark size=1.5pt";


    if ((ShowArea)&&((ShowPoints)||(ShowLine)))
    {
        //нарисуем закрашенную область
        for (j=0;j<VMHL_M/2;j++)
        {
            Plot[j]+="\\addplot[color="+ColorArea[j]+", draw=none,fill, fill opacity = "+Opacity+",forget plot] coordinates {\n";
            Plot[j]+=" ("+QString::number(Temp_VMHL_MatrixXY[0][2*j])+", "+QString::number(MinY)+") \n";
            Plot[j]+=SData[j];
            Plot[j]+=" ("+QString::number(Temp_VMHL_MatrixXY[VMHL_N_EveryCol[j*2]-1][2*j])+", "+QString::number(MinY)+") \n";
            Plot[j]+="};\n\n";
        }
    }

    if ((ShowArea)&&(!ShowPoints)&&(!ShowLine))
    {
        //нарисуем закрашенную область
        for (j=0;j<VMHL_M/2;j++)
        {
            Plot[j]+="\\addplot[color="+ColorArea[j]+", draw=none,fill, fill opacity = "+Opacity+"] coordinates {\n";
            Plot[j]+=" ("+QString::number(Temp_VMHL_MatrixXY[0][2*j])+", "+QString::number(MinY)+") \n";
            Plot[j]+=SData[j];
            Plot[j]+=" ("+QString::number(Temp_VMHL_MatrixXY[VMHL_N_EveryCol[j*2]-1][2*j])+", "+QString::number(MinY)+") \n";
            Plot[j]+="};\n";
            Plot[j]+="\\addlegendentry{"+NameLine[j]+"};\n\n";
        }
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график
        for (j=0;j<VMHL_M/2;j++)
        {
            //Нарисуем график
            Plot[j]+="\\addplot[color=plot"+QString::number(j+1)+",mark options={plot"+QString::number(j+1)+",opacity = 1, fill=white,thick,solid}"+MarkSize+",very thick"+TypeLine[j]+", mark="+FaceOfLine[j]+"] coordinates {\n";
            Plot[j]+=SData[j];
            Plot[j]+="};\n";
            Plot[j]+="\\addlegendentry{"+NameLine[j]+"};\n\n";
        }
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем точки
        for (j=0;j<VMHL_M/2;j++)
        {
            Plot[j]+="\\addplot[color=plot"+QString::number(j+1)+",mark options={plot"+QString::number(j+1)+",opacity = 1, fill=white,thick}"+MarkSize+",only marks, mark="+FaceOfLine[j]+"] coordinates {\n";
            Plot[j]+=SData[j];
            Plot[j]+="};\n";
            Plot[j]+="\\addlegendentry{"+NameLine[j]+"};\n\n";
        }
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        //Нарисуем только линию
        for (j=0;j<VMHL_M/2;j++)
        {
            Plot[j]+="\\addplot[color=plot"+QString::number(j+1)+", no markers,very thick"+TypeLine[j]+"] coordinates {\n";
            Plot[j]+=SData[j];
            Plot[j]+="};\n";
            Plot[j]+="\\addlegendentry{"+NameLine[j]+"};\n\n";
        }
    }

    //Цвета соберем
    for (j=0;j<VMHL_M/2;j++)
    {
        VMHL_Result+="\\definecolor{plot"+QString::number(j+1)+"}{HTML}{"+Color[j]+"}\n";
    }
    VMHL_Result+="\n";

    //собираем общий график
    for (j=0;j<VMHL_M/2;j++)
        VMHL_Result+=Plot[VMHL_M/2-j-1];

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

    VMHL_Result+="}\n\n";

    delete [] SData;
    delete [] Plot;
    delete [] Color;
    delete [] ColorArea;
    delete [] TypeLine;
    delete [] FaceOfLine;

    for (i=0;i<VMHL_N_Max;i++) delete [] Temp_VMHL_MatrixXY[i];
    delete [] Temp_VMHL_MatrixXY;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции отличается отсутствием параметров GrayStyle, SolidStyle, CircleStyle.
Входные параметры:
 VMHL_MatrixXY - указатель на матрицу значений X и Y графиков;
 VMHL_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VMHL_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
 NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VMHL_M/2;
 Label - label для графика;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную область под кривой;
 ShowSpecPoints - показывать ли специальные точки;
 ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VMHL_Result;//переменная итогового результата

    VMHL_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VMHL_MatrixXY, VMHL_N_EveryCol, VMHL_M, TitleChart,  NameVectorX, NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, ForNormalSize, false,  false,  false);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции отличается отсутствием параметров ForNormalSize, GrayStyle, SolidStyle, CircleStyle.
Входные параметры:
 VMHL_MatrixXY - указатель на матрицу значений X и Y графиков;
 VMHL_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VMHL_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
 NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VMHL_M/2;
 Label - label для графика;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную область под кривой;
 ShowSpecPoints - показывать ли специальные точки.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VMHL_Result;//переменная итогового результата

    VMHL_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VMHL_MatrixXY, VMHL_N_EveryCol, VMHL_M, TitleChart,  NameVectorX, NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, true, false,  false,  false);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции отличается отсутствием всех булевских переменных.
Входные параметры:
 VMHL_MatrixXY - указатель на матрицу значений X и Y графиков;
 VMHL_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VMHL_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
 NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VMHL_M/2;
 Label - label для графика.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VMHL_Result;//переменная итогового результата

    VMHL_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VMHL_MatrixXY, VMHL_N_EveryCol, VMHL_M, TitleChart,  NameVectorX, NameVectorY, NameLine, Label, true, true, false, true, true, false,  false,  false);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции отличается отсутствием всех булевских переменных и переменных названия.
Входные параметры:
 VMHL_MatrixXY - указатель на матрицу значений X и Y графиков;
 VMHL_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VMHL_M - количество столбцов матрицы (должно быть четным числом конечно).
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VMHL_Result;//переменная итогового результата

    QString *NameLine;

    NameLine = new QString[VMHL_M-1];

    for (int i=0;i<VMHL_M-1;i++) NameLine[i]="График "+QString::number(i+1);

    VMHL_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VMHL_MatrixXY, VMHL_N_EveryCol, VMHL_M, "", "x", "y", NameLine, "Chart"+HQt_RandomString(8), true, true, false, true, true, false,  false,  false);

    delete [] NameLine;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle, bool SolidStyle, bool CircleStyle)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции, что число элементов в каждом графике одинаковое, поэтому вместо VMHL_N_EveryCol используется одно число VMHL_N.
Входные параметры:
 VMHL_MatrixXY - указатель на матрицу значений X и Y графиков;
 VMHL_N - количество элементов в каждом столбце. Это число точек;
 VMHL_M - количество столбцов матрицы (должно быть четным числом конечно) VMHL_M/2 - это число графиков;
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
 NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VMHL_M/2;
 Label - label для графика;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную область под кривой;
 ShowSpecPoints - показывать ли специальные точки;
 ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается;
 GrayStyle - серый стиль графиков;
 SolidStyle - линии делать сплошными или разными по типу (точками, тире и др.);
 CircleStyle - точки все делать кругляшками или нет.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VMHL_Result;//переменная итогового результата

    int *VMHL_N_EveryCol = new int[VMHL_M];
    for (int i=0;i<VMHL_M;i++) VMHL_N_EveryCol[i]=VMHL_N;

    VMHL_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VMHL_MatrixXY, VMHL_N_EveryCol, VMHL_M, TitleChart,  NameVectorX, NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, ForNormalSize, GrayStyle,  SolidStyle,  CircleStyle);

    delete [] VMHL_N_EveryCol;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции, что число элементов в каждом графике одинаковое, поэтому вместо VMHL_N_EveryCol используется одно число VMHL_N. От основной функции также отличается отсутствием параметров GrayStyle, SolidStyle, CircleStyle.
Входные параметры:
 VMHL_MatrixXY - указатель на матрицу значений X и Y графиков;
 VMHL_N - количество элементов в каждом столбце. Это число точек;
 VMHL_M - количество столбцов матрицы (должно быть четным числом конечно) VMHL_M/2 - это число графиков;
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
 NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VMHL_M/2;
 Label - label для графика;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную область под кривой;
 ShowSpecPoints - показывать ли специальные точки;
 ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VMHL_Result;//переменная итогового результата

    int *VMHL_N_EveryCol = new int[VMHL_M];
    for (int i=0;i<VMHL_M;i++) VMHL_N_EveryCol[i]=VMHL_N;

    VMHL_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VMHL_MatrixXY, VMHL_N_EveryCol, VMHL_M, TitleChart,  NameVectorX, NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, ForNormalSize, false,  false,  false);

    delete [] VMHL_N_EveryCol;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции, что число элементов в каждом графике одинаковое, поэтому вместо VMHL_N_EveryCol используется одно число VMHL_N. От основной функции также отличается отсутствием параметров ForNormalSize, GrayStyle, SolidStyle, CircleStyle.
Входные параметры:
 VMHL_MatrixXY - указатель на матрицу значений X и Y графиков;
 VMHL_N - количество элементов в каждом столбце. Это число точек;
 VMHL_M - количество столбцов матрицы (должно быть четным числом конечно) VMHL_M/2 - это число графиков;
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
 NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VMHL_M/2;
 Label - label для графика;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную область под кривой;
 ShowSpecPoints - показывать ли специальные точки.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VMHL_Result;//переменная итогового результата

    int *VMHL_N_EveryCol = new int[VMHL_M];
    for (int i=0;i<VMHL_M;i++) VMHL_N_EveryCol[i]=VMHL_N;

    VMHL_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VMHL_MatrixXY, VMHL_N_EveryCol, VMHL_M, TitleChart,  NameVectorX, NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints, true, false,  false,  false);

    delete [] VMHL_N_EveryCol;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции, что число элементов в каждом графике одинаковое, поэтому вместо VMHL_N_EveryCol используется одно число VMHL_N. От основной функции также отличается отсутствием всех булевских переменных.
Входные параметры:
 VMHL_MatrixXY - указатель на матрицу значений X и Y графиков;
 VMHL_N - количество элементов в каждом столбце. Это число точек;
 VMHL_M - количество столбцов матрицы (должно быть четным числом конечно) VMHL_M/2 - это число графиков;
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
 NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VMHL_M/2;
 Label - label для графика.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VMHL_Result;//переменная итогового результата

    int *VMHL_N_EveryCol = new int[VMHL_M];
    for (int i=0;i<VMHL_M;i++) VMHL_N_EveryCol[i]=VMHL_N;

    VMHL_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VMHL_MatrixXY, VMHL_N_EveryCol, VMHL_M, TitleChart,  NameVectorX, NameVectorY, NameLine, Label, true, true, false, true, true, false,  false,  false);

    delete [] VMHL_N_EveryCol;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
От основной функции, что число элементов в каждом графике одинаковое, поэтому вместо VMHL_N_EveryCol используется одно число VMHL_N. От основной функции также отличается отсутствием всех булевских переменных и переменных названий.
Входные параметры:
 VMHL_MatrixXY - указатель на матрицу значений X и Y графиков;
 VMHL_N - количество элементов в каждом столбце. Это число точек;
 VMHL_M - количество столбцов матрицы (должно быть четным числом конечно) VMHL_M/2 - это число графиков.
Возвращаемое значение:
 Строка с Latex кодами с выводимым графиком.
*/
    QString VMHL_Result;//переменная итогового результата

    int *VMHL_N_EveryCol = new int[VMHL_M];
    for (int i=0;i<VMHL_M;i++) VMHL_N_EveryCol[i]=VMHL_N;

    QString *NameLine;
    NameLine = new QString[VMHL_M-1];
    for (int i=0;i<VMHL_M-1;i++) NameLine[i]="График "+QString::number(i+1);

    VMHL_Result = THQt_LatexShowIndependentChartsOfLineFromMatrix (VMHL_MatrixXY, VMHL_N_EveryCol, VMHL_M, "", "x", "y", NameLine, "Chart"+HQt_RandomString(8), true, true, false, true, true, false,  false,  false);

    delete [] VMHL_N_EveryCol;
    delete [] NameLine;


    return VMHL_Result;
}