template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize, bool GrayStyle, bool SolidStyle, bool CircleStyle)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    Входные параметры:
     VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
     VHQt_N - количество точек;
     VHQt_M - количество столбцов матрицы (1+количество графиков);
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M-1 (так как первый столбец - это X значения);
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
    QString VHQt_Result;//переменная итогового результата
    int i,j,k;

    //цвета
    QString *Color=new QString [VHQt_M-1];
    for (j=0;j<VHQt_M-1;j++) Color[j]="97BBCD";

    QString *ColorArea=new QString [VHQt_M-1];
    for (j=0;j<VHQt_M-1;j++) ColorArea[j]="plot1";

    QString *TypeLine=new QString [VHQt_M-1];
    //for (j=0;j<VHQt_M-1;j++) TypeLine[j]="";

    QString *FaceOfLine=new QString [VHQt_M-1];
    for (j=0;j<VHQt_M-1;j++) FaceOfLine[j]="*";

    QString Opacity="0.5";

    QString Legend;
    if (VHQt_M-1>3) Legend="legend columns=2,\n";

    if (GrayStyle)
    {
        if (VHQt_M-1==2)//если два графика
        {
            Color[1]="CCCCCC";
        }
        if (VHQt_M-1==3)//если три графика
        {
            Color[0]="799BAC";
            Color[1]="97BBCD";
            Color[2]="CCCCCC";
        }
        if (VHQt_M-1==4)//если 4 графика
        {
            Color[0]="799BAC";
            Color[1]="83A6B7";
            Color[2]="97BBCD";
            Color[3]="CCCCCC";
        }
        if (VHQt_M-1==5)//если 5 графика
        {
            Color[0]="799BAC";
            Color[1]="83A6B7";
            Color[2]="97BBCD";
            Color[3]="ADC2CD";
            Color[4]="CCCCCC";
        }
        if (VHQt_M-1==6)//если 6 графика
        {
            Color[0]="799BAC";
            Color[1]="83A6B7";
            Color[2]="97BBCD";
            Color[3]="ADC2CD";
            Color[4]="BEC7CD";
            Color[5]="CCCCCC";
        }
        if (VHQt_M-1==7)//если 7 графика
        {
            Color[0]="6A8795";
            Color[1]="799BAC";
            Color[2]="83A6B7";
            Color[3]="97BBCD";
            Color[4]="ADC2CD";
            Color[5]="BEC7CD";
            Color[6]="CCCCCC";
        }
        if (VHQt_M-1==8)//если 8 графика
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
        if (VHQt_M-1==9)//если 9 графика
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
        if (VHQt_M-1>9)//если больше 9 графика
        {
            double position;
            for (j=0;j<VHQt_M-1;j++)
            {
                position=j/double(VHQt_M-1);
                Color[j]=(THQt_ColorFromGradient(position,"#6A8795","#CCCCCC")).mid(1).toUpper();//"537c90";
            }

            Opacity="0.1";
        }

        for (j=0;j<VHQt_M-1;j++) ColorArea[j]="plot"+QString::number(j+1);
    }
    else
    {
        double position;
        for (j=0;j<VHQt_M-1;j++)
        {
            position=j/double(VHQt_M-1);
            Color[j]=(THQt_AlphaBlendingColorToColor(0.2,THQt_GiveRainbowColorRGB(position),"#000000")).mid(1).toUpper();//"537c90";
        }

        Opacity="0.3";

        for (j=0;j<VHQt_M-1;j++) ColorArea[j]="plotmain";

        if (VHQt_M-1==1)
        {
            Color[0]="97BBCD";
            ColorArea[0]="plotmain";

            Opacity="0.5";
        }

        if (VHQt_M-1==2)
        {
            Color[0]="97BBCD";
            ColorArea[0]="plotmain";

            Color[1]="FF0000";
            ColorArea[1]="plotsecond";

            Opacity="0.5";
        }

        if (VHQt_M-1==3)
        {
            Color[0]="97BBCD";
            Color[1]="4AC955";
            Color[2]="E06C65";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M-1==4)
        {
            Color[0]="97BBCD";
            Color[1]="4AC955";
            Color[2]="E7CC4C";
            Color[3]="E06C65";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M-1==5)
        {
            Color[0]="97BBCD";
            Color[1]="4AC955";
            Color[2]="E7CC4C";
            Color[3]="E06C65";
            Color[4]="9D50C8";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M-1==6)
        {
            Color[0]="97BBCD";
            Color[1]="4AC955";
            Color[2]="B5D24E";
            Color[3]="E7CC4C";
            Color[4]="E06C65";
            Color[5]="9D50C8";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M-1==7)
        {
            Color[0]="6250C9";
            Color[1]="97BBCD";
            Color[2]="4AC955";
            Color[3]="B5D24E";
            Color[4]="E7CC4C";
            Color[5]="E06C65";
            Color[6]="9D50C8";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M-1==8)
        {
            Color[0]="6250C9";
            Color[1]="97BBCD";
            Color[2]="4AC955";
            Color[3]="B5D24E";
            Color[4]="E7CC4C";
            Color[5]="E06C65";
            Color[6]="9D50C8";
            Color[7]="C64F8F";
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
        if (VHQt_M-1==9)
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
            for (j=0;j<VHQt_M/2;j++)
                Color[j]=(THQt_AlphaBlendingColorToColor(0.2,"#"+Color[j],"#000000")).mid(1).toUpper();
        }
    }

    for (j=0;j<VHQt_M-1;j++)
    {
        if (j%6==1) TypeLine[j]=",dashed";
        if (j%6==2) TypeLine[j]=",dotted";
        if (j%6==3) TypeLine[j]=",dashdotted";
        if (j%6==4) TypeLine[j]=",dashdotdotted";
        if (j%6==5) TypeLine[j]=",loosely dotted";
    }

    for (j=0;j<VHQt_M-1;j++)
    {
        if (j%5==1) FaceOfLine[j]="square*";
        if (j%5==2) FaceOfLine[j]="triangle*";
        if (j%5==3) FaceOfLine[j]="diamond*";
        if (j%5==4) FaceOfLine[j]="triangle*, every mark/.append style={rotate=90}";
    }

    if (CircleStyle) for (j=0;j<VHQt_M-1;j++) FaceOfLine[j]="*";
    if (SolidStyle)  for (j=0;j<VHQt_M-1;j++) TypeLine[j]="";

    //посчитаем гарницы изменения параметров
    T MinX=VHQt_MatrixXY[0][0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_MatrixXY[i][0]<MinX)
            MinX=VHQt_MatrixXY[i][0];

    T MaxX=VHQt_MatrixXY[0][0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_MatrixXY[i][0]>MaxX)
            MaxX=VHQt_MatrixXY[i][0];

    T MinY=VHQt_MatrixXY[0][1];
    for (j=0;j<VHQt_M-1;j++)
        for (int i=0;i<VHQt_N;i++)
            if (VHQt_MatrixXY[i][j+1]<MinY)
                MinY=VHQt_MatrixXY[i][j+1];

    T MaxY=VHQt_MatrixXY[0][1];
    for (j=0;j<VHQt_M-1;j++)
        for (int i=0;i<VHQt_N;i++)
            if (VHQt_MatrixXY[i][j+1]>MaxY)
                MaxY=VHQt_MatrixXY[i][j+1];

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
        VHQt_Result+="% Вывод графика\n{\n";
    else
        VHQt_Result+="% Вывод подграфика\n{\n";

    //Если график маленький, то дополнительные настройки:
    if (!ForNormalSize)
    {
        VHQt_Result+="\\pgfplotsset{every axis legend/.append style={at={(0.5,-0.25)},anchor=north,legend cell align=left},}\n";
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
    if (ForNormalSize) VHQt_Result+="\\begin{figure} [H]\n";
    if (ForNormalSize) VHQt_Result+="\\centering\n";
    if (ForNormalSize) VHQt_Result+="\\begin{tikzpicture}\n"; else VHQt_Result+="\\begin{tikzpicture}[scale=0.9, baseline]\n";
    VHQt_Result+="\\begin{axis} [\n";
    VHQt_Result+="xlabel={"+NameVectorXnew+"},\n";
    VHQt_Result+="ylabel={"+NameVectorYnew+"},\n";
    //if (ForNormalSize)
    VHQt_Result+="xmax="+SRightXBoundingBox+",\n";
    //if (ForNormalSize)
    VHQt_Result+="ymax="+SRightYBoundingBox+",\n";
    if (ForNormalSize)
    {
        QString HeightPlot="10cm";

        if (VHQt_M-1>10) HeightPlot="9cm";

        if (VHQt_M-1>19) HeightPlot="8cm";

        if (VHQt_M-1>25) HeightPlot="12cm";

        if (VHQt_M-1>35) HeightPlot="10cm";

        VHQt_Result+="height="+HeightPlot+",\n";
        VHQt_Result+="width=17cm,\n";
    }
    else
    {
        QString HeightPlot="5.8cm";

        if (VHQt_M-1>10) HeightPlot="4.8cm";

        if (VHQt_M-1>17) HeightPlot="6.8cm";


        VHQt_Result+="height="+HeightPlot+",\n";
        VHQt_Result+="width=8.5cm,\n";
    }
    VHQt_Result+=Legend;
    VHQt_Result+="]\n\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T **Temp_VHQt_MatrixXY;
    Temp_VHQt_MatrixXY=new double*[VHQt_N];
    for (i=0;i<VHQt_N;i++) Temp_VHQt_MatrixXY[i]=new double[VHQt_M];
    for (i=0;i<VHQt_N;i++)
        for (j=0;j<VHQt_M;j++)
            Temp_VHQt_MatrixXY[i][j]=VHQt_MatrixXY[i][j];

    //отсортируем массивы
    for(i=VHQt_N-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_MatrixXY[j][0]>Temp_VHQt_MatrixXY[j+1][0])
            {
                for (k=0;k<VHQt_M;k++)
                {
                    T x;
                    x=Temp_VHQt_MatrixXY[j+1][k];
                    Temp_VHQt_MatrixXY[j+1][k]=Temp_VHQt_MatrixXY[j][k];
                    Temp_VHQt_MatrixXY[j][k]=x;
                }
            }

    QString *SData = new QString[VHQt_M-1];

    QString *Plot = new QString[VHQt_M-1];

    for (j=0;j<VHQt_M-1;j++)
    {
        for (i=0;i<VHQt_N-1;i++)
            SData[j]+=" ("+QString::number(Temp_VHQt_MatrixXY[i][0])+", "+QString::number(Temp_VHQt_MatrixXY[i][j+1])+") \n";
        SData[j]+=" ("+QString::number(Temp_VHQt_MatrixXY[VHQt_N-1][0])+", "+QString::number(Temp_VHQt_MatrixXY[VHQt_N-1][j+1])+") \n";
    }

    QString MarkSize;
    if (VHQt_N>100) MarkSize=",mark size=1.5pt";

    if ((ShowArea)&&((ShowPoints)||(ShowLine)))
    {
        //нарисуем закрашенную область
        for (j=0;j<VHQt_M-1;j++)
        {
            Plot[j]+="\\addplot[color="+ColorArea[j]+", draw=none,fill, fill opacity = "+Opacity+",forget plot] coordinates {\n";
            Plot[j]+=" ("+QString::number(MinX)+", "+QString::number(MinY)+") \n";
            Plot[j]+=SData[j];
            Plot[j]+=" ("+QString::number(MaxX)+", "+QString::number(MinY)+") \n";
            Plot[j]+="};\n\n";
        }
    }

    if ((ShowArea)&&(!ShowPoints)&&(!ShowLine))
    {
        //нарисуем закрашенную область
        for (j=0;j<VHQt_M-1;j++)
        {
            Plot[j]+="\\addplot[color="+ColorArea[j]+", draw=none,fill, fill opacity = "+Opacity+"] coordinates {\n";
            Plot[j]+=" ("+QString::number(MinX)+", "+QString::number(MinY)+") \n";
            Plot[j]+=SData[j];
            Plot[j]+=" ("+QString::number(MaxX)+", "+QString::number(MinY)+") \n";
            Plot[j]+="};\n";
            Plot[j]+="\\addlegendentry{"+NameLine[j]+"};\n\n";
        }
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график
        for (j=0;j<VHQt_M-1;j++)
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
        for (j=0;j<VHQt_M-1;j++)
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
        for (j=0;j<VHQt_M-1;j++)
        {
            Plot[j]+="\\addplot[color=plot"+QString::number(j+1)+", no markers,very thick"+TypeLine[j]+"] coordinates {\n";
            Plot[j]+=SData[j];
            Plot[j]+="};\n";
            Plot[j]+="\\addlegendentry{"+NameLine[j]+"};\n\n";
        }
    }

    //Цвета соберем
    for (j=0;j<VHQt_M-1;j++)
    {
        VHQt_Result+="\\definecolor{plot"+QString::number(j+1)+"}{HTML}{"+Color[j]+"}\n";
    }
    VHQt_Result+="\n";

    //собираем общий график
    for (j=0;j<VHQt_M-1;j++)
        VHQt_Result+=Plot[VHQt_M-1-j-1];

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
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\min_{"+LabelX+"}="+QString::number(MinX)+"; \\min_{"+LabelY+"}="+QString::number(MinY)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=south west,font=\\tiny},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="]\n";
        VHQt_Result+="coordinates {("+QString::number(MinX)+","+QString::number(MinY)+")};\n";

        //Максимальная по Y
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\max_{"+LabelY+"} = "+QString::number(MaxY)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=south west,font=\\tiny},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="] \n";
        VHQt_Result+="coordinates {("+QString::number(MinX)+","+QString::number(MaxY)+")};\n";

        //Максимальная по X
        VHQt_Result+="\\addplot [\n";
        VHQt_Result+="black,\n";
        VHQt_Result+="mark = *,\n";
        VHQt_Result+="mark options={plotcoordinate, opacity = 1, fill=white, fill opacity = 1, thin, solid,scale=0.6},\n";
        VHQt_Result+="nodes near coords={$\\max_{"+LabelX+"} = "+QString::number(MaxX)+" $},\n";
        VHQt_Result+="every node near coord/.style={black, anchor=north west,font=\\tiny, rotate=90},\n";
        VHQt_Result+="fill=white,\n";
        VHQt_Result+="forget plot\n";
        VHQt_Result+="] \n";
        VHQt_Result+="coordinates {("+QString::number(MaxX)+","+QString::number(MinY)+")};\n";
    }

    VHQt_Result+="\\end{axis}\n";
    VHQt_Result+="\\end{tikzpicture}\n";

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
            VHQt_Result+="\\caption{График}\\label{"+Label+"}\n";
        else
            VHQt_Result+="\\caption{График}\n";
    }
    if (ForNormalSize) VHQt_Result+="\\end{figure}\n";

    VHQt_Result+="}\n\n";

    delete [] SData;
    delete [] Plot;
    delete [] Color;
    delete [] ColorArea;
    delete [] TypeLine;
    delete [] FaceOfLine;

    for (i=0;i<VHQt_N;i++) delete [] Temp_VHQt_MatrixXY[i];
    delete [] Temp_VHQt_MatrixXY;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints, bool ForNormalSize)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    По сравнению с основной функцией отсутствуют параметры GrayStyle, SolidStyle, CircleStyle.
    Входные параметры:
     VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
     VHQt_N - количество точек;
     VHQt_M - количество столбцов матрицы (1+количество графиков);
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M-1 (так как первый столбец - это X значения);
     Label - label для графика;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     ForNormalSize - нормальный размер графика (на всю ширину) или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N, VHQt_M, TitleChart, NameVectorX,  NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints,  ForNormalSize,  false,  false,  false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    По сравнению с основной функцией отсутствуют параметры GrayStyle, SolidStyle, CircleStyle, ForNormalSize.
    Входные параметры:
     VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
     VHQt_N - количество точек;
     VHQt_M - количество столбцов матрицы (1+количество графиков);
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M-1 (так как первый столбец - это X значения);
     Label - label для графика;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N, VHQt_M, TitleChart, NameVectorX,  NameVectorY, NameLine, Label, ShowLine, ShowPoints, ShowArea, ShowSpecPoints,  true,  false,  false,  false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, QString Label)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    По сравнению с основной функцией отсутствуют все булевские переменные.
    Входные параметры:
     VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
     VHQt_N - количество точек;
     VHQt_M - количество столбцов матрицы (1+количество графиков);
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M-1 (так как первый столбец - это X значения);
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_LatexShowChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N, VHQt_M, TitleChart, NameVectorX,  NameVectorY, NameLine, Label, true, true, false, true,  true,  false,  false,  false);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с Latex кодами.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    По сравнению с основной функцией отсутствуют все булевские переменные и текстовые. Все устанавливается по умолчанию.
    Входные параметры:
     VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
     VHQt_N - количество точек;
     VHQt_M - количество столбцов матрицы (1+количество графиков).
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VHQt_Result;//переменная итогового результата

    QString *NameLine;

    NameLine = new QString[VHQt_M-1];

    for (int i=0;i<VHQt_M-1;i++) NameLine[i]="График "+QString::number(i+1);

    VHQt_Result = THQt_LatexShowChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N, VHQt_M, "", "x", "y", NameLine, "Chart"+HQt_RandomString(8), true, true, false, true,  true,  false,  false,  false);

    delete [] NameLine;

    return VHQt_Result;
}