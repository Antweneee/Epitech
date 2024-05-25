import 'dart:ui';

import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:url_launcher/url_launcher.dart';

import '../../pages/reaction_page.dart';

final Uri _url = Uri.parse('https://flutter.dev');
class CardStaivePlus extends StatelessWidget {
  const CardStaivePlus({
    Key? key,
    required this.email,
    required this.text,
    required this.price,
    required this.shadowColor,
    required this.textColor,
  }) : super(key: key);

  final String email;
  final String text;
  final String price;
  final Color shadowColor;
  final Color textColor;

  @override
  Widget build(BuildContext context) {
    double w = MediaQuery.of(context).size.width;
    double h = MediaQuery.of(context).size.height;
    var supportingText =
       'Beautiful home to rent, recently refurbished with modern appliances...';
    return Padding(
      padding: const EdgeInsets.only(
        bottom: 13,
        left: 10,
        right: 10  
      ),
      child: Card(
        color: shadowColor,
        shadowColor: shadowColor,
        elevation: 25,
        clipBehavior: Clip.antiAlias,
        shape: RoundedRectangleBorder(
          borderRadius: BorderRadius.circular(24),
        ),
        child: Column(
          children: [
            Padding(
              padding: const EdgeInsets.only(top: 10.0, left: 10),
              child: ListTile(
                title: Text(
                  text,
                  style: TextStyle(
                    color: textColor,
                    fontSize: 30,
                    fontWeight: FontWeight.bold
                  ),
                ),
                subtitle: Text(
                  price,
                  style: TextStyle(
                    color: textColor,
                  ),  
                ),
              ),
            ),
            Container(
              height: h * 0.10, 
              color: shadowColor,
              child: Ink.image(
                image: const AssetImage(
                  ""
                ),
                fit: BoxFit.cover,
              ),
            ),
            Container(
              padding: EdgeInsets.all(16.0),
              alignment: Alignment.centerLeft,
              child: Text(
                supportingText,
                style: TextStyle(
                  color: textColor,
                ),
              ),
            ),
            Padding(
              padding: const EdgeInsets.only(bottom: 12.0),
              child: ElevatedButton(
                onPressed: () {},
                style: ElevatedButton.styleFrom(
                  fixedSize: const Size(150, 50),
                  textStyle: const TextStyle(
                    fontSize: 15,
                    fontWeight: FontWeight.bold
                  ),
                  backgroundColor: const Color.fromARGB(255, 250, 250, 250),
                  foregroundColor: Colors.black87,
                  elevation: 15,
                  shadowColor: shadowColor,
                  shape: const StadiumBorder()
                ),
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: const [
                    Text("Lesgooo"),
                    Icon(Icons.add_shopping_cart),
                  ],
                ),
              ),
            )
         ],
       )
       /*
        child: Stack(
          alignment: Alignment.center,
          children: [
            Ink.image(
              image: const AssetImage(
                ""
              ),
              height: h * 0.3,
              fit: BoxFit.cover,
              child: InkWell(
                onTap: () {
                }
              ),
            ),
            BackdropFilter(
              filter: ImageFilter.blur(sigmaX: 10, sigmaY: 10),
              child: Container(
                alignment: Alignment.center,
                child: Padding(
                  padding: const EdgeInsets.only(left: 10, right: 10),
                  child: Text(
                    text,
                    textAlign: TextAlign.center,
                    style: TextStyle(
                      fontWeight: FontWeight.bold,
                      color: textColor,
                      fontSize: 22,
                    ),
                  ),
                ),
              ),
            ),
            
          ],
        )*/
      ),
    );
  }
  Future<void> _launchUrl() async {
    if (!await launchUrl(_url)) {
      throw 'Could not launch $_url';
    }
  }
}