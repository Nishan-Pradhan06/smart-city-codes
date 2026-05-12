import 'package:flutter/material.dart';

class TrafficLightScreen extends StatelessWidget {
  const TrafficLightScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: const Color(0xff06111F),
      body: SafeArea(
        child: Stack(
          children: [
            /// ROAD BACKGROUND
            Center(
              child: Container(
                width: double.infinity,
                height: double.infinity,
                color: const Color(0xff081522),
              ),
            ),

            /// VERTICAL ROAD
            Center(
              child: Container(
                width: 150,
                height: double.infinity,
                color: const Color(0xff101C2C),
              ),
            ),

            /// HORIZONTAL ROAD
            Center(
              child: Container(
                width: double.infinity,
                height: 150,
                color: const Color(0xff101C2C),
              ),
            ),

            /// CENTER DIVIDER VERTICAL
            Center(
              child: Column(
                children: List.generate(
                  20,
                  (index) => Expanded(
                    child: Container(
                      width: 4,
                      margin: const EdgeInsets.symmetric(vertical: 6),
                      color: Colors.amber,
                    ),
                  ),
                ),
              ),
            ),

            /// CENTER DIVIDER HORIZONTAL
            Center(
              child: Row(
                children: List.generate(
                  20,
                  (index) => Expanded(
                    child: Container(
                      height: 4,
                      margin: const EdgeInsets.symmetric(horizontal: 6),
                      color: Colors.amber,
                    ),
                  ),
                ),
              ),
            ),

            /// TRAFFIC LIGHTS
            trafficLight(top: 160, left: 55, isGreen: false),
            trafficLight(top: 160, right: 55, isGreen: true),
            trafficLight(bottom: 160, left: 55, isGreen: true),
            trafficLight(bottom: 160, right: 55, isGreen: false),
          ],
        ),
      ),

      /// BOTTOM NAVIGATION
      bottomNavigationBar: BottomNavigationBar(
        backgroundColor: const Color(0xff09131F),
        selectedItemColor: Colors.cyanAccent,
        unselectedItemColor: Colors.white54,
        type: BottomNavigationBarType.fixed,
        items: const [
          BottomNavigationBarItem(icon: Icon(Icons.home), label: "Home"),
          BottomNavigationBarItem(icon: Icon(Icons.traffic), label: "Traffic"),
          BottomNavigationBarItem(
            icon: Icon(Icons.directions_car),
            label: "Vehicles",
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.bar_chart),
            label: "Analytics",
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.settings),
            label: "Settings",
          ),
        ],
      ),
    );
  }

  Widget buildVehicle({
    required double top,
    required double left,
    required Color color,
    required String speed,
    IconData? icon,
  }) {
    return Positioned(
      top: top,
      left: left,
      child: Column(
        children: [
          speedTag(speed),
          const SizedBox(height: 5),
          Container(
            width: 26,
            height: 45,
            decoration: BoxDecoration(
              color: color,
              borderRadius: BorderRadius.circular(8),
              boxShadow: [
                BoxShadow(color: color.withOpacity(0.8), blurRadius: 12),
              ],
            ),
            child: icon != null ? Icon(icon, color: Colors.red) : null,
          ),
        ],
      ),
    );
  }

  Widget speedTag(String text) {
    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 3),
      decoration: BoxDecoration(
        borderRadius: BorderRadius.circular(6),
        color: Colors.black,
        border: Border.all(color: Colors.cyanAccent),
      ),
      child: Text(
        text,
        style: const TextStyle(
          color: Colors.cyanAccent,
          fontSize: 10,
          fontWeight: FontWeight.bold,
        ),
      ),
    );
  }

  Widget neonCard(String title, Color color) {
    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 12),
      decoration: BoxDecoration(
        borderRadius: BorderRadius.circular(14),
        border: Border.all(color: color),
        color: color.withOpacity(0.08),
        boxShadow: [BoxShadow(color: color.withOpacity(0.4), blurRadius: 12)],
      ),
      child: Text(
        title,
        style: TextStyle(
          color: color,
          fontWeight: FontWeight.bold,
          letterSpacing: 1.2,
        ),
      ),
    );
  }

  Widget trafficLight({
    double? top,
    double? bottom,
    double? left,
    double? right,
    required bool isGreen,
  }) {
    return Positioned(
      top: top,
      bottom: bottom,
      left: left,
      right: right,
      child: Column(
        children: [
          Container(
            width: 28,
            height: 80,
            decoration: BoxDecoration(
              color: const Color(0xff0E1726),
              borderRadius: BorderRadius.circular(14),
              border: Border.all(color: Colors.cyanAccent),
            ),
            child: Column(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                circleLight(isGreen ? Colors.black : Colors.redAccent),
                circleLight(Colors.black),
                circleLight(isGreen ? Colors.greenAccent : Colors.black),
              ],
            ),
          ),
          const SizedBox(height: 6),
          speedTag(isGreen ? "18s" : "21s"),
        ],
      ),
    );
  }

  Widget circleLight(Color color) {
    return Container(
      width: 14,
      height: 14,
      decoration: BoxDecoration(
        color: color,
        shape: BoxShape.circle,
        boxShadow: [BoxShadow(color: color.withOpacity(0.8), blurRadius: 10)],
      ),
    );
  }
}
