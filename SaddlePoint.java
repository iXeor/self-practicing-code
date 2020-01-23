package Idea;

public class SaddlePoint{
	public static void outPutList(int data[][]){
		for(int i = 0;i<3;i++){
			for(int j = 0;j<3;j++){
				System.out.print(data[i][j]+"\t");
			}
			System.out.println();
		}
	}
	public static void BigOne(int data[][]) {
		int MaxinL[] = new int[3];
		int MaxinP[] = new int[3];
		int x = 0;
		for (int i = 0; i < 3; i++) {
			int tempMax = data[i][0];
			for (int j = 0; j < 3; j++) {
				if (data[i][j] > tempMax) {
					tempMax = data[i][j];
				}
			}
			MaxinL[i] = tempMax;
		}
		for (int a = 0; a < 3; a++) {
			int tempMax = data[0][a];
			for (int b = 0; b < 3; b++) {
				if (data[b][a] > tempMax) {
					tempMax = data[b][a];
				}
			}
			MaxinP[a] = tempMax;
		}
		for (int i = 0; i < MaxinL.length; i++) {
			int a = 0;
			for (int j = 0; j < MaxinP.length; j++) {
				if (MaxinL[i] == MaxinP[j]) {
					System.out.print(MaxinP[j]+"\t");
				}
			}
		}
	}

    public static void main(String[] args) {
		int data[][] = {{8,2,5},{3,1,12},{6,4,10}};
		outPutList(data);
		BigOne(data);
    }
}
