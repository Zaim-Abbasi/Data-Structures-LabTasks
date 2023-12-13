#Persistent
SetTitleMatchMode, 2

FileRead, FileContent, main.cpp
FileLines := StrSplit(FileContent, "`n")

OutputDirectory := "output" ; Set the output directory for header and source files

Loop, % FileLines.Length()
{
    Line := FileLines[A_Index]
    ; Check if the line contains a class definition
    if (RegExMatch(Line, "class\s+(\w+)"))
    {
        ClassName := RegExReplace(Line, "class\s+(\w+)", "$1")
        ; Create a header file for the class
        ClassHeader := OutputDirectory "\" ClassName ".h"
        FileAppend, "#pragma once`n`n", ClassHeader
        FileAppend, "class " ClassName "`n{`npublic:`n};`n", ClassHeader
        ; Create a source file for the class
        ClassSource := OutputDirectory "\" ClassName ".cpp"
        FileAppend, "#include """ ClassName ".h""`n`n", ClassSource
    }
    ; Append the line to the corresponding source file
    FileAppend, Line "`n", ClassSource
}

; Create a main.cpp file with includes and the main function
MainHeader := OutputDirectory "\main.h"
FileAppend, "#pragma once`n`n", MainHeader
FileAppend, "#include <iostream>`n", MainHeader
FileAppend, "#include """ main.cpp """`n", MainHeader
FileAppend, "int main() {`n", MainHeader
FileAppend, FileContent, MainHeader
FileAppend, "`nreturn 0;`n}", MainHeader

; Display a message when done
MsgBox, Code refactoring complete!
