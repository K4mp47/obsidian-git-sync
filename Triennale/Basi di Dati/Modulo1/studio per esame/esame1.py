class Seggio:
    def __init__(self, numero, comune):
        self.numero = numero
        self.comune = comune

class Presidente:
    def __init__(self, codice_fiscale, cognome, nome, comune_residenza, eta, seggio_numero):
        self.codice_fiscale = codice_fiscale
        self.cognome = cognome
        self.nome = nome
        self.comune_residenza = comune_residenza
        self.eta = eta
        self.seggio_numero = seggio_numero

class Scrutinatore:
    def __init__(self, codice_fiscale, cognome, nome, comune_residenza, seggio_numero):
        self.codice_fiscale = codice_fiscale
        self.cognome = cognome
        self.nome = nome
        self.comune_residenza = comune_residenza
        self.seggio_numero = seggio_numero

class RappresentanteLista:
    def __init__(self, codice_fiscale, cognome, nome, comune_residenza, partito_nome):
        self.codice_fiscale = codice_fiscale
        self.cognome = cognome
        self.nome = nome
        self.comune_residenza = comune_residenza
        self.partito_nome = partito_nome

class Elettore:
    def __init__(self, codice_fiscale, cognome, nome, comune_residenza, seggio_numero, ha_votato, data_voto):
        self.codice_fiscale = codice_fiscale
        self.cognome = cognome
        self.nome = nome
        self.comune_residenza = comune_residenza
        self.seggio_numero = seggio_numero
        self.ha_votato = ha_votato
        self.data_voto = data_voto

class Partito:
    def __init__(self, nome):
        self.nome = nome

class EsitoVotazioni:
    def __init__(self, seggio_numero, partito_nome, voti, schede_nulle):
        self.seggio_numero = seggio_numero
        self.partito_nome = partito_nome
        self.voti = voti
        self.schede_nulle = schede_nulle

# Sample data instantiation
seggio1 = Seggio(1, "Roma")
presidente1 = Presidente("ABC123", "Rossi", "Mario", "Roma", 45, 1)
scrutinatore1 = Scrutinatore("DEF456", "Bianchi", "Anna", "Roma", 1)
partito1 = Partito("Partito A")
rappresentante_lista1 = RappresentanteLista("GHI789", "Verdi", "Luca", "Roma", "Partito A")
elettore1 = Elettore("JKL012", "Neri", "Giulia", "Roma", 1, True, "2024-04-01")
esito_votazioni1 = EsitoVotazioni(1, "Partito A", 1000, 50)

# Output preview
print("Seggio:", seggio1.__dict__)
print("Presidente:", presidente1.__dict__)
print("Scrutinatore:", scrutinatore1.__dict__)
print("RappresentanteLista:", rappresentante_lista1.__dict__)
print("Elettore:", elettore1.__dict__)
print("Partito:", partito1.__dict__)
print("EsitoVotazioni:", esito_votazioni1.__dict__)

