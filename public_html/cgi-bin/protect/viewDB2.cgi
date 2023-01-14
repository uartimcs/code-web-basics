#!/usr/bin/perl

use CGI qw(:standard);

# This is the flat-file database. Each record is stored on a single line, and
# each field is delimited by a semi-colon.
$DB_FILE = "../db.dat";

# The delimiter used to separate the fields in each record.
$DELIMITER = ";";

print header(), start_html("Lab 2.5 - Database Records");
print "<table border='1' cellspacing='0' cellpadding='5'> \n";
print "<tr style='background-color: #BBBBBB'> \n";
print "<td width='150'>Last Name</td> \n";
print "<td width='150'>First Name</td> \n";
print "<td width='300'>Email Address</td> \n";
print "</tr> \n";

open (FILE_HANDLE, $DB_FILE) or die "Error: $!";

# Reads the database file line by line until the end of file is reached.
$i=0;
while (<FILE_HANDLE>) {
  # Split each record into the individual fields.
  ($last[$i], $first[$i], $address[$i]) = split /$DELIMITER/, $_;
    $i++;
}
close FILE_HANDLE;

for ($j=1;$j<=$i; $j++)
{
print "<tr><td>$last[$i-$j]</td><td>$first[$i-$j]</td><td>";
 
 if ($address[$i-$j]=~/^$/) {
    print "&nbsp;</td></tr>\n";
  }
  else {
    print "$address[$i-$j]</td></tr>\n";
  }

}



print "</table>\n";
print end_html();

