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