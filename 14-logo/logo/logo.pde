import processing.serial.*;
Serial myPort;

PImage logo;

int bgcolor = 0;
String imageURL = "full_2024_logo.png"; // Ensure the image is available locally

void settings() {
    logo = loadImage(imageURL);
    if (logo != null) {
        size(logo.width, logo.height);
    } else {
        println("Image could not be loaded, setting default size.");
        size(200, 200); // Default size if the image fails to load
    }
}

void setup() {
    colorMode(HSB, 255);
    
    if (logo == null) {
        println("Failed to load image!");
        return; // Exit setup if image loading fails
    }

    // Initialize serial communication
    String[] ports = Serial.list();
    if (ports.length > 0) {
        myPort = new Serial(this, ports[0], 9600);
    } else {
        println("No serial ports available!");
        return; // Exit setup if no ports are available
    }
}

void draw() {
    if (myPort != null && myPort.available() > 0) {
        bgcolor = myPort.read();
        println(bgcolor);
    }
    background(bgcolor, 255, 255);
    image(logo, 0, 0);
}
