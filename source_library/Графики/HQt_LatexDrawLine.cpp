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