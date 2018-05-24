import java.util.*;

public class cll {
    public static void main(String[] args) {
    	DogInfo dog = new DogInfo();
    }
}

class DogInfo {
	private String dogName;
	private boolean vip;
	private boolean bigDog;
	private boolean smallDog;
	private boolean biter;
	private boolean walk;
	private boolean training;
	private boolean cuddle;
	
	public String getDogName() {return dogName;}			public void setDogName(String s) {dogName = s;}
	public boolean getVIP() {return vip;}					public void setVIP(boolean s) {vip = s;}
	public boolean getBigDog() {return bigDog;}				public void setBigDog(boolean s) {bigDog = s;}
	public boolean getSmallDog() {return smallDog;}			public void setSmallDog(boolean s) {smallDog = s;}
	public boolean getBiter() {return biter;}				public void setBiter(boolean s) {biter = s;}
	public boolean getWalk() {return walk;}					public void setWalk(boolean s) {walk = s;}
	public boolean getTraining() {return training;}			public void setTraining(boolean s) {training = s;}
	public boolean getCuddle() {return cuddle;}				public void setCuddle(boolean s) {cuddle = s;}
	
	public DogInfo() {
		dogName = "Snoop Dog";
		vip = false;
		bigDog = false;
		smallDog = false;
		biter = false;
		walk = false;
		training = false;
		cuddle = false;
		enterData();
	}
	
	public void enterData() {
		Scanner input = new Scanner(System.in);
		System.out.print("Enter name: ");
		dogName = input.next();
		String tf;
		System.out.print("VIP? (T/F): ");
		tf = input.next();
		if(tf == "T" || tf == "t")
			vip = true;
		System.out.print("Big dog? (T/F): ");
		tf = input.next();
		if(tf == "T" || tf == "t") {
			bigDog = true;
		} else {
		System.out.print("Small dog? (T/F): ");
		tf = input.next();
		if(tf == "T" || tf == "t")
			smallDog = true;
		}
		System.out.print("Biter? (T/F): ");
		tf = input.next();
		if(tf == "T" || tf == "t")
			biter = true;
		System.out.print("Walked? (T/F): ");
		tf = input.next();
		if(tf == "T" || tf == "t")
			walk = true;
		System.out.print("Training? (T/F): ");
		tf = input.next();
		if(tf == "T" || tf == "t")
			training = true;
		System.out.print("Cuddle? (T/F): ");
		tf = input.next();
		if(tf == "T" || tf == "t")
			cuddle = true;
	}
}

class DogNode {
	private DogInfo dog;
	private DogNode next;
	
	public DogNode(DogInfo d, DogNode n) {
		dog = d;
		next = n;
	}
	
	public DogInfo getValue() {return dog;}
	public DogNode getNext() {return next;}
	public void setValue(DogInfo d) {dog = d;}
	public void setNext(DogNode d) {next = d;}
}

class DoggieDayCare {
	DogNode s1;
	DogNode s2;
	DogNode s3;
	DogNode wait;
	int c1;
	int c2;
	int c3;

	public DoggieDayCare() {
		wait = null;
		s1 = null;
		s2 = null;
		s3 = null;
		c1 = c2 = c3 = 0;
	}
	
	
	
	
}
