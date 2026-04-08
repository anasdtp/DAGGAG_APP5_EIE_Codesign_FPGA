# Validation logicielle du calculateur

Fichiers:
- validation_calculateur.c: test automatique (plusieurs vecteurs)
- manual_calculateur.c: test manuel interactif (saisie operation + operandes)

Objectif:
- Initialiser l'interface calculateur
- Declencher des calculs pour les 4 operations
- Lire result/ready/overflow
- Comparer avec un modele logiciel de reference

## Important

Avant compilation:
- Regenerer votre systeme Platform Designer
- Regenerer le BSP (system.h)
- Verifier les adresses MMIO (SENSOR_CONTROL_BASE, SENSOR_STATUS_BASE, etc.)

## Build type (exemple)

- nios2-bsp hal BSP <sopcinfo>
- nios2-app-generate-makefile --bsp-dir BSP --src-rdir . --app-dir app
- make -C app

Adapter ces commandes a votre environnement de TP.
