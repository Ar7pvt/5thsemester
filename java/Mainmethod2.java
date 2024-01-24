class Measurement {
    double km;
    double meter;
    double millimeter;

    Measurement(double km, double meter, double millimeter) {
        this.km = km;
        this.meter = meter;
        this.millimeter = millimeter;
    }

    int roundOffKm() {
        return (int) Math.round(km);
    }

    int roundOffMeter() {
        return (int) Math.round(meter);
    }

    int roundOffMillimeter() {
        return (int) Math.round(millimeter);
    }
}

public class Mainmethod2 {
    public static void main(String[] args) {
        Measurement m = new Measurement(10.5, 100.7, 500.3);
        System.out.println("Kilometer: " + m.roundOffKm());
        System.out.println("Meter: " + m.roundOffMeter());
        System.out.println("Millimeter: " + m.roundOffMillimeter());
    }
}


