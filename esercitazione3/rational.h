#include <concepts>
#include <iostream>
#include <numeric> // serve per calcolo MCD -> semplificare frazioni
template<typename I> requires std::integral<I>
class rational
{
	I num_;
	I den_;
	bool nan_;
	bool inf_;

public: 

	//Costruttore default
	rational()
		: num_(0), den_(1), nan_(false), inf_(false)
	{}
	
	//Costruttore user-defined
	rational(const I num, const I den)
		: num_(num), den_(den), nan_(false), inf_(false)
	{
		if (den_ == 0) {
			if (num_ == 0) {
				nan_ = true;
			}
			else  {
				inf_ = true;
			}
		}
	}
	
	//Metodi che restituiscono valori di num, den, nan, inf
	I num() const {
		return num_;
	}
	
	I den() const {
		return den_;
	}
	
	bool nan() const {
		return nan_;
	}
	
	bool inf() const {
		return inf_;
	}
	
	//metodo per cambio segno 
	rational change_sign() {
		rational ret = *this; 
		ret.num_ = -ret.num_;
		return ret;
	}
	
	//Operatore incremento -> modifica razionale cui applicato
	rational operator+=(const rational other) {
		
		// se almeno uno NaN --> ottengo NaN
		if (nan_ == true || other.nan_ == true) {
			nan_ = true;
		}
		
		else {
			// caso inf + numero oppure infiniti concordi --> mantengo segno originale
			if ((inf_ == true && other.inf_ == false) || ((inf_ == true && other.inf_ == true) && ((num_ > 0 && other.num_ > 0) || (num_< 0 && other.num_ < 0)))) {
				inf_ = true;
			}
			// caso numero + inf --> devo cambiare segno in base a quello dell'inf
			else {
				if (inf_ == false && other.inf_ == true) {
					if (other.num_ > 0) {
						num_ = +1; //caso numero + (+inf) --> ottengo (+inf)
						inf_ = true; 
						//salvo l'informazione del segno con questo +1
					}
					else {
						num_ = -1; //caso numero + (-inf) --> ottengo (-inf)
						inf_ = true; 
					}
				}
				
				else {
				// caso infiniti discordi 
					if ((inf_ == true && other.inf_ == true) && ((num_ > 0 && other.num_ < 0) || (num_< 0 && other.num_ > 0))) {
							nan_ = true; 
							inf_ = false;
					}
					// incremento di base
					else {
						num_ = num_*other.den_ + other.num_*den_;
						den_ = den_*other.den_;
					}	
				}	
			}		
		}	
		
		return *this;
	}
	
	//Operatore somma -> restituisce nuovo razionale (la somma)
	rational operator+(const rational other) const {
		rational ret = *this;
		ret += other;
		return ret;
	}
	
	//Operatore differenza -> restituisce nuovo razionale (la differenza)
	rational operator-(const rational other) const {
		rational ret = *this;
		//aggiungo l'opposto del numero
		rational temp = other;
		ret += (temp.change_sign()); 
		return ret;
	}
	
	//Operatore moltiplicazione -> modifica razionale su cui applicato
	rational operator*=(const rational other) {
		
		// se almeno uno NaN --> ottengo NaN
		if (nan_ == true || other.nan_ == true) {
			nan_ = true;
		}
		
		else {
			// caso (+-inf) * 0
			if (inf_ == true && other.num_ == 0) {
				nan_ = true; 
				inf_ = false;
				}
			
			else {
				// caso numero * (+-inf)
				if (inf_ == false && other.inf_ == true) {
					
					// caso 0 * (+-inf)
					if (num_ == 0) {
						nan_ = true;
					}
					
					// numero non nullo * (+-inf)
					else {
						if (other.num_ > 0) {
							inf_ = true; 
							num_ = +1; 
						}
						
						else {
							inf_ = true; 
							num_ = -1; 
						}
					}
				}
				
				// moltiplicazione di base (casi infinito * infinito, infinito * numero non nullo, prodotto tra razionali)
				else {
					num_ = num_*other.num_;
					den_ = den_*other.den_;
				}
			}	
		}	
		return *this;
	}	
	
	//Operatore prodotto -> restituisce nuovo razionale (il prodotto)
	rational operator*(const rational other) const {
		rational ret = *this;
		ret *= other;
		return ret;
	}
	
	//Operatore divisione -> modifica razionale su cui applicato
	rational operator/=(const rational other) {
		
		// se almeno uno NaN --> ottengo NaN
		if (nan_ == true || other.nan_ == true) {
			nan_ = true;
		}
		else {
			// divido per infinito 
			if (other.inf_ == true ) {
				// caso numero diviso infinito
				if (inf_ == false) {
					num_ = 0; 
				}
				// caso infinito diviso infinito
				else {	
					nan_ = true; 
					inf_ = false; 
				}
			}
			// divido per zero 
			if (other.num_ == 0) {
				// caso zero diviso zero
				if (num_ == 0) {
					nan_ = true; 
				}
				// caso numero o infinito diviso zero
				else {
					inf_ = true; 
				}		
			
			}
			// divido per numero non nullo 
			else {
				// caso infinito diviso numero non nullo 
				if (inf_ == true) {
					num_ = num_*other.num_;	
				}
				// divisione di base 
				else {
					num_ = num_*other.den_;
					den_ = den_*other.num_;
				} 
			}	
		}
		return *this;
	}
	
	//Operatore diviso -> restituisce nuovo razionale (risultato della divisione)
	rational operator/(const rational other) const {
		rational ret = *this;
		ret /= other;
		return ret;
	}
};
//operatore << per stampa oggetto della classe rational
template<typename I> requires std::integral<I>
std::ostream& operator<<(std::ostream& os, const rational<I> r)
	{
		if (r.nan() == true) {
			os << "NaN";
		} 
		
		if (r.inf() == true) {
			if (r.num() > 0) {
				os << "+Inf";
			}
			else {
				os << "-Inf";
			}
			
		}
		
		if (r.inf() == false && r.nan() == false) {
			int mcd = std::gcd(r.num(), r.den()); //calcolo massimo divisore comune
			os << r.num()/mcd << "/" << r.den()/mcd << "\n";
		}
		
		return os;
	}