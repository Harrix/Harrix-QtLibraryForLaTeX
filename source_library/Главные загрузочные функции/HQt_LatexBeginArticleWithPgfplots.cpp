QString HQt_LatexBeginArticleWithPgfplots()
{
    /*
     Возвращает начало для полноценного Latex файла в виде статьи для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate
     с использованием графиков через пакет pgfplots.
     */
    QString VMHL_Result;
    VMHL_Result+="\\documentclass[a4paper,12pt]{article}\n\n";
    VMHL_Result+="\\input{packages} %Подключаем модуль пакетов\n";
    VMHL_Result+="\\input{styles} %Подключаем модуль стилей\n\n";
    VMHL_Result+="\\usepgfplotslibrary{external}\n";
    VMHL_Result+="\\tikzexternalize[prefix=TikzPictures/]\n\n";
    VMHL_Result+="\\begin{document}\n\n";
    VMHL_Result+="\\input{names} %Подключаем модуль переименования некоторых команд\n\n";

    return VMHL_Result;
}