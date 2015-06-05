#include "printer.hpp"
#include "template.hpp"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

using namespace bake;

Printer::Printer (string filename) {
	this->filename = filename;
}

void Printer::print (Tree* temp, vector<Post*> posts) {
	fstream *file = new fstream(filename, ios::out);

	if (file->is_open()) {
		(*file) << temp->get_begin();
		auto post_temp = temp->get_post_template();

		for (auto post :posts) {
			string post_str = post_temp->get_post(post);
			(*file) << post_str;
		}

		(*file) << temp->get_end();

		file->close();
	}

	delete file;
}