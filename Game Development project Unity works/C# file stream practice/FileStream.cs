using System.IO;
using System;
namespace HelloWorld
{
    class FileStream {         
        static void Main()
        {
            string writeText="This is a file";
            File.WriteAllText("file1.txt",writeText);

            string readText=File.ReadAllText("file1.txt");
            Console.WriteLine(readText);
        }
    }
}