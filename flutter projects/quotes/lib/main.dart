
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/painting.dart';
import 'quotes.dart';

void main() {
  runApp(MaterialApp(
    home: QuoteList(),
  ));
}

class QuoteList extends StatefulWidget {
  const QuoteList({Key? key}) : super(key: key);

  @override
  _QuoteListState createState() => _QuoteListState();
}

class _QuoteListState extends State<QuoteList> {

  int i=0;
  void check_i(){
    if(this.i>17)
      this.i = 0;
  }
  List<Quote> quotes = [
    Quote(text:"Positive thinking will let you use the ability which you have, and that is awesome. ",author:" Zig Ziglar"),
    Quote(text:"I am thankful for all of those who said NO to me. It’s because of them I’m doing it myself.",author:"Albert Einstein"),
    Quote(text:"Leave the fireworks for those who cast no spark of their own.",author:"Karen Abbott "),
    Quote(text:"Enthusiasm is a kind of faith that has been set on fire.",author:"George Matthew Adams"),
    Quote(text:"Love the life you live. Live the life you love.",author:"Bob Marley"),
    Quote(text:"If you want to be average, do what others do. If you want to be awesome, do what no one does.",author:"Alexander Den Heijer"),
    Quote(text:"The best thing about being who you really are is that you simply cannot fail! Be you, be awesome and live awesomely. ",author:"Ricardo Housham"),
    Quote(text:"Flaws are awesome – so, ‘flawsome!’ I love making up a word.",author:"Tyra Banks"),
    Quote(text:"Beliefs have the power to create and the power to destroy. Human beings have the awesome ability to take any experience of their lives and create a meaning that disempowers them or one that can literally save their lives.",author:"Tony Robbins"),
    Quote(text:"I’m a person who gets better with practice. Getting older is awesome – because you get more practice. ",author:"Zooey Deschanel"),
    Quote(text:"Be awesome! Smile like a flower. ",author:"Debasish Mridha M.D."),
    Quote(text:"I woke up and realized life is great and people are awesome and life is worth living. ",author:" Hulk Hogan"),
    Quote(text:"People always tell you, ‘Be humble. Be humble.’ When was the last time someone told you to be amazing? Be great! Be great! Be awesome! Be awesome! ",author:"Kanye West"),
    Quote(text:"I adore your anger and resentments; with such beauty, everything you do looks awesome.",author:"M.F. Moonzajer"),
    Quote(text:"You are people with a present and with a future. Don’t muff the ball. Be excellent. ",author:"Gordon B. Hinckley"),
    Quote(text:"Every villain is a hero in his own mind.",author:"Tom Hiddleston"),
    Quote(text:"Yelling doesn't get your point across, it only makes it louder.",author:"Grant Hill"),
    Quote(text:"No more quotes for you",author:"Return"),
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey.shade900,
      appBar: AppBar(
        title: Text("Awesome Quotes"),
        centerTitle: true,
        backgroundColor: Colors.grey.shade700,
      ),
      floatingActionButton: Column(
        mainAxisAlignment: MainAxisAlignment.end,
        children: [
          FloatingActionButton(
            onPressed: (){
              setState(() {
                print("$i");
                i +=1;
                check_i();
              });
            },
            child:
            Icon(Icons.navigate_next),
            backgroundColor: Colors.amber.shade600,

          ),
          SizedBox(height: 10.0,),
          FloatingActionButton(onPressed: (){
            setState(() {
              i=0;
            });
          },
            child:
            Icon(Icons.refresh),
            backgroundColor: Colors.amber.shade600,
          ),
        ],
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children:[
            Text("${quotes[i].text}",
              style:TextStyle(
                fontSize: 30.0,
                letterSpacing: 1.0,
                fontFamily: "IndieFlower",
                color: Colors.amber,
              ),
            ),
            SizedBox(height: 10.0,),
            Text("---${quotes[i].author}",
              style:TextStyle(
                fontSize: 20.0,
                letterSpacing: 1.0,
                fontFamily: "IndieFlower",
                color: Colors.white,
              ),
            ),

          ],
        ),
      ),

    );
  }
}

