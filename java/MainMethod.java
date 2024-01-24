class Employee {
    int emp_code;
    String name;
    String designation;
    int salary;

    Employee() {
        emp_code = 0;
        name = "";
        designation = "";
        salary = 0;
    }

    Employee(int emp_code, String name, String designation) {
        this.emp_code = emp_code;
        this.name = name;
        this.designation = designation;
        if (designation.equals("clerk")) {
            salary = 5000;
        } else if (designation.equals("peon")) {
            salary = 2000;
        } else if (designation.equals("manager")) {
            salary = 10000;
        } else {
            salary = 1000;
        }
    }

    Employee(int emp_code, String name, String designation, int salary) {
        this.emp_code = emp_code;
        this.name = name;
        this.designation = designation;
        this.salary = salary;
    }

    void display() {
        System.out.println("Employee Code: " + emp_code);
        System.out.println("Name: " + name);
        System.out.println("Designation: " + designation);
        System.out.println("Salary: Rs. " + salary);
    }
}

public class MainMethod {
    public static void main(String[] args) {
        Employee emp = new Employee(101, "John Doe", "manager");
        emp.display();
    }
}
