package model.character;

public class Character {
	protected Position position;
	protected int livingTime;
	protected int walkingTime;
	protected int looksType;
	protected boolean isInfected;

	protected int speed = 4;

	public Character(Position position) {
		this.position = position;
		this.livingTime = 0;
	}

	public Position getPosition() {
		return this.position;
	}

	public int getSpeed() {
		return this.speed;
	}

	public void setIsInfected(boolean isInfected) {
		this.isInfected = isInfected;
	}

	public boolean getIsInfected() {
		return this.isInfected;
	}

	/*
	 * NPCの見た目を表すTypeを返す
	 * 1～8の整数
	 */
	public int getLooksType() {
		return this.looksType;
	}

	/*
	 * キャラクターを移動させる
	 * dx: x座標の移動距離
	 * dy: y座標の移動距離
	 */
	public void move(int dx, int dy, int xLimit, int yLimit) {
		move(dx, dy);
		if(0 < dx && xLimit < position.getX()) {
			position.setX(xLimit);
		}else if(dx < 0 && position.getX() < xLimit) {
			position.setX(xLimit);
		}else if(0 < dy && yLimit < position.getY()) {
			position.setY(yLimit);
		}else if(dy < 0 && position.getY() < yLimit) {
			position.setY(yLimit);
		}
	}

	public void move(int dx, int dy) {
		dx *= speed;
		dy *= speed;
		position.setX(position.getX()+dx);
		position.setY(position.getY()+dy);
		int rotate = 0;
		if(0 < dy) {
			rotate = 0;
		}else if(dx < 0) {
			rotate = 1;
		}else if(0 < dx) {
			rotate = 2;
		}else if(dy < 0) {
			rotate = 3;
		}
		position.setRotate(rotate);
		walkingTime++;
	}

	public void update() {
		this.livingTime++;
	}

	/*  歩行グラフィックIDを取得用
	 *  1～3の値を返す。
	 */
	public int getWalkingPattern() {
		int index = walkingTime % 9;
		if(index < 3) {
			return 0;
		}else if(index < 6) {
			return 1;
		}else {
			return 2;
		}
	}
}
