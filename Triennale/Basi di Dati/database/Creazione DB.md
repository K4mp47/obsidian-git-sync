```sql
-- Database: Scuola

-- DROP DATABASE IF EXISTS "Scuola";

-- Creazione della tabella Studenti
CREATE TABLE Studenti (
    Matricola VARCHAR PRIMARY KEY,
    Nome VARCHAR NOT NULL,
    Cognome VARCHAR NOT NULL,
    Nascita INTEGER NOT NULL,
    Provincia VARCHAR,
    Tutor VARCHAR,
    CONSTRAINT FK_Tutor FOREIGN KEY (Tutor) REFERENCES Studenti(Matricola)
);

-- Creazione della tabella Docenti
CREATE TABLE Docenti (
    CodDoc VARCHAR PRIMARY KEY,
    Nome VARCHAR NOT NULL,
    Cognome VARCHAR NOT NULL
);

-- Creazione della tabella Esami
CREATE TABLE Esami (
    Codice VARCHAR PRIMARY KEY,
    Candidato VARCHAR NOT NULL,
    Materia VARCHAR NOT NULL,
    CodDoc VARCHAR NOT NULL,
    Data DATE NOT NULL,
    Voto INT NOT NULL,
    Lode BOOLEAN NOT NULL,
    CONSTRAINT FK_Candidato FOREIGN KEY (Candidato) REFERENCES Studenti(Matricola),
    CONSTRAINT FK_CodDoc FOREIGN KEY (CodDoc) REFERENCES Docenti(CodDoc)
);
```

Inserire ed eseguire il codice dopo aver creato un database dentro il programma pgAdmin 4 chiamato 'Scuola'.

---

