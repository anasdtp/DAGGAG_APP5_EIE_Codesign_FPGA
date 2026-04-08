# Validation logicielle du calculateur

Fichier: validation_calculateur.c

Objectif:
- Initialiser l'interface calculateur
- Declencher des calculs pour les 4 operations
- Lire result/ready/overflow
- Comparer avec un modele logiciel de reference

## Important

Avant compilation:
- Regenerer votre systeme Platform Designer
- Ouvrir le system.h de votre BSP
- Remplacer les macros CALC_*_BASE par les vraies adresses

## Build type (exemple)

- nios2-bsp hal BSP <sopcinfo>
- nios2-app-generate-makefile --bsp-dir BSP --src-rdir . --app-dir app
- make -C app

Adapter ces commandes a votre environnement de TP.
