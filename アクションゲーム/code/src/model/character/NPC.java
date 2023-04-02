package model.character;

import java.util.Random;

public class NPC extends Character{

	public static final int INFECTED_LOOKS_TYPE = 5;
	int infectTime;
	int stayTime;
	int stayEstimatedTime;
	private boolean isStay;
	private int infectNecessaryTime;
	private Position currentDestination;

	public NPC(Position position) {
		this(position, false);
	}

	public NPC(Position position, boolean isInfected) {
		super(position);
		this.isInfected = isInfected;
		Random r = new Random();
		this.speed = 3 + r.nextInt(3);
		this.infectTime = 0;
		this.infectNecessaryTime = 200 + r.nextInt(200);
		this.infectNecessaryTime /= CharacterManager.INFECT_CHECK_INTERVAL;
		decideType(isInfected);
		decideNextDestination();
	}

	private void decideType(boolean isInfected) {
		if(isInfected) {
			this.looksType = INFECTED_LOOKS_TYPE;
		}else{
			this.looksType = new Random().nextInt(6) + 1;
			if(this.looksType == INFECTED_LOOKS_TYPE) {
				this.looksType = 7;
			}
		}
	}

	public int getInfectNecessaryTime() {
		return infectNecessaryTime;
	}

	public void infected() {
		this.isInfected = true;
		this.looksType = 5;
	}

	public boolean isStay() {
		return isStay;
	}

	public void walk(int x, int y) {
		int cx = this.getPosition().getX();
		int cy = this.getPosition().getY();
		if(cx < x) {
			move(1, 0, x, 0);
		}else if(x < cx) {
			move(-1,  0, x, 0);
		}else if(cy < y) {
			move(0,  1, 0, y);
		}else if(y < cy) {
			move(0, -1, 0, y);
		}
	}

	public void dismiss() {
		if(isStay) {
			decideNextDestination();
		}
	}

	private void decideNextDestination() {
		isStay = false;
		Random r = new Random();
		stayTime = 0;
		stayEstimatedTime = 200 + r.nextInt(500);
		currentDestination = new Position(r.nextInt(700) + 50,  r.nextInt(600));
		infectTime = infectTime * 3 /4;

		/*
		int buildingId = r.nextInt(9);
		int bx = buildingId % 3 * 16 * 16 + 8 * 16;
		int by = buildingId / 3 * 13 * 16 + 6 * 16;
		currentDestination = new Position(bx,  by);
		*/

	}

	@Override
	public void update() {
		super.update();
		stayTime++;
		if(stayTime > stayEstimatedTime) {
			decideNextDestination();
		}
		if(currentDestination != null) {
			if(this.position.getX() == currentDestination.getX() && this.position.getY() == currentDestination.getY() ) {
				currentDestination = null;
			}else {
				walk(currentDestination.getX(), currentDestination.getY());
			}
		}else {
			isStay = true;
		}
	}
}
