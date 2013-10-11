/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

package yax;

import org.xml.sax.Locator;

/**
Define a class to hold information provided to each kind of event
*/
public class SaxEvent
{
    static public boolean longform = false;

    public SaxEventType event = null;
    public String name = null;
    public String fullname = null;
    public String namespace = null;

    public String value = null; // for attributes
    public String text = null;  // for text

    public Locator locator = null;

    public SaxEvent(SaxEventType event)
    {
	this.event = event;
    }

    public SaxEvent(SaxEventType event, String name)
    {
        this(event);
	this.name=name;
    }

    public SaxEvent(SaxEventType event,
		    String name,
		    String fullname,
                    String uri)
    {
	this(event,name);
	this.fullname = fullname;
	this.namespace = uri;
    }

    public Locator getLocator() {return this.locator;}
    public void setLocator(Locator locator) {this.locator = locator;}

    public String toString()
    {
	String text; 
	if(longform)
	    text = (event == null ? "undefined" : event.toString());
	else
	    text = Util.trace(this);
	return text;
    }

} // class SaxEvent

