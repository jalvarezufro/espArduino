import processing.serial.*;

Serial arduino; // Create object from Serial class
Serial esp; // Create object from Serial class
String val;     // Data received from the serial port
int highest = 0;

void setup()
{
background(0,0,0);
size(400, 400);
textSize(80);
rect(120, 80, 220, 220, 28);

fill(0, 408, 612, 204);
text("Alto: ", 40, 360);
  // I know that the first port in the serial list on my mac
  // is Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
  arduino = new Serial(this, portName, 9600);
  
  portName = Serial.list()[1]; //change the 0 to a 1 or 2 etc. to match your port
  esp = new Serial(this, portName, 19200);

}

void draw()
{
  

  if ( arduino.available() > 0) 
  {  // If data is available,
  val = arduino.readStringUntil('\n');    // read it and store it in val
  if(val != null){
    int valValue = Integer.valueOf(trim(val));
    if(valValue > 400){
      esp.write(1);
    }
  println(Integer.valueOf(trim(val)));
  if(Integer.valueOf(trim(val))>highest){
    highest = Integer.valueOf(trim(val));
  }
  }
  } 
//print it out in the console
}

void mouseClicked(){
  if(overRect(120, 80, 220, 220)){
    arduino.write(0);
    fill(0, 408, 612, 204);
    text(highest, 210, 360);
    
}
}

boolean overRect(int x, int y, int width, int height)  {
  if (mouseX >= x && mouseX <= x+width && 
      mouseY >= y && mouseY <= y+height) {
    return true;
  } else {
    return false;
  }
}
