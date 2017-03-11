#include "Libraries/shared.h"
#include "Compiler/parsing.h"
#include "Structures/tokenType.h"
#include "Structures/Error.h"
#include "Structures/File.h"
#include "Structures/ASTNode.h"
#include "Structures/ASTTree.h"
#include "Structures/Compiler.h"
std::string startupMessage = "Welcome to B++ v0.2.\nPlease enter the name of a file to open:\n";

void startProcess(File *readfile,File *writefile)
{
preParseContents(readfile);
ASTTree bt = assembleTree(readfile);
/*
bt->validateTree();
std::cout << bt->dumpLog() << std::endl;
*/
std::cout<<"Everything working"<<std::endl;
bt.getRoot()->assemble();
std::cout << bt.getRoot()->getResult() << std::endl;
}

int main(int argc,char** argv)
{
    std::cout << startupMessage;
    /*
    Compiler c(argc,argv);
    c.prepare()
    c.lex();
    c.finish();
    */
    Compiler c(argc,argv);
    c.run();
    std::string fileToOpen;
    std::cin >> fileToOpen;
    File sourceFile;
    sourceFile.read(fileToOpen);
    std::string fileToWrite;
    std::cout << "Enter the output filename:\n";
    std::cin >> fileToWrite;
    File compileFile;
    //compileFile.read(fileToWrite);
    startProcess(&sourceFile,&compileFile);
    /*
    if(errorOnCompiling.errorExists())
    {
        std::cout << "==========Error occured while compiling:=============\n" << errorOnCompiling.getMessage() <<'\n';
        return 0;
    }
    */
    std::cout << "Compilation sucessful!" + fileToWrite + '\n';
    return 0;
}
