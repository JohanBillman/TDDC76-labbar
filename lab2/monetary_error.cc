/*
 * FILNAMN:       monetary_error.cc
 * LABORATION:    2
 * PROGRAMMERARE: Johan Billman 9202271772 johbi142
 * 				  Emma Värbrand 9101283068 emmva911
 * DATUM:         2013-09-26
 *
 * BESKRIVNING 
 * 
 * felhanteringsklass
 */

#include "Monetary.h"

 class monetary_error : public std::logic_error{
 	explicit monetary_error::monetary_error(const std::string& what_arg) 
 	: logic_error(what_arg) {}
 };