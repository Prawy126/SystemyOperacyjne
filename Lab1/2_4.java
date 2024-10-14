public class DrzewoKatalogowe {

    public static void main(String[] args) {
        String[][][] drzewoA = {
            {{"A"}, {"B", "D"}, {"C"}, {"D"}, {"f1", "E"}}
        };

        String[][][] drzewoX = {
            {{"X"}, {"Y", "X", "f1"}, {"Z"}, {"f1", "Z"}}
        };

        
        System.out.println("Drzewo A:");
        wyswietlDrzewo(drzewoA);

        
        System.out.println("\nDrzewo X:");
        wyswietlDrzewo(drzewoX);
    }

    public static void wyswietlDrzewo(String[][][] drzewo) {
        for (int i = 0; i < drzewo.length; i++) {
            for (int j = 0; j < drzewo[i].length; j++) {
                for (int k = 0; k < drzewo[i][j].length; k++) {
                    System.out.print(drzewo[i][j][k] + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}
