using System.IO;
using System;
using System.Text;

namespace HelloWorld
{
    public class one {         
        public static void Main()
        {
           FileStream  f= new FileStream("maruf.txt",FileMode.OpenOrCreate);
           StreamWriter s=new StreamWriter(f);

           s.WriteLine("Marubbai jindabad");
           f.WriteByte(65);
           
           s.Close();
           f.Close();
           

        }
    }
}