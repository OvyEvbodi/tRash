#!/bin/bash
gcc notes_log_2.0_.c -o notes_log;
sudo mv notes_log /usr/bin/;
echo "notes_log updated successfully.
Run 'notes_log' from anywhere for new or existing notes with auto timestamp.";
