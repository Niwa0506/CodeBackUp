void drawFuncs(int unit){
  float t = -100,step = .1;
  float x1,y1,x2,y2,a = 1;
  x2 = xInWindow(xFunc(a,t),unit);
  y2 = yInWindow(yFunc(a,t),unit);
  while(t < 100){
    x1 = x2;y1 = y2;
    x2 = xInWindow(xFunc(a,t),unit);
    y2 = yInWindow(yFunc(a,t),unit);
    t+=step;
    line(x1,y1,x2,y2);
  }
}
