class Sprite {
  float x, y, w, speed;
  int len, index;
  ArrayList<PImage> animation;
  Sprite(ArrayList<PImage> animation_, float x_, float y_, float speed_) {
    x = x_;
    y = y_;
    animation = animation_;
    w = animation.get(0).width;
    len = animation.size();
    speed = speed_;
    index = 0;
  }

  void show() {
    int index = floor(this.index) % len;
    image(animation.get(index), x, y);
  }

  void animate() {
    index += speed;
    x += speed * 15;

    if (x > width) {
      x = -w;
    }
  }
}
