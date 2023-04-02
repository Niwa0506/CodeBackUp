void setup(){
  size(600,600);
  background(255);
  textFont(createFont("Tempus Sans ITC", 18));
  textAlign(CENTER);
  fill(0);
  smooth();
  drawFuncs(drawGrid(10));
}
//drawFuncs.pde
void drawFuncs(int unit){
  float theta = .0,step = .001;
  float x1,y1,x2,y2,a =5,b = 6;
  x2 = xInWindow(xFunc(a,theta,0),unit);
  y2 = yInWindow(yFunc(b,theta),unit);
  while(theta <TWO_PI){
    x1 = x2;y1 = y2;
    theta+=step;
    x2 = xInWindow(xFunc(a,theta,0),unit);
    y2 = yInWindow(yFunc(b,theta),unit);
    line(x1,y1,x2,y2);
  }
}
//drawGrid.pde
float yInWindow(float x,int unit){return(x * unit + width / 2); }//xinWindow
float xInWindow(float y,int unit){return(- y * unit + height / 2); }//yinWindow
int drawGrid(int maxVal){//drawgrids
  int unitPixels = width / maxVal / 2;//gridinterval(pixels/unit)
  int xc = width / 2, yc = height / 2;
  stroke(144, 238, 144);
  for(int i = 1 - maxVal; i < maxVal; i++){
    line(0, unitPixels * i + xc, width, unitPixels * i + yc);//horizontalgrid
    line(unitPixels * i + xc, 0, unitPixels * i + yc, height);//verticalgrid
    if(i != 0){text(i, unitPixels * i + xc, yc + 18);//x-coordinatevalues
    text(i, xc - 14, unitPixels * i + yc + 5);//y-coordinatevalues
    }
  }
  stroke(0);
  text("O", xc - 14, yc + 18);//Origin(atthecenteroftheWindow)
  line(0, yc, width, yc);//x-axis
  line(xc, 0, xc, height);//y-axis2122
  return unitPixels;
}
//funcDef.pde
float A=10,B=10;
float xFunc(float t,float b,float c){return B*sin(b*t+c);}
float yFunc(float a,float t){return A*cos(a*t);}
