import 'package:flutter/material.dart';
import 'quote.dart';

void main() => runApp(MaterialApp(
  home: QuoteList(),
));

class QuoteList extends StatefulWidget {
  const QuoteList({Key? key}) : super(key: key);

  @override
  _QuoteListState createState() => _QuoteListState();
}

class _QuoteListState extends State<QuoteList> {

  List<Quote> quotes = [
    Quote(author:"THW",text:"Bye bye tata khatam"),
    Quote(author:"Nahid takku",text:"Miss me"),
    Quote(author:"English",text:"See you not for mind")
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey.shade200,
      appBar: AppBar(
        title: Text("Awesome quotes"),
        centerTitle: true,
        backgroundColor: Colors.deepPurple.shade400,
      ),
    body: Column(
      children: quotes.map((quote){
        return Text("${quote.text} - ${quote.author}");
      }).toList(),

    ),

    );
  }
}
