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
