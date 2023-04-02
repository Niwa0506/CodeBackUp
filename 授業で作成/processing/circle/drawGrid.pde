float xInWindow(float x,int unit){return(x * unit + width / 2); }//xinWindow
float yInWindow(float y,int unit){return(- y * unit + height / 2); }//yinWindow
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
