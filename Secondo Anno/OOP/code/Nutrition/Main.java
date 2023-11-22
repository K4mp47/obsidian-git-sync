import java.util.*;

    
abstract class Food {
    public double proteins;
    public double fats;
    public double carbs;
    public int tastyScore;

    public Food(double protein, double fat, double carbs) {
        this.proteins = protein;
        this.fats = fat;
        this.carbs = carbs; 
    }

    abstract void getMacroNutrients();
}

class Bread extends Food {
    public String type = "vegetarian";

    public Bread(double protein, double fat, double carbs) {
      super(protein, fat, carbs);
      tastyScore = 8;
    }
      
    public void getMacroNutrients(){
      System.out.println("A slice of bread has " + this.proteins + " gms of protein, " + this.fats + " gms of fats and " + this.carbs + " gms of carbohydrates.");
    }
}

class Egg extends Food {      
    public String type = "non-vegetarian";
      
    public Egg(double protein, double fat, double carbs) {
      super(protein, fat, carbs);
      tastyScore = 7;
    }
      
    public void getMacroNutrients(){
      System.out.println("An egg has " + this.proteins + " gms of protein, " + this.fats + " gms of fats and " + this.carbs + " gms of carbohydrates.");
    }
}
   
public class Main { 
    public static void main(String args[] ) throws Exception {
        Scanner sc = new Scanner(System.in);
        int cnt = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < cnt; i++) {
            String name = sc.nextLine();

            if(name.equals("Bread")) {
                Bread breadObj = new Bread(4, 1.1, 13.8);
                for(int j = 0; j < 3; j++) {
                    String command = sc.nextLine();
                    if(command.equals("getMacros")) {
                        breadObj.getMacroNutrients();
                    } else if(command.equals("getTaste")) {
                        System.out.println("Taste: " + breadObj.tastyScore);
                    } else if(command.equals("getType")) {
                        System.out.println("Bread is " + breadObj.type);
                    }
                }
            } else if (name.equals("Egg")) {
                Egg eggObj = new Egg(6.3, 5.3, 0.6);
                for(int j = 0; j < 3; j++) {
                    String command = sc.nextLine();
                    if(command.equals("getMacros")) {
                        eggObj.getMacroNutrients();
                    } else if(command.equals("getTaste")) {
                        System.out.println("Taste: " + eggObj.tastyScore);
                    } else if(command.equals("getType")) {
                        System.out.println("Egg is " + eggObj.type);
                    }
                }
            }
        }
    }
}
