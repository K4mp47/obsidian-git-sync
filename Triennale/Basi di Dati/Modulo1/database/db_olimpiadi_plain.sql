-- Olimpiadi invernali --
-- DROP TABLE IF EXISTS public.nazioni;
CREATE TABLE IF NOT EXISTS public.nazioni (
    nome character varying NOT NULL,
    estensione integer,
    mumAbitanti integer, 
    CONSTRAINT nazioni_pkey PRIMARY KEY (nome)
);

-- DROP TABLE IF EXISTS public.atleti;
CREATE TABLE IF NOT EXISTS public.atleti (
    idatleta integer NOT NULL,
    nome character varying NOT NULL,
    cognome character varying NOT NULL,
    nazione character varying NOT NULL,
    sesso char(1) NOT NULL,
    annonascita integer NOT NULL,
    CONSTRAINT atleti_pkey PRIMARY KEY (idatleta),
    CONSTRAINT nazione FOREIGN KEY (nazione)
        REFERENCES public.nazioni (nome) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
);

-- DROP TABLE IF EXISTS public.medaglie;
CREATE TABLE IF NOT EXISTS public.medaglie (
    codice integer NOT NULL,
    tipo character varying NOT NULL,
    sport character varying NOT NULL,
    disciplina character varying,
    idatleta integer NOT NULL,
    anno integer NOT NULL,
    edizione integer NOT NULL,
    CONSTRAINT medaglie_pkey PRIMARY KEY (codice),
    CONSTRAINT idatleta FOREIGN KEY (idatleta)
        REFERENCES public.atleti (idatleta) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
);

INSERT INTO public.nazioni (nome, estensione, mumAbitanti) VALUES 
('Italia', 302073, 58760000),
('Svezia', 450295, 10540000),
('Francia', 551695, 68170000),
('Spagna', 506030, 48370000),
('USA', 9834000, 334900000),
('Norvegia', 385207, 5520000),
('Germania', 357022, 84480000),
('Svizzera', 41285, 8850000),
('Olanda', 41850, 17880000),
('Finlandia', 338440, 5580000),
('Austria', 83879, 9130000);

INSERT INTO public.atleti (idatleta, nome, cognome, nazione, sesso, annonascita) VALUES 
(1, 'Therese', 'Johaug', 'Norvegia', 'F', 1988),
(2, 'Kerttu', 'Niskanen', 'Finlandia', 'F', 1988),
(3, 'Krista', 'Lahteenmaki-Parmakoski', 'Finlandia', 'F', 1990), 
(4, 'Dario', 'Cologna', 'Svizzera', 'M', 1986), 
(5, 'Tora', 'Berger', 'Norvegia', 'F', 1981),
(6, 'Martin', 'Fourcade', 'Francia', 'M', 1988),
(7, 'Wolfgang', 'Perner', 'Austria', 'M', 1967),
(8, 'Arianna', 'Fontana', 'Italia', 'F', 1990),
(9, 'Suzanne', 'Schulting', 'Olanda', 'F', 1997),
(10, 'Thomas', 'Krol', 'Olanda', 'M', 1992),
(11, 'Marianne', 'Timmer', 'Olanda', 'F', 1974),
(12, 'Kelly', 'Clark', 'USA', 'F', 1983),
(13, 'Benjamin', 'Karl', 'Austria', 'M', 1985),
(14, 'Federica', 'Brignone', 'Italia', 'F', 1990),
(15, 'Sofia', 'Goggia', 'Italia', 'F', 1992),
(16, 'Andre', 'Myhrer', 'Svezia', 'M', 1983),
(17, 'Natalie', 'Geisenberger', 'Germania', 'F', 1988),
(18, 'Armin', 'Zoeggeler', 'Italia', 'M', 1974),
(19, 'Georg', 'Hackl', 'Italia', 'M', 1966),
(20, 'Matthias', 'Mayer', 'Austria', 'M', 1990),
(21, 'Michaela', 'Dorfmeister', 'Austria', 'F', 1973),
(22, 'Max', 'Langenhan', 'Germania', 'M', 1999),                          -- senza medaglia
(23, 'Ramona', 'Siebenhofer', 'Austria', 'F', 1991),                      -- senza medaglia
(24, 'Alberto', 'Tomba', 'Italia', 'M', 1966);

