#include "uebung4.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BUFFER_SIZE 512


int print_file(char *filename)
{
  char buffer[BUFFER_SIZE];
  FILE* file = fopen(filename, "r");
  if(!file){
    return 1;
  }
  int size;
  while(!feof(file) && !ferror(file)){
    size = fread((void*)buffer, 1, BUFFER_SIZE, file);
    printf("%.*s", size, buffer); 
  }
  if(ferror(file)){
    fclose(file);
    return 2;
  }
  fclose(file);
  return 0;
}


int copy_file(char *source,char* dest)
{
  if(source == dest){
    return 2;
  }
  FILE* sourceFile = fopen(source, "r");
  FILE* destFile = fopen(dest, "w");

  if(!sourceFile){
  fclose(destFile);
    return 1;
  }
  
  if(!destFile){
  fclose(sourceFile);
    return 2;
  }

  char buffer[BUFFER_SIZE];
  while(!feof(sourceFile) && !ferror(sourceFile) && !ferror(destFile)){
    int size = fread((void*)buffer, 1, BUFFER_SIZE, sourceFile);
    fwrite((void*)buffer, 1, size, destFile);
  }

  if(ferror(sourceFile)){
  fclose(sourceFile);
  fclose(destFile);
    return 3;
  }
  else if(ferror(destFile)){
  fclose(sourceFile);
  fclose(destFile);
    return 4;
  }
  else{
  fclose(sourceFile);
  fclose(destFile);
    return 0;
  }
}


int addressbook_save(char* filename,struct s_addressbook_record* addressbook,int entries,int append)
{
  FILE* destFile;
  if(append == 1){
    destFile = fopen(filename, "a");
  }
  else{
    destFile = fopen(filename, "w");
  }

  
  if(!destFile)
    return 1;

  for(int i = 0; i<entries; i++){
    fwrite((void*)&addressbook[i], sizeof(addressbook), 1, destFile);
  }


  if(ferror(destFile)){
    fclose(destFile);
    return 2;
  }
  else{
    fclose(destFile);
    return 0;
  }
}


int addressbook_load(char* filename,struct s_addressbook_record* addressbook,int *entries)
{

  FILE* srcfile = fopen(filename, "r");
  
  if(!srcfile)
    return 1;


  int i = 0;
  while(!ferror(srcfile)){
    int size = fread((void*)&addressbook[i], sizeof(addressbook), 1, srcfile);
    if(feof(srcfile)){
      fclose(srcfile);
      return 0;
    }
    i++;
  }


  if(ferror(srcfile)){
  fclose(srcfile);
    return 2;
  }
  else{
  fclose(srcfile);
    return 3;
  }
}







