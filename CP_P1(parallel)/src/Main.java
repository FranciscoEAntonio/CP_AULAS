
public class Main {

	public static void main(String[] args) {
		double shots = Double.parseDouble(args[0]);
		int threads = Integer.parseInt(args[1]);
		double hits = 0;
		SolverThread [] savedThreads = new SolverThread [threads];

		for (int i = 0; i < threads; i++) {
			SolverThread t1  = new SolverThread(shots / threads);
			t1.start();
			savedThreads[i] = t1;
		}

		try {
			for(SolverThread aux : savedThreads) {
				aux.join();
				hits += aux.getHits(); 
			}
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		System.out.println("Shots by thread: " + shots / threads);
		System.out.println("Total Number of points: " + shots);
		System.out.println("Points within circle: " + hits);
		System.out.println("Pi estimation: " + hits / shots * 4);
	}
}
