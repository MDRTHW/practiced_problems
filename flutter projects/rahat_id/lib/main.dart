import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(MaterialApp(
    home:rahatcard(),
  ));
}

class rahatcard extends StatefulWidget {
  const rahatcard({Key? key}) : super(key: key);

  @override
  _rahatcardState createState() => _rahatcardState();
}

class _rahatcardState extends State<rahatcard> {

  int rahatlevel = 0;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey.shade900,
      appBar: AppBar(
        title: Text("Rahat ID card"),
        backgroundColor: Colors.grey.shade800,
        centerTitle: true,
        elevation: 0.0,



      ),
      floatingActionButton: Column(
        mainAxisAlignment: MainAxisAlignment.end,
        children: [
          FloatingActionButton(
            onPressed: () {
              setState(() {
                rahatlevel +=1;
              });
            },
            child:
            Icon(Icons.add),
            backgroundColor: Colors.grey.shade800,

          ),
          SizedBox(height: 10.0,),
          FloatingActionButton(
            onPressed: () {
              setState(() {
                rahatlevel = 0;
              });
            },
            child:
            Icon(Icons.refresh),
            backgroundColor: Colors.grey.shade800,

          ),
        ],
      ),


      body: Padding(
      padding: EdgeInsets.fromLTRB(30.0, 40.0, 30.0,0.0),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Center(
            child: CircleAvatar(
              backgroundImage: AssetImage("assets/nobara.jpg"),
              radius: 50.0,
            ),
          ),
          Divider(
            height: 60.0,
            color: Colors.grey.shade800,
          ),
          Text(
               "NAME",
              style: TextStyle(
                color: Colors.grey,
                letterSpacing: 2.0
              ),
        ),
          SizedBox(height: 10.0,),
          Text(
            "RAHAT",
            style: TextStyle(
                color: Colors.amberAccent.shade200,
                letterSpacing: 2.0,
              fontSize: 28.0,
              fontWeight: FontWeight.bold,
            ),
          ),
          SizedBox(height: 30.0,),
          Text(
            "Current RAHAT level",
            style: TextStyle(
                color: Colors.grey,
                letterSpacing: 2.0
            ),
          ),
          SizedBox(height: 10.0,),
          Text(
            "$rahatlevel",
            style: TextStyle(
              color: Colors.amberAccent.shade200,
              letterSpacing: 2.0,
              fontSize: 28.0,
              fontWeight: FontWeight.bold,
            ),
          ),
          SizedBox(height: 10.0,),
          Row(
            children: [
              Icon(
                Icons.email,
                color:Colors.grey,
              ),
              SizedBox(width: 10.0,),
              Text(
                "md3rahat2cse93@gmail.com",
                 style:  TextStyle(
                   color: Colors.grey,
                   fontSize: 18.0,
                   letterSpacing: 1.0,
                 ),
              ),
            ],
          ),
        ],
      ),

      ),

    );
  }
}



