package mathquiz;

import java.util.Random;

public class NumericQuestion {
    private int num1;
    private int num2;
    private int operator;

    public NumericQuestion() {
        randomInit();
    }

    public int getNum1() {
        return num1;
    }

    public void setNum1(int num1) {
        this.num1 = num1;
    }

    public int getNum2() {
        return num2;
    }

    public void setNum2(int num2) {
        this.num2 = num2;
    }

    public int getOperator() {
        return operator;
    }

    public void setOperator(char operator) {
        this.operator = operator;
    }

    public void randomInit(){
        Random random = new Random();
        num1 = random.nextInt(100);
        num2 = random.nextInt(70);
        operator = random.nextInt(2);
    }
    public int getResult(){
        if(operator == 0){
            return num1 + num2;
        }
        return num1 - num2;
    }

    @Override
    public String toString(){
        return num1 + " " + (operator == 0 ? "+" : "-") + " " + num2;
    }
}
