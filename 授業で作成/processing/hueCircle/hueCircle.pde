size(400, 400);
background(255);
colorMode(HSB, 100);
int x = width/2, y=height/2,r=40,R=160;
for(int i = 0; i < 100; i++){
  stroke(i, 100, 100);
  line(r*cos(radians(360*i/100))+x, r*sin(radians(360*i/100))+y,
       R*cos(radians(360*i/100))+x,R*sin(radians(360*i/100))+y);
  }