// ID3 Tag Genres
char const* const genre_list[256] = {
  /* 0 */  "Blues", 
  /* 1 */  "Classic Rock", 
  /* 2 */  "Country", 
  /* 3 */  "Dance", 
  /* 4 */  "Disco", 
  /* 5 */  "Funk", 
  /* 6 */  "Grunge", 
  /* 7 */  "Hip-Hop", 
  /* 8 */  "Jazz", 
  /* 9 */  "Metal", 
  /* 10 */  "New Age", 
  /* 11 */  "Oldies", 
  /* 12 */  "Other", 
  /* 13 */  "Pop", 
  /* 14 */  "R&B", 
  /* 15 */  "Rap", 
  /* 16 */  "Reggae", 
  /* 17 */  "Rock", 
  /* 18 */  "Techno", 
  /* 19 */  "Industrial", 
  /* 20 */  "Alternative", 
  /* 21 */  "Ska", 
  /* 22 */  "Death Metal", 
  /* 23 */  "Pranks", 
  /* 24 */  "Soundtrack", 
  /* 25 */  "Euro-Techno", 
  /* 26 */  "Ambient", 
  /* 27 */  "Trip-Hop", 
  /* 28 */  "Vocal", 
  /* 29 */  "Jazz+Funk", 
  /* 30 */  "Fusion", 
  /* 31 */  "Trance", 
  /* 32 */  "Classical", 
  /* 33 */  "Instrumental", 
  /* 34 */  "Acid", 
  /* 35 */  "House", 
  /* 36 */  "Game", 
  /* 37 */  "Sound Clip", 
  /* 38 */  "Gospel", 
  /* 39 */  "Noise", 
  /* 40 */  "AlternRock", 
  /* 41 */  "Bass", 
  /* 42 */  "Soul", 
  /* 43 */  "Punk", 
  /* 44 */  "Space", 
  /* 45 */  "Meditative", 
  /* 46 */  "Instrumental Pop", 
  /* 47 */  "Instrumental Rock", 
  /* 48 */  "Ethnic", 
  /* 49 */  "Gothic", 
  /* 50 */  "Darkwave", 
  /* 51 */  "Techno-Industrial", 
  /* 52 */  "Electronic", 
  /* 53 */  "Pop-Folk", 
  /* 54 */  "Eurodance", 
  /* 55 */  "Dream", 
  /* 56 */  "Southern Rock", 
  /* 57 */  "Comedy", 
  /* 58 */  "Cult", 
  /* 59 */  "Gangsta", 
  /* 60 */  "Top 40", 
  /* 61 */  "Christian Rap", 
  /* 62 */  "Pop/Funk", 
  /* 63 */  "Jungle", 
  /* 64 */  "Native American", 
  /* 65 */  "Cabaret", 
  /* 66 */  "New Wave", 
  /* 67 */  "Psychadelic", 
  /* 68 */  "Rave", 
  /* 69 */  "Showtunes", 
  /* 70 */  "Trailer", 
  /* 71 */  "Lo-Fi", 
  /* 72 */  "Tribal", 
  /* 73 */  "Acid Punk", 
  /* 74 */  "Acid Jazz", 
  /* 75 */  "Polka", 
  /* 76 */  "Retro", 
  /* 77 */  "Musical", 
  /* 78 */  "Rock & Roll", 
  /* 79 */  "Hard Rock", 
  /* 80 */  "Folk", 
  /* 81 */  "Folk-Rock", 
  /* 82 */  "National Folk", 
  /* 83 */  "Swing", 
  /* 84 */  "Fast Fusion", 
  /* 85 */  "Bebob", 
  /* 86 */  "Latin", 
  /* 87 */  "Revival", 
  /* 88 */  "Celtic", 
  /* 89 */  "Bluegrass", 
  /* 90 */  "Avantgarde", 
  /* 91 */  "Gothic Rock", 
  /* 92 */  "Progressive Rock", 
  /* 93 */  "Psychedelic Rock", 
  /* 94 */  "Symphonic Rock", 
  /* 95 */  "Slow Rock", 
  /* 96 */  "Big Band", 
  /* 97 */  "Chorus", 
  /* 98 */  "Easy Listening", 
  /* 99 */  "Acoustic", 
  /* 100 */  "Humour", 
  /* 101 */  "Speech", 
  /* 102 */  "Chanson", 
  /* 103 */  "Opera", 
  /* 104 */  "Chamber Music", 
  /* 105 */  "Sonata", 
  /* 106 */  "Symphony", 
  /* 107 */  "Booty Bass", 
  /* 108 */  "Primus", 
  /* 109 */  "Porn Groove", 
  /* 110 */  "Satire", 
  /* 111 */  "Slow Jam", 
  /* 112 */  "Club", 
  /* 113 */  "Tango", 
  /* 114 */  "Samba", 
  /* 115 */  "Folklore", 
  /* 116 */  "Ballad", 
  /* 117 */  "Power Ballad", 
  /* 118 */  "Rhythmic Soul", 
  /* 119 */  "Freestyle", 
  /* 120 */  "Duet", 
  /* 121 */  "Punk Rock", 
  /* 122 */  "Drum Solo", 
  /* 123 */  "A capella", 
  /* 124 */  "Euro-House", 
  /* 125 */  "Dance Hall", 
  /* 126 */  "UNKNOWN", 
  /* 127 */  "UNKNOWN", 
  /* 128 */  "UNKNOWN", 
  /* 129 */  "UNKNOWN", 
  /* 130 */  "UNKNOWN", 
  /* 131 */  "UNKNOWN", 
  /* 132 */  "UNKNOWN", 
  /* 133 */  "UNKNOWN", 
  /* 134 */  "UNKNOWN", 
  /* 135 */  "UNKNOWN", 
  /* 136 */  "UNKNOWN", 
  /* 137 */  "UNKNOWN", 
  /* 138 */  "UNKNOWN", 
  /* 139 */  "UNKNOWN", 
  /* 140 */  "UNKNOWN", 
  /* 141 */  "UNKNOWN", 
  /* 142 */  "UNKNOWN", 
  /* 143 */  "UNKNOWN", 
  /* 144 */  "UNKNOWN", 
  /* 145 */  "UNKNOWN", 
  /* 146 */  "UNKNOWN", 
  /* 147 */  "UNKNOWN", 
  /* 148 */  "UNKNOWN", 
  /* 149 */  "UNKNOWN", 
  /* 150 */  "UNKNOWN", 
  /* 151 */  "UNKNOWN", 
  /* 152 */  "UNKNOWN", 
  /* 153 */  "UNKNOWN", 
  /* 154 */  "UNKNOWN", 
  /* 155 */  "UNKNOWN", 
  /* 156 */  "UNKNOWN", 
  /* 157 */  "UNKNOWN", 
  /* 158 */  "UNKNOWN", 
  /* 159 */  "UNKNOWN", 
  /* 160 */  "UNKNOWN", 
  /* 161 */  "UNKNOWN", 
  /* 162 */  "UNKNOWN", 
  /* 163 */  "UNKNOWN", 
  /* 164 */  "UNKNOWN", 
  /* 165 */  "UNKNOWN", 
  /* 166 */  "UNKNOWN", 
  /* 167 */  "UNKNOWN", 
  /* 168 */  "UNKNOWN", 
  /* 169 */  "UNKNOWN", 
  /* 170 */  "UNKNOWN", 
  /* 171 */  "UNKNOWN", 
  /* 172 */  "UNKNOWN", 
  /* 173 */  "UNKNOWN", 
  /* 174 */  "UNKNOWN", 
  /* 175 */  "UNKNOWN", 
  /* 176 */  "UNKNOWN", 
  /* 177 */  "UNKNOWN", 
  /* 178 */  "UNKNOWN", 
  /* 179 */  "UNKNOWN", 
  /* 180 */  "UNKNOWN", 
  /* 181 */  "UNKNOWN", 
  /* 182 */  "UNKNOWN", 
  /* 183 */  "UNKNOWN", 
  /* 184 */  "UNKNOWN", 
  /* 185 */  "UNKNOWN", 
  /* 186 */  "UNKNOWN", 
  /* 187 */  "UNKNOWN", 
  /* 188 */  "UNKNOWN", 
  /* 189 */  "UNKNOWN", 
  /* 190 */  "UNKNOWN", 
  /* 191 */  "UNKNOWN", 
  /* 192 */  "UNKNOWN", 
  /* 193 */  "UNKNOWN", 
  /* 194 */  "UNKNOWN", 
  /* 195 */  "UNKNOWN", 
  /* 196 */  "UNKNOWN", 
  /* 197 */  "UNKNOWN", 
  /* 198 */  "UNKNOWN", 
  /* 199 */  "UNKNOWN", 
  /* 200 */  "UNKNOWN", 
  /* 201 */  "UNKNOWN", 
  /* 202 */  "UNKNOWN", 
  /* 203 */  "UNKNOWN", 
  /* 204 */  "UNKNOWN", 
  /* 205 */  "UNKNOWN", 
  /* 206 */  "UNKNOWN", 
  /* 207 */  "UNKNOWN", 
  /* 208 */  "UNKNOWN", 
  /* 209 */  "UNKNOWN", 
  /* 210 */  "UNKNOWN", 
  /* 211 */  "UNKNOWN", 
  /* 212 */  "UNKNOWN", 
  /* 213 */  "UNKNOWN", 
  /* 214 */  "UNKNOWN", 
  /* 215 */  "UNKNOWN", 
  /* 216 */  "UNKNOWN", 
  /* 217 */  "UNKNOWN", 
  /* 218 */  "UNKNOWN", 
  /* 219 */  "UNKNOWN", 
  /* 220 */  "UNKNOWN", 
  /* 221 */  "UNKNOWN", 
  /* 222 */  "UNKNOWN", 
  /* 223 */  "UNKNOWN", 
  /* 224 */  "UNKNOWN", 
  /* 225 */  "UNKNOWN", 
  /* 226 */  "UNKNOWN", 
  /* 227 */  "UNKNOWN", 
  /* 228 */  "UNKNOWN", 
  /* 229 */  "UNKNOWN", 
  /* 230 */  "UNKNOWN", 
  /* 231 */  "UNKNOWN", 
  /* 232 */  "UNKNOWN", 
  /* 233 */  "UNKNOWN", 
  /* 234 */  "UNKNOWN", 
  /* 235 */  "UNKNOWN", 
  /* 236 */  "UNKNOWN", 
  /* 237 */  "UNKNOWN", 
  /* 238 */  "UNKNOWN", 
  /* 239 */  "UNKNOWN", 
  /* 240 */  "UNKNOWN", 
  /* 241 */  "UNKNOWN", 
  /* 242 */  "UNKNOWN", 
  /* 243 */  "UNKNOWN", 
  /* 244 */  "UNKNOWN", 
  /* 245 */  "UNKNOWN", 
  /* 246 */  "UNKNOWN", 
  /* 247 */  "UNKNOWN", 
  /* 248 */  "UNKNOWN", 
  /* 249 */  "UNKNOWN", 
  /* 250 */  "UNKNOWN", 
  /* 251 */  "UNKNOWN", 
  /* 252 */  "UNKNOWN", 
  /* 253 */  "UNKNOWN", 
  /* 254 */  "UNKNOWN", 
  /* 255 */  "UNKNOWN"};

  
  int print_id3(char* filename)
{
  
  FILE* songFile = fopen(filename, "r");
  char buffer[3];

  if(!songFile){
    return 1;
    }
  fseek(songFile, 127, SEEK_END);

  if(ferror(songFile)){
    fclose(songFile);
    return 2;
  }

  

struct id3tag{
  char tag[3];
  char titel[30];
  char kuenstler[30];
  char album[30];
  char jahr[4];
  char kommentar[30];
  int genre;
};

struct id3tag tag;

fread((void*)&tag, sizeof(tag), 1, songFile);

  if(ferror(songFile)){
    fclose(songFile);
    return 3;
  }

  if(tag.tag != "TAG"){
    fclose(songFile);
    return 2;
  }

fclose(songFile);

printf("Titel: %s\n", tag.titel);
printf("Künstler: %s\n", tag.kuenstler);
printf("Album: %s\n", tag.album);
printf("Jahr: %s\n", tag.jahr);
printf("Kommentar: %s\n", tag.kommentar);
printf("Genre: %s\n", genre_list[tag.genre]);

  return 0;

}