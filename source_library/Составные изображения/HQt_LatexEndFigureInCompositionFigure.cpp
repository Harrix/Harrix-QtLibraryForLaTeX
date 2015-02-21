QString HQt_LatexEndFigureInCompositionFigure ()
{
    /*
    Функция возвращает строку с Latex кодом после добавлении дополнительного рисунка или графика в рисунок, состоящего из нескольких рисунков.
    Входные параметры:
     Отсутствует.
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
    QString VHQt_Result;

    VHQt_Result="\n\\end{subfigure}\n";

    return VHQt_Result;
}