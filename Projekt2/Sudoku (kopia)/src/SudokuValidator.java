import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicBoolean;

public class SudokuValidator {

    private static final int ROZMIAR = 9;
    private static final int ROZMIAR_PODSIATKI = 3;
    private static final int[][] siatkaSudoku = {
            {6, 1, 4, 5, 3, 9, 1, 8, 7},
            {5, 2, 9, 7, 2, 8, 6, 3, 4},
            {8, 3, 7, 6, 1, 4, 2, 9, 5},
            {1, 4, 3, 8, 6, 5, 7, 2, 9},
            {9, 5, 8, 2, 4, 7, 3, 6, 1},
            {7, 6, 2, 3, 9, 1, 4, 5, 8},
            {3, 7, 1, 9, 5, 6, 8, 4, 2},
            {4, 9, 6, 1, 8, 2, 5, 7, 3},
            {2, 8, 5, 4, 7, 3, 9, 1, 6}
    };

    private static final AtomicBoolean czyPoprawne = new AtomicBoolean(true);

    public static void main(String[] args) {
        if (!czySudokuPrawidlowe()) {
            System.out.println("Tablica Sudoku nie jest poprawnie wypełniona.");
            return;
        }

        ExecutorService wykonawca = Executors.newFixedThreadPool(ROZMIAR + 2);

        // Walidacja wierszy
        for (int i = 0; i < ROZMIAR; i++) {
            int wiersz = i;
            wykonawca.submit(() -> sprawdzWiersz(wiersz));
        }

        // Walidacja kolumn
        for (int i = 0; i < ROZMIAR; i++) {
            int kolumna = i;
            wykonawca.submit(() -> sprawdzKolumne(kolumna));
        }

        // Walidacja podsiatek
        for (int wiersz = 0; wiersz < ROZMIAR; wiersz += ROZMIAR_PODSIATKI) {
            for (int kolumna = 0; kolumna < ROZMIAR; kolumna += ROZMIAR_PODSIATKI) {
                int poczatekWiersz = wiersz;
                int poczatekKolumna = kolumna;
                wykonawca.submit(() -> sprawdzPodsiatke(poczatekWiersz, poczatekKolumna));
            }
        }

        wykonawca.shutdown();
        while (!wykonawca.isTerminated()) {
            // Czekaj na zakończenie wszystkich wątków
        }

        if (czyPoprawne.get()) {
            System.out.println("Rozwiązanie Sudoku jest poprawne.");
        } else {
            System.out.println("Rozwiązanie Sudoku jest niepoprawne.");
        }
    }

    private static boolean czySudokuPrawidlowe() {
        if (siatkaSudoku.length != ROZMIAR) return false;
        for (int i = 0; i < ROZMIAR; i++) {
            if (siatkaSudoku[i].length != ROZMIAR) return false;
            for (int j = 0; j < ROZMIAR; j++) {
                if (siatkaSudoku[i][j] < 1 || siatkaSudoku[i][j] > ROZMIAR) return false;
            }
        }
        return true;
    }

    private static void sprawdzWiersz(int wiersz) {
        boolean[] widziane = new boolean[ROZMIAR];
        for (int kolumna = 0; kolumna < ROZMIAR; kolumna++) {
            int liczba = siatkaSudoku[wiersz][kolumna];
            if (liczba < 1 || liczba > ROZMIAR || widziane[liczba - 1]) {
                czyPoprawne.set(false);
                return;
            }
            widziane[liczba - 1] = true;
        }
    }

    private static void sprawdzKolumne(int kolumna) {
        boolean[] widziane = new boolean[ROZMIAR];
        for (int wiersz = 0; wiersz < ROZMIAR; wiersz++) {
            int liczba = siatkaSudoku[wiersz][kolumna];
            if (liczba < 1 || liczba > ROZMIAR || widziane[liczba - 1]) {
                czyPoprawne.set(false);
                return;
            }
            widziane[liczba - 1] = true;
        }
    }

    private static void sprawdzPodsiatke(int poczatekWiersz, int poczatekKolumna) {
        boolean[] widziane = new boolean[ROZMIAR];
        for (int wiersz = 0; wiersz < ROZMIAR_PODSIATKI; wiersz++) {
            for (int kolumna = 0; kolumna < ROZMIAR_PODSIATKI; kolumna++) {
                int liczba = siatkaSudoku[poczatekWiersz + wiersz][poczatekKolumna + kolumna];
                if (liczba < 1 || liczba > ROZMIAR || widziane[liczba - 1]) {
                    czyPoprawne.set(false);
                    return;
                }
                widziane[liczba - 1] = true;
            }
        }
    }
}
