

struct Pulse{
    int pulse;
    int time;
};



// Structure permettant de stocker chaque ligne d'information (le pouls et le temps)

void ReadFile(); // Lit le fichier et stocke les différents pouls dans un tableau

void AddPulse(struct Pulse *pls); // Ajoute une pulsation au tableau des pouls

struct Pulse **GetPulses(); // Fonction qui retourne le tableau des pouls

int GetPulsesSize(); // Affiche la taille du tableau des pouls

