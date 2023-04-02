size(270,180);
background(218,37,29);
fill(255,255,0);
noStroke();
 beginShape();
for(int i=0;i<5;i++){
 int R=3*height/10;
 vertex(R*cos(radians(144*i-90))+135,R*sin(radians(144*i-90))+90);
}
 endShape(CLOSE);
