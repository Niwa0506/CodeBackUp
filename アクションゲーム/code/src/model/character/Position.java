package model.character;

public class Position {
	public static final int ROTATE_NORTH = 0;
	public static final int ROTATE_EAST = 1;
	public static final int ROTATE_SOUTH = 2;
	public static final int ROTATE_WEST = 3;

	private int x;
	private int y;
	private int rotate;

	public Position(int x, int y, int rotate) {
		this.x = x;
		this.y = y;
		this.rotate = rotate;
	}

	public Position(int x, int y) {
		this(x, y, 0);
	}

	public Position() {
		this(0, 0);
	}

	public int getX() {
		return this.x;
	}

	public int getY() {
		return this.y;
	}

	public void setX(int x) {
		this.x = x;
	}

	public void setY(int y) {
		this.y = y;
	}

	public int getRotate() {
		return this.rotate;
	}

	public void setRotate(int rotate) {
		this.rotate = rotate;
	}
}
