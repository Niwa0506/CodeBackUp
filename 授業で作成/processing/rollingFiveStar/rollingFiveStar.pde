void setup(){
  size(400,200);
  smooth();
  noStroke();
  fill(200,255,200);
  frameRate(30);
}
int d = 20,x = d,vx = 1,y=d,vy = 1,r,R=20,j=1;
void draw(){
  int w = width-d,h = height-d;
  background(255);
  beginShape();
    for(int i=0;i<12;i++){
      if(r%2==0)r=R;
      else r=R/2;
      vertex(r*cos(radians(i*144-(90+j)))+x,r*sin(radians(i*144-(90+j)))+y); 
    }
  endShape(CLOSE);
  if(x>=w||x<20){vx = -1*vx;}
  if(y>=h||y<20){vy = -1*vy;}
  x += vx;y += vy;j+=10;
}
