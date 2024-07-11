import java.util.Scanner;
public class BillingProgram {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Welcome to the Billing Program!");
        System.out.print("Enter customer name: ");
        String customerName = scanner.nextLine();
        System.out.print("Enter customer phone number: ");
        String customerPhone = scanner.nextLine();
        
        System.out.print("Enter number of items: ");
        int numItems = scanner.nextInt();
        scanner.nextLine(); 
        double total = 0.0;
        for (int i = 0; i < numItems; i++) {
            System.out.print("Enter item " + (i + 1) + " name: ");
            String itemName = scanner.nextLine();
            System.out.print("Enter item " + (i + 1) + " price: ");
            double itemPrice = scanner.nextDouble();
            scanner.nextLine(); 
            total += itemPrice;
           }
        double taxRate = 0.02;
        double tax = total * taxRate;
        double amountDue = total + tax;
        System.out.println("\nInvoice:");
        System.out.println("Customer Name: " + customerName);
        System.out.println("Customer Phone: " + customerPhone);
        System.out.println("Items:");
       
        System.out.println("Subtotal: " + total);
        System.out.println("Tax (2%): " + tax);
        System.out.println("Total Amount Due: " + amountDue);

        scanner.close();
    }
}
