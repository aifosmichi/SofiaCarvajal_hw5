Resultados_hw5.pdf: Resultados_hw5.tex CI*.png RC*.png *.py CID*.txt canal_ionico.c
	pdflatex Resultados_hw5.tex
	
Resultados_hw5.pdf: Resultados_hw5.tex CI1B.png canalio.c
	pdflatex Resultados_hw5.tex

Resultados_hw5.tex: CI*.png RC*.png *.py CID*.txt canal_ionico.c
	touch Resultados_hw4.tex
	
Resultados_hw5.tex: CI1B.png canalio.c
	touch Resultados_hw4.tex
	
RC*.png : circuitoRC.py
	python circuitoRC.py

CID*.txt: canal_ionico.c
	cc canal_ionico.c -lm -o cuac.x
	./cuac.x

CI*.png: plots_canal_ionico.py CID*.txt
	python plots_canal_ionico.py
	
CI1B.png: plots_canal_ionico.py datosci1.txt
	python plots_canal_ionico.py
	
datosci1.txt: canalio.c
	cc canalio.c -lm -o cuac1.x
	./cuac.x

CI1B.png: plots_canal_ionico.py datosci1.txt
	python plots_canal_ionico.py

clean:
	rm *.png *.aux *.log *.pdf *.x
	


