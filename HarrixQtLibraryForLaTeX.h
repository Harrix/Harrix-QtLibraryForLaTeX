#ifndef HARRIXQTLIBRARYFORLATEX_H
#define HARRIXQTLIBRARYFORLATEX_H

#include "HarrixQtLibrary.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

QString HQt_LatexBegin();//Возвращает начало для полноценного Latex файла.
QString HQt_LatexEnd();//Возвращает концовку для полноценного Latex файла.

QString HQt_LatexShowText (QString TitleX);//Функция возвращает строку с выводом некоторой строки с Latex кодами. Для добавление в Latex файл.
QString HQt_LatexShowSimpleText (QString String);//Функция возвращает строку с выводом некоторой строки с Latex кодами без всякого излишевства. Для добавление в Latex файл.
QString HQt_LatexShowHr ();//Функция возвращает строку с выводом горизонтальной линии. Для добавление в Latex файл.
QString HQt_LatexShowSection (QString String);//Функция возвращает строку с выводом некоторой строки в виде заголовка. Для добавление в Latex файл.
QString HQt_LatexShowSubsection (QString String);//Функция возвращает строку с выводом некоторой строки в виде подзаголовка. Для добавление в Latex файл.
QString HQt_LatexShowAlert (QString String);//Функция возвращает строку с выводом некоторого предупреждения. Для добавление в Latex файл.
template <class T> QString THQt_LatexShowNumber (T VMHL_X, QString TitleX, QString NameX);//Функция возвращает строку с выводом некоторого числа VMHL_X с Latex кодами. Для добавление в Latex файл.
template <class T> QString THQt_LatexShowNumber (T VMHL_X, QString NameX);//Функция возвращает строку с выводом некоторого числа VMHL_X с Latex кодами. Для добавление в Latex файл.
template <class T> QString THQt_LatexShowNumber (T VMHL_X);//Функция возвращает строку с выводом некоторого числа VMHL_X с Latex кодами. Для добавление в Latex файл.

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// РЕАЛИЗАЦИЯ ШАБЛОНОВ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
template <class T> QString THQt_LatexShowNumber (T VMHL_X, QString TitleX, QString NameX)
{
    /*
    Функция возвращает строку с выводом некоторого числа VMHL_X с Latex кодами. Для добавление в Latex файл.
    Входные параметры:
     VMHL_X - выводимое число;
     TitleX - заголовок выводимого числа;
     NameX - обозначение числа.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым числом.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n"+TitleX+":\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+=NameX+" = " + QString::number(VMHL_X) + ".\n";
    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowNumber (T VMHL_X, QString NameX)
{
    /*
    Функция возвращает строку с выводом некоторого числа VMHL_X с Latex кодами. Для добавление в Latex файл.
    Входные параметры:
     VMHL_X - выводимое число;
     NameX - обозначение числа.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым числом.
    */
    QString VMHL_Result;

    VMHL_Result+="\n\n\\begin{equation}\n";
    VMHL_Result+=NameX+" = " + QString::number(VMHL_X) + ".\n";
    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_LatexShowNumber (T VMHL_X)
{
    /*
    Функция возвращает строку с выводом некоторого числа VMHL_X с Latex кодами. Для добавление в Latex файл.
    Входные параметры:
     VMHL_X - выводимое число.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым числом.
    */
    QString VMHL_Result;

    VMHL_Result+="\n\n\\begin{equation}\n";
    VMHL_Result+="x = " + QString::number(VMHL_X) + ".\n";
    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

#endif // HARRIXQTLIBRARYFORLATEX_H
