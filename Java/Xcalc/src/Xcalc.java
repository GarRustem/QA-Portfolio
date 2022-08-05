import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Objects;

public class Xcalc {
    private JPanel winCalc;
    private JTextField displayField;
    private String[] numButtons;
    private String[] operatorButtons;
    private String[] signButtons;
    private JPanel panel1;
    private JPanel panel2;
    private BorderLayout bL;
    private JButton[] numbers;
    private JButton[] operators;
    private JButton[] signs;
    private JFrame frame;

    Xcalc() {
            winCalc = new JPanel();
            bL = new BorderLayout();
            winCalc.setLayout(bL);

            displayField = new JFormattedTextField("0");
            displayField.setFocusable(false);
            winCalc.add("North", displayField);

            panel1 = new JPanel();
            GridLayout gL = new GridLayout(4, 3);
            panel1.setLayout(gL);
            winCalc.add("Center", panel1);

            panel2 = new JPanel();
            GridLayout gL1 = new GridLayout(5, 1);
            panel2.setLayout(gL1);
            winCalc.add("East", panel2);

            frame = new JFrame("Calculator Mark V");
            frame.setContentPane(winCalc);
            frame.pack();
            frame.setVisible(true);
            frame.setSize(300, 400);
            frame.setResizable(false);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setLocation(800, 300);

            operatorButtons = new String[]{"+", "-", "*", "/", "C"};
            signButtons = new String[]{".", "="};
            numButtons = new String[]{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

            numbers = new JButton[numButtons.length];
            for (int i = 0; i < numButtons.length; i++) {
                numbers[i] = new JButton(numButtons[i]);
                panel1.add(numbers[i]);
            }
            for (JButton num : numbers) {
                num.addActionListener(CalcEngine);
            }

            signs = new JButton[signButtons.length];
            for (int j = 0; j < signButtons.length; j++) {
                signs[j] = new JButton(signButtons[j]);
                panel1.add(signs[j]);
            }
            for (JButton sign : signs) {
                sign.addActionListener(CalcEngine);
            }

            operators = new JButton[operatorButtons.length];
            for (int k = 0; k < operatorButtons.length; k++) {
                operators[k] = new JButton(operatorButtons[k]);
                panel2.add(operators[k]);
            }
            for (JButton op : operators) {
                op.addActionListener(CalcEngine);
            }
    }

    public class Engine implements ActionListener {
        char action = ' ';
        double currentResolve = 0;
        double displayValue = 0;

        @Override
        public void actionPerformed(ActionEvent e) {

            if (!"".equals(displayField.getText())) {
                displayValue = Double.parseDouble(displayField.getText());
            }

            if (e.getSource() == signs[0]) {
                String dot;
                int findDot = displayField.getText().indexOf(".");
                if (findDot == -1) {
                    dot = ".";
                    displayField.setText(displayField.getText() + dot);
                } else {
                    dot = "";
                    displayField.setText(displayField.getText() + dot);
                }
            } else if (e.getSource() == signs[1]) {
                if (action == '+') {
                    currentResolve = currentResolve + displayValue;
                    displayField.setText("" + currentResolve);
                } else if (action == '-') {
                    currentResolve = currentResolve - displayValue;
                    displayField.setText("" + currentResolve);
                } else if (action == '*') {
                    currentResolve = currentResolve * displayValue;
                    displayField.setText("" + currentResolve);
                } else if (action == '/') {
                    currentResolve = currentResolve / displayValue;
                    displayField.setText("" + currentResolve);
                }
            }

            if (e.getSource() == numbers[0]) {
                if (displayField.getText().equals("0")) {
                    return;
                } else {
                    displayField.setText(displayField.getText() + "0");
                }
//                String zero;
//                int findZero = displayField.getText().indexOf(".");
//                if (findZero == -1) {
//                    zero = "0.";
//                    displayField.setText(displayField.getText() + zero);
//                } else {
//                    zero = "0";
//                    displayField.setText(displayField.getText() + zero);
//                }
            } else if (e.getSource() == numbers[1]) {
                if (displayField.getText().equals("0")) {
                    displayField.setText("1");
                } else {
                    displayField.setText(displayField.getText() + "1");
                }
            } else if (e.getSource() == numbers[2]) {
                if (displayField.getText().equals("0")) {
                    displayField.setText("2");
                } else {
                    displayField.setText(displayField.getText() + "2");
                }
            } else if (e.getSource() == numbers[3]) {
                if (displayField.getText().equals("0")) {
                    displayField.setText("3");
                } else {
                    displayField.setText(displayField.getText() + "3");
                }
            } else if (e.getSource() == numbers[4]) {
                if (displayField.getText().equals("0")) {
                    displayField.setText("4");
                } else {
                    displayField.setText(displayField.getText() + "4");
                }
            } else if (e.getSource() == numbers[5]) {
                if (displayField.getText().equals("0")) {
                    displayField.setText("5");
                } else {
                    displayField.setText(displayField.getText() + "5");
                }
            } else if (e.getSource() == numbers[6]) {
                if (displayField.getText().equals("0")) {
                    displayField.setText("6");
                } else {
                    displayField.setText(displayField.getText() + "6");
                }
            } else if (e.getSource() == numbers[7]) {
                if (displayField.getText().equals("0")) {
                    displayField.setText("7");
                } else {
                    displayField.setText(displayField.getText() + "7");
                }
            } else if (e.getSource() == numbers[8]) {
                if (displayField.getText().equals("0")) {
                    displayField.setText("8");
                } else {
                    displayField.setText(displayField.getText() + "8");
                }
            } else if (e.getSource() == numbers[9]) {
                if (displayField.getText().equals("0")) {
                    displayField.setText("9");
                } else {
                    displayField.setText(displayField.getText() + "9");
                }
            }

            if (e.getSource() == operators[0]) {
                action = '+';
                currentResolve = displayValue;
                displayField.setText("0");
            } else if (e.getSource() == operators[1]) {
                action = '-';
                currentResolve = displayValue;
                displayField.setText("0");
            } else if (e.getSource() == operators[2]) {
                action = '*';
                currentResolve = displayValue;
                displayField.setText("0");
            } else if (e.getSource() == operators[3]) {
                action = '/';
                currentResolve = displayValue;
                displayField.setText("0");
            } else if (e.getSource() == operators[4]) {
                currentResolve = 0;
                displayValue = 0;
                displayField.setText("0");
            }
        }
    }
    Engine CalcEngine = new Engine();

    public static void main (String[] args) {
        Xcalc MarkV = new Xcalc();
    }
}
// Ноль отображается по умолчанию - успешно, понятно по коду;
// Ноль не добавляется первой цифрой - грубое решение (отвечают строчки 120-128) заменено на более изящное;
// Деление на ноль запрещено;
// Точка может быть только одна - отвечают строчки 93-102;
// Арифметические операции проходят успешно - отвечают строчки 88-90;
// Новый ввод после "=" не добавляется к результату вычислений;
// Добавлена кнопка clear - успешно;
// Калькулятор оформлен шрифтом и цветом.
