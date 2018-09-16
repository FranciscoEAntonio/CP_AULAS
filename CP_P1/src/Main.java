
public class Main {

	public static void main(String[] args) {
		double shots = Double.parseDouble(args[0]);
		double hits = 0;
		double x, y;
		for(int i = 0; i < shots; i++) {
			x = Math.random();
			y = Math.random();
			
			
			if(Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2)) <= 1) {
				hits++;
			}
		}
		
		System.out.println("Total Number of points: " + shots);
		System.out.println("Points within circle: " + hits);
		System.out.println("Pi estimation: " + hits/shots * 4);
	}

}
