package myChatFX.utilities;

public enum PrintColors {
    RESET("\u001B[0m"),
    BOLD("\u001B[1m"),
    ITALIC("\u001B[3m"),
    RED("\u001B[31m"),
    GREEN("\u001B[32m"),
    YELLOW("\u001B[33m"),
    BLUE("\u001B[34m"),
    PURPLE("\u001B[35m"),
    CYAN("\u001B[36m");

    private final String code;

    PrintColors(String code) {
        this.code = code;
    }

    public String getCode() {
        return code;
    }

    public static String format(String text, PrintColors... styles) {
        StringBuilder sb = new StringBuilder();
        for (PrintColors style : styles) {
            sb.append(style.getCode());
        }
        sb.append(text).append(RESET.getCode());
        return sb.toString();
    }
}
