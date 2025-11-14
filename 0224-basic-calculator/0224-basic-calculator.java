class Solution {
    public int calculate(String s) {
        int result = 0;
        int num = 0;
        char operator = '+';
        Stack<Integer> stack = new Stack<>();

        for (char c : s.toCharArray()) {

            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            }

            if (!Character.isDigit(c) && c != ' ') {

                // 1) + 또는 - 처리
                if (operator == '+') result += num;
                else if (operator == '-') result += -num;

                // operator 갱신은 +, - 일 때만!
                if (c == '+' || c == '-') operator = c;

                num = 0;

                // 2) '(' 처리
                if (c == '(') {
                    // 현재까지의 result 저장
                    stack.push(result);

                    // 현재까지의 sign 저장
                    stack.push(operator == '+' ? 1 : -1);

                    // 괄호 안에서 새 계산 시작
                    result = 0;
                    operator = '+';
                }

                // 3) ')' 처리
                if (c == ')') {
                    int sign = stack.pop();
                    int prev = stack.pop();

                    result = prev + sign * result;
                }
            }
        }

        // 마지막 숫자 처리
        if (operator == '+') result += num;
        else if (operator == '-') result += -num;

        return result;
    }
}
