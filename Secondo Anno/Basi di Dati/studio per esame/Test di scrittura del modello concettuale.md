| Value (left) | Value (right) | Meaning                       |
| ------------ | ------------- | ----------------------------- |
| `\|o`        | `o\|`         | Zero or one                   |
| `\|`         | `\|`          | Exactly one                   |
| `}o`         | `o{`          | Zero or more (no upper limit) |
| `}\|`        | `\|{`         | One or more (no upper limit)  |
| `PK`         | `FK`          | primary key/ foreign key      |

```mermaid
---
title: Prestiti dei libri
---
erDiagram

Libri ||--|| Descrizioni : "Descrive"
Autori ||--|| Descrizioni : "Ha scritto"
Termini ||--|| Descrizioni : "Indicizza"
Utenti ||--|| Docenti : "sottoclasse"
Utenti ||--|| Studenti : "sottoclasse"
InConsultazione ||--|| Prestiti : "sottoclasse"
Regolari ||--|| Prestiti : "sottoclasse"
Prestabili ||--|| Libri : "sottoclasse"
Consultabili ||--|| Libri : "sottoclasse"
Utenti ||--|| Regolari : "Ha preso"
Docenti ||--|| InConsultazione : "Consulta"
Consultabili ||--|| InConsultazione : "Riguarda"
Regolari ||--|| Prestabili : "Riguarda"

Libri {
	string Codice
}

Autori {
	string CF PK
	string Nome
	string Nazionalita
	string AnnoNascita
}

Utenti {
	string CF PK
	string Nome
	string Indirizzo
	seq Telefoni
}

Studenti {
	string Matricola PK
}

Docenti {
	string TelefonoUfficio
}

Termini {
	string Termine
}

Prestiti {
	date DataPrestito
	date DataRestituzione
}

InConsultazione{

}

Regolari {

}

Prestabili{

}

Consultabili {
	int PerGiorni
}

Descrizioni {
	string ISBN PK
	string Titolo
	string Editore
	int    AnnoPubblicazione
}

```

```mermaid
---
title: Segreteria
---
erDiagram

DomandaTrasferimento ||--|| PraticaTrasferimento : "Causa"
Delibera ||--|| PraticaTrasferimento : "EvasaDa"
CorsoEsterno ||--|| DomandaTrasferimento : "DichiaratoIn"
Convalida ||--|| Delibera : "ApprovatoIn"
CorsoEsterno ||--|| Convalida : "ConsideratoIn"
CorsoInterno ||--|| Convalida : "Convalida"
CorsoInterno ||--|| CorsoEsterno : "ConvalidaTipica(La classe)"
Studente ||--|| DomandaTrasferimento : "Presentano"
BozzaDelibera ||--|| Delibera : "sottoclasse"
DeliberaApprovata ||--|| Delibera : "sottoclasse"
Studente ||--|| CorsoDiLaurea : "FrequentatoDa"
CorsoDiLaurea ||--|| CorsoEsterno : "SvoltoIn"
Studente {
	string Nome
	string Recapito
	string Universita
	string Facolta
	string CorsoDiProvenienza
}

DomandaTrasferimento {
	int NumeroProtocollo PK
	string DatiPresentazione
}

PraticaTrasferimento {
	int id PK
	string Annotazione
}

Delibera {
	string Annotazioni
}

BozzaDelibera {
	
}

DeliberaApprovata {
	date DataVerbale
	int NumeroVerbale
}

Convalida {
	bool PrevioColloquio
}

ConvalidaTipica {
	bool PrevioColloquio
}

CorsoInterno {
	string Nome
	int NumeroCrediti
}

CorsoEsterno {
	string Nome
	string Universita
	string Facolta
	string CorsoLaurea
	date AnnoAccademicoSuperamento
}

CorsoDiLaurea {
	string nome PK
	string Universita PK
	string Facolta
}

```