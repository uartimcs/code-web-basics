#!/usr/bin/perl -w
use strict;
use CGI qw(:standard);
print header();
print `whoami`;
