import java.util.*;

class TicketCounter {
    private int passengerTotal;
    private double cashTotal;

    TicketCounter() {
        passengerTotal = 0;
        cashTotal = 0;
    }

    void payingPassenger() {
        passengerTotal++;
        cashTotal += 50;
    }

    void childPassenger() {
        passengerTotal++;
    }

    void display() {
        System.out.println("Total number of passengers: " + passengerTotal);
        System.out.println("Total amount of cash collected: Rs. " + cashTotal);
    }
}

public class MainMethod3 {
    public static void main(String[] args) {
        TicketCounter tc = new TicketCounter();
        char choice;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("Press 'p' to count a paying passenger");
            System.out.println("Press 'c' to count a child passenger");
            System.out.println("Press 'd' to display the totals and exit");
            choice = sc.next().charAt(0);
            switch (choice) {
                case 'p':
                    tc.payingPassenger();
                    break;
                case 'c':
                    tc.childPassenger();
                    break;
                case 'd':
                    tc.display();
                    break;
                default:
                    System.out.println("Invalid choice. Try again.");
            }
        } while (choice != 'd');
    }
}
