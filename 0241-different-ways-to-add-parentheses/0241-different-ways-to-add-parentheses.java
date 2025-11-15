class Solution {
    public List<Integer> diffWaysToCompute(String expression) {
        return helper(expression);
    }

    public List<Integer> helper(String expression) {
        List<Integer> res = new ArrayList<>();

        // base case: expression 전체가 숫자인 경우
        if (expression.chars().allMatch(Character::isDigit)) {
            res.add(Integer.parseInt(expression));
            return res;
        }

        for (int i = 0; i < expression.length(); i++) {
            char op = expression.charAt(i);

            if (op == '+' || op == '-' || op == '*') {

                // 재귀적으로 왼쪽/오른쪽 계산
                List<Integer> left = helper(expression.substring(0, i));
                List<Integer> right = helper(expression.substring(i + 1));

                // 조합
                for (int l : left) {
                    for (int r : right) {
                        if (op == '+') res.add(l + r);
                        else if (op == '-') res.add(l - r);
                        else if (op == '*') res.add(l * r);
                    }
                }
            }
        }

        return res;
    }
}