Ora inseriamo gli Studenti, i Docenti e gli Esami
```sql
-- Inserimento di 30 studenti nella tabella Studenti
INSERT INTO Studenti (Matricola, Nome, Cognome, Nascita, Provincia, Tutor)
VALUES 
('S001', 'Luca', 'Rossi', 1999, 'Milano', NULL),
('S002', 'Maria', 'Bianchi', 2000, 'Roma', 'S001'),
('S003', 'Giovanni', 'Verdi', 1998, 'Napoli', 'S002'),
('S004', 'Anna', 'Neri', 1997, 'Torino', 'S001'),
('S005', 'Paolo', 'Galli', 1999, 'Firenze', 'S002'),
('S006', 'Laura', 'Conti', 2001, 'Venezia', 'S003'),
('S007', 'Marco', 'Ricci', 2000, 'Bologna', 'S002'),
('S008', 'Chiara', 'De Luca', 2002, 'Genova', 'S004'),
('S009', 'Simone', 'Ferrari', 1997, 'Palermo', 'S003'),
('S010', 'Elena', 'Costa', 1998, 'Catania', 'S005'),
('S011', 'Giorgio', 'Marini', 1999, 'Perugia', NULL),
('S012', 'Silvia', 'Barbieri', 2000, 'Trieste', 'S011'),
('S013', 'Alessandro', 'Fontana', 1998, 'Padova', 'S006'),
('S014', 'Valentina', 'Serra', 2001, 'Verona', 'S011'),
('S015', 'Andrea', 'Lombardi', 1997, 'Salerno', 'S007'),
('S016', 'Giulia', 'Giordano', 1999, 'Bari', 'S003'),
('S017', 'Davide', 'Riva', 2000, 'Ancona', 'S008'),
('S018', 'Martina', 'D’Amico', 2002, 'Messina', 'S009'),
('S019', 'Emanuele', 'Pellegrini', 1997, 'Reggio Calabria', 'S010'),
('S020', 'Federica', 'Gatti', 1998, 'Aosta', 'S005'),
('S021', 'Matteo', 'Battaglia', 1999, 'Cagliari', 'S001'),
('S022', 'Sara', 'Mancini', 2000, 'L’Aquila', 'S011'),
('S023', 'Nicola', 'Orlandi', 1998, 'Modena', 'S006'),
('S024', 'Irene', 'Santoro', 2001, 'Ravenna', 'S012'),
('S025', 'Lorenzo', 'Puglisi', 1997, 'Pisa', 'S004'),
('S026', 'Beatrice', 'Biagi', 1999, 'Brescia', 'S007'),
('S027', 'Filippo', 'Fabbri', 2000, 'Lecco', 'S002'),
('S028', 'Camilla', 'Caprioli', 2002, 'Como', 'S009'),
('S029', 'Francesca', 'Cavalli', 1997, 'Vicenza', 'S005'),
('S030', 'Tommaso', 'Greco', 1998, 'Alessandria', 'S011'),
('Marco', 'Rossi', 'S031', 2000, 'Milano', 'S001'), 
('Lucia', 'Bianchi', 'S032', 1999, 'Roma', 'S002'),
('Giovanni', 'Verdi', 'S033', 2001, 'Napoli', 'S003'),
('Anna', 'Neri', 'S034', 2002, 'Firenze', 'S004'),
('Matteo', 'Gallo', 'S035', 1998, 'Torino', 'S005'), 
('Sara', 'Russo', 'S036', 2000, 'Bari', 'S006'),
('Davide', 'Ferrari', 'S037', 1999, 'Venezia', 'S007'),
('Giulia', 'Ricci', 'S038', 2001, 'Genova', 'S008'), 
('Francesco', 'Lombardi', 'S039', 2002, 'Bologna', 'S009'), 
('Elisa', 'Romano', 'S040', 1998, 'Palermo', 'S010'), 
('Alessandro', 'Conti', 'S041', 2000, 'Perugia', 'S011'),
('Chiara', 'Greco', 'S042', 1999, 'Ancona', 'S012'), 
('Lorenzo', 'Marini', 'S043', 2001, 'Cagliari', 'S013'), 
('Federica', 'Sartori', 'S044', 2002, 'Trento', 'S014'), 
('Stefano', 'De Luca', 'S045', 1998, 'Aosta', 'S015'), 
('Martina', 'Barbieri', 'S046', 2000, 'Rimini', 'S016'), 
('Simone', 'Esposito', 'S047', 1999, 'Parma', 'S017'), 
('Alice', 'D’Amico', 'S048', 2001, 'Pescara', 'S018'), 
('Emanuele', 'Fontana', 'S049', 2002, 'Udine', 'S019'), 
('Valentina', 'Caputo', 'S050', 1998, 'Lecce', 'S020'), 
('Antonio', 'Vitali', 'S051', 2000, 'Messina', 'S021'), 
('Laura', 'Pellegrini', 'S052', 1999, 'Verona', 'S022'), 
('Michele', 'Serra', 'S053', 2001, 'Trieste', 'S023'), 
('Beatrice', 'Grimaldi', 'S054', 2002, 'Potenza', 'S024'), 
('Alberto', 'Fabbri', 'S055', 1998, 'Novara', 'S025'), 
('Ilaria', 'Mancini', 'S056', 2000, 'Cremona', 'S026'), 
('Carlo', 'Orlandi', 'S057', 1999, 'Treviso', 'S027'), 
('Sofia', 'Piazza', 'S058', 2001, 'Catania', 'S028'), 
('Giorgio', 'Ferraro', 'S059', 2002, 'Campobasso', 'S029'), 
('Elena', 'Moretti', 'S060', 1998, 'Varese', 'S030');
```

```sql
-- Inserimento di 30 docenti nella tabella Docenti
INSERT INTO Docenti (CodDoc, Nome, Cognome)
VALUES
('D001', 'Alessandro', 'Rossi'),
('D002', 'Maria', 'Bianchi'),
('D003', 'Giovanni', 'Verdi'),
('D004', 'Anna', 'Neri'),
('D005', 'Paolo', 'Galli'),
('D006', 'Laura', 'Conti'),
('D007', 'Marco', 'Ricci'),
('D008', 'Chiara', 'De Luca'),
('D009', 'Simone', 'Ferrari'),
('D010', 'Elena', 'Costa'),
('D011', 'Giorgio', 'Marini'),
('D012', 'Silvia', 'Barbieri'),
('D013', 'Alessandro', 'Fontana'),
('D014', 'Valentina', 'Serra'),
('D015', 'Andrea', 'Lombardi'),
('D016', 'Giulia', 'Giordano'),
('D017', 'Davide', 'Riva'),
('D018', 'Martina', 'D’Amico'),
('D019', 'Emanuele', 'Pellegrini'),
('D020', 'Federica', 'Gatti'),
('D021', 'Matteo', 'Battaglia'),
('D022', 'Sara', 'Mancini'),
('D023', 'Nicola', 'Orlandi'),
('D024', 'Irene', 'Santoro'),
('D025', 'Lorenzo', 'Puglisi'),
('D026', 'Beatrice', 'Biagi'),
('D027', 'Filippo', 'Fabbri'),
('D028', 'Camilla', 'Caprioli'),
('D029', 'Francesca', 'Cavalli'),
('D030', 'Tommaso', 'Greco');
```

