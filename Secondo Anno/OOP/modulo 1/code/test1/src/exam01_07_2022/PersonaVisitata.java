package exam01_07_2022;

public class PersonaVisitata extends Persona {

    private Integer priority_code;
    private String reparto;

    public PersonaVisitata(String codiceFiscale, String nome, String cognome, Integer priority_code, String reparto) {
        super(codiceFiscale, nome, cognome);
        this.priority_code = priority_code;
        this.reparto = reparto;
    }

    public void setPriority_code(int priority_code) {
        this.priority_code = priority_code;
    }

    public void setReparto(String reparto) {
        this.reparto = reparto;
    }

    public Integer getPriority_code() {
        return this.priority_code;
    }

    public String getReparto() {
        return this.reparto;
    }
}
