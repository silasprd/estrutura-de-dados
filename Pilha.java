public class Pilha {
    private int maxSize;
    private int[] values;
    private int top;

    public Pilha(int maxSize) {
        this.maxSize = maxSize;
        this.values = new int[maxSize];
        this.top = -1;
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top == maxSize - 1;
    }

    public void add(int value) {
        if (isFull()) {
            throw new ArrayIndexOutOfBoundsException("Não foi possível adicionar, pilha cheia!");
        }
        values[++top] = value;
    }

    public int remove() {
        if (isEmpty()) {
            throw new ArrayIndexOutOfBoundsException("Não foi possível remover, pilha vazia!");
        }
        return values[top--];
    }

    public int size() {
        return top + 1;
    }

    public int lastValue() {
        if (top != -1) {
            return values[top];
        } else {
            throw new ArrayIndexOutOfBoundsException("Nenhum elemento na pilha");
        }
    }

    public void print(int[] values) {
        for (int i = 0; i < values.length; i++) {
            System.out.println(values[i]);
        }
    }

    public static void main(String[] args) {
        Pilha p = new Pilha(4);

        p.add(3);
        p.add(2);
        p.add(1);
        p.add(4);

        System.out.println("Lista está vazia? " + p.isEmpty());
        System.out.println("Lista está cheia? " + p.isFull());
        System.out.println("Tamanho da lista> " + p.size());
        System.out.println("Último elemento> " + p.lastValue());

        p.print(p.values);
    }
}