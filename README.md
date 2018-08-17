ProgettoCpp
# Calcolo del prodotto tra due matrici

## Edoardo Righi - id468wfl - UNIVR

### Progetto C++ 

Questo progetto è ispirato ad un precedente progetto svolto per il corso di Sistemi Operativi.
Il programma costruito permette di eseguire la moltiplicazione tra due matrici in 2 casi:

1. Le due matrici sono quadrate e con le stesse dimensioni [ (nxn)*(nxn) ]
2. Le due matrici NON sono quadrate ma hanno dimensioni complementari [ (nxm)*(mxn) ]

#### Guida per compilazione ed esecuzione

1. Build del progetto con il comando bash `cmake -DCMAKE_BUILD_TYPE=Debug {PROJ_DIR}` nel caso di modalità Debug, `cmake -DCMAKE_BUILD_TYPE=Release {PROJ_DIR}` nel caso di modalità Release
2. Compilare con `make`
3. [Opzionale] Eseguire `make install` per spostare gli eseguibili dalla cartella `/build/bin` a `/bin`
4. Dare i permessi di esecuzione al file `CppProj` con `chmod +x CppProj`
5. Eseguire il file `./CppProj` con parametri i due file con le matrici di input e il file di output (esempio: `./bin/CppProj matA matB matC` [nel caso `CppProj` sia in `/bin`])

##### Esempio esecuzione rapida (terminale aperto nella directory principale)

1. `cmake .`
2. `make install`
3. `chmod +x ./bin/CppProj`
4. `./bin/CppProj matA matB matC`

#### make valgrind

Per utilizzare valgrind, dopo aver eseguito `make install`, inserire le matrici in due file chiamati `matA` e `matB`. Con il comando `make valgrind`, eseguito dalla directory principale del progetto, il risultato verrà salvato nel file `matC`.


#### Alcune soluzioni di prodotti già eseguiti


======================= 4x4 * 4x4 ==========================

con matA:

1 2 3 4  
1 1 2 2  
1 2 5 6  
2 7 4 -8  
  
e matB:  
  
1 2 7 8  
4 6 3 6  
7 4 3 2  
3 5 7 9  

risultato:
  
42 46 50 62  
25 26 30 36  
62 64 70 84  
34 22 -9 -6  

======================= 4x5 * 5x4 ==========================  

con matA:  

1 2 3 4  
1 1 2 2  
1 2 5 6  
2 7 4 -8  
1 1 1 1   

e matB: 

1 2 7 8 1  
4 6 3 6 1  
7 4 3 2 1  
3 5 7 9 1  

risultato:  

42 46 50 62 10  
25 26 30 36 6   
62 64 70 84 14  
34 22 -9 -6 5  
15 17 20 25 4  
