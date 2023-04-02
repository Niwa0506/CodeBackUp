void setup(){
  size(400,200);
  smooth();
  noStroke();
  fill(200,255,200);
  ellipseMode(CORNER);
  frameRate(30);
}
int d = 20, x = 0,vx= 1,y = 0, vy = 1,j=0,vj=1,c,x_z=4,y_z=4;
void draw(){
  int h = height - d,w = width - d;
  background(255);
  ellipse(x,y,d,d);
  fill(255);
  if(vx==1&&vy==-1){c=-135;}
  else if(vx==1&&vy==1){c=-45;}
  else if(vx==-1&&vy==1){c=45;}
  else if(vx==-1&&vy==-1){c=135;}
  else if(vx==0&&vy==1){c=0;}
  else if(vx==0&&vy==-1){c=180;}
  else if(vx==1&&vy==0){c=-90;}
  else{c=90;}
  arc(x,y,d,d,radians(70-j*5+c),radians(j*5+110+c));
  fill(200,255,200);
  if((x>=w||x<0)&&(y<0||y>=h)){
     vx = -1*vx;vy = -1*vy;
  }else{
    if(x>=w||x<0){vx = -1*vx;vy=int(random(3))-1;}
    if(y>=h||y<0){vy = -1*vy;vx=int(random(3))-1;}
  }
  if(j>=10||j<0)vj=vj*-1;
  x += vx;y += vy;j+=vj;
}
