public abstract class Piece {
    protected int xPos;
    protected int yPos;
    private String type;
    public abstract Piece Piece(String type, int x, int y);
    public abstract void move(int x, int y);
}
