class Solution {
    public int calculate(String s) {
        Stack<Integer> nums = new Stack<>();
        Stack<Character> ops = new Stack<>();

        int n = s.length();
        int num = 0;

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);

            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            }

            if (c == '(') {
                ops.push(c);
            }

            // 숫자 뒤, 연산자, 괄호 닫힘, 마지막 문자에서 처리
            if (!Character.isDigit(c) && c != ' ' || i == n - 1) {

                if (Character.isDigit(c) && i == n - 1) {
                    nums.push(num);
                } else {
                    if (i > 0 && Character.isDigit(s.charAt(i - 1))) {
                        nums.push(num);
                    }
                }
                num = 0;

                if (c == ')') {
                    while (ops.peek() != '(') {
                        apply(nums, ops);
                    }
                    ops.pop(); // '(' 제거
                } 
                else if (isOp(c)) {
                    while (!ops.isEmpty() && ops.peek() != '('
                           && prec(ops.peek()) >= prec(c)) {
                        apply(nums, ops);
                    }
                    ops.push(c);
                }
            }
        }

        while (!ops.isEmpty()) apply(nums, ops);
        return nums.pop();
    }

    private boolean isOp(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    private int prec(char c) {
        if (c == '+' || c == '-') return 1;
        return 2;  // * /
    }

    private void apply(Stack<Integer> nums, Stack<Character> ops) {
        int b = nums.pop();
        int a = nums.pop();
        char op = ops.pop();

        if (op == '+') nums.push(a + b);
        else if (op == '-') nums.push(a - b);
        else if (op == '*') nums.push(a * b);
        else if (op == '/') nums.push(a / b);
    }
}
