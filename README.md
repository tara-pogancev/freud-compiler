# Freud Compiler
#### Autor: Tara Pogančev

![Freud_Compiler](https://i.imgur.com/GvB1y2H.png)

Programski prevodilac "Freud" (Frojd) akademski je projekat na Fakultetu tehničkih nauka (smer Računarstvo i automatika), predmeta programski prevodioci. 

## O kompajleru
Jednostavan komapjler ima ulogu sintaksnu, leksičku i semantičku analizu datog koda pisanom u "Freud" jeziku (ekstenzija _.mew_).
Nakon uspešne analize koda, generiše se _.asm_ datoteka sa prevedenim originalnim kodom na asemblerski jezik. Ovaj kod može se pokrenuti i testirati korišćenjem _Hipsim_ simulatora.

Neke od *funkcionalnosti kompajlera* podrazumevaju:
	- Rad sa int i unsigned vrednostima
	- Rad sa funkcijama sa i bez povratne vrednosti (void)
	- Osnovne aritmetičke operacije sabiranje i oduzimanje
	- Postinkrementni operator
	- Jednolinijske i višelinijske komentare
	- Globalne promenljive
	- Ternarni operator u okviru numeričkih izraza
	- PARA iskaz (analogno logici for-statement-a)
	- SWITCH - CASE

## Upotreba kompajlera

_Pokretanjem make komande, generišu se fajlovi neophodni za pokretanje testova i korišćenje kompajlera i HIPSIM simulatora._
_Make test pokreće testove uz kratak ispis uspešnosti istih, dok Make det pokreće sve testove, i ispisuje moguće greške, kao i izlaznu vrednost._

```bash
make
make test
make det
```