INSERT INTO public.medaglie (codice, tipo, sport, disciplina, idatleta, anno, edizione) VALUES 
(101, 'Argento', 'Biathlon', '10km Inseguimento F',5,2014,22),             -- Tora Berger
(102, 'Oro', 'Biathlon', '12.5km Inseguimento M',6,2014,22),               -- Martin Fourcade
(103, 'Bronzo', 'Biathlon', '10km M',7,2002,19),                           -- Wolfgang Perner
(104, 'Argento', 'Pattinaggio di velocità', '1000m M',10,2022,24),         -- Thomas Krol
(105, 'Oro', 'Pattinaggio di velocità', '1000m F',11,1998,18),             -- Marianne Timmer
(106, 'Oro', 'Sci di fondo', '10km Femminile TC',1,2022,24),               -- Therese Johaug
(107, 'Argento', 'Sci di fondo', '10km Femminile TC',2,2022,24),           -- Kerttu Niskanen
(108, 'Bronzo', 'Sci di fondo', '10km Femminile TC',3,2022,24),            -- Krista Lahteenmaki-Parmakoski
(109, 'Oro', 'Sci di fondo', '15km Liberi M',4,2018,23),                   -- Dario Cologna
(110, 'Argento', 'Short Track', '1500m F',8,2022,24),                      -- Arianna Fontana
(111, 'Oro', 'Short Track', '500m F',8,2022,24),                           -- Arianna Fontana
(112, 'Bronzo', 'Short Track', '1500m F',9,2022,24),                       -- Suzanne Schulting
(113, 'Argento', 'Short Track', '500m F',9,2022,24),                       -- Suzanne Schulting
(114, 'Bronzo', 'Snowboard', 'Halfpipe F',12,2014,22),                     -- Kelly Clark
(115, 'Argento', 'Snowboard', 'Slalom Gigante Parallelo M',13,2010,23),    -- Benjamin Karl
(116, 'Bronzo', 'Sci Alpino', 'Combinata Alpina F',14,2022,24),            -- Federica Brignone
(117, 'Argento', 'Sci Alpino', 'Slalom Gigante F',14,2022,24),             -- Federica Brignone
(118, 'Argento', 'Sci Alpino', 'Discesa Libera D',15,2022,24),             -- Sofia Goggia
(119, 'Oro', 'Sci Alpino', 'Slalom M',16,2018,23),                         -- Andre Myhrer
(120, 'Oro', 'Sci Alpino', 'Super-G F',21,2006,20),                        -- Michaela Dorfmeister
(121, 'Oro', 'Sci Alpino', 'Super-G M',20,2022,24),                        -- Matthias Mayer
(122, 'Bronzo', 'Slittino', 'Singolo F',17,2010,21),                       -- Natalie Geisenberger
(123, 'Bronzo', 'Slittino', 'Singolo M',18,2010,21),                       -- Armin Zoeggeler
(124, 'Bronzo', 'Slittino', 'Singolo M',18,1994,17),                       -- Armin Zoeggeler
(125, 'Argento', 'Slittino', 'Singolo M',18,1998,18),                      -- Armin Zoeggeler
(126, 'Oro', 'Slittino', 'Singolo M',18,2006,20),                          -- Armin Zoeggeler
(127, 'Bronzo', 'Slittino', 'Singolo M',18,2014,22),                       -- Armin Zoeggeler
(128, 'Oro', 'Slittino', 'Singolo M',19,1994,17),                          -- Georg Hackl
(129, 'Oro', 'Sci Alpino', 'Slalom Gigante M', 24, 1988, 15),              -- Alberto Tomba
(130, 'Oro', 'Sci Alpino', 'Slalom Speciale M', 24, 1988, 15),             -- Alberto Tomba
(131, 'Oro', 'Sci Alpino', 'Slalom Gigante M', 24, 1992, 16),              -- Alberto Tomba
(132, 'Argento', 'Sci Alpino', 'Slalom Speciale M', 24, 1992, 16),         -- Alberto Tomba
(133, 'Oro', 'Sci Alpino', 'Slalom Speciale M', 24, 1994, 17);             -- Alberto Tomba
