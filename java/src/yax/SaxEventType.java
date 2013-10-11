/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

package yax;

/* Enumerate the kinds of Sax Events received by the SaxEventHandler */

public enum SaxEventType {
    /* Use null for undefined */
    STARTDOCUMENT,
    ENDDOCUMENT,
    STARTELEMENT,
    ENDELEMENT,
    ATTRIBUTE,
    CHARACTERS;
}
