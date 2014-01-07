//HarrixQtLibraryForLaTeX
//Версия 1.6
//Библиотека для отображения различных данных в LaTeX файлах.
//https://github.com/Harrix/HarrixQtLibraryForLaTeX
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include "HarrixQtLibraryForLaTeX.h"

QString HQt_LatexBegin()
{
    /*
     Возвращает начало для полноценного Latex файла для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate.
     */
    QString VMHL_Result;
    VMHL_Result+="\\documentclass[a4paper,12pt]{report}\n\n";
    VMHL_Result+="\\input{packages} %Подключаем модуль пакетов\n";
    VMHL_Result+="\\input{styles} %Подключаем модуль стилей\n\n";
    VMHL_Result+="\\begin{document}\n\n";
    VMHL_Result+="\\input{names} %Подключаем модуль переименования некоторых команд\n\n";

    return VMHL_Result;
}
//--------------------------------------------------------------------------

QString HQt_LatexEnd()
{
    /*
     Возвращает концовку для полноценного Latex файла для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate.
     */
    return "\n\n\\end{document}";
}
//--------------------------------------------------------------------------

QString HQt_LatexShowText (QString TitleX)
{
    /*
    Функция возвращает строку с выводом некоторой строки с Latex кодами.
    Входные параметры:
     TitleX - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой (в виде абзаца).
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\textbf{"+TitleX+".}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexShowSimpleText (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки с Latex кодами без всякого излишества.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n"+String+"\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexShowHr ()
{
    /*
    Функция возвращает строку с выводом горизонтальной линии.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Строка с Latex кодами с тэгом горизонтальной линии.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\hrulefill\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexShowSection (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки в виде заголовка.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\section{"+String+"}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexShowSubsection (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки в виде подзаголовка.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\subsection{"+String+"}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexShowAlert (QString String)
{
    /*
    Функция возвращает строку с выводом некоторого предупреждения.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым предупреждением.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\textcolor{red}{\\textbf{"+String+"}}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexBeginCompositionFigure ()
{
    /*
    Функция возвращает строку с выводом начала рисунка, состоящего из нескольких рисунков или графиков.
    Входные параметры:
     Отстуствтует.
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

    VMHL_Result="\n\\begin{figure}[H]\n\\centering\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------

QString HQt_LatexBeginFigureInCompositionFigure ()
{
    /*
    Функция возвращает строку с Latex кодом при добавлении дополнительного рисунка или графика в рисунок, состоящего из нескольких рисунков.
    Входные параметры:
     Отстуствтует.
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

    VMHL_Result="\\begin{subfigure}[t]{0.48\\textwidth}\n\\centering\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexEndFigureInCompositionFigure ()
{
    /*
    Функция возвращает строку с Latex кодом после добавлении дополнительного рисунка или графика в рисунок, состоящего из нескольких рисунков.
    Входные параметры:
     Отстуствтует.
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

    VMHL_Result="\n\\end{subfigure}\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
