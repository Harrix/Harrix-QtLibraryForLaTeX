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