package exam14_01_2022;

import java.util.Date;
public class Main {

    public static void main(String[] args) {

        PersonaConGreenPass persona = new PersonaConGreenPass("12345678901");
        persona.addGreenPass(new VaccinoGreenPass("12345678901", new Date()));
        ControlloGreenPass controllo = new ControlloGreenPass();
        System.out.println(controllo.haGreenPassSuper(persona));
    }
}
