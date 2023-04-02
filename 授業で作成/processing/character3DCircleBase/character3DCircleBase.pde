void setup(){
  size(400, 300, P3D);
  smooth();
  frameRate(30);
  textFont(createFont("Tempus Sans ITC", 24));
}
void draw(){
   background(255);
   pushMatrix();
   translate(200, 150, -50);
   rotateX(map(mouseY, 0, height, PI, -PI));
   rotateY(map(mouseX, 0, width, -PI, PI));
   fill(0, 0, 0, 255);
   String s ="Visual Computing";
   float r = 2 * textWidth(s) / PI, theta = PI / s.length();
   for(int i = 0; i < s.length(); i++){
     pushMatrix();
       translate(-r * cos(theta * i), -r * sin(theta * i), 0);
       rotateZ(theta * i - PI / 2);
       text(s.charAt(i), 0, 0, 0);
     popMatrix();
   }
   popMatrix();
}
