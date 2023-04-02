package model.character;

public class Player extends Character{

	private boolean[][] collisionMapData;

	public Player(Position position) {
		this(position, null);
	}

	public Player(Position position, boolean[][]collisionMapData) {
		super(position);
		this.speed = 8;
		this.looksType = 0;
		this.collisionMapData = collisionMapData;
	}

	public void setCollisionMapData(boolean[][] collisionMapData) {
		this.collisionMapData = collisionMapData;
	}

	public void setPosition(Position pos) {
		this.position = pos;
	}

	@Override
	public void move(int dx, int dy) {
		dx *= speed;
		dy *= speed;
		position.setX(position.getX()+dx);
		position.setY(position.getY()+dy);

		/*
		 * Viewの値がここに影響するのは致し方ない
		 */
		if(position.getY() < 0) {
			position.setY(0);
		}else if(16 * 40 - 48<= position.getY()) {
			position.setY(16 * 40 - 48);
		}
		if(position.getX() < 0) {
			position.setX(0);
		}else if(16 * 50 - 32 <= position.getX()) {
			position.setX(16 * 50 - 32);
		}

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

		/*
		//当たり判定
		int ddx = 0;
		int ddy = 0;
		if(collisionMapData != null) {
			if(0 < dy) {
				ddy = 48;
				ddx = 16;
				if(16 * 30 <= position.getY() + ddy) {
					position.setY(position.getY() - position.getY() % MapChipLoader.MAPCHIP_SIZE);
				}else if(collisionMapData[(position.getY()+ddy)/MapChipLoader.MAPCHIP_SIZE][(position.getX()+ddx) / MapChipLoader.MAPCHIP_SIZE]) {
					position.setY(position.getY() - position.getY() % MapChipLoader.MAPCHIP_SIZE);
				}
			}else if(0 < dx) {
				ddx = 32;
				if(16 * 50 <= position.getX() + ddx) {
					position.setX(position.getX() - position.getX() % MapChipLoader.MAPCHIP_SIZE);
				}else if(collisionMapData[(position.getY()+ddy)/MapChipLoader.MAPCHIP_SIZE][(position.getX()+ddx) / MapChipLoader.MAPCHIP_SIZE]) {
					position.setX(position.getX() - position.getX() % MapChipLoader.MAPCHIP_SIZE);
				}
			}else if(dx < 0) {
				if(position.getX() + ddx < 0) {
					position.setX(position.getX() - position.getX() % MapChipLoader.MAPCHIP_SIZE);
				}else if(collisionMapData[(position.getY()+ddy)/MapChipLoader.MAPCHIP_SIZE][(position.getX()+ddx) / MapChipLoader.MAPCHIP_SIZE]) {
					position.setX(position.getX() - position.getX() % MapChipLoader.MAPCHIP_SIZE);
				}
			}else if(dy < 0) {
				ddy = 24;
				if(position.getY() + ddy < 0) {
					position.setY(position.getY() - position.getY() % MapChipLoader.MAPCHIP_SIZE);
				}else if(collisionMapData[(position.getY()+ddy)/MapChipLoader.MAPCHIP_SIZE][(position.getX()+ddx) / MapChipLoader.MAPCHIP_SIZE]) {
					position.setY(position.getY() - position.getY() % MapChipLoader.MAPCHIP_SIZE);
				}
			}
			*/
			/*
			else if(dx < 0) {
				position.setX(position.getX() + position.getX() % MapChipLoader.MAPCHIP_SIZE);
			}else if(0 < dx) {
				position.setX(position.getX() - position.getX() % MapChipLoader.MAPCHIP_SIZE);
			}else if(dy < 0) {
				position.setY(position.getY() + position.getY() % MapChipLoader.MAPCHIP_SIZE);
			}
			*/



			/*
			if(position.getY() < 0) {
				position.setY(0);
			}else if(16 * 30 - 32<= position.getY()) {
				position.setY(16 * 30 - 32);
			}else if(position.getX() < 0) {
				position.setX(0);
			}else if(16 * 50 - 32 <= position.getX()) {
				position.setX(16 * 50 - 32);
			}else if(collisionMapData[position.getY()/MapChipLoader.MAPCHIP_SIZE][position.getX() / MapChipLoader.MAPCHIP_SIZE]) {
				System.out.println("Hit");
				if(0 < dy) {
					position.setY(position.getY() - position.getY() % MapChipLoader.MAPCHIP_SIZE);
				}else if(dx < 0) {
					position.setX(position.getX() + position.getX() % MapChipLoader.MAPCHIP_SIZE);
				}else if(0 < dx) {
					position.setX(position.getX() - position.getX() % MapChipLoader.MAPCHIP_SIZE);
				}else if(dy < 0) {
					position.setY(position.getY() + position.getY() % MapChipLoader.MAPCHIP_SIZE);
				}

			}
			*/
	/*
		}

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
	*/

}
