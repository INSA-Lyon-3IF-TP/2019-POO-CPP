#Utilisation du Makefile

Pour ne pas afficher les traces de débogage, la directive DMAP peut être commentée dans le fichier Makefile.
	
    $> make
pour compiler projet

    $> ./main
pour exécuter le programme

    $> make clean
pour nettoyer le répertoire des fichiers .o, l'exécutable, ainsi qu'un éventuel dump du core en cas d'erreur à l'exécution.


#Conclusion

Le plus gros problème que nous avons rencontré lors de notre projet concerne les fuites de mémoire. Toutefois, en utilisant correctement Valgrind ainsi que les traces de débogage, nous avons réussi à corriger ces problèmes.
Nous n'avons pas essayé de d'implémenter la recherche avancée car la difficulté de cette réalisation nous paraissait trop importante. Ainsi, on pourrait améliorer le travail en ajoutant la recherche avancée au projet.
Pour des raisons de facilité d'implémentation, nous ne considérons comme nom de ville que les noms sans espace, ce qui pourrait également être amélioré.