import java.util.ArrayList;
import java.util.Scanner;
class Item {
    private String name;
    private double price;
    private int quantity;

    public Item(String name, double price, int quantity) {
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public int getQuantity() {
        return quantity;
    }
}

public class SupermarketBillingSystem {
    private ArrayList<Item> cart;
    private Scanner scanner;

    public SupermarketBillingSystem() {
        cart = new ArrayList<>();
        scanner = new Scanner(System.in);
    }

    public void addItemToCart() {
        System.out.print("Enter item name: ");
        String name = scanner.nextLine();
        System.out.print("Enter item price: ");
        double price = scanner.nextDouble();
        System.out.print("Enter item quantity: ");
        int quantity = scanner.nextInt();
        scanner.nextLine(); // consume newline left-over

        Item item = new Item(name, price, quantity);
        cart.add(item);
        System.out.println("Item added to cart successfully!");
    }

    public void removeItemFromCart() {
        System.out.print("Enter item name to remove: ");
        String name = scanner.nextLine();

        for (Item item : cart) {
            if (item.getName().equals(name)) {
                cart.remove(item);
                System.out.println("Item removed from cart successfully!");
                return;
            }
        }

        System.out.println("Item not found in cart!");
    }

    public void calculateTotalCost() {
        double totalCost = 0;
        for (Item item : cart) {
            totalCost += item.getPrice() * item.getQuantity();
        }
        System.out.println("Total cost: " + totalCost);
    }

    public void displayBill() {
        System.out.println("Bill Details:");
        for (Item item : cart) {
            System.out.println("Item Name: " + item.getName());
            System.out.println("Quantity: " + item.getQuantity());
            System.out.println("Price: " + item.getPrice());
            System.out.println("Total Cost: " + item.getPrice() * item.getQuantity());
            System.out.println();
        }
    }

    public static void main(String[] args) {
        SupermarketBillingSystem system = new SupermarketBillingSystem();

        while (true) {
            System.out.println("1. Add item to cart");
            System.out.println("2. Remove item from cart");
            System.out.println("3. Calculate total cost");
            System.out.println("4. Display bill");
            System.out.println("5. Exit");

            System.out.print("Enter your choice: ");
            int choice = system.scanner.nextInt();
            system.scanner.nextLine(); // consume newline left-over

            switch (choice) {
                case 1:
                    system.addItemToCart();
                    break;
                case 2:
                    system.removeItemFromCart();
                    break;
                case 3:
                    system.calculateTotalCost();
                    break;
                case 4:
                    system.displayBill();
                    break;
                case 5:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice!");
            }
        }
    }
}

