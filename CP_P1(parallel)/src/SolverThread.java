import java.util.Random;

public class SolverThread extends Thread{
	
	private double shots;
	private double hits;
	private Random r;
	
	public SolverThread(double shots) {
		this.shots = shots;
		hits = 0;
		r = new Random();
	}

	public void run() {
		double x, y;
		for(int i = 0; i < shots; i++) {
			x = r.nextDouble();
			y = r.nextDouble();
		
			if(Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2)) <= 1) {
				hits++;
			}
		}
    }

	public double getHits() {
		return hits;
	}
	
    public static void main(String args[]) {
        (new SolverThread(Double.parseDouble(args[0]))).start();
    }
}