```sql
-- Inserimento di 40 esami nella tabella Esami
INSERT INTO Esami (Codice, Candidato, Materia, CodDoc, Data, Voto, Lode)
VALUES
('E001', 'S001', 'Matematica', 'D001', '2023-01-15', 28, false),
('E002', 'S002', 'Fisica', 'D002', '2023-01-16', 30, true),
('E003', 'S003', 'Chimica', 'D003', '2023-01-17', 24, false),
('E004', 'S004', 'Informatica', 'D004', '2023-01-18', 27, false),
('E005', 'S005', 'Biologia', 'D005', '2023-01-19', 29, true),
('E006', 'S006', 'Storia', 'D006', '2023-01-20', 26, false),
('E007', 'S007', 'Geografia', 'D007', '2023-01-21', 22, false),
('E008', 'S008', 'Letteratura', 'D008', '2023-01-22', 25, false),
('E009', 'S009', 'Filosofia', 'D009', '2023-01-23', 30, true),
('E010', 'S010', 'Arte', 'D010', '2023-01-24', 18, false),
('E011', 'S011', 'Musica', 'D011', '2023-01-25', 20, false),
('E012', 'S012', 'Economia', 'D012', '2023-01-26', 28, false),
('E013', 'S013', 'Giurisprudenza', 'D013', '2023-01-27', 27, true),
('E014', 'S014', 'Ingegneria', 'D014', '2023-01-28', 25, false),
('E015', 'S015', 'Psicologia', 'D015', '2023-01-29', 21, false),
('E016', 'S016', 'Sociologia', 'D016', '2023-01-30', 30, true),
('E017', 'S017', 'Statistica', 'D017', '2023-02-01', 26, false),
('E018', 'S018', 'Astronomia', 'D018', '2023-02-02', 24, false),
('E019', 'S019', 'Fisioterapia', 'D019', '2023-02-03', 29, true),
('E020', 'S020', 'Agraria', 'D020', '2023-02-04', 28, false),
('E021', 'S021', 'Architettura', 'D021', '2023-02-05', 22, false),
('E022', 'S022', 'Scienze Politiche', 'D022', '2023-02-06', 27, false),
('E023', 'S023', 'Scienze Motorie', 'D023', '2023-02-07', 30, true),
('E024', 'S024', 'Scienze Ambientali', 'D024', '2023-02-08', 25, false),
('E025', 'S025', 'Scienze Naturali', 'D025', '2023-02-09', 21, false),
('E026', 'S026', 'Antropologia', 'D026', '2023-02-10', 30, true),
('E027', 'S027', 'Teologia', 'D027', '2023-02-11', 18, false),
('E028', 'S028', 'Geologia', 'D028', '2023-02-12', 20, false),
('E029', 'S029', 'Chirurgia', 'D029', '2023-02-13', 29, false),
('E030', 'S030', 'Farmacia', 'D030', '2023-02-14', 30, true);
```

---

```sql
-- seleziona gli studenti che hanno fatto almeno un esame e che hanno ottenuto solo 30.
select *
from studenti s
where matricola <>all 
(
	select candidato
	from esami
	where voto <> 30
) 
-- senza questo and, nell'output saranno presenti
-- anche tutti gli studenti che non hanno sostenuto
-- un esame, fare attenzione!
and matricola in (
	select candidato
	from esami
)
```
