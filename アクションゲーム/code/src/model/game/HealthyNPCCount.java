package model.game;

import java.util.Observable;

public class HealthyNPCCount extends Observable{
	int value;
	public HealthyNPCCount() {
		value = 0;
	}

	public void setValue(int value) {
		this.value = value;
		setChanged();
		notifyObservers();
	}

	public int getValue() {
		return this.value;
	}
}
