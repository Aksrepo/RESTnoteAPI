// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest

#ifndef NOTES_H
#define NOTES_H

#include <fstream>
#include <string>
#include <list>
#include <ngrest/common/Service.h>

//! A simple note API 
/*! A simple note API which supports POST, GET by id, GET by query and GET all operations */
// '*location' comment sets resource path for this service
// *location: /notes

struct note {
	int id;
	std::string body;
};

// *interface.defaultInlineResult: true

class notes: public ngrest::Service
{
public:
    //! Adds a new note
    // *method: POST 
    note add(const std::string& body) {
	std::fstream fs;
	std::string line;
	int noteid = 0;
	note newnote;
        fs.open("notes.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	if(fs.is_open()) {
		fs << body << std::endl;
		fs.seekg(0);
		while(getline(fs,line)) {
			noteid++;
		}
	}
	fs.close();
	newnote.id = noteid;
	newnote.body = body;
  	return newnote;
    }
  
    //! Gets all notes
    // *method: GET
    std::list<note> getAll() {
	std::fstream fs;
	std::string line;
	int noteid = 0;
	note tempnote;
	std::list<note> allnotes;
	fs.open("notes.txt", std::fstream::in);
	fs.seekg (0,fs.end);
   	long size = fs.tellg();
   	fs.seekg (0);

	if(fs.is_open() && size) {
		while(getline(fs,line))
                {
                //push all the notes into the allnotes list
                	noteid++;
			tempnote.id = noteid;
			tempnote.body = line;
			allnotes.push_back(tempnote);
                }
	}
	fs.close();
	return allnotes;
    }

    //! Gets a note by id
    // *method: GET
    // *location: /{id}
    note get(const std::string& id) {
	std::fstream fs;
	std::string line;
	int noteid = 0, queryid;
	note idnote;
	queryid = stoi(id);
	fs.open("notes.txt", std::fstream::in);
        fs.seekg (0,fs.end);
        long size = fs.tellg();
        fs.seekg (0);

	if(fs.is_open() && size) {
                while(getline(fs,line))
                {
                //output the note matching the given id
                        noteid++;
			if(queryid == noteid) {
                        	idnote.id = noteid;
                        	idnote.body = line;
				return idnote;
			}
                }
        }
	fs.close();
	idnote.id = queryid;
	return idnote;
    }

    //! Gets all notes containing the query string (Note: Query string is case sensitive)
    // *method: GET
    std::list<note> getQuery(const std::string& query) {
	std::fstream fs;
	std::string line;
        int noteid = 0;
	note tempnote;
        std::list<note> querynotes;
        fs.open("notes.txt", std::fstream::in);
        fs.seekg (0,fs.end);
        long size = fs.tellg();
        fs.seekg (0);

        if(fs.is_open() && size) {
                while(getline(fs,line))
                {
                 //push the notes which match the query string into the querynotes list
                        noteid++;
                        if(line.find(query) != std::string::npos) {
                                tempnote.id = noteid;
                                tempnote.body = line;
                                querynotes.push_back(tempnote);
                        }
                }
        }
        fs.close();
        return querynotes;
    }
};


#endif // NOTES_H



