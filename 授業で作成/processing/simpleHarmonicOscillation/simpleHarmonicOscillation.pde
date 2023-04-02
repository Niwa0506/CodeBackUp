int t = 0, R = 90, T = 120,w,sum=0;
float OMEGA = TWO_PI /T;
String s = "Welcome to Media Programming Class!!";
void setup(){
  size(600,400);
  textFont(createFont("Tempus Sans ITC",18));
  textAlign(CENTER);
  textSize(30);
  frameRate(30);
}

void drawSimpleHarmonicOscillation(int cx,int cy){
  sum = 0;
  
  noStroke();
  fill(255, 0, 0);
  for(int i=0;i<s.length();i++){
    w = int(textWidth(s.substring(i,i+1)));
    sum+=w;
    pushMatrix();
    translate(cx+sum-w/2,cy+R*sin(-OMEGA*(t+(s.length()-i)*5)));
    text(s.substring(i,i+1),10,10);
    popMatrix();
  }
}

void draw(){
  background(255);
  drawSimpleHarmonicOscillation(width / 100, height / 2);
  t++;
}
