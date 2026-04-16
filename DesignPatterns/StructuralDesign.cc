/* 

----- Structual Design Pattern -----

The structural design patterns is a way of combining or arranging different classes and objects to form larger and complex structures to solve a particular problem in a better way.
These patterns help in simplifying the design by identifying simple ways to realize relationships between entities. 

Take an example of a Building. A building is made up of different parts like roofs, walls, doors, etc. Each part has its own characteristics and functions, but when combined,
they form a complete structure that serves a specific purpose. Similarly, in software, structual design patterns help in combining different classes and objects to create larger
structures that are easier to understand and maintain. 

Structual design patterns are all about how classes and objects are composed to form larger structures. These patterns provide a way to create relationships between objects and classes
in a way that is easy to understand and maintain. 

--- Types of Structural Design Patterns ---

There are 7 main types of structural design patterns: 

 > Adapter Pattern, Converts the interface of a class into another interface that a client expects

 > Bridge Pattern, Separates an abstraction from its implementation so that the two can vary independently

 > Composite Pattern, Composes objects into tree structures to represent part-whole structure

 > Decorator Pattern, Adds new functionality to an object dynamically without changing its structure

 > Facade Pattern, Provides a simplified interface to a complex subsystem

 > Flyweight Pattern, Reduces the memory footprint by sharing common parts of objects

 > Proxy Pattern, Provides a surrogate or placeholder for another object to control access to it. 

--- When to Use Structural Design Patterns? ---

Structural design patterns are useful in the following scenarios: 

> If you want to simplify the design of a complex system by breaking it down into smaller, more manageable parts

> Times when you think you need to improve the flexibility and maintainability of your code by creating relationships
  between objects and classes that are easy to understand and modify. 

> To optimize the performance of your code by reducing memory usage and improving access to objects. 

> When you want to add new functionality to an object dynamically without changing its structure

> To provide a simplified interface to a complex subsystem. 

> If you want to control access to an object by providing a surrogate or placeholder for it. 

> If you want to separate an abstraction from its implementation so that the two can vary independently. 

--- Pros and Cons of Structural Design Patterns --- 

Pros: 

Improves code organization
Enhances flexibility and maintainability
Facilitates code reuse 
Reduces memory usage
Provides clear structure for complex systems

Cons: 

Can introduce complexity 
May lead to over-engineering 
Can impact performance 
May require additional learning 
Can make debugging more difficult 

--- Conclusion --- 

In this chapter, we have discussed the Structural Design Patterns in C++. We have seen the different types of structural design patterns and how they can be used to create flexible and 
maintable code. We have also seen an example of how multiple structual design patterns can be used together to create a complex system. Structural design patterns are an important tool
for any software developer, and understanding them can help you create better software. 
*/

#include <iostream> 
#include <string> 
#include <vector>
#include <memory>
using namespace std; 

class MediaFile { 
  public: 
    virtual string getType() = 0; 
    virtual void play() = 0; 
    virtual ~MediaFile() = default;
};

class MP3File : public MediaFile { 
  public: 
    string getType() { 
      return "MP3";
    }
    void play() { 
      cout << "Playing MP3 file" << endl; 
    }
};

class MP4File : public MediaFile { 
  public: 
    string getType() { 
      return "MP4";
    }
    void play(){ 
      cout << "Playing MP4 file" << endl;
    }
}; 

class MediaAdapter : public MediaFile { 
  private: 
    shared_ptr<MediaFile> mediaFile;
  public: 
    MediaAdapter(shared_ptr<MediaFile> file){
      mediaFile = file;
    }
    string getType(){
      return mediaFile->getType();
    }
    void play(){
      mediaFile->play();
    }
};

class Playlist : public MediaFile{
  private:
    vector<shared_ptr<MediaFile>> mediaFiles;
  public: 
    void add(shared_ptr<MediaFile> file){
      mediaFiles.push_back(file);
    }
    string getType(){
      return "Playlist";
    }
    void play(){
      cout << "Playing playlist:" << endl;
      for (auto& file : mediaFiles){
        file->play();
      }
    }
};

// Decorator
class MediaDec : public MediaFile { 
  protected: 
    shared_ptr<MediaFile> mediaFile;
  public: 
    MediaDec(shared_ptr<MediaFile> file) {
      mediaFile = file; 
    }
    string getType(){
      return mediaFile->getType();
    }
    void play(){
      mediaFile->play();
    }
};

class VisualEffectDec : public MediaDec { 
  public: 
    VisualEffectDec(shared_ptr<MediaFile> file) : MediaDec(file) {}
    void play(){
      mediaFile->play();
      cout << "Visual Effect for Audio" << endl;
    }
};

class AudioEnhancementDec : public MediaDec{
  public: 
    AudioEnhancementDec(shared_ptr<MediaFile> file) : MediaDec(file) {}
    void play(){
      mediaFile->play();
      cout << "Enhancing Audio" << endl;
    }
};

