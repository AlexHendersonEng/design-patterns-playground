/*
    Facade: Provides a simplified, uniform interface to a complex subsystem,
            making it easier to use. Instead of interacting with multiple components 
            of a system individually, the Facade acts as a single entry point
            that abstracts away the complexities.
*/

// Include necessary headers
#include <iostream>

// Subsystem 1: Amplifier
class Amplifier {
public:
    void on() { std::cout << "Amplifier is turned ON.\n"; }
    void off() { std::cout << "Amplifier is turned OFF.\n"; }
    void setVolume(int level) { std::cout << "Amplifier volume set to " << level << "\n"; }
};

// Subsystem 2: DVD Player
class DVDPlayer {
public:
    void on() { std::cout << "DVD Player is turned ON.\n"; }
    void off() { std::cout << "DVD Player is turned OFF.\n"; }
    void play(std::string movie) { std::cout << "Playing movie: " << movie << "\n"; }
};

// Subsystem 3: Projector
class Projector {
public:
    void on() { std::cout << "Projector is turned ON.\n"; }
    void off() { std::cout << "Projector is turned OFF.\n"; }
    void wideScreenMode() { std::cout << "Projector set to widescreen mode.\n"; }
};

// Facade: Home Theater System
class HomeTheaterFacade {
private:
    Amplifier amp;
    DVDPlayer dvd;
    Projector projector;

public:
    HomeTheaterFacade(Amplifier a, DVDPlayer d, Projector p) : amp(a), dvd(d), projector(p) {}

    void watchMovie(std::string movie) {
        std::cout << "\nPreparing to watch a movie...\n";
        amp.on();
        amp.setVolume(10);
        dvd.on();
        projector.on();
        projector.wideScreenMode();
        dvd.play(movie);
        std::cout << "Enjoy your movie!\n";
    }

    void endMovie() {
        std::cout << "\nShutting down the home theater system...\n";
        dvd.off();
        projector.off();
        amp.off();
        std::cout << "Home theater system is off.\n";
    }
};

// Client Code
int main() {
    // Creating subsystem objects
    Amplifier amp;
    DVDPlayer dvd;
    Projector projector;

    // Creating the facade with subsystem objects
    HomeTheaterFacade homeTheater(amp, dvd, projector);

    // Using the facade to watch a movie
    homeTheater.watchMovie("Inception");

    // Ending the movie
    homeTheater.endMovie();

    return 0;
}
