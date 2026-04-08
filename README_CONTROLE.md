# Projet Quartus CONTROLE

Ce depot contient un projet Quartus minimal pour la partie controle (TP codesign):

- CONTROLE.vhd: top-level FPGA
- calculateur_cable.vhd: bloc arithmetique cable (4 operations)
- capteurs_sol.vhd: interface ADC LTC2308
- clock_div2.vhd: division 50 MHz -> 25 MHz
- pulse_gen.vhd: generation data_capture a 2 kHz
- CONTROLE.qsf / CONTROLE.qpf: configuration Quartus et brochage
- software/validation_calculateur.c: programme de validation HW/SW

## Fonctionnement rapide

- SW[1:0] selectionnent l'operation:
  - 00: addition
  - 01: soustraction
  - 10: amplification x2
  - 11: attenuation /2
- SW[2] selectionne la paire de capteurs:
  - 0: data0 et data1
  - 1: data2 et data3
- SW[3] active le lancement du calcul a chaque nouvelle acquisition capteur.

Affichage LEDs:
- LED[7] = calc_data_ready
- LED[6] = overflow
- LED[5:0] = resultat (LSB)

## Etapes Quartus (13.0)

1. Ouvrir CONTROLE.qpf.
2. Verifier device: EP4CE22F17C6.
3. Lancer Analysis & Synthesis.
4. Compiler completement le VHDL avec Quartus (jusqu'a generation du fichier .sof).
5. Programmer la carte avec Altera Monitor Program.

## Note pour la validation logicielle (Q16)

Le fichier software/validation_calculateur.c suppose des adresses MMIO dediees au calculateur.
Ces adresses doivent etre alignees avec votre Platform Designer (system.h genere).