// Facade Pattern
class MediaPlayer{
  private: 
    shared_ptr<MediaFile> mediaFile;
  public: 
    MediaPlayer(shared_ptr<MediaFile> file){
      mediaFile = file;
    }
    void play(){
      mediaFile->play();
    }
};

// Proxy Pattern
class MediaProxy : public MediaFile { 
  private: 
    shared_ptr<MediaFile> mediaFile;
    bool authorized;
  public:
    MediaProxy(shared_ptr<MediaFile> file, bool auth){
      mediaFile = file;
      authorized = auth;
    }
    string getType(){
      return mediaFile->getType();
    }
    void play(){ 
      if (authorized){
        mediaFile->play();
      }
      else { 
        cout << "Access denied" << endl;
      }
    }
};

// Bridge Pattern 
class MediaImplmentation { 
  public: 
    virtual void play() = 0;
    virtual ~MediaImplmentation() = default;
};

class VLCImplementation : public MediaImplmentation { 
  public:
    void play(){
      cout << "Playing using VLC implementation" << endl;
    }
};

class WindowsMediaImplementation : public MediaImplmentation { 
  public: 
    void play(){ 
      cout << "Playing using Windows Media implementation" << endl;
    }
};

class MediaAbstraction { 
  protected: 
    shared_ptr<MediaImplmentation> implementation; 
  public: 
    MediaAbstraction(shared_ptr<MediaImplmentation> impl){
      implementation = impl;
    }
    virtual void play() = 0;
    virtual ~MediaAbstraction() = default;
};

class AdvancedMediaPLayer : public MediaAbstraction { 
  public:
    AdvancedMediaPLayer(shared_ptr<MediaImplmentation> impl) : 
  MediaAbstraction(impl){}
    void play() { 
      implementation->play();
    }
};

// Flyweight Pattern
class MediaMetadata{
  private: 
    string title;
    string artist;
    string album;

  public: 
    MediaMetadata(string t, string ar, string al) : title(t), artist(ar), album(al) {}
    string getTitle() {string title;}
    string getArtist() {string artist;}
    string getAlbum() {string album;}
    void display() { 
        cout << "Title: " << title << ", Artist: " << artist << ", Album: " << album << endl;
    }
};

class MediaMetadataFactory { 
  private: 
    vector<shared_ptr<MediaMetadata>> metadataPool;
  public: 
    shared_ptr<MediaMetadata> getMetadata(string title, string artist, string album) { 
      for (auto& meta : metadataPool){
        if (meta->getTitle() == title && 
            meta->getArtist() == artist &&
            meta->getAlbum() == album) { 
              return meta;
            }
      }
    shared_ptr<MediaMetadata> newMeta = make_shared<MediaMetadata> (title, artist, album);
    metadataPool.push_back(newMeta);
    return newMeta;
    }
  };
int main() { 
  // Create media files
  auto mp3 = make_shared<MP3File>();
  auto mp4 = make_shared<MP4File>();
  auto adaptedMp3 = make_shared<MediaAdapter>(mp3);
  auto adaptedMp4 = make_shared<MediaAdapter>(mp4);

  // Create playlist
  auto playlist = make_shared<Playlist>();
  playlist->add(adaptedMp3);
  playlist->add(adaptedMp4);
  playlist->add(make_shared<VisualEffectDec>(adaptedMp4));
  playlist->add(make_shared<AudioEnhancementDec>(adaptedMp4));

  // Create media player facade
  auto player = make_shared<MediaPlayer>(playlist);
  player->play();

  // Create media proxy
  auto proxy1 = make_shared<MediaProxy>(adaptedMp4, false);
  proxy1->play();
  auto proxy2 = make_shared<MediaProxy>(adaptedMp4, true);
  proxy2->play();

  // Create advanced media player with bridge pattern
  auto vlcImpl = make_shared<VLCImplementation>();
  shared_ptr<MediaAbstraction> advancedPlayer = 
  make_shared<AdvancedMediaPLayer>(vlcImpl);
  advancedPlayer->play();

  auto wmImpl = make_shared<WindowsMediaImplementation>();
  advancedPlayer = make_shared<AdvancedMediaPLayer>(wmImpl);
  advancedPlayer->play();

  // Create media metadata using flyweight pattern
  auto metadataFactory = make_shared<MediaMetadataFactory>();
  auto meta1 = metadataFactory->getMetadata("Song1", "Artist1", "Album1");
  auto meta2 = metadataFactory->getMetadata("Song2", "Artist1", "Album1");
  auto meta3 = metadataFactory->getMetadata("Song2", "Artist1", "Album2");

  meta1->display();
  meta2->display();
  meta3->display();

  return 0;
};