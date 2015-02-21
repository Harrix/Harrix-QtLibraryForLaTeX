QString HQt_LatexBeginArticleWithPgfplots()
{
    /*
     Возвращает начало для полноценного Latex файла в виде статьи для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate
     с использованием графиков через пакет pgfplots.
     */
    QString VHQt_Result;
    VHQt_Result+="\\documentclass[a4paper,12pt]{article}\n\n";
    VHQt_Result+="\\input{packages} %Подключаем модуль пакетов\n";
    VHQt_Result+="\\input{styles} %Подключаем модуль стилей\n\n";
    VHQt_Result+="\\usepgfplotslibrary{external}\n";
    VHQt_Result+="\\tikzexternalize[prefix=TikzPictures/]\n\n";
    VHQt_Result+="\\begin{document}\n\n";
    VHQt_Result+="\\input{names} %Подключаем модуль переименования некоторых команд\n\n";

    return VHQt_Result;
}