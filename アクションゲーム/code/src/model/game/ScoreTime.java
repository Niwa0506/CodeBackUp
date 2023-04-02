package model.game;

import java.util.Observable;

public class ScoreTime extends Observable{

	private long startRealTime;
	private long endRealTime;
	private int second;
	private int minute;

	public ScoreTime() {
		init();
	}

	public void init() {
		startRealTime = 0;
		endRealTime = 0;
		second = 0;
		minute = 0;
	}

	public int getSecond() {
		return this.second;
	}

	public int getMinute() {
		return this.minute;
	}

	public int getScore() {
		return (int)(endRealTime - startRealTime);
	}

	public void setStartTime(long startRealTime) {
		this.startRealTime = startRealTime;
	}

	public void setEndTime(long endRealTime) {
		this.endRealTime = endRealTime;
		calculateTime();
	}

	private void calculateTime() {
		int currentSecond = (int) (((endRealTime - startRealTime) / 1000) % 60);
		int currentMinute = (int) (((endRealTime - startRealTime) / 1000) / 60);

		if(currentSecond != second || currentMinute != minute) {
			setChanged();
			notifyObservers();
		}
		this.second = currentSecond;
		this.minute = currentMinute;
	}
}
