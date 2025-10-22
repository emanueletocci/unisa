package mathquiz;

public class NumericQuestionAttempt {
    private NumericQuestion question;
    private int givenAnswer;

    public NumericQuestionAttempt(NumericQuestion question, int givenAnswer) {
        this.question = question;
        this.givenAnswer = givenAnswer;
    }
    public NumericQuestion getQuestion() {
        return question;
    }

    public void setQuestion(NumericQuestion question) {
        this.question = question;
    }

    public int getGivenAnswer() {
        return givenAnswer;
    }

    public void setGivenAnswer(int givenAnswer) {
        this.givenAnswer = givenAnswer;
    }

    private boolean isCorrect(){
        return question.getResult() == givenAnswer;
    }

    public String getString(){
        if(isCorrect()){
            return "Right";
        } else {
            return "Wrong";
        }
    }

    @Override
    public String toString() {
        return question.toString() + " = " + givenAnswer;
    }
}
