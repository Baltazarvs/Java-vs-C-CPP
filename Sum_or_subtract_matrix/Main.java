import java.util.Scanner;

public class Main {
	final static int CRIT_SUM = 1;
	final static int CRIT_SUB = 2;
	
	public static int[][] create_matrix(Scanner sc, int rows, int cols, boolean prompt, String matrix_name)
	{
		int matrix[][] = new int[rows][cols];
		for(int i = 0; i < rows; ++i)
		{
			for(int j = 0; j < cols; ++j)
			{
				if(prompt)
				{
					System.out.print(matrix_name + ": Enter [" + i + "]" + "[" + j + "]: ");
					matrix[i][j] = sc.nextInt();
				}
				else
				{
					matrix[i][j] = 0;
				}
			}
		}
		return matrix;
	}
	
	public static int[][] alter_matrix(int criteria, int[][] matrixA, int[][] matrixB)
	{
		int sum_matrix[][] = create_matrix(null, matrixA.length, matrixA[0].length, false, null);
		
		for(int i = 0; i < matrixA.length; ++i)
		{
			for(int j =0; j < matrixA[0].length; ++j)
			{
				switch(criteria)
				{
					case CRIT_SUB:
						sum_matrix[i][j] = matrixA[i][j] - matrixB[i][j];
						break;
					case CRIT_SUM:
					default:
						sum_matrix[i][j] = matrixA[i][j] + matrixB[i][j];
				}
			}
		}
		return sum_matrix;
	}
	
	public static int[] prompt_matrix_rc(Scanner sc, String matrix_name)
	{
		int mn[] = { 0, 0 };
		System.out.print("[" + matrix_name + "]" + " Enter rows: ");
		int rows = sc.nextInt();
		System.out.print("[" + matrix_name + "]" + " Enter columns: ");
		int cols = sc.nextInt();
		System.out.println("[" + matrix_name + "]" + " Matrix [" + rows + "]" + "[" + cols + "]");
		mn[0] = rows;
		mn[1] = cols;
		return mn;
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int mn[] = prompt_matrix_rc(sc, "2x2 Matrix");
		int rows = mn[0];
		int cols = mn[1];
		
		int res_matrix[][] = create_matrix(sc, rows, cols, false, null);
		int matrixA[][] = create_matrix(sc, rows, cols, true, "A");
		int matrixB[][] = create_matrix(sc, rows, cols, true, "B");
		
		System.out.print("0) Sum Matrix\t\t1) Subtract Matrix\nChoice: ");
		short choice = sc.nextShort();
		switch(choice)
		{
			case 1:
				res_matrix = alter_matrix(CRIT_SUB, matrixA, matrixB);
				break;
			case 0:
			default:
				res_matrix = alter_matrix(CRIT_SUM, matrixA, matrixB);
		}
		
		System.out.println("\nA + B");
		for(int i = 0; i < rows; ++i)
		{
			System.out.print("[\t");
			for(int j = 0; j < cols; ++j)
			{
				System.out.print(res_matrix[i][j] + "\t");
			}
			System.out.print("]\n");
		}
	}
}
