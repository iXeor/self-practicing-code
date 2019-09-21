import java.util.Scanner;

class studentScores {
    private static double scores[] = new double [5];
    private static double temp = 0;
    public static void setScores(){
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入该生五道题的成绩:");
        for(int i = 0;i < 5;i++){
            scores[i] = sc.nextDouble();
        }
    }
    public static void displayScores() {
        for(int i = 0;i < 5;i++){
            System.out.print(scores[i]+"\t");
        }
    }
    public static double aCalc(){
        for(int i = 0;i<5;i++) {
            temp += scores[i];
        }
        return temp/5;
    }
    public static void resetAcalc(){
        temp = 0;
    }
    public static void mistakeMaker(){
        int h = 0;
        int i;
        for(i = 0;i < 4;i++){
            if(scores[i] > scores[i+1]) h = i+1;
        }
        System.out.println("该学生错误率最高的题目是第"+ (int)(h+1) + "题");
    }
    public static void gradeSelector(){
        resetAcalc();
        int x = (int) aCalc()/10;
        switch(x){
            case 10:
            case 9 : {
                System.out.println("Grade A");
                break;
            }
            case 8 : {
                System.out.println("Grade B");
                break;
            }
            case 7 : {
                System.out.println("Grade C");
                break;
            }
            case 6: {
                System.out.println("Grade D");
                break;
            }
            default : {
                System.out.println("Grade E");
            }
        }
    }
}
public class Main{
    public static void main(String args[]){
        studentScores a[] = new studentScores [10];
        for(int i = 0;i < 2;i++){
            System.out.println("请输入第"+(i+1)+"名学生的成绩");
            a[i].setScores();
            a[i].gradeSelector();
            a[i].mistakeMaker();
        }
    }
}
