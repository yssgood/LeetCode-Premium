class CustomStack {
    int[] stack;
    int size = 0;

    public CustomStack(int maxSize) {
        stack = new int[maxSize];
    }

    public void push(int x) {
        if (size < stack.length) {
            stack[size++] = x;
        }
    }

    public int pop() {
        if (size == 0) return -1;
        return stack[--size];
    }

    public void increment(int k, int val) {
        int limit = Math.min(k, size);   // k가 size보다 크면 size까지만
        for (int i = 0; i < limit; i++) {
            stack[i] += val;             // bottom부터 직접 증가
        }
    }
}