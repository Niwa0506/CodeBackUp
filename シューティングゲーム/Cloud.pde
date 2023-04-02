class Cloud{
  PGraphics cl;
  int wi;
  int he;
  float ystart;
  Cloud(){
    wi = 1200;
    he = 800;
    ystart=.0;
    cl = createGraphics(wi,he,JAVA2D);
    }
    void update(){
      cl.beginDraw();
      cl.loadPixels();
     float xoff = .0;
     float increment = .02;
    for(int x = 0;x<wi;x++){
      xoff +=increment;
      float yoff = ystart;
      for(int y=0;y<he;y++){
        yoff+=increment;
        float n = noise(xoff,yoff);
        float bright = pow(n,3)*255;
        if(bright<100)cl.pixels[x+y*wi]=color(bright,0);
        else cl.pixels[x+y*wi]=color(bright);
      }
    }
    cl.updatePixels();
    cl.endDraw();
    ystart +=increment;
  }
  void show(){
    pushMatrix();
      translate(-width/2,height/2+50,0);
      rotateX(-PI/2);
      image(cl,0,0);
    popMatrix();
  }
}
