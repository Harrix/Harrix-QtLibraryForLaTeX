//HarrixQtLibraryForLaTeX
//Версия 1.4
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
    Функция возвращает строку с выводом некоторой строки с Latex кодами. Для добавление в Latex файл.
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
    Функция возвращает строку с выводом некоторой строки с Latex кодами без всякого излишевства. Для добавление в Latex файл.
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
    Функция возвращает строку с выводом горизонтальной линии. Для добавление в Latex файл.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Строка с Latex кодами с тэгом горизонтмальной линии.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\hrulefill\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexShowSection (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки в виде заголовка. Для добавление в Latex файл.
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
    Функция возвращает строку с выводом некоторой строки в виде подзаголовка. Для добавление в Latex файл.
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
    Функция возвращает строку с выводом некоторого предупреждения. Для добавление в Latex файл.
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
