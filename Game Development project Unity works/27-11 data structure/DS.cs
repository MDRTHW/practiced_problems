using System;
using System.Collections.Generic;
class Hello
{
    public int result=1;
    public int CallByValue(ref int val)
    {
        if (val==0)
            return 0;
        else if(val==1)
            return 1;
        else
            for(int i=val;i>0;i--)
              result=result*i;
        Console.WriteLine("From inside function: "+result);
        return result;
    }

    public static void Main()
    {
        var names=new LinkedList<string>();
        
        names.AddFirst("Md");
        names.AddLast("Rahat");
        names.AddAfter(names.Find("Md"),"Raiyan");

        foreach (var item in names)
        {
            Console.WriteLine(item);
        }
    }

}